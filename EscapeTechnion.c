#include <assert.h>
#include <mem.h>
#include "EscapeTechnion.h"
#include "stdlib.h"
#include "Company.h"

struct EscapeTechnionS {
    Set companies;
    Set costumers;
    int current_day;
};

static MtmErrorCode errorConverter(CompanyErrorCode company_error) {
    switch (company_error) {
        case COMPANY_INVALID_ARGUMENT:
            return MTM_INVALID_PARAMETER;
        case COMPANY_NULL_PARAMETER:
            return MTM_NULL_PARAMETER;
        case COMPANY_SUCCESS:
            return MTM_SUCCESS;
        case COMPANY_OUT_OF_MEMORY:
            return MTM_OUT_OF_MEMORY;
        case COMPANY_ROOM_ALREADY_EXIST:
            return MTM_ID_ALREADY_EXIST;
        case COMPANY_ROOM_DOESNT_EXIST:
            return MTM_ID_DOES_NOT_EXIST;
        case COMPANY_CLIENT_IN_ROOM:
            return MTM_CLIENT_IN_ROOM;
        case COMPANY_ROOM_ORDERS_EXIST:
            return MTM_RESERVATION_EXISTS;
        case COMPANY_ROOM_NOT_AVAILABLE:
            return MTM_ROOM_NOT_AVAILABLE;
        case COMPANY_UNKNOWN:
            return MTM_OUT_OF_MEMORY;

    }
}

MtmErrorCode escapeTechnionCreate(EscapeTechnion escape_technion) {
    escape_technion = malloc(sizeof(*escape_technion));
    if (escape_technion == NULL) {
        return MTM_OUT_OF_MEMORY;
    }
    escape_technion->companies = setCreate(escapeTechnionCopyCompany,
                                           escapeTechnionFreeCompany,
                                           escapeTechnionCompareCompanies);
    if (escape_technion->companies == NULL) {
        free(escape_technion);
        return MTM_OUT_OF_MEMORY;
    }
    escape_technion->costumers = setCreate(escapeTechnionCopyCostumer,
                                           escapeTechnionFreeCostumer,
                                           escapeTechnionCompareCostumers);
    if (escape_technion->costumers == NULL) {
        setDestroy(escape_technion->companies);
        free(escape_technion);
        return MTM_OUT_OF_MEMORY;
    }
    escape_technion->current_day = 0;
    return MTM_SUCCESS;
}

void escapeTechnionDestroy(EscapeTechnion escape_technion) {
    setDestroy(escape_technion->costumers);
    setDestroy(escape_technion->companies);
    free(escape_technion);
}

static bool checkEmailAddress(char *email_address) {
    int counter = 0;
    while (*email_address != '\0') {
        if (*email_address == '@') {
            counter++;
        }
        email_address++;
    }
    if (counter == 1) {
        return true;
    }
    return false;
}

static bool emailExists(EscapeTechnion escape_technion, char *email) {
    SET_FOREACH(Company, company_iterator, escape_technion->companies) {
        if (strcmp(companyGetEmailAddress(company_iterator), email) == 0) {
            return true;
        }
    }
    SET_FOREACH(Costumer, costumer_iterator, escape_technion->costumers) {
        if (strcmp(costumerGetEmailAddress(costumer_iterator), email) ==
            0) {
            return true;
        }
    }
    return false;
}

MtmErrorCode escapeTechnionAddCompany(EscapeTechnion escape_technion,
                                      char *email,
                                      TechnionFaculty faculty) {
    if (escape_technion == NULL || checkEmailAddress(email) == false) {
        return MTM_INVALID_PARAMETER;
    }
    if (emailExists(escape_technion, email) == true) {
        return MTM_EMAIL_ALREADY_EXISTS;
    }
    Email company_email;
    company_email.address = email;
    company_email.user_type = COMPANY;
    Company company = companyCreate(company_email, faculty);
    if (company == NULL) {
        return MTM_OUT_OF_MEMORY;
    }
    SetResult result;
    result = setAdd(escape_technion->companies, (SetElement) company);
    companyDestroy(company);
    if (result == SET_OUT_OF_MEMORY) {
        return MTM_OUT_OF_MEMORY;
    }
    return MTM_SUCCESS;
}

MtmErrorCode escapeTechnionDestroyCompany(EscapeTechnion escape_technion,
                                          char *email_address) {
    Company company_to_delete = NULL;
    SET_FOREACH(Company, company_iterator, escape_technion->companies) {
        if (strcmp(companyGetEmailAddress(company_iterator),
                   email_address) == 0) {
            company_to_delete = company_iterator;
            break;
        }
    }
    if (company_to_delete == NULL) {
        return MTM_COMPANY_EMAIL_DOES_NOT_EXIST;
    }
    if (companyOrdersExist(company_to_delete)) {
        return MTM_RESERVATION_EXISTS;
    }
    setRemove(escape_technion->companies, company_to_delete);
    return MTM_SUCCESS;
}

MtmErrorCode
escapeTechnionAddRoom(EscapeTechnion escape_technion, char *email_address,
                      int id, int price,
                      int num_people, int open_hour,
                      int close_hour, int difficulty) {
    CompanyErrorCode result;
    Email company_email;
    company_email.address = email_address;
    company_email.user_type = COMPANY;
    Company company = NULL;
    SET_FOREACH(Company, company_finder, escape_technion->companies) {
        if (company_email.address ==
            companyGetEmailAddress(company_finder)) {
            company = company_finder;
            break;
        }
    }
    if (company == NULL) {
        return MTM_COMPANY_EMAIL_DOES_NOT_EXIST;
    }
    SET_FOREACH(Company, company_itreator, escape_technion->companies) {
        if (companyGetFaculty(company_itreator) ==
            companyGetFaculty(company)) {
            if (companyCheckRoomExist(company_itreator)) {
                return MTM_ID_ALREADY_EXIST;
            }
        }
    }
    companyAddRoom(company, id, price, open_hour, close_hour, num_people,
                   difficulty);
    return MTM_SUCCESS;
}

MtmErrorCode escapeTechnionDeleteRoom(EscapeTechnion escape_technion,
                                      TechnionFaculty faculty, int id) {
    if(escape_technion==NULL || faculty>UNKNOWN || faculty <0 || id<0){
        return MTM_INVALID_PARAMETER;
    }
    SET_FOREACH(Company, company_iterator, escape_technion->companies) {
        if (companyGetFaculty(company_iterator) == faculty) {
            CompanyErrorCode company_result =
                    companyDeleteRoomByID(company_iterator, id);
            MtmErrorCode result = errorConverter(company_result);
            if(result!=MTM_INVALID_PARAMETER){
                return result;
            }
        }
    }
    return MTM_ID_DOES_NOT_EXIST;
}


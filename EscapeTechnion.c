#include <assert.h>
#include <mem.h>
#include "EscapeTechnion.h"
#include "stdlib.h"
#include "Company.h"

struct EscapeTechnionS{
    Set companies;
    Set costumers;
    int current_day;
};
MtmErrorCode escapeTechnionCreate(EscapeTechnion escape_technion){
    escape_technion = malloc(sizeof(*escape_technion));
    if(escape_technion==NULL){
        return MTM_OUT_OF_MEMORY;
    }
    escape_technion->companies=setCreate(escapeTechnionCopyCompany,
                                        escapeTechnionFreeCompany,
                                        escapeTechnionCompareCompanies);
    if(escape_technion->companies==NULL){
        free(escape_technion);
        return MTM_OUT_OF_MEMORY;
    }
    escape_technion->costumers=setCreate(escapeTechnionCopyCostumer,
                                        escapeTechnionFreeCostumer,
                                        escapeTechnionCompareCostumers);
    if(escape_technion->costumers==NULL){
        setDestroy(escape_technion->companies);
        free(escape_technion);
        return MTM_OUT_OF_MEMORY;
    }
    escape_technion->current_day=0;
    return MTM_SUCCESS;
}

void escapeTechnionDestroy(EscapeTechnion escape_technion){
    setDestroy(escape_technion->costumers);
    setDestroy(escape_technion->companies);
    free(escape_technion);
}
static bool checkEmailAddress(char *email_address){
    int counter=0;
    while(*email_address!='\0'){
        if(*email_address=='@'){
            counter++;
        }
        email_address++;
    }
    if(counter==1){
        return true;
    }
    return false;
}
static bool emailExists(EscapeTechnion escape_technion,char *email){
    SET_FOREACH(Company , company_iterator,escape_technion->companies){
        if(strcmp(companyGetEmailAddress(company_iterator),email)==0){
            return true;
        }
    }
    SET_FOREACH(Costumer , costumer_iterator , escape_technion->costumers){
        if(strcmp(costumerGetEmailAddress(costumer_iterator),email)==0){
            return true;
        }
    }
    return false;
}
MtmErrorCode escapeTechnionAddCompany(EscapeTechnion escape_technion,
                                      char *email,TechnionFaculty faculty){
    if(escape_technion==NULL || checkEmailAddress(email)==false){
        return MTM_INVALID_PARAMETER;
    }
    if(emailExists(escape_technion,email)==true){
        return MTM_EMAIL_ALREADY_EXISTS;
    }
    Email company_email;
    company_email.address=email;
    company_email.user_type=COMPANY;
    Company company = companyCreate(company_email,faculty);
    if(company==NULL){
        return MTM_OUT_OF_MEMORY;
    }
    SetResult result;
    result=setAdd(escape_technion->companies , (SetElement)company);
    companyDestroy(company);
    if(result==SET_OUT_OF_MEMORY){
        return MTM_OUT_OF_MEMORY;
    }
    return MTM_SUCCESS;
}

MtmErrorCode escapeTechnionDestroyCompany(EscapeTechnion escape_technion,
                                          char *email_address){
    Company company_to_delete=NULL;
    SET_FOREACH(Company ,company_iterator,escape_technion->companies){
        if(strcmp(companyGetEmailAddress(company_iterator),email_address)==0){
            company_to_delete=company_iterator;
            break;
        }
    }
    if(company_to_delete==NULL){
        return MTM_COMPANY_EMAIL_DOES_NOT_EXIST;
    }
    if(companyOrdersExist(company_to_delete)) {
        return MTM_RESERVATION_EXISTS;
    }
    setRemove(escape_technion->companies,company_to_delete);
    return MTM_SUCCESS;
}
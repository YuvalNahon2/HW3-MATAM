#include <assert.h>
#include <string.h>
#include "EscapeTechnion.h"
#include <stdlib.h>
#include "Company.h"
#include "Order.h"

struct EscapeTechnionS {
    Set companies;
    Set costumers;
    int current_day;
    int faculties_money[UNKNOWN];
};
int escapeTechnionGetDay(EscapeTechnion escape_technion){
    return escape_technion->current_day;
}
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
    return MTM_NULL_PARAMETER;
}

static SetElement escapeTechnionCopyCompany(SetElement company) {
    return (SetElement) companyCopy((Company) company);
}

static void escapeTechnionFreeCompany(SetElement company) {
    companyDestroy((Company) company);
}

static int escapeTechnionCompareCompanies(SetElement company1,
                                          SetElement company2) {
    return strcmp(companyGetEmailAddress((Company) company1),
                  companyGetEmailAddress((Company) company2));
}

static SetElement escapeTechnionCopyCostumer(SetElement costumer) {
    return costumerCopy((Costumer) costumer);
}

static void escapeTechnionFreeCostumer(SetElement costumer) {
    costumerDestroy((Costumer) costumer);
}

static int escapeTechnionCompareCostumers(SetElement costumer1,
                                          SetElement costumer2) {
    return strcmp(costumerGetEmailAddress((Costumer) costumer1),
                  costumerGetEmailAddress((Costumer) costumer2));
}

EscapeTechnion escapeTechnionCreate() {
    EscapeTechnion escape_technion;
    escape_technion = malloc(sizeof(*escape_technion));
    if (escape_technion == NULL) {
        return NULL;
    }
    escape_technion->companies = setCreate(escapeTechnionCopyCompany,
                                           escapeTechnionFreeCompany,
                                           escapeTechnionCompareCompanies);
    if (escape_technion->companies == NULL) {
        free(escape_technion);
        return NULL;
    }
    escape_technion->costumers = setCreate(escapeTechnionCopyCostumer,
                                           escapeTechnionFreeCostumer,
                                           escapeTechnionCompareCostumers);
    if (escape_technion->costumers == NULL) {
        setDestroy(escape_technion->companies);
        free(escape_technion);
        return NULL;
    }
    escape_technion->current_day = 0;
    for(int k=0;k<UNKNOWN;k++) {
        escape_technion->faculties_money[k]=0;
    }
    return escape_technion;
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
    if(setGetSize(escape_technion->companies)==0){
        return false;
    }
    SET_FOREACH(Company, company_iterator, escape_technion->companies) {
        if (strcmp(companyGetEmailAddress(company_iterator), email) == 0) {
            return true;
        }
    }
    SET_FOREACH(Costumer, costumer_iterator, escape_technion->costumers) {
        if (strcmp(costumerGetEmailAddress(costumer_iterator), email) == 0) {
            return true;
        }
    }
    return false;
}

MtmErrorCode escapeTechnionAddCompany(EscapeTechnion escape_technion,
                                      char *email,
                                      TechnionFaculty faculty) {
    if (escape_technion == NULL || email == NULL) {
        return MTM_NULL_PARAMETER;
    }
    if (checkEmailAddress(email) == false || faculty >= UNKNOWN ||
        faculty < 0) {
        return MTM_INVALID_PARAMETER;
    }
    if (emailExists(escape_technion, email) == true) {
        return MTM_EMAIL_ALREADY_EXISTS;
    }
    Company company = companyCreate(email, faculty);
    if (company == NULL) {
        return MTM_OUT_OF_MEMORY;
    }
    SetResult result;
    result = setAdd(escape_technion->companies, company);
    companyDestroy(company);
    if (result == SET_ITEM_ALREADY_EXISTS) {
        return MTM_EMAIL_ALREADY_EXISTS;
    }
    return MTM_SUCCESS;
}

MtmErrorCode escapeTechnionDestroyCompany(EscapeTechnion escape_technion,
                                          char *email_address) {
    if (escape_technion == NULL || email_address == NULL) {
        return MTM_NULL_PARAMETER;
    }
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


MtmErrorCode escapeTechnionAddRoom(EscapeTechnion escape_technion,
                                   char *email_address, int id, int price,
                                   int num_people, int open_hour,
                                   int close_hour, int difficulty) {
    if (escape_technion == NULL || email_address == NULL) {
        return MTM_NULL_PARAMETER;
    }
    Company company = NULL;
    SET_FOREACH(Company, company_finder, escape_technion->companies) {
        if (strcmp(email_address,
            companyGetEmailAddress(company_finder))==0) {
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
            if (companyHasRoom(company_itreator,id)) {
                return MTM_ID_ALREADY_EXIST;
            }
        }
    }
    return errorConverter(companyAddRoom(company, id, price, open_hour,
                                         close_hour, num_people, difficulty));
}

MtmErrorCode escapeTechnionDeleteRoom(EscapeTechnion escape_technion,
                                      TechnionFaculty faculty, int id) {
    if (escape_technion == NULL) {
        return MTM_NULL_PARAMETER;
    }
    SET_FOREACH(Company, company_iterator, escape_technion->companies) {
        if (companyGetFaculty(company_iterator) == faculty) {
            CompanyErrorCode company_result =
                    companyDeleteRoom(company_iterator, id);
            MtmErrorCode result = errorConverter(company_result);
            if (result != MTM_ID_DOES_NOT_EXIST) {
                return result;
            }
        }
    }
    return MTM_ID_DOES_NOT_EXIST;
}

MtmErrorCode escapeTechnionAddCostumer(EscapeTechnion escape_technion,
                                       char *email_address,
                                       TechnionFaculty faculty,
                                       int skill_level) {
    if (escape_technion == NULL || email_address == NULL) {
        return MTM_NULL_PARAMETER;
    }
    if (!checkEmailAddress(email_address) || faculty>=UNKNOWN || faculty<0
        ||skill_level<1 || skill_level>10) {
        return MTM_INVALID_PARAMETER;
    }
    Costumer costumer = costumerCreate(email_address, faculty, skill_level);
    if (costumer == NULL) {
        return MTM_OUT_OF_MEMORY;
    }
    SetResult result = setAdd(escape_technion->costumers, costumer);
    assert(result != SET_NULL_ARGUMENT);
    if (result == SET_OUT_OF_MEMORY) {
        return MTM_OUT_OF_MEMORY;
    }
    if (result == SET_ITEM_ALREADY_EXISTS) {
        return MTM_EMAIL_ALREADY_EXISTS;
    }
    costumerDestroy(costumer);
    return MTM_SUCCESS;
}

MtmErrorCode escapeTechnionDestroyCostumer(EscapeTechnion escape_technion,
                                           char *email_address) {
    bool costumer_exists = false;
    if (escape_technion == NULL || email_address == NULL) {
        return MTM_NULL_PARAMETER;
    }
    if (!checkEmailAddress(email_address)) {
        return MTM_INVALID_PARAMETER;
    }
    SET_FOREACH(Costumer, costumer_iterator, escape_technion->costumers) {
        if (strcmp(costumerGetEmailAddress(costumer_iterator), email_address) ==
            0) {
            costumer_exists = true;
            SET_FOREACH(Company, company_iterator, escape_technion->companies) {
                companyDeleteCostumerOrders(company_iterator,
                                            costumer_iterator);
            }
            setRemove(escape_technion->costumers,costumer_iterator);
        }
    }
    if (costumer_exists == false) {
        return MTM_CLIENT_EMAIL_DOES_NOT_EXIST;
    }
    return MTM_SUCCESS;
}

static Costumer escapeTechnionFindCostumer(EscapeTechnion escape_technion,
                                           char *costumer_email) {
    Costumer costumer = NULL;
    SET_FOREACH(Costumer, costumer_iterator, escape_technion->costumers) {
        if (strcmp(costumerGetEmailAddress(costumer_iterator),
                   costumer_email) == 0) {
            costumer = costumer_iterator;
        }
    }
    return costumer;
}

MtmErrorCode escapeTechnionCreateOrder(EscapeTechnion escape_technion,
                                       char *costumer_email,
                                       TechnionFaculty room_faculty,
                                       int room_id, int day,
                                       int hour, int num_people) {
    if (escape_technion == NULL) {
        return MTM_NULL_PARAMETER;
    }
    if (!checkEmailAddress(costumer_email) || room_faculty<0 ||
            room_faculty>UNKNOWN || day<escape_technion->current_day || day<0 ||
            hour<0 || hour>23 || num_people<=0) {
        return MTM_INVALID_PARAMETER;
    }
    Costumer costumer = escapeTechnionFindCostumer(escape_technion,
                                                   costumer_email);
    SET_FOREACH(Company,company_iterator,escape_technion->companies) {
        if(companyCostumerHasOrder(company_iterator,costumer,room_faculty,
                                   room_id,day,hour)){
            return MTM_CLIENT_IN_ROOM;
        }

    }
    if (costumer == NULL) {
        return MTM_CLIENT_EMAIL_DOES_NOT_EXIST;
    }
    Company company_to_order = NULL;

    SET_FOREACH(Company, company_iterator, escape_technion->companies) {
        if (companyGetFaculty(company_iterator) == room_faculty) {
            if (companyHasRoom(company_iterator, room_id)) {
                company_to_order = company_iterator;
                CompanyErrorCode company_result = companyCreateOrder(
                        company_to_order, costumer,
                        room_id, day, hour, num_people,escape_technion->current_day);
                MtmErrorCode result = errorConverter(company_result);
                return result;
            }
        }
    }
    return MTM_ID_DOES_NOT_EXIST;
}

MtmErrorCode escapeTechnionOrderRecommended(EscapeTechnion escape_technion,
                                            char *costumer_email_address,
                                            int num_people) {
    if (escape_technion == NULL || costumer_email_address == NULL) {
        return MTM_NULL_PARAMETER;
    }
    if (!checkEmailAddress(costumer_email_address)) {
        return MTM_INVALID_PARAMETER;
    }
    Costumer costumer = escapeTechnionFindCostumer(escape_technion,
                                                   costumer_email_address);
    if (costumer == NULL) {
        return MTM_CLIENT_EMAIL_DOES_NOT_EXIST;
    }

    int min_recommend_score = -1;
    EscapeRoom min_recommend_room = NULL;
    Company recommended_company = NULL;
    SET_FOREACH(Company, company_iterator, escape_technion->companies) {
        EscapeRoom curr_recommended = companyGetRecommendedRoom(
                company_iterator,
                costumer, num_people);
        int curr_score = escapeRoomRecommendScore(curr_recommended,
                                                  costumerGetSkillLevel(costumer),
                                                  num_people);
        if (curr_score < min_recommend_score || min_recommend_score == -1) {
            min_recommend_room = curr_recommended;
            min_recommend_score = curr_score;
            recommended_company = company_iterator;
        }
        else if (curr_score == min_recommend_score) {
            int check=abs(companyGetFaculty(company_iterator)-costumerGetFaculty(costumer))-
                      abs(companyGetFaculty(recommended_company)-costumerGetFaculty(costumer));
            if(check<0){
                min_recommend_room = curr_recommended;
                min_recommend_score = curr_score;
                recommended_company = company_iterator;
            }
            else if(check==0){
                if(escapeRoomGetId(curr_recommended)<escapeRoomGetId(min_recommend_room)){
                    min_recommend_room = curr_recommended;
                    min_recommend_score = curr_score;
                    recommended_company = company_iterator;
                }
            }
        }
    }
    if (recommended_company == NULL || min_recommend_room == NULL) {
        return MTM_NO_ROOMS_AVAILABLE;
    }
    bool discount = costumerGetFaculty(costumer) ==
                    companyGetFaculty(recommended_company);
    if (escapeRoomOrderClosest(min_recommend_room, costumer, num_people,
                               discount,
                               escape_technion->current_day) ==
                                                    ROOM_OUT_OF_MEMORY) {
        return MTM_OUT_OF_MEMORY;
    }
    return MTM_SUCCESS;
}

static int compareOrdersByHour(ListElement order1, ListElement order2) {
    return orderGetOrderHour(order1)-
           orderGetOrderHour(order2);
}


MtmErrorCode escapeTechnionEndDay(EscapeTechnion escape_technion,FILE *output) {
    List orders_faculties[UNKNOWN];
    for (int i = 0;  i < (int)UNKNOWN;i++) {
        orders_faculties[i]=NULL;
    }
    int money_earned_company;
    SET_FOREACH(Company,company_iterator,escape_technion->companies){
        TechnionFaculty faculty=companyGetFaculty(company_iterator);
        orders_faculties[faculty]=
                companyEndDay(company_iterator,escape_technion->current_day,
                              &money_earned_company);
        escape_technion->faculties_money[faculty]+=money_earned_company;
    }
    List all_today_orders = listCreate(escapeRoomOrderCopy,
                                       escapeRoomOrderDestroy);
    if (all_today_orders == NULL) {
        return MTM_OUT_OF_MEMORY;
    }
    for(int i=0;i<(int)UNKNOWN;i++) {
        if(orders_faculties==NULL){
            continue;
        }
        LIST_FOREACH(Order, order_iterator,orders_faculties[i]){
            listInsertLast(all_today_orders,order_iterator);
        }
    }
    listSort(all_today_orders,compareOrdersByHour);
    mtmPrintDayHeader(output,escape_technion->current_day,
                      listGetSize(all_today_orders));
    //runs through all orders.
    Company curr_company=NULL;
    LIST_FOREACH(Order,order_iterator,all_today_orders) {
        Costumer curr_costumer=orderGetCostumer(order_iterator);
        int room_id=escapeRoomGetId(orderGetRoom(order_iterator));
        TechnionFaculty faculty=costumerGetFaculty(curr_costumer);
        //searches for the company.

        SET_FOREACH(Company,company_finder,escape_technion->companies){
            if(companyGetFaculty(company_finder)==faculty && companyHasRoom(company_finder,room_id)){
                curr_company=company_finder;
                break;
            }
        }
        mtmPrintOrder(output,
                      costumerGetEmailAddress(orderGetCostumer(order_iterator)),
                      costumerGetSkillLevel(curr_costumer),faculty,
                      companyGetEmailAddress(curr_company),
                      companyGetFaculty(curr_company),
                      room_id,orderGetOrderHour(order_iterator),
                      escapeRoomGetDiff(orderGetRoom(order_iterator)),
                      orderGetNumPeople(order_iterator),
                      orderGetPrice(order_iterator));
    }
    mtmPrintDayFooter(output,escape_technion->current_day);
    for(int i=0;i<UNKNOWN;i++) {
        listDestroy(orders_faculties[i]);
    }
    escape_technion->current_day++;
    return MTM_SUCCESS;
}
void escapeTechnionPrintWinningFaculties(EscapeTechnion escape_technion,FILE *output) {
    //an array to store the results:
    int max[3][2];
    for(int i=0;i<3;i++) {
        max[i][0] = escape_technion->faculties_money[i];
        max[i][1] = i;
    }
    int curr_max=0;
    for(int k=0;k<3;k++) {
        for (int i = k; i < UNKNOWN; i++) {
            if (escape_technion->faculties_money[i] > curr_max) {
                max[k][0] = escape_technion->faculties_money[i];
                max[k][1]=i;
                curr_max=escape_technion->faculties_money[i];
            }
        }
    }
    int sum_money=0;
    for(int i=0;i<(int)UNKNOWN;i++){
        sum_money+=escape_technion->faculties_money[i];
    }
    mtmPrintFacultiesHeader(output,UNKNOWN,escape_technion->current_day,sum_money);
    for(int i=0;i<3;i++) {
        mtmPrintFaculty(output,(TechnionFaculty)max[i][1],max[i][0]);
    }
    mtmPrintFacultiesFooter(output);
}
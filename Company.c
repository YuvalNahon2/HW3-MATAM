#include <assert.h>
#include <string.h>
#include "Company.h"
#include "stdlib.h"
#include "Order.h"

struct CompanyS{
    TechnionFaculty faculty;
    char *email;
    Set EscapeRooms;
};
static int companyCompareRooms(SetElement escapeRoom1,SetElement escapeRoom2){
    return escapeRoomGetId(escapeRoom1)-escapeRoomGetId(escapeRoom2);
}
static SetElement companyCopyRoom(SetElement escapeRoom){
    EscapeRoom copy=NULL;
    copy=escapeRoomCopy((EscapeRoom)escapeRoom);
    return (SetElement)copy;
}
static void companyDestroyRoom(SetElement escapeRoom){
    escapeRoomDestroy((EscapeRoom)escapeRoom);
}
/**
 * a function that converts an EscapeRoom error to a Company error
 * @param room_error - the RoomErrorCode we change to a CompanyErrorCode.
 * @return the matching CompanyErrorCode.
 */
static CompanyErrorCode roomErrorToCompanyError(RoomErrorCode room_error){
    switch (room_error){
        case ROOM_NULL_PARAMETER:
            return COMPANY_NULL_PARAMETER;
        case ROOM_ORDERS_EXIST:
            return COMPANY_ROOM_ORDERS_EXIST;
        case ROOM_OUT_OF_MEMORY:
            return COMPANY_OUT_OF_MEMORY;
        case ROOM_SUCCESS:
            return COMPANY_SUCCESS;
        case ROOM_CLIENT_IN_ROOM:
            return COMPANY_CLIENT_IN_ROOM;
        case ROOM_NOT_AVAILABLE:
            return COMPANY_ROOM_NOT_AVAILABLE;
        case ROOM_INVALID_ARGUMENT:
            return COMPANY_INVALID_ARGUMENT;
        default:
            return COMPANY_UNKNOWN;
    }
}

Company companyCreate(char* email,TechnionFaculty faculty){
    if(faculty<0 || faculty>=UNKNOWN){
        return NULL;
    }
    Company company;
    company=malloc(sizeof(*company));
    if(company==NULL){
        return NULL;
    }
    company->email=malloc(strlen(email)+1);
    strcpy(company->email,email);
    company->faculty=faculty;
    company->EscapeRooms=setCreate(companyCopyRoom,companyDestroyRoom,companyCompareRooms);
    return company;
}

void companyDestroy(Company company){
    if(company==NULL){
        return;
    }
    if(companyOrdersExist(company)){
        return;
    }
    free(company->email);
    setDestroy(company->EscapeRooms);
    free(company);
}
Company companyCopy(Company company){
    Company new_company=companyCreate(company->email,company->faculty);
    new_company->EscapeRooms=setCopy(company->EscapeRooms);
    return new_company;
}
CompanyErrorCode companyAddRoom(Company company,int id,int price,
                                int open_hour,int close_hour,int num_people,int difficulty){
    if(company==NULL){
        return COMPANY_NULL_PARAMETER;
    }
    if(close_hour>23 || open_hour<0 || price<=0 || price%4!=0 ||
       num_people<1 || difficulty<1 || difficulty > 10 || open_hour>=close_hour)
    {
        return COMPANY_INVALID_ARGUMENT;
    }
    EscapeRoom new_room;
    new_room=escapeRoomCreate(id,price,num_people,open_hour,close_hour,difficulty);
    if(new_room==NULL){
        return COMPANY_OUT_OF_MEMORY;
    }
    if(setAdd(company->EscapeRooms,new_room)==SET_ITEM_ALREADY_EXISTS){
        return COMPANY_ROOM_ALREADY_EXIST;
    }
    return COMPANY_SUCCESS;
}
CompanyErrorCode companyCreateOrder(Company company,Costumer costumer,int room_id,int day,
                                int hour,int num_people,int today)
{
    if(company==NULL || costumer==NULL)
        return COMPANY_NULL_PARAMETER;
    EscapeRoom requested_room=NULL;
    SET_FOREACH(EscapeRoom,room_iterator,company->EscapeRooms){
        if(escapeRoomGetId(room_iterator)==room_id) {
            requested_room=room_iterator;
            break;
        }
    }
    if(requested_room==NULL)
        return COMPANY_ROOM_DOESNT_EXIST;
    return roomErrorToCompanyError(escapeRoomOrder(requested_room,costumer,day,
                                                   hour,num_people,
                                                   costumerGetFaculty(costumer)
                                                   ==company->faculty));
}

EscapeRoom companyGetRecommendedRoom(Company company,Costumer costumer,
                                     int num_people) {
    if(costumer==NULL || company==NULL){
        return NULL;
    }
    int level=costumerGetSkillLevel(costumer);
    int min_score=-1;
    EscapeRoom min_room=NULL;
    SET_FOREACH(EscapeRoom , room_iterator , company->EscapeRooms){
        int curr_score=escapeRoomRecommendScore(room_iterator,level,num_people);
        if(curr_score<min_score || min_score==-1 ||
                (curr_score==min_score &&
                 escapeRoomGetId(room_iterator)<escapeRoomGetId(min_room))) {
            min_room = room_iterator;
            min_score=curr_score;
        }
    }
    return min_room;
}

static int orderCompare(ListElement order1,ListElement order2){
    return escapeRoomGetId(orderGetRoom((Order)order1))-
            escapeRoomGetId(orderGetRoom((Order)order2));
}
List companyEndDay(Company company,int day,int *money_earned) {
    assert(company!=NULL);
    List company_today_orders=listCreate(escapeRoomOrderCopy,escapeRoomOrderDestroy);
    int money_earned_company=0;
    List today_orders=NULL;
    SET_FOREACH(EscapeRoom,room_iterator,company->EscapeRooms){
        int money_earned_room=0;
        today_orders=escapeRoomEndDay(room_iterator,&money_earned_room,day);
        money_earned_company += money_earned_room;
        LIST_FOREACH(Order,order_iterator,today_orders) {
            listInsertLast(company_today_orders,order_iterator);
        }
    }
    *money_earned=money_earned_company;
    listSort(company_today_orders,orderCompare);
    return company_today_orders;
}
TechnionFaculty companyGetFaculty(Company company)
{
    assert(company!=NULL);
    return company->faculty;
}

char* companyGetEmailAddress(Company company){
    return company->email;
}
CompanyErrorCode companyDeleteRoom(Company company,int id){
    if(company==NULL) {
        return COMPANY_NULL_PARAMETER;
    }
    SET_FOREACH(EscapeRoom,room_iterator,company->EscapeRooms){
        if(escapeRoomGetId(room_iterator)==id){
            if(escapeRoomOrdersExist(room_iterator)){
                return COMPANY_ROOM_ORDERS_EXIST;
            }
            setRemove(company->EscapeRooms,room_iterator);
            return COMPANY_SUCCESS;
        }
    }
    return COMPANY_ROOM_DOESNT_EXIST;
}

bool companyOrdersExist(Company company) {
    if(setGetSize(company->EscapeRooms)==0){
        return false;
    }
    SET_FOREACH(EscapeRoom,room_iterator,company->EscapeRooms){
        if(escapeRoomOrdersExist(room_iterator)==true){
            return true;
        }
    }
    return false;
}
bool companyCheckRoomExist(Company company){
    if(setGetSize(company->EscapeRooms)>0){
        return true;
    }
    return false;
}
void companyDeleteCostumerOrders(Company company,Costumer costumer) {
    SET_FOREACH(EscapeRoom,room_iterator,company->EscapeRooms){
        escapeRoomRemoveCostumerOrders(room_iterator,costumer);
    }
}
bool companyHasRoom(Company company,int id){
    SET_FOREACH(EscapeRoom,room_iterator,company->EscapeRooms){
        if(escapeRoomGetId(room_iterator)==id){
            return true;
        }
    }
    return false;
}
bool companySearchRoom(Company company,EscapeRoom escape_room){
    if(setAdd(company->EscapeRooms,escape_room)==SET_ITEM_ALREADY_EXISTS){
        return true;
    }
    setRemove(company->EscapeRooms,escape_room);
    return false;
}
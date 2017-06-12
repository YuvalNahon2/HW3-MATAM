#include <assert.h>
#include "Company.h"
#include "stdlib.h"
struct CompanyS{
    TechnionFaculty faculty;
    Email email;
    Set EscapeRooms;
    int earned_money;
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

Company companyCreate(Email email,TechnionFaculty faculty){
    if(faculty<0 || faculty>=UNKNOWN){
        return NULL;
    }
    Company company;
    company=malloc(sizeof(*company));
    if(company==NULL){
        return NULL;
    }
    company->email=email;
    company->faculty=faculty;
    company->EscapeRooms=setCreate(companyCopyRoom,companyDestroyRoom,companyCompareRooms);
    return company;
}

void companyDestroy(Company company){
    if(companyOrdersExist(company)){
        return;
    }
    setDestroy(company->EscapeRooms);
    free(company);
}
CompanyErrorCode companyAddRoom(Company company,int id,int price,
                                int open_hour,int close_hour,int num_people,int difficulty){
    if(company==NULL){
        return COMPANY_NULL_PARAMETER;
    }
    if(close_hour>23 || open_hour<0 || price<0 ||
       num_people<1 || difficulty<1 || difficulty > 10){
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
List *companyEndDay(Company company,int day,int *size) {
    assert(company!=NULL);
    List *company_today_orders;
    *size=setGetSize(company->EscapeRooms);
    company_today_orders=malloc(*size *sizeof(List));
    int money_earned_company=0;
    int counter=0;
    List today_orders=NULL;
    SET_FOREACH(EscapeRoom,room_iterator,company->EscapeRooms){
        int money_earned_room=0;
        today_orders=escapeRoomEndDay(room_iterator,&money_earned_room,day);
        money_earned_company+=money_earned_room;
        listInsertLast(company_today_orders[counter],today_orders);
    }
    return company_today_orders;
}

int companyGetMoney(Company company)
{
    assert(company!=NULL);
    return company->earned_money;
}
TechnionFaculty companyGetFaculty(Company company)
{
    assert(company!=NULL);
    return company->faculty;
}

char* companyGetEmailAddress(Company company){
    return company->email.address;
}
CompanyErrorCode companyDeleteRoom(Company company,int id){
    if(company==NULL)
        return COMPANY_NULL_PARAMETER;
    if(id<0){
        return COMPANY_INVALID_ARGUMENT;
    }
    SET_FOREACH(EscapeRoom,room_iterator,company->EscapeRooms){
        if(escapeRoomGetId(room_iterator)==id){
            if(escapeRoomOrdersExist(room_iterator)){
                return COMPANY_ROOM_ORDERS_EXIST;
            }
            companyDestroyRoom(room_iterator);
            return COMPANY_SUCCESS;
        }
    }
    return COMPANY_INVALID_ARGUMENT;
}

bool companyOrdersExist(Company company) {
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

/*
 * the escapeRoom set functions:these are used to
 */


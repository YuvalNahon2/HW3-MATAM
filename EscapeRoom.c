#include <stdlib.h>
#define POW2(x) ((x)*(x))
#include "EscapeRoom.h"
struct EscapeRoomS{
    int id;
    List Orders;
    Company *company;
    int price;
    int num_people;
    int open_hour;
    int close_hour;
    int dificulty;
};

static MtmErrorCode checkRoom(EscapeRoom escapeRoom,Costumer costumer,
                              int day,int hour);


MtmErrorCode escapeRoomCreate (EscapeRoom escapeRoom, Company *company, int id,
                               int price, int num_people, int open_hour,
                               int close_hour, int diff){
    escapeRoom=malloc(sizeof(*escapeRoom));
    if(escapeRoom==NULL)
        return MTM_OUT_OF_MEMORY;
    escapeRoom->company=company;
    escapeRoom->id=id;
    escapeRoom->dificulty=diff;
    escapeRoom->num_people=num_people;
    escapeRoom->price=price;
    escapeRoom->open_hour=open_hour;
    escapeRoom->close_hour=close_hour;
    List ordersList;
    ordersList=listCreate(escapeRoomOrderCopy,orderDestroy);
    if(ordersList==NULL)
        return MTM_OUT_OF_MEMORY;
    escapeRoom->Orders=ordersList;
    return MTM_SUCCESS;

}
ListElement escapeRoomOrderCopy(ListElement order){
    return (ListElement)orderCopy((Order)order);
}
MtmErrorCode escapeRoomDestroy(EscapeRoom escapeRoom){
    if(listGetSize(escapeRoom->Orders)>0)
        return MTM_RESERVATION_EXISTS;
    listDestroy(escapeRoom->Orders);
    free(escapeRoom);
    return MTM_SUCCESS;
}
MtmErrorCode escapeRoomOrder(EscapeRoom escapeRoom,Costumer costumer,
                             int day,int hour,int num_people){
    MtmErrorCode check_room_avaliable;
    check_room_avaliable=checkRoom(escapeRoom,costumer,day,hour);
    if(check_room_avaliable!=MTM_SUCCESS){
        return check_room_avaliable;
    }
    Order newOrder;
    newOrder=orderCreate(day,hour,&escapeRoom,&costumer,num_people);
    if(newOrder==NULL)
        return MTM_OUT_OF_MEMORY;
    listInsertLast(escapeRoom->Orders,newOrder);
    return MTM_SUCCESS;
}
static MtmErrorCode checkRoom(EscapeRoom escapeRoom,Costumer costumer,
                              int day,int hour){
    Order iterator;
    iterator=listGetFirst(escapeRoom->Orders);
    OrderTime iteratorOrderTime;
    Costumer iteratorCostumer;
    while(iterator!=NULL){
        iteratorOrderTime=orderGetOrderTime(iterator);
        iteratorCostumer=orderGetCostumer(iterator);
        if(iteratorOrderTime.order_hour==hour &&
           iteratorOrderTime.order_day==day){
            if(iteratorCostumer==costumer) {
                return MTM_CLIENT_IN_ROOM;
            }
            return MTM_ROOM_NOT_AVAILABLE;
        }
        iterator=listGetNext(escapeRoom->Orders);
    }
    return MTM_SUCCESS;
}
int escapeRoomRecommendScore(EscapeRoom escapeRoom,int costumer_level,int num_people){
    return POW2((escapeRoom->num_people-num_people))+
           POW2((escapeRoom->dificulty-costumer_level));
}
List escapeRoomEndDay(EscapeRoom escapeRoom,List *roomOrders,int money_earned,int day){
    List todays_orders;
    bool today=true;
    todays_orders=listFilter(escapeRoom->Orders,orderCheckOrderday,&today);
    today = false;

    return todays_orders;

}

int getId(EscapeRoom escapeRoom){
    return escapeRoom->id;
}
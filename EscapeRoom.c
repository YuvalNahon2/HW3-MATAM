#include <stdlib.h>
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
MtmErrorCode escapeRoomCreate (EscapeRoom escapeRoom,Company *company, int id,
                               int price, int num_people,int open_hour,
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
    return MTM_SUCCESS;

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
    Order newOrder;
    return orderCreate(&newOrder,day,hour,&escapeRoom,&costumer,num_people);
}
MtmErrorCode escapeRoomRecommendScore(EscapeRoom escapeRoom,Costumer costumer,int num_people){

}
MtmErrorCode escapeRoomEndDay(EscapeRoom escapeRoom,List *roomOrders,int money_earned,int day){

}
#include <stdlib.h>
#include <assert.h>
#include "list.h"
#include "Order.h"
#define POW2(x) ((x)*(x))

#include "Order.h"
struct EscapeRoomS{
    int id;
    List Orders;
    int price;
    int num_people;
    int open_hour;
    int close_hour;
    int dificulty;
};
//these functions are used to pass to the listCreate function to create a list
// of orders
/**
 * creates a copy of an order
 * @param order - the order to copy
 * @return the copy of the order (as a ListElement).
 */
static ListElement escapeRoomOrderCopy(ListElement order){
    return (ListElement)orderCopy((Order)order);
}
/**
 * destroys an order
 * @param order - the order to destroy.
 */
static void escapeRoomOrderDestroy(ListElement order){
    orderDestroy((Order)order);
}
/**
 * creates a new EscapeRoom.
 * @param id - the id of the new room
 * @param price - the full price of the room
 * @param num_people - the number of people recommended.
 * @param open_hour - the open hour. a number between 0-23
 * @param close_hour - the close hour.
 * @param diff
 * @return
 */
EscapeRoom escapeRoomCreate ( int id,
    int price, int num_people, int open_hour,
    int close_hour, int diff){
    if(close_hour>24 || close_hour<1 || open_hour<0 ||open_hour >23 ||
            price<0 || num_people<1 || diff<1 || diff > 10){
        return NULL;
    }
    EscapeRoom escapeRoom;
    escapeRoom=malloc(sizeof(*escapeRoom));
    if(escapeRoom==NULL) {
        return NULL;
    }
    escapeRoom->id=id;
    escapeRoom->dificulty=diff;
    escapeRoom->num_people=num_people;
    escapeRoom->price=price;
    escapeRoom->open_hour=open_hour;
    escapeRoom->close_hour=close_hour;
    List ordersList;
    ordersList=listCreate(escapeRoomOrderCopy,escapeRoomOrderDestroy);
    if(ordersList==NULL) {
        free(escapeRoom);
        return NULL;
    }
    escapeRoom->Orders=ordersList;
    return escapeRoom;
    }

RoomErrorCode escapeRoomDestroy(EscapeRoom escapeRoom){
    if(listGetSize(escapeRoom->Orders)>0)
        return ROOM_ORDERS_EXIST;
    listDestroy(escapeRoom->Orders);
    free(escapeRoom);
    return ROOM_SUCCESS;
}
EscapeRoom escapeRoomCopy(EscapeRoom src){
    EscapeRoom room_copy;
    if (src==NULL) {
        return NULL;
    }
    room_copy=escapeRoomCreate(src->id,src->price,src->num_people,
                     src->open_hour,src->close_hour,src->dificulty);
    if(room_copy==NULL) {
        return NULL;
    }
    listDestroy(room_copy->Orders);
    room_copy->Orders=listCopy(room_copy->Orders);
    return room_copy;
}
//change this return CLIENT_IN_ROOM andROOM_NOT_AVAILABLE
static RoomErrorCode checkRoomAvailable(EscapeRoom escapeRoom,Costumer costumer,
                               int day,int hour){
    assert(escapeRoom!=NULL && costumer!=NULL);
    if(hour>23 || hour<0) {
        return ROOM_INVALID_ARGUMENT;
    }
    if(hour>=escapeRoom->close_hour || hour<escapeRoom->open_hour){
        return ROOM_NOT_AVAILABLE;
    }
    LIST_FOREACH(Order,iterator,escapeRoom->Orders){
        OrderTime order_time=orderGetOrderTime(iterator);
        if(order_time.order_day==day && order_time.order_hour==hour){
            return ROOM_NOT_AVAILABLE;
        }
    }
    return ROOM_SUCCESS;
}
RoomErrorCode escapeRoomOrder(EscapeRoom escapeRoom,Costumer costumer,
                             int day,int hour,int num_people,bool discount){
    if(escapeRoom == NULL || costumer==NULL)
        return ROOM_NULL_PARAMETER;
    RoomErrorCode check_room_avaliable;
    check_room_avaliable=checkRoomAvailable(escapeRoom,costumer,day,hour);
    if(check_room_avaliable!=ROOM_SUCCESS){
        return check_room_avaliable;
    }
    Order newOrder;
    newOrder=orderCreate(day,hour,&escapeRoom,&costumer,num_people,discount);
    if(newOrder==NULL) {
        return ROOM_OUT_OF_MEMORY;
    }
    listInsertLast(escapeRoom->Orders,newOrder);
    return ROOM_SUCCESS;
}

int escapeRoomRecommendScore(EscapeRoom escapeRoom,int costumer_level,int num_people){
    return POW2((escapeRoom->num_people-num_people))+
           POW2((escapeRoom->dificulty-costumer_level));
}
List escapeRoomEndDay(EscapeRoom escapeRoom,int *money_earned,int today){
    List todays_orders;
    todays_orders=listFilter(escapeRoom->Orders,orderCheckOrderToday,&today);
    List temp = escapeRoom->Orders;
    int money_today=0;
    LIST_FOREACH(Order,order_iterator,temp){
        money_today+=orderGetPrice(order_iterator);
    }
    escapeRoom->Orders=listFilter(escapeRoom->Orders,orderCheckOrderToday,&today);
    listDestroy(temp);
    *money_earned=money_today;
    return todays_orders;
}
int escapeRoomGetId(EscapeRoom escapeRoom){
    return escapeRoom->id;
}
int escapeRoomGetPrice(EscapeRoom escapeRoom){
    return escapeRoom->price;
}
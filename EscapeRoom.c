#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "list.h"
#include "Order.h"
#define POW2(x) ((x)*(x))

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
ListElement escapeRoomOrderCopy(ListElement order){
    return (ListElement)orderCopy((Order)order);
}
/**
 * destroys an order
 * @param order - the order to destroy.
 */
void escapeRoomOrderDestroy(ListElement order){
    orderDestroy((Order)order);
}

EscapeRoom escapeRoomCreate ( int id,
    int price, int num_people, int open_hour,
    int close_hour, int diff){
    if(close_hour>24 || close_hour<1 || open_hour<0 ||open_hour >23 ||
            close_hour <=open_hour || price<0 || price%4!=0 ||
            num_people<1 || diff<1 || diff > 10){
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
    if(escapeRoom==NULL){
        return ROOM_NULL_PARAMETER;
    }
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
    room_copy->Orders=listCopy(src->Orders);
    assert(listGetSize(room_copy->Orders)==listGetSize(src->Orders));
    return room_copy;
}
//remove costumer..
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
    newOrder=orderCreate(day,hour,escapeRoom,costumer,num_people,discount);
    if(newOrder==NULL) {
        return ROOM_OUT_OF_MEMORY;
    }
    listInsertLast(escapeRoom->Orders,(ListElement)newOrder);
    orderDestroy(newOrder);
    return ROOM_SUCCESS;
}

int escapeRoomRecommendScore(EscapeRoom escapeRoom,int costumer_level,int num_people){
    if(escapeRoom==NULL || costumer_level<1 || costumer_level>10 || num_people<1){
        return -1;
    }
    return POW2((escapeRoom->num_people-num_people))+
           POW2((escapeRoom->dificulty-costumer_level));
}

List escapeRoomEndDay(EscapeRoom escapeRoom,int *money_earned,int today){
    List todays_orders;
    todays_orders=listFilter(escapeRoom->Orders,orderCheckOrderToday,&today);
    List temp = escapeRoom->Orders;
    int money_today=0;
    LIST_FOREACH(Order,order_iterator,todays_orders){
            money_today += orderGetPrice(order_iterator);
    }
    escapeRoom->Orders=listFilter(escapeRoom->Orders,orderCheckOrderNotToday,&today);
    listDestroy(temp);
    *money_earned=money_today;
    return todays_orders;
}
int escapeRoomGetId(EscapeRoom escapeRoom){
    assert(escapeRoom!=NULL);
    return escapeRoom->id;
}
int escapeRoomGetPrice(EscapeRoom escapeRoom){
    return escapeRoom->price;
}

int escapeRoomGetDiff(EscapeRoom escape_room){
    return escape_room->dificulty;
}
bool escapeRoomOrdersExist(EscapeRoom escape_room){
    if(listGetSize(escape_room->Orders)>0){
        return true;
    }
    return false;
}
/**
 *
 * @param order
 * @param costumer
 * @return
 */
static bool listFilterCostumerOrders(ListElement order,
                                     ListFilterKey costumer){
    if(orderGetCostumer((Order)order)!=costumer){
                return false;
    }
    return true;

}
void escapeRoomRemoveCostumerOrders(EscapeRoom escape_room,Costumer costumer){
    List temp=escape_room->Orders;
    escape_room->Orders=listFilter(escape_room->Orders,
                                   listFilterCostumerOrders, costumer);
    listDestroy(temp);
}

RoomErrorCode escapeRoomOrderClosest(EscapeRoom escape_room,Costumer costumer,
                            int num_people,bool discount,int today){
    int hour=escape_room->open_hour;
    int day=today;
    while(checkRoomAvailable(escape_room,costumer,day,hour)!=ROOM_SUCCESS){
        if(hour==escape_room->close_hour-1){
            hour=escape_room->open_hour;
            day+=1;
        }
        else{
            hour+=1;
        }
    }
    return escapeRoomOrder(escape_room,costumer,day,hour,num_people,discount);

}
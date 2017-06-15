#include <stdlib.h>
#include <assert.h>
#include "Order.h"

struct OrderS{
    OrderTime orderTime;
    Costumer costumer;
    EscapeRoom requested_room;
    int num_of_people;
    int price;
};

Order orderCreate(int order_day, int order_hour, EscapeRoom escapeRoom,
                  Costumer costumer, int num_of_people,bool discount) {
    if(escapeRoom==NULL || costumer==NULL){
        return NULL;
    }
    if(order_day<0 || order_hour<0 || order_hour>23 ){
        return NULL;
    }
    Order order;
    order=malloc(sizeof(*order));
    if(order==NULL)
        return order;
    order->orderTime.order_day=order_day;
    order->orderTime.order_hour=order_hour;
    order->costumer=costumer;
    order->num_of_people=num_of_people;
    order->requested_room=escapeRoom;
    if(discount==true) {
        order->price = (num_of_people*escapeRoomGetPrice(escapeRoom) * 3) / 4;
    }
    else {
        order->price = num_of_people*escapeRoomGetPrice(escapeRoom);
    }
    return order;
}

Order orderCopy(Order order){
    if(order==NULL){
        return NULL;
    }
    Order newOrder;
    newOrder=malloc(sizeof(*newOrder));
    if(newOrder==NULL)
        return NULL;
    newOrder->costumer=order->costumer;
    newOrder->num_of_people=order->num_of_people;
    newOrder->orderTime.order_day=order->orderTime.order_day;
    newOrder->orderTime.order_hour=order->orderTime.order_hour;
    newOrder->requested_room=order->requested_room;
    newOrder->price=order->price;
    return newOrder;
}
void orderDestroy(Order order)
{
    free(order);
}
Costumer orderGetCostumer(Order order){
    if(order==NULL){
        return NULL;
    }
    return order->costumer;
}
OrderTime orderGetOrderTime(Order order){
    assert(order!=NULL);
    return order->orderTime;
}
int orderGetPrice(Order order) {
    if (order == NULL) {
        return -1;
    }
    return order->price;
}
int orderGetNumPeople(Order order){
    return order->num_of_people;
}
EscapeRoom orderGetRoom(Order order){
    return order->requested_room;
}
bool orderCheckOrderToday(ListElement order,void* today){
    assert(order!=NULL);
    return ((Order)order)->orderTime.order_day==*(int*)today;
}
bool orderCheckOrderNotToday(ListElement order,void* today){
    assert(order!=NULL);
    return ((Order)order)->orderTime.order_day!=*(int*)today;
}
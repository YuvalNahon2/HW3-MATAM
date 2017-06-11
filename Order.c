#include <stdlib.h>
#include "Order.h"
#include "EscapeTechnion.h"
struct OrderS{
    OrderTime orderTime;
    Costumer *costumer;
    EscapeRoom *requested_room;
    int num_of_people;
    int price;
};
Order orderCreate(int order_day, int order_hour, EscapeRoom *escapeRoom,
                  Costumer *costumer, int num_of_people,bool discount) {
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
        order->price = (num_of_people*escapeRoomGetPrice(*escapeRoom) * 3) / 4;
    }
    else {
        order->price = escapeRoomGetPrice(*escapeRoom);
    }
    return order;
}

Order orderCopy(Order order){
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
    return *order->costumer;
}
OrderTime orderGetOrderTime(Order order){
    return order->orderTime;
}
int orderGetPrice(Order order){
    return order->price;
}
bool orderCheckOrderToday(ListElement order,void* today){
        return ((Order)order)->orderTime.order_day==*(int*)today;
}
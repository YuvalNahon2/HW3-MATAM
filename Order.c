#include <stdlib.h>
#include "Order.h"
struct OrderS{
    OrderTime orderTime;
    Costumer *costumer;
    EscapeRoom *requested_room;
    int num_of_people;
};
Order orderCreate(int order_day, int order_hour, EscapeRoom *escapeRoom,
                  Costumer *costumer, int num_of_people)
{
    Order order;
    order=malloc(sizeof(*order));
    if(order==NULL)
        return order;
    order->orderTime.order_day=order_day;
    order->orderTime.order_hour=order_hour;
    order->costumer=costumer;
    order->num_of_people=num_of_people;
    order->requested_room=escapeRoom;
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
    return newOrder;
}
void orderDestroy(ListElement order)
{
    free(order);
}
Costumer orderGetCostumer(Order order){
    return *order->costumer;
}
OrderTime orderGetOrderTime(Order order){
    return order->orderTime;
}
bool orderCheckOrderday(ListElement order,void* today){
    bool is_today= *(bool *) today;
    if(is_today)
        return ((Order)order)->orderTime.order_day==0;

    return ((Order)order)->orderTime.order_day!=0;
}
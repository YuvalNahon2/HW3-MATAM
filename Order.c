#include <stdlib.h>
#include "Order.h"
struct OrderS{
    int order_day;
    int order_hour;
    Costumer *costumer;
    EscapeRoom *requested_room;
    int num_of_people;
};
Order orderCreate(int order_day, int order_hour, EscapeRoom *escapeRoom, Costumer *costumer, int num_of_people)
{
    Order order;
    order=malloc(sizeof(*order));
    if(order==NULL)
        return order;
    order->order_day=order_day;
    order->order_hour=order_hour;
    order->costumer=costumer;
    order->num_of_people=num_of_people;
    order->requested_room=escapeRoom;
}

MtmErrorCode orderDestroy(Order order)
{
    free(order);
}
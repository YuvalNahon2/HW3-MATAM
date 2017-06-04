#ifndef HW3_ORDER_H
#define HW3_ORDER_H

#include "Costumer.h"
#include "EscapeRoom.h"
typedef struct OrderS *Order;
#endif //HW3_ORDER_H
typedef struct OrderTimeS{
    int order_day;
    int order_hour;
}OrderTime;

Order orderCreate(int order_day, int order_hour,
                         EscapeRoom *escapeRoom, Costumer *costumer,
                         int num_of_people);
Order orderCopy(Order order);
void orderDestroy(ListElement order);
Costumer orderGetCostumer(Order order);
OrderTime orderGetOrderTime(Order order);
bool orderCheckOrderday(ListElement order,void* day);
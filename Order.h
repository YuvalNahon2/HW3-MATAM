#ifndef HW3_ORDER_H
#define HW3_ORDER_H

#include "Costumer.h"
#include "EscapeRoom.h"
#include "list.h"
typedef struct OrderS *Order;
typedef struct OrderTimeS{
    int order_day;
    int order_hour;
}OrderTime;

Order orderCreate(int order_day, int order_hour, EscapeRoom *escapeRoom,
                  Costumer *costumer, int num_of_people,bool discount);
Order orderCopy(Order order);
void orderDestroy(Order order);

Costumer orderGetCostumer(Order order);
OrderTime orderGetOrderTime(Order order);
int orderGetPrice(Order order);
bool orderCheckOrderToday(ListElement order,void* day);
#endif //HW3_ORDER_H
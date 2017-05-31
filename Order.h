//
// Created by Yuval on 5/30/2017.
//

#ifndef HW3_ORDER_H
#define HW3_ORDER_H

#include "Costumer.h"
#include "EscapeRoom.h"
typedef struct OrderTimeS{
    int day;
    int hour;
}OrderTime;
typedef struct OrderS *Order;
#endif //HW3_ORDER_H

MtmErrorCode orderCreate(int order_day, int order_hour, EscapeRoom escapeRoom, Costumer costumer, int num_of_people);

MtmErrorCode orderDestroy(int day, );

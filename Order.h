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
typedef struct OrderS{
    OrderTime orderTime;
    Costumer *costumer;
    EscapeRoom *requested_room;
    int num_of_people;
}Order;
#endif //HW3_ORDER_H

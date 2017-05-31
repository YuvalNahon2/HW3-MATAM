#ifndef HW3_ORDER_H
#define HW3_ORDER_H

#include "Costumer.h"
#include "EscapeRoom.h"
typedef struct OrderS *Order;
#endif //HW3_ORDER_H
Order orderCreate(int order_day, int order_hour,
                         EscapeRoom *escapeRoom, Costumer *costumer,
                         int num_of_people);

MtmErrorCode orderDestroy(Order order);

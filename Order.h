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
/**
 * creates a new order.
 * @param order_day - the order's day.
 * @param order_hour - the order's hour.
 * @param escapeRoom - the escapeRoom the order is for.
 * @param costumer - the costumer that makes the order.
 * @param num_of_people - the number of people the order is for.
 * @param discount - if the costumer deserves a discount.
 * @return
 * the new order if everything went right.
 */
Order orderCreate(int order_day, int order_hour, EscapeRoom *escapeRoom,
                  Costumer *costumer, int num_of_people,bool discount);
/**
 * creates a copy of the order.
 * @param order - the order to create a copy of.
 * @return the order's copy.
 */
Order orderCopy(Order order);

/**
 * destroys an order.
 * @param order - the order to destroy.
 */
void orderDestroy(Order order);
/**
 *
 * @param order - an order.
 * @return the order's costumer.
 */
Costumer orderGetCostumer(Order order);

/**
 *
 * @param order - an order.
 * @return the order's orderTime.
 */
OrderTime orderGetOrderTime(Order order);

/**
 *
 * @param order - an order.
 * @return the order's price.
 */
int orderGetPrice(Order order);

/**
 * check if the order is for today.
 * @param order - the order.
 * @param day - today.
 * @return
 * true - the order is for today.
 * false - the order is not for today.
 *
 */
bool orderCheckOrderToday(ListElement order,void* day);
#endif //HW3_ORDER_H
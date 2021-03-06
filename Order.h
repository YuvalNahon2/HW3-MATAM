#ifndef HW3_ORDER_H
#define HW3_ORDER_H
#include "list.h"
#include "Costumer.h"
#include "EscapeRoom.h"
typedef struct OrderS *Order;

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
 * NULL if the arguments (escapeRoom or costumer) are NULL pointers.
 */
Order orderCreate(int order_day, int order_hour, EscapeRoom escapeRoom,
                  Costumer costumer, int num_of_people,bool discount);
/**
 * creates a copy of the order.
 * @param order - the order to create a copy of.
 * @return the order's copy.
 * if the order given is NULL pointer the function will return NULL.
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
 * if the order given is NULL pointer the function will return NULL.
 */
Costumer orderGetCostumer(Order order);

/**
 *
 * @param order - an order.
 * @return the order's orderTime.
 * if the order given is NULL pointer the fuunction will return NULL.
 */
int orderGetOrderDay(Order order);

int orderGetOrderHour(Order order);

/**
 *
 * @param order - an order.
 * @return the order's price.
 *if the order given is NULL pointer the fuunction will return -1.
 */
int orderGetPrice(Order order);

int orderGetNumPeople(Order order);

EscapeRoom orderGetRoom(Order order);

/**
 * check if the order is for today.
 * @param order - the order.
 * @param today - today.
 * @return
 * true - the order is for today.
 * false - the order is not for today.
 *
 */
bool orderCheckOrderToday(ListElement order,void* today);
/**
 * check if the order is not for today.
 * @param order - the order.
 * @param today - today.
 * @return
 * true - the order is not for today.
 * false - the order is for today.
 *
 */
bool orderCheckOrderNotToday(ListElement order,void* today);
#endif //HW3_ORDER_H
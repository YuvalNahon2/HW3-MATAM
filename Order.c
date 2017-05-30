#include "Order.h"
struct OrderS{
    OrderTime orderTime;
    Costumer *costumer;
    EscapeRoom *requested_room;
    int num_of_people;
};
#include "Order.h"
struct OrderS{
    int day;
    int hour;
    Costumer *costumer;
    EscapeRoom *requested_room;
    int num_of_people;
};
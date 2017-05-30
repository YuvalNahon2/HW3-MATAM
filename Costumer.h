//
// Created by Yuval on 5/30/2017.
//

#ifndef HW3_COSTUMER_H
#define HW3_COSTUMER_H

#include "mtm_ex3.h"
#include "EscapeRoom.h"
#include "Order.h"
#include "Email.h"
typedef struct CostumerS{
    Email email;
    TechnionFaculty faculty;
    int skill_level;
    EscapeRoom current_room;
}Costumer;
#endif //HW3_COSTUMER_H

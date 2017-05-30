//
// Created by Yuval on 5/30/2017.
//

#ifndef HW3_SYSTEM_H
#define HW3_SYSTEM_H

#include "mtm_ex3.h"
#include "set.h"
#include "list.h"
typedef struct SystemS{
    Set Companies;
    Set Costumers;
    Set Emails;
    List Orders;
    int current_day;
}System;







#endif //HW3_SYSTEM_H

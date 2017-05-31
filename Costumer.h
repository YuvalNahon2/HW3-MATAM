//
// Created by Yuval on 5/30/2017.
//

#ifndef HW3_COSTUMER_H
#define HW3_COSTUMER_H

#include "mtm_ex3.h"
#include "EscapeRoom.h"
#include "Order.h"
#include "Email.h"
typedef struct CostumerS* Costumer;
#endif //HW3_COSTUMER_H

MtmErrorCode costumerCreate(Costumer costumer,Email email, int faculty, int skill_level);

MtmErrorCode costumerDestroy(Costumer costumer);

MtmErrorCode costumerOrderCreate(Costumer costumer, int faculty, int id, int time, int num_of_people);


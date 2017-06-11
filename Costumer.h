#ifndef HW3_COSTUMER_H
#define HW3_COSTUMER_H

#include "mtm_ex3.h"
#include "Email.h"
typedef struct CostumerS* Costumer;

Costumer costumerCreate(Email email, TechnionFaculty faculty, int skill_level);

void costumerDestroy(Costumer costumer);

int costumerGetSkillLevel(Costumer costumer);

TechnionFaculty costumerGetFaculty(Costumer costumer);
#endif //HW3_COSTUMER_H
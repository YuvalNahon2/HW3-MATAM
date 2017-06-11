#ifndef HW3_COSTUMER_H
#define HW3_COSTUMER_H

#include "mtm_ex3.h"
#include "Email.h"
typedef struct CostumerS* Costumer;

/**
 * creates a new Costumer.
 * @param email - the costumer's email.
 * @param faculty - the costumer's faculty.
 * @param skill_level - the costumer skill level.
 * @return the new costumer and in case of memory allocation error or
 * invalid skill level/email NULL.
 */
Costumer costumerCreate(Email email, TechnionFaculty faculty, int skill_level);

/**
 * destroys a costumer
 * @param costumer - the costumer to delete
 */
void costumerDestroy(Costumer costumer);

/**
 * returns the costumer's skill level
 * @param costumer - the costumer
 * @return the costumer skill level
 */
int costumerGetSkillLevel(Costumer costumer);

/**
 * @param costumer - the costumer
 * @return the costumer's faculty
 */
TechnionFaculty costumerGetFaculty(Costumer costumer);

/**
 *
 * @param costumer - a costumer.
 * @return the costumer's email address.
 */
char* costumerGetEmailAddress(Costumer costumer);
#endif //HW3_COSTUMER_H
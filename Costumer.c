
#include "Costumer.h"
#include <stdlib.h>
#include <assert.h>

struct CostumerS{
    Email email;
    TechnionFaculty faculty;
    int skill_level;
};
/**
 * creates a new Costumer.
 * @param email - the costumer's email.
 * @param faculty - the costumer's faculty.
 * @param skill_level - the costumer skill level.
 * @return the new costumer and in case of memory allocation error or
 * invalid skill level/email
 */
Costumer costumerCreate(Email email, TechnionFaculty faculty, int skill_level){
    assert(email.user_type==COSTUMER);
    Costumer costumer;
    costumer = malloc(sizeof(*costumer));
    if(costumer==NULL){
        return NULL;
    }
    costumer->email=email;
    costumer->faculty=faculty;
    if(skill_level<1 || skill_level>10)
        return NULL;
    costumer->skill_level=skill_level;
}

void costumerDestroy(Costumer costumer){
    free(costumer);
}





int costumerGetSkillLevel(Costumer costumer){
    return costumer->skill_level;
}
TechnionFaculty costumerGetFaculty(Costumer costumer){
    return costumer->faculty;
}
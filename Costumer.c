
#include "Costumer.h"
#include <stdlib.h>
#include <assert.h>
#include <mem.h>

struct CostumerS{
    Email email;
    TechnionFaculty faculty;
    int skill_level;
};
Costumer costumerCreate(Email email, TechnionFaculty faculty, int skill_level){
    assert(email.user_type==COSTUMER);
    Costumer costumer;
    costumer = malloc(sizeof(*costumer));
    if(costumer==NULL){
        return NULL;
    }
    costumer->email.address=malloc(strlen(email.address)+1);
    strcpy(costumer->email.address,email.address);
    email.user_type=COSTUMER;
    costumer->faculty=faculty;
    if(skill_level<1 || skill_level>10)
        return NULL;
    costumer->skill_level=skill_level;
    return costumer;
}
void costumerDestroy(Costumer costumer){
    free(costumer);
}

Costumer costumerCopy(Costumer costumer){
    Costumer new_costumer=costumerCreate(costumer->email,costumer->faculty,
                                         costumer->skill_level);
    return new_costumer;

}

int costumerGetSkillLevel(Costumer costumer){
    return costumer->skill_level;
}

TechnionFaculty costumerGetFaculty(Costumer costumer){
    return costumer->faculty;
}

char* costumerGetEmailAddress(Costumer costumer){
    return costumer->email.address;
}
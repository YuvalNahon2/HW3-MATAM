
#include "Costumer.h"
#include <stdlib.h>
#include <assert.h>
#include <string.h>

struct CostumerS{
    char *email;
    TechnionFaculty faculty;
    int skill_level;
};
Costumer costumerCreate(char *email, TechnionFaculty faculty, int skill_level){
    Costumer costumer;
    costumer = malloc(sizeof(*costumer));
    if(costumer==NULL){
        return NULL;
    }
    costumer->email=malloc(strlen(email)+1);
    strcpy(costumer->email,email);
    costumer->faculty=faculty;
    if(skill_level<1 || skill_level>10)
        return NULL;
    costumer->skill_level=skill_level;
    return costumer;
}
void costumerDestroy(Costumer costumer){
    if(costumer==NULL){
        return;
    }
    free(costumer->email);
    free(costumer);
}

Costumer costumerCopy(Costumer costumer){
    if(costumer==NULL){
        return NULL;
    }
    Costumer new_costumer=costumerCreate(costumer->email,costumer->faculty,
                                         costumer->skill_level);
    return new_costumer;

}

int costumerGetSkillLevel(Costumer costumer){
    if(costumer==NULL){
        return -1;
    }
    return costumer->skill_level;
}

TechnionFaculty costumerGetFaculty(Costumer costumer){
    if(costumer==NULL){
        return UNKNOWN;
    }
    return costumer->faculty;
}

char* costumerGetEmailAddress(Costumer costumer){
    if(costumer==NULL){
        return NULL;
    }
    return costumer->email;
}
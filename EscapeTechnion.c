//
// Created by Yuval on 5/30/2017.
//

#include "EscapeTechnion.h"
#include "stdlib.h"
#include "Company.h"

struct EscapeTechnionS{
    Set Companies;
    Set Costumers;
    Set Emails;
    List Orders;
    int current_day;
};
MtmErrorCode escapeTechnionCreate(EscapeTechnion escapeTechnion){
    escapeTechnion = malloc(sizeof(*escapeTechnion));
    escapeTechnion->Companies=setCreate(escapeTechnionCopyCompany,,);
}
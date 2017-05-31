//
// Created by Yuval on 5/30/2017.
//

#ifndef HW3_ESCAPETECHNION_H
#define HW3_ESCAPETECHNION_H

#include "mtm_ex3.h"
#include "set.h"
#include "Email.h"
#include "list.h"
typedef struct EscapeRoomS *EscapeTechnion;
MtmErrorCode systemAddCompany(EscapeTechnion system,Email email,TechnionFaculty faculty);

MtmErrorCode systemDestroyCompany(EscapeTechnion system,Email email);

MtmErrorCode systemAddRoom(EscapeTechnion system,Email email,int id,int price,
                           int num_people,int open_hour,
                           int close_hour,int difficulty);
MtmErrorCode systemDeleteRoom(TechnionFaculty faculty,int id);

MtmErrorCode systemAddCostumer(EscapeTechnion system,Email email,
                               TechnionFaculty faculty,int skill_level);

MtmErrorCode systemDeleteCostumer(EscapeTechnion system,Email email);

MtmErrorCode systemDestroyCostumer(EscapeTechnion system,Email email);

MtmErrorCode systemCreateOrder(EscapeTechnion system,Email email,
                               TechnionFaculty room_faculty,int room_id,int day,
                               int hour,int num_people);

MtmErrorCode systemOrderRecommended(EscapeTechnion system,Email costumer_email,
                                    int num_people);
MtmErrorCode systemEndDay(EscapeTechnion system);

MtmErrorCode systemPrintWinningFaculties(EscapeTechnion system);


#endif //HW3_ESCAPETECHNION_H

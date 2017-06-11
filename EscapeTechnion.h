#ifndef HW3_ESCAPETECHNION_H
#define HW3_ESCAPETECHNION_H

#include "mtm_ex3.h"
#include "set.h"
#include "Email.h"
#include "list.h"
typedef struct EscapeTechnionS *EscapeTechnion;

MtmErrorCode escapeTechnionCreate(EscapeTechnion escapeTechnion);

MtmErrorCode escapeTechnionDestroy(EscapeTechnion escapeTechnion);

MtmErrorCode escapeTechnionAddCompany(EscapeTechnion escapeTechnion,Email email,TechnionFaculty faculty);

MtmErrorCode escapeTechnionDestroyCompany(EscapeTechnion escapeTechnion,Email email);


MtmErrorCode escapeTechnionAddRoom(EscapeTechnion escapeTechnion,Email email,int id,int price,
                           int num_people,int open_hour,
                           int close_hour,int difficulty);

MtmErrorCode escapeTechnionDeleteRoom(EscapeTechnion escapeTechnion,TechnionFaculty faculty,int id);


MtmErrorCode escapeTechnionAddCostumer(EscapeTechnion escapeTechnion,Email email,
                               TechnionFaculty faculty,int skill_level);

MtmErrorCode escapeTechnionDestroyCostumer(EscapeTechnion escapeTechnion,Email email);


MtmErrorCode escapeTechnionCreateOrder(EscapeTechnion escapeTechnion,Email costumer_email,
                               TechnionFaculty room_faculty,int room_id,int day,
                               int hour,int num_people);

MtmErrorCode escapeTechnionOrderRecommended(EscapeTechnion escapeTechnion,Email costumer_email,
                                            int num_people);


MtmErrorCode escapeTechnionEndDay(EscapeTechnion escapeTechnion);

MtmErrorCode escapeTechnionPrintWinningFaculties(EscapeTechnion escapeTechnion);

#endif //HW3_ESCAPETECHNION_H

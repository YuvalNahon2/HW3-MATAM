#ifndef HW3_ESCAPETECHNION_H
#define HW3_ESCAPETECHNION_H

#include "mtm_ex3.h"
#include "set.h"
#include "Email.h"
#include "list.h"
typedef struct EscapeTechnionS *EscapeTechnion;
/**
 * creates a new EscapeTechnion.
 * @param escape_technion - parameter used to return the new EscapeTechnion.
 * @return
 * MTM_OUT_OF_MEMORY - if any memory allocation has failed.
 * MTM_SUCCESS - if everything went right and a new new EscapeTechnion was
 * created.
 */
MtmErrorCode escapeTechnionCreate(EscapeTechnion escape_technion);

/**
 * destroys an EscapeTechnion.
 * @param escape_technion - the EscapeTechnion to destroy.
 */
void escapeTechnionDestroy(EscapeTechnion escape_technion);

/**
 * adds a new company to escape_technion.
 * @param escape_technion - an EscapeTechnion to add the company to.
 * @param email - the company's Email.
 * @param faculty - the faculty the company belongs to.
 * @return
 * MTM_INVALID_PARAMETER - an invalid email address or NULL escape_technion was
 * sent.
 * MTM_EMAIL_ALREADY_EXISTS - the email address already exists in the
 * escape_technion's emails set.
 * MTM_OUT_OF_MEMORY - in case a memory allocation failed.
 * MTM_SUCCESS - a new company was added to the system.
 */
MtmErrorCode escapeTechnionAddCompany(EscapeTechnion escape_technion,
                                      char *email,TechnionFaculty faculty);

/**
 * destroys a company based on its email address.
 * @param escape_technion - the EscapeTechnion the company belongs to.
 * @param email - the email address of the company.
 * @return
 * MTM_COMPANY_EMAIL_DOES_NOT_EXIST-there is no company with the given email.
 * MTM_RESERVATION_EXISTS- the selected room has orders in it.
 * MTM_SUCCESS - the company was destroyed.
 */
MtmErrorCode escapeTechnionDestroyCompany(EscapeTechnion escape_technion,
                                          char *email_address);


MtmErrorCode escapeTechnionAddRoom(EscapeTechnion escape_technion,char *email_address,int id,int price,
                           int num_people,int open_hour,
                           int close_hour,int difficulty);

MtmErrorCode escapeTechnionDeleteRoom(EscapeTechnion escape_technion,TechnionFaculty faculty,int id);


MtmErrorCode escapeTechnionAddCostumer(EscapeTechnion escape_technion,Email email,
                               TechnionFaculty faculty,int skill_level);

MtmErrorCode escapeTechnionDestroyCostumer(EscapeTechnion escape_technion,Email email);


MtmErrorCode escapeTechnionCreateOrder(EscapeTechnion escape_technion,Email costumer_email,
                               TechnionFaculty room_faculty,int room_id,int day,
                               int hour,int num_people);

MtmErrorCode escapeTechnionOrderRecommended(EscapeTechnion escape_technion,Email costumer_email,
                                            int num_people);


MtmErrorCode escapeTechnionEndDay(EscapeTechnion escape_technion);

MtmErrorCode escapeTechnionPrintWinningFaculties(EscapeTechnion escape_technion);

#endif //HW3_ESCAPETECHNION_H

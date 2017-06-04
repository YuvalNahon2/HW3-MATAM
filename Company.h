
#ifndef HW3_COMPANY_H
#define HW3_COMPANY_H

#include "mtm_ex3.h"
#include "Email.h"
#include "set.h"
#include "EscapeRoom.h"
#include "Costumer.h"
#include "list.h"

typedef struct CompanyS *Company;
#endif //HW3_COMPANY_H

MtmErrorCode companyCreate (Company company,Email *email, int faculty,int *day);

MtmErrorCode companyDestroy(Company company);

MtmErrorCode companyAddRoom(Company company,int id,int price,
                            int open_hour,int close_hour,int difficulty);
MtmErrorCode companyDestroyRoom(Company company,int id);
/**
 * a function that searches the company's rooms for a suitable room and creates
 * reservation
 * @returns MTM_NO_ROOMS_AVAILABLE-no suitable room found
 *          MTM_SUCCESS-a room was found
 */
MtmErrorCode companyCreateOrder(Company company,Costumer costumer,
                               TechnionFaculty faculty,int room_id,int day,
                               int hour,int num_people);

MtmErrorCode companyGetRecommendedRoom(Company company,Costumer costumer,int num_people);

//deletes todays orders and changes the money earned by the company
MtmErrorCode companyEndDay(Company company,int day,List todayOrders);
//gets the amount of money the company made and the faculty of the company
MtmErrorCode companyGetMoney(Company company,int *money_earned);
MtmErrorCode companyGetFaculty(Company company,TechnionFaculty *faculty);
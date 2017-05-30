//
// Created by Yuval on 5/30/2017.
//

#ifndef HW3_COMPANY_H
#define HW3_COMPANY_H

#include "mtm_ex3.h"
#include "Email.h"
#include "set.h"
#include "EscapeRoom.h"
typedef struct CompanyS{
    TechnionFaculty faculy;
    Email email;
    Set EscapeRooms;
    int earned_money;
}Company;
#endif //HW3_COMPANY_H

MtmErrorCode companyAddRoom(int id,int price,int open_hour,int close_hour,int difficulty);
MtmErrorCode companyDestroyRoom(TechnionFaculty faculty,int id);

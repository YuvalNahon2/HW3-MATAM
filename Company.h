//
// Created by Yuval on 5/30/2017.
//

#ifndef HW3_COMPANY_H
#define HW3_COMPANY_H

#include "mtm_ex3.h"
#include "Email.h"
#include "set.h"
#include "EscapeRoom.h"
typedef struct CompanyS *Company;
#endif //HW3_COMPANY_H

MtmErrorCode companyCreate (Email email, int faculty);

MtmErrorCode companyDestroy(Email email);

MtmErrorCode companyAddRoom(Company company,int id,int price,
                            int open_hour,int close_hour,int difficulty);
MtmErrorCode companyDestroyRoom(Company company,TechnionFaculty faculty,int id);




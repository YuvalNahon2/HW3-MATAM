//
// Created by Yuval on 5/30/2017.
//
#include <stdlib.h>
#include "Company.h"
struct CompanyS{
    TechnionFaculty faculty;
    Email *email;
    Set EscapeRooms;
    int earned_money;
    int *day;
};
MtmErrorCode companyCreate (Company company,Email *email, int faculty,int *day)
{
    company->email=email;
    company->faculty=faculty;
    company->day=day;
}
MtmErrorCode companyDestroy(Company company)
{
    free(company);
}

MtmErrorCode company

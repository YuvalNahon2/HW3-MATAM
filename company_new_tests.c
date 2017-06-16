#include <stdio.h>
#include <stdbool.h>
#include "test_utilities.h"
#include "Order.h"
#include "EscapeRoom.h"
#include "company.h"


static bool testCompanyCreate()
{
    char* mail_company="Intel@mail.com";
    TechnionFaculty company_faculty=ELECTRICAL_ENGINEERING;
    Company company1;
    company1=companyCreate(mail_company,company_faculty);
    ASSERT_TEST(company1!=NULL);
    companyDestroy(company1);
    return true;
}

static bool testCompanyAddRoom()
{
    char* mail_company="Intel@mail.com";
    TechnionFaculty company_faculty=ELECTRICAL_ENGINEERING;
    Company company;
    company=companyCreate(mail_company,company_faculty);

    int id=69;
    int price=60;
    int open_hour=7;
    int close_hour=20;
    int num_people=10;
    int diff=6;

    companyAddRoom(company,id,price,open_hour,close_hour,num_people,diff);
    companyDeleteRoom(company,id);
    companyDestroy(company);

}
static bool testCompanyCopy()
{
    char* mail_company="Intel@mail.com";
    TechnionFaculty company_faculty=ELECTRICAL_ENGINEERING;
    Company company;
    company=companyCreate(mail_mail,company_faculty);

    Company copy=companyCopy(company);
    ASSERT_TEST(copy!=NULL);
    companyDestroy(copy);
    companyDestroy(company);
}

static bool testCompanyDeleteRoom()
{
    char* mail_company="Intel@mail.com";
    TechnionFaculty company_faculty=ELECTRICAL_ENGINEERING;
    Company company;
    company=companyCreate(mail_company,company_faculty);

    int id=69;
    int price=60;
    int open_hour=7;
    int close_hour=20;
    int num_people=10;
    int diff=6;

    companyAddRoom(company,id,price,open_hour,close_hour,num_people,diff);
    ASSERT_TEST(companyHasRoom(company,id)==true);
    companyDestroy(company);
    return true;
}
static bool testCompanyCreateOrder()
{
    char* mail_company="Intel@mail.com";
    TechnionFaculty company_faculty=ELECTRICAL_ENGINEERING;
    Company company=companyCreate(mail_company,company_faculty);

    int id=69;
    int price=60;
    int open_hour=7;
    int close_hour=20;
    int num_people=10;
    int diff=6;
    EscapeRoom room=companyAddRoom(company,id,price,open_hour,close_hour,num_people,diff);

    char* yuval_email="yunahon@gmail.com";
    Costumer yuval=costumerCreate(yuval_email,COMPUTER_SCIENCE,4);

    int room_id1=69;
    int day1=4;
    int hour1=16;
    int num_peopleC1=4;
    int today1=1;

    Order order=companyCreateOrder(company,yuval,room_id1,day1,hour1,num_peopleC1,today1);
    ASSERT_TEST(order!=NULL);
    orderDestroy(order);
    companyDeleteRoom(company,id);
    companyDestroy(company);
    return true;

}
static bool testGetReccomendedRoom()
{
    char* mail_company="Intel@mail.com";
    TechnionFaculty company_faculty=ELECTRICAL_ENGINEERING;
    company=companyCreate(email,company_faculty);

    char* yuval_email="yunahon@gmail.com";
    Costumer yuval=costumerCreate(yuval_email,COMPUTER_SCIENCE,4);

    int id=69;
    int price=60;
    int open_hour=7;
    int close_hour=20;
    int num_people=10;
    int diff=6;
    EscapeRoom room=companyAddRoom(company,id,price,open_hour,close_hour,num_people,diff);

    int id1=70;
    int price1=60;
    int open_hour1=7;
    int close_hour1=20;
    int num_people1=20;
    int diff1=3;
    EscapeRoom room=companyAddRoom(company,id,price,open_hour,close_hour,num_people,diff);

    int num_peopleC1=4;
ASSERT(escapeRoomGetId(companyGetRecommendedRoom(company,yuval,num_peopleC1))==);

}
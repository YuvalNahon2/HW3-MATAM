#include <stdbool.h>
#include "test_utilities.h"
#include "EscapeRoom.h"
#include "Company.h"
#include <string.h>
static bool testCompanyCreate()
{

    char* mail_comp1="JPMorgan@company.com";
    TechnionFaculty faculty1=ELECTRICAL_ENGINEERING;

    char* mail_comp2="JPMorgancompany.com";
    TechnionFaculty faculty2=ELECTRICAL_ENGINEERING;

    char* mail_comp3="JPMorgan@company.com";
    TechnionFaculty faculty3=UNKNOWN;

    Company company1=companyCreate(mail_comp1,faculty1);
    Company company2=companyCreate(mail_comp2,faculty2);
    Company company3=companyCreate(mail_comp3,faculty3);

    ASSERT_TEST(company1!=NULL);
    ASSERT_TEST(company2!=NULL);
    ASSERT_TEST(company3==NULL);


    companyDestroy(company1);
    companyDestroy(company2);
    companyDestroy(company3);

    return true;


}

static bool testCompanyAddRoom()
{

    char* mail_comp1="JPMorgan@company.com";
    TechnionFaculty faculty1=ELECTRICAL_ENGINEERING;
    Company company1=companyCreate(mail_comp1,faculty1);

    char* mail_comp2="intel@company.com";
    TechnionFaculty faculty2=ELECTRICAL_ENGINEERING;
    Company company2=companyCreate(mail_comp2,faculty2);


    int id1=69;
    int price1=60;
    int num_people1=10;
    int open_hour1=5;
    int close_hour1=13;
    int diff1=10;

    int id2=69;
    int price2=40;
    int num_people2=30;
    int open_hour2=5;
    int close_hour2=22;
    int diff2=10;

    int id3=19;
    int price3=40;
    int num_people3=30;
    int open_hour3=5;
    int close_hour3=-22;
    int diff3=10;

    int id4=19;
    int price4=40;
    int num_people4=30;
    int open_hour4=5;
    int close_hour4=22;
    int diff4=10;


    ASSERT_TEST(companyAddRoom(company1,id1,price1,open_hour1,close_hour1,num_people1,diff1)==COMPANY_SUCCESS);
    ASSERT_TEST(companyAddRoom(company2,id1,price1,open_hour2,close_hour2,num_people1,diff1)==COMPANY_SUCCESS);
    ASSERT_TEST(companyAddRoom(company1,id2,price2,open_hour2,close_hour2,num_people2,diff2)==COMPANY_ROOM_ALREADY_EXIST);
    ASSERT_TEST(companyAddRoom(company1,id3,price3,open_hour3,close_hour3,num_people3,diff3)==COMPANY_INVALID_ARGUMENT);
    ASSERT_TEST(companyAddRoom(company1,id4,price4,open_hour4,close_hour4,num_people4,diff4)==COMPANY_SUCCESS);

    companyDeleteRoom(company1,id1);
    companyDeleteRoom(company2,id1);
    companyDeleteRoom(company1,id2);
    companyDeleteRoom(company1,id3);
    companyDeleteRoom(company1,id4);

    companyDestroy(company1);
    companyDestroy(company2);


    return true;

}

static bool testCompanyCreateOrder()
{
    char* mail_comp1="JPMorgan@company.com";
    TechnionFaculty faculty1=ELECTRICAL_ENGINEERING;
    Company company1=companyCreate(mail_comp1,faculty1);

    char* mail_comp2="JPMorgan@company.com";
    TechnionFaculty faculty2=ELECTRICAL_ENGINEERING;
    Company company2=companyCreate(mail_comp2,faculty2);


    char* yuval_email="yunahon@gmail.com";
    Costumer yuval=costumerCreate(yuval_email,COMPUTER_SCIENCE,4);

    char* omri_email="omriporkinggmail.com";
    Costumer omri=costumerCreate(omri_email,MATHEMATICS,2);

    char* eyal_email="eyel@gmail.com";
    Costumer eyal = costumerCreate(eyal_email,MECHANICAL_ENGINEERING,3);


    int id1=69;
    int price1=60;
    int num_people1=10;
    int open_hour1=5;
    int close_hour1=19;
    int diff1=10;


    int id2=70;
    int price2=20;
    int num_people2=10;
    int open_hour2=5;
    int close_hour2=19;
    int diff2=10;

    int id3=71;
    int price3=60;
    int num_people3=10;
    int open_hour3=5;
    int close_hour3=19;
    int diff3=10;

    int room_id1=69;
    int day1=4;
    int hour1=16;
    int num_peopleC1=4;
    int today1=1;

    int room_id2=45;
    int day2=4;
    int hour2=16;
    int num_peopleC2=4;
    int today2=1;

    int room_id3=70;
    int day3=4;
    int hour3=16;
    int num_peopleC3=4;
    int today3=5;



    int room_id6=71;
    int day6=5;
    int hour6=24;
    int num_peopleC6=4;
    int today6=1;


    int room_id7=69;
    int day7=2;
    int hour7=-6;
    int num_peopleC7=4;
    int today7=1;

    int room_id8=71;
    int day8=4;
    int hour8=21;
    int num_peopleC8=4;
    int today8=1;

    int room_id9=69;
    int day9=4;
    int hour9=16;
    int num_peopleC9=4;
    int today9=1;

    companyAddRoom(company1,id1,price1,open_hour1,close_hour1,num_people1,diff1);
    companyAddRoom(company1,id2,price2,open_hour2,close_hour2,num_people2,diff2);
    companyAddRoom(company1,id3,price3,open_hour3,close_hour3,num_people3,diff3);

    ASSERT_TEST(companyCreateOrder(company1,yuval,room_id1,day1,hour1,num_peopleC1,today1)==COMPANY_SUCCESS);
    ASSERT_TEST(companyCreateOrder(company2,yuval,room_id1,day1,hour1,num_peopleC1,today1)==COMPANY_ROOM_DOESNT_EXIST);
    ASSERT_TEST(companyCreateOrder(company1,omri,room_id1,day1,hour1,num_peopleC1,today1)==COMPANY_CLIENT_IN_ROOM);

    ASSERT_TEST(companyCreateOrder(company1,yuval,room_id2,day2,hour2,num_peopleC2,today2)==COMPANY_ROOM_DOESNT_EXIST);
    ASSERT_TEST(companyCreateOrder(company1,yuval,room_id3,day3,hour3,num_peopleC3,today3)==COMPANY_SUCCESS);
    ASSERT_TEST(companyCreateOrder(company1,yuval,room_id6,day6,hour6,num_peopleC6,today6)==COMPANY_INVALID_ARGUMENT);
    ASSERT_TEST(companyCreateOrder(company1,yuval,room_id7,day7,hour7,num_peopleC7,today7)==COMPANY_INVALID_ARGUMENT);
    ASSERT_TEST(companyCreateOrder(company1,eyal,room_id8,day8,hour8,num_peopleC8,today8)==COMPANY_ROOM_NOT_AVAILABLE);
    ASSERT_TEST(companyCreateOrder(company1,yuval,room_id9,day9,hour9,num_peopleC9,today9)==COMPANY_CLIENT_IN_ROOM);

    companyDeleteCostumerOrders(company1,yuval);
    companyDeleteCostumerOrders(company1,omri);
    companyDeleteCostumerOrders(company1,eyal);
    companyDeleteCostumerOrders(company2,yuval);
    costumerDestroy(omri);
    costumerDestroy(yuval);
    costumerDestroy(eyal);
    companyDeleteRoom(company1,id1);
    companyDeleteRoom(company1,id2);
    companyDeleteRoom(company1,id3);
    companyDestroy(company1);
    companyDestroy(company2);

    return true;

}
static bool testCompanyGetRecommendedRoom()
{
    char* mail_comp1="JPMorgan@company.com";
    TechnionFaculty faculty1=ELECTRICAL_ENGINEERING;
    Company company1=companyCreate(mail_comp1,faculty1);

    char* mail_comp2="JPMorgan@company.com";
    TechnionFaculty faculty2=ELECTRICAL_ENGINEERING;
    Company company2=companyCreate(mail_comp2,faculty2);

    char* mail_comp3="JPMorgan@company.com";
    TechnionFaculty faculty3=ELECTRICAL_ENGINEERING;
    Company company3=companyCreate(mail_comp3,faculty3);

    char* yuval_email="yunahon@gmail.com";
    Costumer yuval=costumerCreate(yuval_email,COMPUTER_SCIENCE,4);

    char* omri_email="omriporking@gmail.com";
    Costumer omri=costumerCreate(omri_email,MATHEMATICS,2);

    char* eyal_email="eyel@gmail.com";

    Costumer eyal = costumerCreate(eyal_email,MECHANICAL_ENGINEERING,3);

    int id1=69;
    int price1=60;
    int num_people1=10;
    int open_hour1=5;
    int close_hour1=19;
    int diff1=10;
      companyAddRoom(company1,id1,price1,open_hour1, close_hour1,num_people1, diff1);


    int id2=70;
    int price2=20;
    int num_people2=7;
    int open_hour2=5;
    int close_hour2=19;
    int diff2=10;
    companyAddRoom(company2,id2,price2,num_people2,open_hour2, close_hour2, diff2);


    int id3=71;
    int price3=60;
    int num_people3=3;
    int open_hour3=5;
    int close_hour3=19;
    int diff3=10;
    companyAddRoom(company3,id3,price3,num_people3,open_hour3, close_hour3, diff3);

    int num_of_people=5;

    ASSERT_TEST(companyGetRecommendedRoom(company1,yuval,num_of_people)!=NULL);
    ASSERT_TEST(companyGetRecommendedRoom(company2,yuval,num_of_people)==NULL);
    ASSERT_TEST(companyGetRecommendedRoom(company1,NULL,num_of_people)==NULL);
    ASSERT_TEST(companyGetRecommendedRoom(company3,yuval,num_of_people)!=NULL);



    companyDeleteRoom(company1,id1);
    companyDeleteRoom(company1,id2);
    companyDeleteRoom(company1,id3);
    costumerDestroy(omri);
    costumerDestroy(yuval);
    costumerDestroy(eyal);
    companyDestroy(company1);
    companyDestroy(company2);
    return true;

}
static bool testCompanyEndDay()
{
    char* mail_comp1="JPMorgan@company.com";
    TechnionFaculty faculty1=ELECTRICAL_ENGINEERING;
    Company company1=companyCreate(mail_comp1,faculty1);



    int id1=10;
    int price1=60;
    int num_people1=10;
    int open_hour1=5;
    int close_hour1=13;
    int diff1=10;

    int id2=11;
    int price2=40;
    int num_people2=8;
    int open_hour2=4;
    int close_hour2=22;
    int diff2=5;

    int id3=12;
    int price3=100;
    int num_people3=8;
    int open_hour3=4;
    int close_hour3=22;
    int diff3=5;

    char* yuval_email="yunahon@gmail.com";
    Costumer yuval=costumerCreate(yuval_email,COMPUTER_SCIENCE,4);

    char* omri_email="omriporkinggmail.com";
    Costumer omri=costumerCreate(omri_email,MATHEMATICS,2);

    companyAddRoom(company1,id1,price1,open_hour1,close_hour1,num_people1,diff1);
    companyAddRoom(company1,id2,price2,open_hour2,close_hour2,num_people2,diff2);
    companyAddRoom(company1,id3,price3,open_hour3,close_hour3,num_people3,diff3);


    int room_id1=10;
    int day1=0;
    int hour1=10;
    int num_peopleC1=8;
    int today1=0;

    int room_id2=11;
    int day2=1;
    int hour2=7;
    int num_peopleC2=8;


    int room_id3=10;
    int day3=2;
    int hour3=6;
    int num_peopleC3=8;

    int room_id4=11;
    int day4=2;
    int hour4=12;
    int num_peopleC4=8;


    int room_id5=12;
    int day5=2;
    int hour5=9;
    int num_peopleC5=8;


    int room_id6=10;
    int day6=3;
    int hour6=11;
    int num_peopleC6=8;


    int room_id7=11;
    int day7=3;
    int hour7=10;
    int num_peopleC7=8;


    companyCreateOrder(company1,omri,room_id1,day1,hour1,num_peopleC1,today1);
    companyCreateOrder(company1,omri,room_id2,day2,hour2,num_peopleC2,today1);
    companyCreateOrder(company1,omri,room_id3,day3,hour3,num_peopleC3,today1);
    companyCreateOrder(company1,omri,room_id4,day4,hour4,num_peopleC4,today1);
    companyCreateOrder(company1,omri,room_id5,day5,hour5,num_peopleC5,today1);
    companyCreateOrder(company1,omri,room_id6,day6,hour6,num_peopleC6,today1);
    companyCreateOrder(company1,omri,room_id7,day7,hour7,num_peopleC7,today1);

    companyDeleteCostumerOrders(company1,omri);

    companyDeleteRoom(company1,id1);
    companyDeleteRoom(company1,id2);
    companyDeleteRoom(company1,id3);
    costumerDestroy(omri);
    costumerDestroy(yuval);
    companyDestroy(company1);
    return true;

}

static bool testCompanyGetMoney()
{
    char* mail_comp1="JPMorgan@company.com";
    TechnionFaculty faculty1=ELECTRICAL_ENGINEERING;
    Company company1=companyCreate(mail_comp1,faculty1);



    int id1=69;
    int price1=60;
    int num_people1=10;
    int open_hour1=5;
    int close_hour1=13;
    int diff1=10;


    char* yuval_email="yunahon@gmail.com";
    Costumer yuval=costumerCreate(yuval_email,COMPUTER_SCIENCE,4);
    companyAddRoom(company1,id1,price1,num_people1,open_hour1,close_hour1,diff1);

    int room_id1=69;
    int day1=1;
    int hour1=10;
    int num_peopleC1=8;
    int today1=0;

    int money=0;
    companyCreateOrder(company1,yuval,room_id1,day1,hour1,num_peopleC1,today1);
    companyEndDay(company1,0,&money);

    companyDeleteCostumerOrders(company1,yuval);

    companyDeleteRoom(company1,id1);


    costumerDestroy(yuval);
    companyDestroy(company1);
    return true;
    return true;


}
static bool testCompanyGetFaculty()
{
    char* mail_comp1="JPMorgan@company.com";
    TechnionFaculty faculty1=ELECTRICAL_ENGINEERING;
    Company company1=companyCreate(mail_comp1,faculty1);
    ASSERT_TEST(companyGetFaculty(company1)==ELECTRICAL_ENGINEERING);
    return true;
}
static bool testCompanyGetEmailAddress()
{
    char* mail_comp1="JPMorgan@company.com";
    TechnionFaculty faculty1=ELECTRICAL_ENGINEERING;
    Company company1=companyCreate(mail_comp1,faculty1);
    ASSERT_TEST(!strcmp(companyGetEmailAddress(company1),"JPMorgan@company.com"));
    return true;
}

static bool testCompanyOrderExists()
{
    char* mail_comp1="JPMorgan@company.com";
    TechnionFaculty faculty1=ELECTRICAL_ENGINEERING;
    Company company1=companyCreate(mail_comp1,faculty1);

    char* mail_comp2="Elbit@company.com";
    TechnionFaculty faculty2=ELECTRICAL_ENGINEERING;
    Company company2=companyCreate(mail_comp2,faculty2);

    int id1=69;
    int price1=60;
    int num_people1=10;
    int open_hour1=5;
    int close_hour1=13;
    int diff1=10;
    companyAddRoom(company1,id1,price1,open_hour1,close_hour1,num_people1,diff1);

    char* yuval_email="yunahon@gmail.com";
    Costumer yuval=costumerCreate(yuval_email,COMPUTER_SCIENCE,4);

    int room_id1=69;
    int day1=1;
    int hour1=10;
    int num_peopleC1=8;
    int today1=0;

    companyCreateOrder(company1,yuval,room_id1,day1, hour1, num_peopleC1, today1);

    ASSERT_TEST(companyOrdersExist(company1)==true);
    ASSERT_TEST(companyOrdersExist(company2)==false);
    companyDeleteCostumerOrders(company1,yuval);
    companyDeleteCostumerOrders(company2,yuval);
    companyDeleteRoom(company1,id1);
    costumerDestroy(yuval);
    companyDestroy(company1);
    companyDestroy(company2);
    return true;
}


static bool testCompanyCheckRoomExist()
{
    char* mail_comp1="JPMorgan@company.com";
    TechnionFaculty faculty1=ELECTRICAL_ENGINEERING;
    Company company1=companyCreate(mail_comp1,faculty1);

    char* mail_comp2="Elbit@company.com";
    TechnionFaculty faculty2=ELECTRICAL_ENGINEERING;
    Company company2=companyCreate(mail_comp2,faculty2);

    int id1=69;
    int price1=60;
    int num_people1=10;
    int open_hour1=5;
    int close_hour1=13;
    int diff1=10;

    companyAddRoom(company1,id1,price1,open_hour1, close_hour1,num_people1, diff1);
    ASSERT_TEST(companyCheckRoomExist(company1)==true);
    ASSERT_TEST(companyCheckRoomExist(company2)==false);

    companyDeleteRoom(company1,id1);
    companyDeleteRoom(company2,id1);
    companyDestroy(company1);
    companyDestroy(company2);



    return true;
}
static bool testCompanyDeleteCostumerOrder()
{
    char* mail_comp1="JPMorgan@company.com";
    TechnionFaculty faculty1=ELECTRICAL_ENGINEERING;
    Company company1=companyCreate(mail_comp1,faculty1);

    char* mail_comp2="Elbit@company.com";
    TechnionFaculty faculty2=ELECTRICAL_ENGINEERING;
    Company company2=companyCreate(mail_comp2,faculty2);


    int id1=69;
    int price1=60;
    int num_people1=10;
    int open_hour1=5;
    int close_hour1=13;
    int diff1=10;


    char* yuval_email="yunahon@gmail.com";
    Costumer yuval=costumerCreate(yuval_email,COMPUTER_SCIENCE,4);

    char* omri_email="omriporkinggmail.com";
    Costumer omri=costumerCreate(omri_email,COMPUTER_SCIENCE,4);

    int room_id1=69;
    int day1=1;
    int hour1=10;
    int num_peopleC1=8;
    int today1=0;
    companyAddRoom(company1,id1,price1,open_hour1,close_hour1,num_people1,diff1);

    companyCreateOrder(company1,yuval,room_id1,day1, hour1, num_peopleC1, today1);
    companyCreateOrder(company2,yuval,room_id1,day1, hour1, num_peopleC1, today1);
    companyCreateOrder(company1,omri,room_id1,day1, hour1, num_peopleC1, today1);

    companyDeleteCostumerOrders(company1,yuval);
    companyDeleteCostumerOrders(company2,yuval);
    companyDeleteCostumerOrders(company1,omri);

    companyDeleteCostumerOrders(company1,yuval);
    companyDeleteCostumerOrders(company2,yuval);
    companyDeleteCostumerOrders(company1,omri);

    companyDeleteRoom(company1,id1);
    companyDeleteRoom(company2,id1);
    costumerDestroy(yuval);
    costumerDestroy(omri);
    companyDestroy(company1);
    companyDestroy(company2);


    return true;
}

int main()
{
    RUN_TEST(testCompanyCreate);
    RUN_TEST(testCompanyAddRoom);
    RUN_TEST(testCompanyCreateOrder);
    RUN_TEST(testCompanyDeleteCostumerOrder);
    RUN_TEST(testCompanyEndDay);
    RUN_TEST(testCompanyGetEmailAddress);
    RUN_TEST(testCompanyGetFaculty);
    RUN_TEST(testCompanyGetMoney);
    RUN_TEST(testCompanyGetRecommendedRoom);
    RUN_TEST(testCompanyOrderExists);
    RUN_TEST(testCompanyCheckRoomExist);
}















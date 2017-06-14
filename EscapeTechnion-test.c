#include <stdbool.h>
#include "test_utilities.h"
#include "EscapeRoom.h"
#include "Company.h"
#include "EscapeTechnion.h"
#include "Order.h"

static bool testEscapeTechnionCreate()
{
EscapeTechnion escape_technion=NULL;
    escape_technion=escapeTechnionCreate();
ASSERT_TEST(escape_technion!=NULL);
escapeTechnionDestroy(escape_technion);
return true;
}
static bool testEscapeTechnionDestroy()
{
    EscapeTechnion escapeTechnion=NULL;
    escapeTechnion=escapeTechnionCreate();
    escapeTechnionDestroy(escapeTechnion);
    return true;
}
static bool testEscapeTechnionAddCompany()
{
    EscapeTechnion escapeTechnion=NULL;
    escapeTechnion=escapeTechnionCreate();


    char* mail_comp1="JPMorgan@company.com";
    TechnionFaculty faculty1=ELECTRICAL_ENGINEERING;

    char* mail_comp2="JPMorgansdcompany.com";
    TechnionFaculty faculty2=ELECTRICAL_ENGINEERING;

    char* mail_comp3="Mell@anox@company.com";
    TechnionFaculty faculty3=ELECTRICAL_ENGINEERING;

    char* mail_comp4="JPMorgan@company.com";
    TechnionFaculty faculty4=MECHANICAL_ENGINEERING;


    char* mail_comp6="Mellanox@company.com";
    TechnionFaculty faculty6=UNKNOWN;



    ASSERT_TEST(escapeTechnionAddCompany(escapeTechnion,mail_comp1,faculty1)==MTM_SUCCESS);
    ASSERT_TEST(escapeTechnionAddCompany(escapeTechnion,mail_comp2,faculty2)==MTM_INVALID_PARAMETER);
    ASSERT_TEST(escapeTechnionAddCompany(escapeTechnion,mail_comp3,faculty3)==MTM_INVALID_PARAMETER);
    ASSERT_TEST(escapeTechnionAddCompany(escapeTechnion,mail_comp4,faculty4)==MTM_EMAIL_ALREADY_EXISTS);
    ASSERT_TEST(escapeTechnionAddCompany(escapeTechnion,mail_comp6,faculty6)==MTM_SUCCESS);


    escapeTechnionDestroyCompany(escapeTechnion,mail_comp1);
    escapeTechnionDestroyCompany(escapeTechnion,mail_comp2);
    escapeTechnionDestroyCompany(escapeTechnion,mail_comp3);
    escapeTechnionDestroyCompany(escapeTechnion,mail_comp4);
    escapeTechnionDestroyCompany(escapeTechnion,mail_comp6);

    escapeTechnionDestroy(escapeTechnion);

    return true;

}
static bool testEscapeTechnionDestroyCompany()
{
    EscapeTechnion escapeTechnion=NULL;
    escapeTechnionCreate(escapeTechnion);

    char* mail_comp1="JPMorgan@company.com";
    TechnionFaculty faculty1=ELECTRICAL_ENGINEERING;



    char* mail_comp5="JPMorgan@company.com";
    TechnionFaculty faculty5=ELECTRICAL_ENGINEERING;

    Company company5=companyCreate(mail_comp5,faculty5);

    char* mail_comp6="Mellanox@@company.com";
    TechnionFaculty faculty6=ELECTRICAL_ENGINEERING;

    Company company6=companyCreate(mail_comp6,faculty6);


    char* yuval_email="yunahon@gmail.com";
    Costumer yuval=costumerCreate(yuval_email,COMPUTER_SCIENCE,4);

    int id1=69;
    int price1=60;
    int num_people1=10;
    int open_hour1=5;
    int close_hour1=19;
    int diff1=10;

    int room_id1=69;
    int day1=4;
    int hour1=16;
    int num_peopleC1=4;
    int today1=1;

    escapeTechnionAddCompany(escapeTechnion,mail_comp1,faculty1);
    escapeTechnionAddCompany(escapeTechnion,mail_comp5,faculty5);
    escapeTechnionAddCompany(escapeTechnion,mail_comp6,faculty6);
    companyAddRoom(company5,id1,price1,open_hour1,close_hour1,num_people1,diff1);
    escapeTechnionCreateOrder(escapeTechnion,yuval_email,faculty1,room_id1,day1,hour1,num_peopleC1);

    ASSERT_TEST(escapeTechnionDestroyCompany(escapeTechnion,mail_comp1)==MTM_SUCCESS);
    ASSERT_TEST(escapeTechnionDestroyCompany(escapeTechnion,mail_comp5)==MTM_RESERVATION_EXISTS);
    ASSERT_TEST(escapeTechnionDestroyCompany(escapeTechnion,mail_comp6)==MTM_COMPANY_EMAIL_DOES_NOT_EXIST);

    escapeTechnionDestroyCostumer(escapeTechnion,yuval_email);
    escapeTechnionDeleteRoom(escapeTechnion,faculty1,room_id1);
    escapeTechnionDestroyCompany(escapeTechnion,mail_comp1);
    escapeTechnionDestroyCompany(escapeTechnion,mail_comp5);
    escapeTechnionDestroyCompany(escapeTechnion,mail_comp6);
    escapeTechnionDestroy(escapeTechnion);

    return true;
}
static bool testEscapeTechnionAddRoom()
{
    EscapeTechnion escapeTechnion=NULL;
    escapeTechnionCreate(escapeTechnion);

    char* mail_comp1="JPMorgan@company.com";
    TechnionFaculty faculty1=ELECTRICAL_ENGINEERING;

    escapeTechnionAddCompany(escapeTechnion,mail_comp1,faculty1);

    char* mail_comp2="JPMorgan@company.com";
    TechnionFaculty faculty2=HUMANITIES_AND_ARTS;

    int id1=69;
    int price1=60;
    int num_people1=10;
    int open_hour1=5;
    int close_hour1=19;
    int diff1=10;

    int id2=69;
    int price2=40;
    int num_people2=10;
    int open_hour2=5;
    int close_hour2=19;
    int diff2=10;

    int id3=10;
    int price3=53;
    int num_people3=10;
    int open_hour3=5;
    int close_hour3=19;
    int diff3=10;

    int id4=11;
    int price4=0;
    int num_people4=10;
    int open_hour4=5;
    int close_hour4=19;
    int diff4=10;

    int id5=12;
    int price5=-20;
    int num_people5=10;
    int open_hour5=5;
    int close_hour5=19;
    int diff5=10;

    int id6=13;
    int price6=60;
    int num_people6=0;
    int open_hour6=5;
    int close_hour6=19;
    int diff6=10;

    int id7=14;
    int price7=60;
    int num_people7=-10;
    int open_hour7=5;
    int close_hour7=19;
    int diff7=10;

    int id8=15;
    int price8=60;
    int num_people8=10;
    int open_hour8=5;
    int close_hour8=4;
    int diff8=10;

    int id9=16;
    int price9=60;
    int num_people9=10;
    int open_hour9=0;
    int close_hour9=19;
    int diff9=10;

    int id10=17;
    int price10=60;
    int num_people10=10;
    int open_hour10=-10;
    int close_hour10=19;
    int diff10=10;

    int id11=18;
    int price11=60;
    int num_people11=10;
    int open_hour11=5;
    int close_hour11=-7;
    int diff11=10;

    int id12=19;
    int price12=60;
    int num_people12=10;
    int open_hour12=5;
    int close_hour12=0;
    int diff12=10;

    int id13=20;
    int price13=60;
    int num_people13=10;
    int open_hour13=5;
    int close_hour13=24;
    int diff13=10;

    int id14=21;
    int price14=60;
    int num_people14=10;
    int open_hour14=5;
    int close_hour14=19;
    int diff14=0;

    int id15=22;
    int price15=60;
    int num_people15=10;
    int open_hour15=5;
    int close_hour15=19;
    int diff15=-10;

    int id16=23;
    int price16=60;
    int num_people16=10;
    int open_hour16=5;
    int close_hour16=19;
    int diff16=11;

    ASSERT_TEST(escapeTechnionAddRoom(escapeTechnion,mail_comp1,id1,price1,num_people1,open_hour1,close_hour1,diff1)==MTM_SUCCESS);
    ASSERT_TEST(escapeTechnionAddRoom(escapeTechnion,mail_comp2,id1,price1,num_people1,open_hour1,close_hour1,diff1)==MTM_COMPANY_EMAIL_DOES_NOT_EXIST);
    ASSERT_TEST(escapeTechnionAddRoom(escapeTechnion,mail_comp1,id2,price2,num_people2,open_hour2,close_hour2,diff2)==MTM_ID_ALREADY_EXIST);
    ASSERT_TEST(escapeTechnionAddRoom(escapeTechnion,mail_comp1,id3,price3,num_people3,open_hour3,close_hour3,diff3)==MTM_INVALID_PARAMETER);
    ASSERT_TEST(escapeTechnionAddRoom(escapeTechnion,mail_comp1,id4,price4,num_people4,open_hour4,close_hour4,diff4)==MTM_INVALID_PARAMETER);
    ASSERT_TEST(escapeTechnionAddRoom(escapeTechnion,mail_comp1,id5,price5,num_people5,open_hour5,close_hour5,diff5)==MTM_INVALID_PARAMETER);
    ASSERT_TEST(escapeTechnionAddRoom(escapeTechnion,mail_comp1,id6,price6,num_people6,open_hour6,close_hour6,diff6)==MTM_INVALID_PARAMETER);
    ASSERT_TEST(escapeTechnionAddRoom(escapeTechnion,mail_comp1,id7,price7,num_people7,open_hour7,close_hour7,diff7)==MTM_INVALID_PARAMETER);
    ASSERT_TEST(escapeTechnionAddRoom(escapeTechnion,mail_comp1,id8,price8,num_people8,open_hour8,close_hour8,diff8)==MTM_INVALID_PARAMETER);
    ASSERT_TEST(escapeTechnionAddRoom(escapeTechnion,mail_comp1,id9,price9,num_people9,open_hour9,close_hour9,diff9)==MTM_INVALID_PARAMETER);
    ASSERT_TEST(escapeTechnionAddRoom(escapeTechnion,mail_comp1,id10,price10,num_people10,open_hour10,close_hour10,diff10)==MTM_INVALID_PARAMETER);
    ASSERT_TEST(escapeTechnionAddRoom(escapeTechnion,mail_comp1,id11,price11,num_people11,open_hour11,close_hour11,diff11)==MTM_INVALID_PARAMETER);
    ASSERT_TEST(escapeTechnionAddRoom(escapeTechnion,mail_comp1,id12,price12,num_people12,open_hour12,close_hour12,diff12)==MTM_INVALID_PARAMETER);
    ASSERT_TEST(escapeTechnionAddRoom(escapeTechnion,mail_comp1,id13,price13,num_people13,open_hour13,close_hour13,diff13)==MTM_INVALID_PARAMETER);
    ASSERT_TEST(escapeTechnionAddRoom(escapeTechnion,mail_comp1,id14,price14,num_people14,open_hour14,close_hour14,diff14)==MTM_INVALID_PARAMETER);
    ASSERT_TEST(escapeTechnionAddRoom(escapeTechnion,mail_comp1,id15,price15,num_people15,open_hour15,close_hour15,diff15)==MTM_INVALID_PARAMETER);
    ASSERT_TEST(escapeTechnionAddRoom(escapeTechnion,mail_comp1,id16,price16,num_people16,open_hour16,close_hour16,diff16)==MTM_INVALID_PARAMETER);

    escapeTechnionDeleteRoom(escapeTechnion,faculty1,id1);
    escapeTechnionDeleteRoom(escapeTechnion,faculty2,id1);
    escapeTechnionDeleteRoom(escapeTechnion,faculty1,id2);
    escapeTechnionDeleteRoom(escapeTechnion,faculty1,id3);
    escapeTechnionDeleteRoom(escapeTechnion,faculty1,id4);
    escapeTechnionDeleteRoom(escapeTechnion,faculty1,id5);
    escapeTechnionDeleteRoom(escapeTechnion,faculty1,id6);
    escapeTechnionDeleteRoom(escapeTechnion,faculty1,id7);
    escapeTechnionDeleteRoom(escapeTechnion,faculty1,id8);
    escapeTechnionDeleteRoom(escapeTechnion,faculty1,id9);
    escapeTechnionDeleteRoom(escapeTechnion,faculty1,id10);
    escapeTechnionDeleteRoom(escapeTechnion,faculty1,id11);
    escapeTechnionDeleteRoom(escapeTechnion,faculty1,id12);
    escapeTechnionDeleteRoom(escapeTechnion,faculty1,id13);
    escapeTechnionDeleteRoom(escapeTechnion,faculty1,id14);
    escapeTechnionDeleteRoom(escapeTechnion,faculty1,id15);
    escapeTechnionDeleteRoom(escapeTechnion,faculty1,id16);

    escapeTechnionDestroyCompany(escapeTechnion,mail_comp1);
    escapeTechnionDestroyCompany(escapeTechnion,mail_comp2);

    escapeTechnionDestroy(escapeTechnion);

    return true;


}
static bool testEscapeTechnionDeleteRoom()
{
    EscapeTechnion escapeTechnion=NULL;
    escapeTechnionCreate(escapeTechnion);


    char *mail_comp1="JPMorgan@company.com";
    TechnionFaculty faculty1=ELECTRICAL_ENGINEERING;

    char *mail_comp2="Mellanoxcompany.com";
    TechnionFaculty faculty2=ELECTRICAL_ENGINEERING;

    char *yuval_mail="yunahon@gmail.com";
    TechnionFaculty facultyC1=ELECTRICAL_ENGINEERING;

    int id1=69;
    int price1=60;
    int num_people1=10;
    int open_hour1=5;
    int close_hour1=19;
    int diff1=10;

    int id2=69;
    int price2=40;
    int num_people2=10;
    int open_hour2=5;
    int close_hour2=19;
    int diff2=10;

    int id3=70;
    int price3=40;
    int num_people3=10;
    int open_hour3=5;
    int close_hour3=19;
    int diff3=10;

    escapeTechnionAddCompany(escapeTechnion,mail_comp1,faculty1);
    escapeTechnionAddCompany(escapeTechnion,mail_comp2,faculty2);

    int order_day3=4;
    int order_hour3=10;
    int num_of_people3=6;
    bool discount3=false;
    int day=0;

    escapeTechnionAddRoom(escapeTechnion,mail_comp1,id1,price1,num_people1,open_hour1,close_hour1,diff1);
    escapeTechnionAddRoom(escapeTechnion,mail_comp1,id2,price2,num_people2,open_hour2,close_hour2,diff2);
    escapeTechnionAddRoom(escapeTechnion,mail_comp1,id3,price3,num_people3,open_hour3,close_hour3,diff3);
    escapeTechnionCreateOrder(escapeTechnion,yuval_mail,faculty1,id1,order_day3,order_hour3,num_of_people3);



    ASSERT_TEST(escapeTechnionDeleteRoom(escapeTechnion,faculty1,id1)==MTM_RESERVATION_EXISTS);
    ASSERT_TEST(escapeTechnionDeleteRoom(escapeTechnion,faculty2,id2)==MTM_NO_ROOMS_AVAILABLE);

    escapeTechnionDeleteRoom(escapeTechnion,faculty1,id1);
    escapeTechnionDeleteRoom(escapeTechnion,faculty2,id2);

    escapeTechnionDestroyCostumer(escapeTechnion,yuval_mail);
    escapeTechnionDestroyCompany(escapeTechnion,mail_comp1);
    escapeTechnionDestroyCompany(escapeTechnion,mail_comp2);
    escapeTechnionDestroy(escapeTechnion);


    return true;

}
static bool testEscapeTechnionAddCostumer()
{
    EscapeTechnion escapeTechnion=NULL;
    escapeTechnionCreate(escapeTechnion);

    char* mail_comp1="JPMorgan@company.com";
    TechnionFaculty faculty1=ELECTRICAL_ENGINEERING;
    escapeTechnionAddCompany(escapeTechnion,mail_comp1,faculty1);



    char* yuval_email="yunahon@gmail.com";
    TechnionFaculty facultyC1=ELECTRICAL_ENGINEERING;
    int skill_level1=3;


     char *omri_email="omrigmail.com";
    TechnionFaculty facultyC2=ELECTRICAL_ENGINEERING;
    int skill_level2=3;

    char* yoni_email="yoni@@gmail.com";
    TechnionFaculty facultyC3=ELECTRICAL_ENGINEERING;
    int skill_level3=3;


    char *tal_email="tal@gmail.com";
    TechnionFaculty facultyC4=UNKNOWN;
    int skill_level4=3;


    char* kobi_email ="kobi@gmail.com";
    TechnionFaculty facultyC5=40;
    int skill_level5=10;


    char* nir_email="nir@gmail.com";
    TechnionFaculty facultyC6=-3;
    int skill_level6=10;

    char* gal_email="gal@gmail.com";
    TechnionFaculty facultyC7=ELECTRICAL_ENGINEERING;
    int skill_level7=10;

    char *jon_email="jon@gmail.com";
    TechnionFaculty facultyC8=ELECTRICAL_ENGINEERING;
    int skill_level8=0;


    char *snow_email="snow@gmail.com";
    TechnionFaculty facultyC9=ELECTRICAL_ENGINEERING;
    int skill_level9=-4;


    char *king_email="king@gmail.com";
    TechnionFaculty facultyC10=ELECTRICAL_ENGINEERING;
    int skill_level10=11;

    char *north_email="yunahon@gmail.com";
    TechnionFaculty facultyC11=ELECTRICAL_ENGINEERING;
    int skill_level11=11;




    ASSERT_TEST(escapeTechnionAddCostumer(escapeTechnion,yuval_email,facultyC1,skill_level1)==MTM_SUCCESS);
    ASSERT_TEST(escapeTechnionAddCostumer(escapeTechnion,omri_email,facultyC2,skill_level2)==MTM_NULL_PARAMETER);
    ASSERT_TEST(escapeTechnionAddCostumer(escapeTechnion,yoni_email,facultyC3,skill_level3)==MTM_NULL_PARAMETER);
    ASSERT_TEST(escapeTechnionAddCostumer(escapeTechnion,tal_email,facultyC4,skill_level4)==MTM_SUCCESS);
    ASSERT_TEST(escapeTechnionAddCostumer(escapeTechnion,kobi_email,facultyC5,skill_level5)==MTM_INVALID_PARAMETER);
    ASSERT_TEST(escapeTechnionAddCostumer(escapeTechnion,nir_email,facultyC6,skill_level6)==MTM_INVALID_PARAMETER);
    ASSERT_TEST(escapeTechnionAddCostumer(escapeTechnion,gal_email,facultyC7,skill_level7)==MTM_INVALID_PARAMETER);
    ASSERT_TEST(escapeTechnionAddCostumer(escapeTechnion,jon_email,facultyC8,skill_level8)==MTM_INVALID_PARAMETER);
    ASSERT_TEST(escapeTechnionAddCostumer(escapeTechnion,snow_email,facultyC9,skill_level9)==MTM_INVALID_PARAMETER);
    ASSERT_TEST(escapeTechnionAddCostumer(escapeTechnion,king_email,facultyC10,skill_level10)==MTM_INVALID_PARAMETER);
    ASSERT_TEST(escapeTechnionAddCostumer(escapeTechnion,north_email,facultyC11,skill_level11)==MTM_EMAIL_ALREADY_EXISTS);

    escapeTechnionDestroyCostumer(escapeTechnion,north_email);
    escapeTechnionDestroyCostumer(escapeTechnion,king_email);
    escapeTechnionDestroyCostumer(escapeTechnion,snow_email);
    escapeTechnionDestroyCostumer(escapeTechnion,jon_email);
    escapeTechnionDestroyCostumer(escapeTechnion,gal_email);
    escapeTechnionDestroyCostumer(escapeTechnion,nir_email);
    escapeTechnionDestroyCostumer(escapeTechnion,kobi_email);
    escapeTechnionDestroyCostumer(escapeTechnion,tal_email);
    escapeTechnionDestroyCostumer(escapeTechnion,yoni_email);
    escapeTechnionDestroyCostumer(escapeTechnion,omri_email);
    escapeTechnionDestroyCostumer(escapeTechnion,yuval_email);

    escapeTechnionDestroyCompany(escapeTechnion,mail_comp1);

    escapeTechnionDestroy(escapeTechnion);
    return true;
}
static bool testEscapeTechnionDestroyCostumer()
{
    EscapeTechnion escapeTechnion=NULL;
    escapeTechnion=escapeTechnionCreate();

    char* mail_comp1="JPMorgan@company.com";
    TechnionFaculty faculty1=ELECTRICAL_ENGINEERING;
    escapeTechnionAddCompany(escapeTechnion,mail_comp1,faculty1);



    char* yuval_email="yunahon@gmail.com";
    TechnionFaculty facultyC1=ELECTRICAL_ENGINEERING;
    int skill_level1=3;


    char *omri_email="omrigmail.com";
    TechnionFaculty facultyC2=ELECTRICAL_ENGINEERING;
    int skill_level2=3;

    char* yoni_email="yoni@@gmail.com";
    TechnionFaculty facultyC3=ELECTRICAL_ENGINEERING;
    int skill_level3=3;


    char *tal_email="tal@gmail.com";
    TechnionFaculty facultyC4=UNKNOWN;
    int skill_level4=3;


    char* kobi_email ="kobi@gmail.com";
    TechnionFaculty facultyC5=40;
    int skill_level5=10;


    char* nir_email="nir@gmail.com";
    TechnionFaculty facultyC6=-3;
    int skill_level6=10;

    char* gal_email="gal@gmail.com";
    TechnionFaculty facultyC7=ELECTRICAL_ENGINEERING;
    int skill_level7=10;

    char *jon_email="jon@gmail.com";
    TechnionFaculty facultyC8=ELECTRICAL_ENGINEERING;
    int skill_level8=0;


    char *snow_email="snow@gmail.com";
    TechnionFaculty facultyC9=ELECTRICAL_ENGINEERING;
    int skill_level9=-4;


    char *king_email="king@gmail.com";
    TechnionFaculty facultyC10=ELECTRICAL_ENGINEERING;
    int skill_level10=11;

    char *north_email="yunahon@gmail.com";
    TechnionFaculty facultyC11=ELECTRICAL_ENGINEERING;
    int skill_level11=9;

    escapeTechnionAddCostumer(escapeTechnion,yuval_email,facultyC1,skill_level1);
    escapeTechnionAddCostumer(escapeTechnion,omri_email,facultyC2,skill_level2);
    escapeTechnionAddCostumer(escapeTechnion,yoni_email,facultyC3,skill_level3);
    escapeTechnionAddCostumer(escapeTechnion,tal_email,facultyC4,skill_level4);
    escapeTechnionAddCostumer(escapeTechnion,kobi_email,facultyC5,skill_level5);
    escapeTechnionAddCostumer(escapeTechnion,nir_email,facultyC6,skill_level6);
    escapeTechnionAddCostumer(escapeTechnion,gal_email,facultyC7,skill_level7);
    escapeTechnionAddCostumer(escapeTechnion,jon_email,facultyC8,skill_level8);
    escapeTechnionAddCostumer(escapeTechnion,snow_email,facultyC9,skill_level9);
    escapeTechnionAddCostumer(escapeTechnion,king_email,facultyC10,skill_level10);
    escapeTechnionAddCostumer(escapeTechnion,north_email,facultyC11,skill_level11);


    ASSERT_TEST(escapeTechnionDestroyCostumer(escapeTechnion,yuval_email)==MTM_SUCCESS);
    ASSERT_TEST(escapeTechnionDestroyCostumer(escapeTechnion,omri_email)==MTM_INVALID_PARAMETER);
    ASSERT_TEST(escapeTechnionDestroyCostumer(escapeTechnion,yoni_email)==MTM_INVALID_PARAMETER);
    ASSERT_TEST(escapeTechnionDestroyCostumer(escapeTechnion,tal_email)==MTM_INVALID_PARAMETER);
    ASSERT_TEST(escapeTechnionDestroyCostumer(escapeTechnion,kobi_email)==MTM_INVALID_PARAMETER);
    ASSERT_TEST(escapeTechnionDestroyCostumer(escapeTechnion,nir_email)==MTM_INVALID_PARAMETER);
    ASSERT_TEST(escapeTechnionDestroyCostumer(escapeTechnion,gal_email)==MTM_INVALID_PARAMETER);
    ASSERT_TEST(escapeTechnionDestroyCostumer(escapeTechnion,jon_email)==MTM_INVALID_PARAMETER);
    ASSERT_TEST(escapeTechnionDestroyCostumer(escapeTechnion,snow_email)==MTM_INVALID_PARAMETER);
    ASSERT_TEST(escapeTechnionDestroyCostumer(escapeTechnion,king_email)==MTM_INVALID_PARAMETER);
    ASSERT_TEST(escapeTechnionDestroyCostumer(escapeTechnion,north_email)==MTM_INVALID_PARAMETER);


    escapeTechnionDestroyCompany(escapeTechnion,mail_comp1);

    escapeTechnionDestroy(escapeTechnion);
    return true;
}
static bool testEscapeTechnionCreateOrder()
{
    EscapeTechnion escapeTechnion=NULL;
    escapeTechnion=escapeTechnionCreate();

    char* mail_comp1="JPMorgan@company.com";
    TechnionFaculty faculty1=ELECTRICAL_ENGINEERING;
    escapeTechnionAddCompany(escapeTechnion,mail_comp1,faculty1);

    char* mail_comp2="JPMorgancompany.com";
    TechnionFaculty faculty2=ELECTRICAL_ENGINEERING;
    escapeTechnionAddCompany(escapeTechnion,mail_comp2,faculty2);

    char* yuval_email="yunahon@gmail.com";
    TechnionFaculty facultyC1=ELECTRICAL_ENGINEERING;
    int skill_level1=3;


    char *omri_email="omrigmail.com";
    TechnionFaculty facultyC2=ELECTRICAL_ENGINEERING;
    int skill_level2=3;

    char *jon_email="jon@gmail.com";
    TechnionFaculty facultyC3=UNKNOWN;
    int skill_level3=3;



    char *stark_email="stark@gmail.com";
    TechnionFaculty facultyC6=ELECTRICAL_ENGINEERING;
    int skill_level6=0;

    char *tywin_email="tywin@gmail.com";
    TechnionFaculty facultyC7=ELECTRICAL_ENGINEERING;
    int skill_level7=11;

    char *tyrion_email="tyrion@gmail.com";
    TechnionFaculty facultyC8=ELECTRICAL_ENGINEERING;
    int skill_level8=-5;



    int id1=69;
    int price1=60;
    int num_people1=10;
    int open_hour1=5;
    int close_hour1=13;
    int diff1=10;

    int id2=70;
    int price2=-100;
    int num_people2=10;
    int open_hour2=5;
    int close_hour2=13;
    int diff2=10;

    int order_day2=4;
    int order_hour2=10;
    int num_of_people2=8;
    bool discount2=false;

    int order_day3=4;
    int order_hour3=10;
    int num_of_people3=6;
    bool discount3=false;

    int order_day4=-4;
    int order_hour4=10;
    int num_of_people4=8;
    bool discount4=true;


    int order_day5=0;
    int order_hour5=10;
    int num_of_people5=8;
    bool discount5=false;

    int order_day6=3;
    int order_hour6=25;
    int num_of_people6=8;
    bool discount6=false;

    int order_day7=3;
    int order_hour7=18;
    int num_of_people7=8;
    bool discount7=false;

    int order_day8=3;
    int order_hour8=25;
    int num_of_people8=8;
    bool discount8=false;

    int order_day9=3;
    int order_hour9=12;
    int num_of_people9=0;
    bool discount9=false;

    int order_day10=3;
    int order_hour10=12;
    int num_of_people10=-8;
    bool discount10=false;

    int today=0;

    escapeTechnionAddCompany(escapeTechnion,mail_comp1,faculty1);
    escapeTechnionAddCompany(escapeTechnion,mail_comp2,faculty2);
    escapeTechnionAddRoom(escapeTechnion,mail_comp1,id1,price1,num_people1,open_hour1,close_hour1,diff1);
    escapeTechnionAddRoom(escapeTechnion,mail_comp1,id2,price2,num_people2,open_hour2,close_hour2,diff2);
    escapeTechnionAddRoom(escapeTechnion,mail_comp2,id1,price1,num_people1,open_hour1,close_hour1,diff1);
    escapeTechnionAddRoom(escapeTechnion,mail_comp2,id2,price2,num_people2,open_hour2,close_hour2,diff2);
    escapeTechnionAddCostumer(escapeTechnion,yuval_email,facultyC1,skill_level1);
    escapeTechnionAddCostumer(escapeTechnion,omri_email,facultyC2,skill_level2);
    escapeTechnionAddCostumer(escapeTechnion,jon_email,facultyC3,skill_level3);
    escapeTechnionAddCostumer(escapeTechnion,stark_email,facultyC6,skill_level6);
    escapeTechnionAddCostumer(escapeTechnion,tywin_email,facultyC7,skill_level7);
    escapeTechnionAddCostumer(escapeTechnion,tyrion_email,facultyC8,skill_level8);

    ASSERT_TEST(escapeTechnionCreateOrder(escapeTechnion,yuval_email,faculty1,id1,order_day2,order_hour2,num_of_people2)==MTM_SUCCESS);
    ASSERT_TEST(escapeTechnionCreateOrder(escapeTechnion,omri_email,faculty1,id1,order_day2,order_hour2,num_of_people2)==MTM_INVALID_PARAMETER);
    ASSERT_TEST(escapeTechnionCreateOrder(escapeTechnion,jon_email,faculty1,id1,order_day2,order_hour2,num_of_people2)==MTM_INVALID_PARAMETER);
    ASSERT_TEST(escapeTechnionCreateOrder(escapeTechnion,stark_email,faculty1,id1,order_day2,order_hour2,num_of_people2)==MTM_INVALID_PARAMETER);
    ASSERT_TEST(escapeTechnionCreateOrder(escapeTechnion,tywin_email,faculty1,id1,order_day2,order_hour2,num_of_people2)==MTM_INVALID_PARAMETER);
    ASSERT_TEST(escapeTechnionCreateOrder(escapeTechnion,tyrion_email,faculty1,id1,order_day2,order_hour2,num_of_people2)==MTM_INVALID_PARAMETER);
    ASSERT_TEST(escapeTechnionCreateOrder(escapeTechnion,yuval_email,faculty2,id1,order_day2,order_hour2,num_of_people2)==MTM_NULL_PARAMETER);
    ASSERT_TEST(escapeTechnionCreateOrder(escapeTechnion,yuval_email,faculty1,id2,order_day2,order_hour2,num_of_people2)==MTM_NULL_PARAMETER);
    ASSERT_TEST(escapeTechnionCreateOrder(escapeTechnion,yuval_email,faculty1,id1,order_day3,order_hour3,num_of_people3)==MTM_INVALID_PARAMETER);
    ASSERT_TEST(escapeTechnionCreateOrder(escapeTechnion,yuval_email,faculty1,id1,order_day4,order_hour4,num_of_people4)==MTM_INVALID_PARAMETER);
    ASSERT_TEST(escapeTechnionCreateOrder(escapeTechnion,yuval_email,faculty1,id1,order_day5,order_hour5,num_of_people5)==MTM_INVALID_PARAMETER);
    ASSERT_TEST(escapeTechnionCreateOrder(escapeTechnion,yuval_email,faculty1,id1,order_day6,order_hour6,num_of_people6)==MTM_INVALID_PARAMETER);
    ASSERT_TEST(escapeTechnionCreateOrder(escapeTechnion,yuval_email,faculty1,id1,order_day7,order_hour7,num_of_people7)==MTM_INVALID_PARAMETER);
    ASSERT_TEST(escapeTechnionCreateOrder(escapeTechnion,yuval_email,faculty1,id1,order_day8,order_hour8,num_of_people8)==MTM_INVALID_PARAMETER);
    ASSERT_TEST(escapeTechnionCreateOrder(escapeTechnion,yuval_email,faculty1,id1,order_day9,order_hour9,num_of_people9)==MTM_INVALID_PARAMETER);
    ASSERT_TEST(escapeTechnionCreateOrder(escapeTechnion,yuval_email,faculty1,id1,order_day10,order_hour10,num_of_people10)==MTM_INVALID_PARAMETER);
    ASSERT_TEST(escapeTechnionCreateOrder(escapeTechnion,yuval_email,faculty1,id1,order_day2,order_hour2,num_of_people2)==MTM_RESERVATION_EXISTS);

    escapeTechnionDestroyCostumer(escapeTechnion,yuval_email);
    escapeTechnionDestroyCostumer(escapeTechnion,omri_email);
    escapeTechnionDestroyCostumer(escapeTechnion,jon_email);
    escapeTechnionDestroyCostumer(escapeTechnion,stark_email);
    escapeTechnionDestroyCostumer(escapeTechnion,tywin_email);
    escapeTechnionDestroyCostumer(escapeTechnion,tyrion_email);


    escapeTechnionDeleteRoom(escapeTechnion,faculty1,id2);
    escapeTechnionDeleteRoom(escapeTechnion,faculty2,id1);
    escapeTechnionDeleteRoom(escapeTechnion,faculty2,id2);
    escapeTechnionDeleteRoom(escapeTechnion,faculty1,id1);
    escapeTechnionDestroyCompany(escapeTechnion,mail_comp1);
    escapeTechnionDestroyCompany(escapeTechnion,mail_comp2);
    escapeTechnionDestroy(escapeTechnion);

    return true;




}
static bool testEscapeTechnionOrderRecommended()
{
    EscapeTechnion escapeTechnion=NULL;
    escapeTechnionCreate(escapeTechnion);

    char* mail_comp1="JPMorgan@company.com";
    TechnionFaculty faculty1=ELECTRICAL_ENGINEERING;
    escapeTechnionAddCompany(escapeTechnion,mail_comp1,faculty1);

    char* mail_comp2="JPMorgancompany.com";
    TechnionFaculty faculty2=ELECTRICAL_ENGINEERING;
    escapeTechnionAddCompany(escapeTechnion,mail_comp2,faculty2);

    char* yuval_email="yunahon@gmail.com";
    TechnionFaculty facultyC1=ELECTRICAL_ENGINEERING;
    int skill_level1=3;


    char *omri_email="omrigmail.com";
    TechnionFaculty facultyC2=ELECTRICAL_ENGINEERING;
    int skill_level2=3;



    int id1=69;
    int price1=60;
    int num_people1=10;
    int open_hour1=5;
    int close_hour1=13;
    int diff1=10;

    int id2=70;
    int price2=-100;
    int num_people2=10;
    int open_hour2=5;
    int close_hour2=13;
    int diff2=10;


    escapeTechnionAddCompany(escapeTechnion,mail_comp1,faculty1);
    escapeTechnionAddCompany(escapeTechnion,mail_comp2,faculty2);
    escapeTechnionAddRoom(escapeTechnion,mail_comp1,id1,price1,num_people1,open_hour1,close_hour1,diff1);
    escapeTechnionAddRoom(escapeTechnion,mail_comp1,id2,price2,num_people2,open_hour2,close_hour2,diff2);
    escapeTechnionAddRoom(escapeTechnion,mail_comp2,id1,price1,num_people1,open_hour1,close_hour1,diff1);
    escapeTechnionAddRoom(escapeTechnion,mail_comp2,id2,price2,num_people2,open_hour2,close_hour2,diff2);
    escapeTechnionAddCostumer(escapeTechnion,yuval_email,facultyC1,skill_level1);
    escapeTechnionAddCostumer(escapeTechnion,omri_email,facultyC2,skill_level2);

    ASSERT_TEST((escapeTechnionOrderRecommended(escapeTechnion,yuval_email,8))!=MTM_NULL_PARAMETER);
    ASSERT_TEST(escapeTechnionOrderRecommended(escapeTechnion,omri_email,8)==MTM_NULL_PARAMETER);
    ASSERT_TEST(escapeTechnionOrderRecommended(escapeTechnion,yuval_email,-5)==MTM_NULL_PARAMETER);
    ASSERT_TEST(escapeTechnionOrderRecommended(escapeTechnion,yuval_email,0)==MTM_NULL_PARAMETER);

    escapeTechnionDestroyCostumer(escapeTechnion,yuval_email);
    escapeTechnionDestroyCostumer(escapeTechnion,omri_email);


    escapeTechnionDeleteRoom(escapeTechnion,faculty1,id2);
    escapeTechnionDeleteRoom(escapeTechnion,faculty2,id1);
    escapeTechnionDeleteRoom(escapeTechnion,faculty2,id2);
    escapeTechnionDeleteRoom(escapeTechnion,faculty1,id1);
    escapeTechnionDestroyCompany(escapeTechnion,mail_comp1);
    escapeTechnionDestroyCompany(escapeTechnion,mail_comp2);
    escapeTechnionDestroy(escapeTechnion);

    return true;
}
static bool testEscapeTechnionEndDay()
{
    EscapeTechnion escapeTechnion=NULL;
    escapeTechnion=escapeTechnionCreate();

    char* mail_comp1="JPMorgan@company.com";
    TechnionFaculty faculty1=ELECTRICAL_ENGINEERING;
    escapeTechnionAddCompany(escapeTechnion,mail_comp1,faculty1);

    char* mail_comp2="JPMorgancompany.com";
    TechnionFaculty faculty2=ELECTRICAL_ENGINEERING;
    escapeTechnionAddCompany(escapeTechnion,mail_comp2,faculty2);

    char* yuval_email="yunahon@gmail.com";
    TechnionFaculty facultyC1=ELECTRICAL_ENGINEERING;
    int skill_level1=3;


    char *omri_email="omrigmail.com";
    TechnionFaculty facultyC2=ELECTRICAL_ENGINEERING;
    int skill_level2=3;

    char *jon_email="jon@gmail.com";
    TechnionFaculty facultyC3=UNKNOWN;
    int skill_level3=3;



    char *stark_email="stark@gmail.com";
    TechnionFaculty facultyC6=ELECTRICAL_ENGINEERING;
    int skill_level6=0;

    char *tywin_email="tywin@gmail.com";
    TechnionFaculty facultyC7=ELECTRICAL_ENGINEERING;
    int skill_level7=11;

    char *tyrion_email="tyrion@gmail.com";
    TechnionFaculty facultyC8=ELECTRICAL_ENGINEERING;
    int skill_level8=-5;



    int id1=69;
    int price1=60;
    int num_people1=10;
    int open_hour1=5;
    int close_hour1=13;
    int diff1=10;

    int id2=70;
    int price2=-100;
    int num_people2=10;
    int open_hour2=5;
    int close_hour2=13;
    int diff2=10;

    int today=0;
    escapeTechnionAddCompany(escapeTechnion,mail_comp1,faculty1);
    escapeTechnionAddCompany(escapeTechnion,mail_comp2,faculty2);
    escapeTechnionAddRoom(escapeTechnion,mail_comp1,id1,price1,num_people1,open_hour1,close_hour1,diff1);
    escapeTechnionAddRoom(escapeTechnion,mail_comp1,id2,price2,num_people2,open_hour2,close_hour2,diff2);
    escapeTechnionAddRoom(escapeTechnion,mail_comp2,id1,price1,num_people1,open_hour1,close_hour1,diff1);
    escapeTechnionAddRoom(escapeTechnion,mail_comp2,id2,price2,num_people2,open_hour2,close_hour2,diff2);
    escapeTechnionAddCostumer(escapeTechnion,yuval_email,facultyC1,skill_level1);
    escapeTechnionAddCostumer(escapeTechnion,omri_email,facultyC2,skill_level2);
    escapeTechnionAddCostumer(escapeTechnion,jon_email,facultyC3,skill_level3);
    escapeTechnionAddCostumer(escapeTechnion,stark_email,facultyC6,skill_level6);
    escapeTechnionAddCostumer(escapeTechnion,tywin_email,facultyC7,skill_level7);
    escapeTechnionAddCostumer(escapeTechnion,tyrion_email,facultyC8,skill_level8);



    escapeTechnionDestroyCostumer(escapeTechnion,yuval_email);
    escapeTechnionDestroyCostumer(escapeTechnion,omri_email);
    escapeTechnionDestroyCostumer(escapeTechnion,jon_email);
    escapeTechnionDestroyCostumer(escapeTechnion,stark_email);
    escapeTechnionDestroyCostumer(escapeTechnion,tywin_email);
    escapeTechnionDestroyCostumer(escapeTechnion,tyrion_email);


    escapeTechnionDeleteRoom(escapeTechnion,faculty1,id2);
    escapeTechnionDeleteRoom(escapeTechnion,faculty2,id1);
    escapeTechnionDeleteRoom(escapeTechnion,faculty2,id2);
    escapeTechnionDeleteRoom(escapeTechnion,faculty1,id1);
    escapeTechnionDestroyCompany(escapeTechnion,mail_comp1);
    escapeTechnionDestroyCompany(escapeTechnion,mail_comp2);
    escapeTechnionDestroy(escapeTechnion);

    return true;
}
static bool testEscapeTechnionPrintWinningFaculty()
{
    EscapeTechnion escapeTechnion=NULL;
    escapeTechnion=escapeTechnionCreate();

    char* mail_comp1="JPMorgan@company.com";
    TechnionFaculty faculty1=ELECTRICAL_ENGINEERING;
    escapeTechnionAddCompany(escapeTechnion,mail_comp1,faculty1);

    char* mail_comp2="Mellanox@company.com";
    TechnionFaculty faculty2=HUMANITIES_AND_ARTS;
    escapeTechnionAddCompany(escapeTechnion,mail_comp2,faculty2);

    char* mail_comp3="SHABAK@company.com";
    TechnionFaculty faculty3=UNKNOWN;
    escapeTechnionAddCompany(escapeTechnion,mail_comp3,faculty3);

    int id1=69;
    int price1=60;
    int num_people1=10;
    int open_hour1=5;
    int close_hour1=13;
    int diff1=10;

    int id2=70;
    int price2=100;
    int num_people2=10;
    int open_hour2=5;
    int close_hour2=13;
    int diff2=10;

    int id3=71;
    int price3=50;
    int num_people3=10;
    int open_hour3=5;
    int close_hour3=13;
    int diff3=10;

    char* yuval_email="yunahon@gmail.com";
    TechnionFaculty facultyC1=ELECTRICAL_ENGINEERING;
    int skill_level1=3;


    char *omri_email="omri@gmail.com";
    TechnionFaculty facultyC2=ELECTRICAL_ENGINEERING;
    int skill_level2=3;

    int order_day1=1;
    int order_hour1=6;
    int num_of_people1=8;
    bool discount1=false;

    int order_day2=1;
    int order_hour2=8;
    int num_of_people2=8;
    bool discount2=false;

    int order_day3=1;
    int order_hour3=10;
    int num_of_people3=6;
    bool discount3=false;

    int order_day4=2;
    int order_hour4=10;
    int num_of_people4=8;
    bool discount4=true;


    int order_day5=2;
    int order_hour5=10;
    int num_of_people5=8;
    bool discount5=false;

    int order_day6=3;
    int order_hour6=25;
    int num_of_people6=8;
    bool discount6=false;
int day=0;
    escapeTechnionAddCompany(escapeTechnion,mail_comp1,faculty1);
    escapeTechnionAddCompany(escapeTechnion,mail_comp2,faculty2);
    escapeTechnionAddCompany(escapeTechnion,mail_comp3,faculty3);
    escapeTechnionAddRoom(escapeTechnion,mail_comp1,id1,price1,num_people1,open_hour1,close_hour1,diff1);
    escapeTechnionAddRoom(escapeTechnion,mail_comp2,id2,price2,num_people2,open_hour2,close_hour2,diff2);
    escapeTechnionAddRoom(escapeTechnion,mail_comp3,id3,price3,num_people3,open_hour3,close_hour3,diff3);
    escapeTechnionAddCostumer(escapeTechnion,yuval_email,facultyC1,skill_level1);
    escapeTechnionAddCostumer(escapeTechnion,omri_email,facultyC2,skill_level2);

    escapeTechnionCreateOrder(escapeTechnion,yuval_email,faculty1,id1,order_day1,order_hour1,num_of_people1);
    escapeTechnionCreateOrder(escapeTechnion,yuval_email,faculty2,id2,order_day2,order_hour2,num_of_people2);
    escapeTechnionCreateOrder(escapeTechnion,yuval_email,faculty3,id3,order_day3,order_hour3,num_of_people3);

    int **money=NULL;
    escapeTechnionEndDay(escapeTechnion,stdout);
    escapeTechnionPrintWinningFaculties(escapeTechnion,stdout);

    






}

int main()
{
    RUN_TEST(testEscapeTechnionAddCompany);
    RUN_TEST(testEscapeTechnionAddCostumer);
    RUN_TEST(testEscapeTechnionAddRoom);
    RUN_TEST(testEscapeTechnionCreate);
    RUN_TEST(testEscapeTechnionCreateOrder);
    RUN_TEST(testEscapeTechnionDeleteRoom);
    RUN_TEST(testEscapeTechnionDestroy);
    RUN_TEST(testEscapeTechnionDestroyCompany);
    RUN_TEST(testEscapeTechnionDestroyCostumer);
    RUN_TEST(testEscapeTechnionEndDay);
    //RUN_TEST(testEscapeTechnionOrderRecommended);
    RUN_TEST(testEscapeTechnionPrintWinningFaculty);






}










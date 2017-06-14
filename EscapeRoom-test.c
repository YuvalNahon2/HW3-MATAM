
#include "EscapeRoom.h"
#include "test_utilities.h"


static bool testEscapeRoomOrder(){
    int id1=69;
    int price1=60;
    int num_people1=10;
    int open_hour1=5;
    int close_hour1=13;
    int diff1=10;
    EscapeRoom  escape_room1=escapeRoomCreate(id1,price1,num_people1,open_hour1, close_hour1, diff1);

    int id2=32;
    int price2=20;
    int num_people2=50;
    int open_hour2=5;
    int close_hour2=19;
    int diff2=5;
    EscapeRoom  escape_room2=escapeRoomCreate(id2,price2,num_people2,open_hour2, close_hour2, diff2);


    char* yuval_email="yunahon@gmail.com";
    Costumer yuval=costumerCreate(yuval_email,COMPUTER_SCIENCE,4);

    char* omri_email="omri@gmail.com";
    Costumer omri=costumerCreate(omri_email,COMPUTER_SCIENCE,4);

    char* eyal_email="eyal@gmail.com";
    Costumer eyal=costumerCreate(eyal_email,MECHANICAL_ENGINEERING,4);

    ASSERT_TEST(escapeRoomOrder(escape_room1,yuval,4,9,5,false)==ROOM_SUCCESS);
    ASSERT_TEST(escapeRoomOrder(escape_room2,omri,5,19,3,false)==ROOM_NOT_AVAILABLE);
    ASSERT_TEST(escapeRoomOrder(escape_room1,yuval,4,9,5,false)==ROOM_CLIENT_IN_ROOM);
    EscapeRoom escape_room3=escapeRoomCopy(escape_room1);
    ASSERT_TEST(escapeRoomOrder(escape_room3,eyal,4,9,5,true)==ROOM_CLIENT_IN_ROOM);
    escapeRoomRemoveCostumerOrders(escape_room1,yuval);
    escapeRoomRemoveCostumerOrders(escape_room3,yuval);
    escapeRoomDestroy(escape_room1);
    escapeRoomDestroy(escape_room2);
    escapeRoomDestroy(escape_room3);
    costumerDestroy(yuval);
    costumerDestroy(omri);
    costumerDestroy(eyal);
    return true;
}
static bool testEscapeRoomCreate()
{
    int id1=69;
    int price1=60;
    int num_people1=10;
    int open_hour1=5;
    int close_hour1=13;
    int diff1=10;
    EscapeRoom  escape_room1=escapeRoomCreate(id1,price1,num_people1,open_hour1, close_hour1, diff1);


    int id2=70;
    int price2=-20;
    int num_people2=10;
    int open_hour2=5;
    int close_hour2=13;
    int diff2=10;
    EscapeRoom  escape_room2=escapeRoomCreate(id2,price2,num_people2,open_hour2, close_hour2, diff2);

    int id3=70;
    int price3=60;
    int num_people3=10;
    int open_hour3=5;
    int close_hour3=13;
    int diff3=10;
    EscapeRoom  escape_room3=escapeRoomCreate(id3,price3,num_people3,open_hour3, close_hour3, diff3);

    int id4=69;
    int price4=65;
    int num_people4=10;
    int open_hour4=5;
    int close_hour4=13;
    int diff4=10;
    EscapeRoom  escape_room4=escapeRoomCreate(id4,price4,num_people4,open_hour4, close_hour4, diff4);

    int id5=10;
    int price5=60;
    int num_people5=0;
    int open_hour5=5;
    int close_hour5=13;
    int diff5=10;
    EscapeRoom  escape_room5=escapeRoomCreate(id5,price5,num_people5,open_hour5, close_hour5, diff5);

    int id6=11;
    int price6=60;
    int num_people6=-10;
    int open_hour6=5;
    int close_hour6=13;
    int diff6=10;
    EscapeRoom  escape_room6=escapeRoomCreate(id6,price6,num_people6,open_hour6, close_hour6, diff6);

    int id7=11;
    int price7=60;
    int num_people7=-10;
    int open_hour7=5;
    int close_hour7=13;
    int diff7=10;
    EscapeRoom  escape_room7=escapeRoomCreate(id7,price7,num_people7,open_hour7, close_hour7, diff7);

    int id8=12;
    int price8=60;
    int num_people8=10;
    int open_hour8=0;
    int close_hour8=13;
    int diff8=10;
    EscapeRoom  escape_room8=escapeRoomCreate(id8,price8,num_people8,open_hour8, close_hour8, diff8);

    int id9=13;
    int price9=60;
    int num_people9=10;
    int open_hour9=25;
    int close_hour9=13;
    int diff9=10;
    EscapeRoom  escape_room9=escapeRoomCreate(id9,price9,num_people9,open_hour9, close_hour9, diff9);

    int id10=14;
    int price10=60;
    int num_people10=10;
    int open_hour10=-12;
    int close_hour10=13;
    int diff10=10;
    EscapeRoom  escape_room10=escapeRoomCreate(id10,price10,num_people10,open_hour10, close_hour10, diff10);

    int id11=15;
    int price11=60;
    int num_people11=10;
    int open_hour11=5;
    int close_hour11=0;
    int diff11=10;
    EscapeRoom  escape_room11=escapeRoomCreate(id11,price11,num_people11,open_hour11, close_hour11, diff11);

    int id12=16;
    int price12=60;
    int num_people12=10;
    int open_hour12=5;
    int close_hour12=3;
    int diff12=10;
    EscapeRoom  escape_room12=escapeRoomCreate(id12,price12,num_people12,open_hour12, close_hour12, diff12);

    int id13=17;
    int price13=60;
    int num_people13=10;
    int open_hour13=5;
    int close_hour13=24;
    int diff13=10;
    EscapeRoom  escape_room13=escapeRoomCreate(id13,price13,num_people13,open_hour13, close_hour13, diff13);

    int id14=18;
    int price14=60;
    int num_people14=10;
    int open_hour14=5;
    int close_hour14=-13;
    int diff14=10;
    EscapeRoom  escape_room14=escapeRoomCreate(id14,price14,num_people14,open_hour14, close_hour14, diff14);

    int id15=19;
    int price15=60;
    int num_people15=10;
    int open_hour15=5;
    int close_hour15=13;
    int diff15=10;
    EscapeRoom  escape_room15=escapeRoomCreate(id15,price15,num_people15,open_hour15, close_hour15, diff15);


    int id16=20;
    int price16=60;
    int num_people16=10;
    int open_hour16=5;
    int close_hour16=13;
    int diff16=0;
    EscapeRoom  escape_room16=escapeRoomCreate(id16,price16,num_people16,open_hour16, close_hour16, diff16);

    int id17=21;
    int price17=60;
    int num_people17=10;
    int open_hour17=5;
    int close_hour17=13;
    int diff17=11;
    EscapeRoom  escape_room17=escapeRoomCreate(id17,price17,num_people17,open_hour17, close_hour17, diff17);

    int id18=22;
    int price18=60;
    int num_people18=10;
    int open_hour18=5;
    int close_hour18=13;
    int diff18=-12;
    EscapeRoom  escape_room18=escapeRoomCreate(id18,price18,num_people18,open_hour18, close_hour18, diff18);


    ASSERT_TEST(escape_room1!=NULL);
    ASSERT_TEST(escape_room2==NULL);
    ASSERT_TEST(escape_room3!=NULL);
    ASSERT_TEST(escape_room4==NULL);
    ASSERT_TEST(escape_room5==NULL);
    ASSERT_TEST(escape_room6==NULL);
    ASSERT_TEST(escape_room7==NULL);
    ASSERT_TEST(escape_room8!=NULL);
    ASSERT_TEST(escape_room9==NULL);
    ASSERT_TEST(escape_room10==NULL);
    ASSERT_TEST(escape_room11==NULL);
    ASSERT_TEST(escape_room12==NULL);
    ASSERT_TEST(escape_room13!=NULL);
    ASSERT_TEST(escape_room14==NULL);
    ASSERT_TEST(escape_room15!=NULL);
    ASSERT_TEST(escape_room16==NULL);
    ASSERT_TEST(escape_room17==NULL);
    ASSERT_TEST(escape_room18==NULL);

    escapeRoomDestroy(escape_room1);
    escapeRoomDestroy(escape_room2);
    escapeRoomDestroy(escape_room3);
    escapeRoomDestroy(escape_room4);
    escapeRoomDestroy(escape_room5);
    escapeRoomDestroy(escape_room6);
    escapeRoomDestroy(escape_room7);
    escapeRoomDestroy(escape_room8);
    escapeRoomDestroy(escape_room9);
    escapeRoomDestroy(escape_room10);
    escapeRoomDestroy(escape_room11);
    escapeRoomDestroy(escape_room12);
    escapeRoomDestroy(escape_room13);
    escapeRoomDestroy(escape_room14);
    escapeRoomDestroy(escape_room15);
    escapeRoomDestroy(escape_room16);
    escapeRoomDestroy(escape_room17);
    escapeRoomDestroy(escape_room18);

    return true;

}
static bool testEscapeRoomDestroy()
{
    int id1=69;
    int price1=60;
    int num_people1=10;
    int open_hour1=5;
    int close_hour1=13;
    int diff1=10;
    EscapeRoom  escape_room1=escapeRoomCreate(id1,price1,num_people1,open_hour1, close_hour1, diff1);

    char* yuval_email="yunahon@gmail.com";
    Costumer yuval=costumerCreate(yuval_email,COMPUTER_SCIENCE,4);

    int id2=10;
    int price2=20;
    int num_people2=10;
    int open_hour2=5;
    int close_hour2=13;
    int diff2=10;
    EscapeRoom  escape_room2=escapeRoomCreate(id2,price2,num_people2,open_hour2, close_hour2, diff2);

    escapeRoomOrder(escape_room1,yuval,4,9,5,false);

    ASSERT_TEST(escapeRoomDestroy(escape_room1)==ROOM_ORDERS_EXIST);
    ASSERT_TEST(escapeRoomDestroy(escape_room2)==ROOM_SUCCESS);
    escapeRoomRemoveCostumerOrders(escape_room1,yuval);
    escapeRoomDestroy(escape_room1);
    costumerDestroy(yuval);
    return true;



}

static bool testEscapeRoomCopy()
{
    int id1=69;
    int price1=60;
    int num_people1=10;
    int open_hour1=5;
    int close_hour1=13;
    int diff1=10;
    EscapeRoom  escape_room1=escapeRoomCreate(id1,price1,num_people1,open_hour1, close_hour1, diff1);


    int id2=70;
    int price2=-20;
    int num_people2=10;
    int open_hour2=5;
    int close_hour2=13;
    int diff2=10;
    EscapeRoom  escape_room2=escapeRoomCreate(id2,price2,num_people2,open_hour2, close_hour2, diff2);

    EscapeRoom copy1=escapeRoomCopy(escape_room1);
    EscapeRoom copy2=escapeRoomCopy(escape_room2);
    ASSERT_TEST(copy1!=NULL);
    ASSERT_TEST(copy2==NULL);
    escapeRoomDestroy(copy2);
    escapeRoomDestroy(copy1);
    escapeRoomDestroy(escape_room1);
    escapeRoomDestroy(escape_room2);

    return true;
}

static bool testEscapeRoomRecommendScore()
{
    int id1=69;
    int price1=60;
    int num_people1=10;
    int open_hour1=5;
    int close_hour1=13;
    int diff1=10;
    EscapeRoom  escape_room1=escapeRoomCreate(id1,price1,num_people1,open_hour1,
                                              close_hour1, diff1);

    int costumer_level1=4;
    num_people1=7;

    int id2=70;
    int price2=-20;
    int num_people2=10;
    int open_hour2=5;
    int close_hour2=13;
    int diff2=10;

    int costumer_level2=0;
    int costumer_level3=-3;
    int costumer_level4=12;
    int num_people3=0;

    EscapeRoom  escape_room2=escapeRoomCreate(id2,price2,num_people2,open_hour2, close_hour2, diff2);
    ASSERT_TEST(escapeRoomRecommendScore(escape_room1,costumer_level1,num_people1)==45);
    ASSERT_TEST(escapeRoomRecommendScore(escape_room2,costumer_level1,num_people1)==-1);
    ASSERT_TEST(escapeRoomRecommendScore(escape_room1,costumer_level2,num_people1)==-1);
    ASSERT_TEST(escapeRoomRecommendScore(escape_room1,costumer_level3,num_people1)==-1);
    ASSERT_TEST(escapeRoomRecommendScore(escape_room1,costumer_level4,num_people1)==-1);
    ASSERT_TEST(escapeRoomRecommendScore(escape_room1,costumer_level1,num_people2)==36);
    ASSERT_TEST(escapeRoomRecommendScore(escape_room1,costumer_level1,num_people3)==-1);

    escapeRoomDestroy(escape_room1);
    escapeRoomDestroy(escape_room2);

    return true;
}
static bool testEscapeRoomEndDay()
{
    int id1=69;
    int price1=60;
    int num_people1=10;
    int open_hour1=5;
    int close_hour1=13;
    int diff1=10;
    EscapeRoom  escape_room1=escapeRoomCreate(id1,price1,num_people1,open_hour1, close_hour1, diff1);

    int id2=10;
    int price2=40;
    int num_people2=8;
    int open_hour2=4;
    int close_hour2=22;
    int diff2=5;
    EscapeRoom  escape_room2=escapeRoomCreate(id2,price2,num_people2,open_hour2, close_hour2, diff2);

    int id3=10;
    int price3=100;
    int num_people3=8;
    int open_hour3=4;
    int close_hour3=22;
    int diff3=5;
    EscapeRoom  escape_room3=escapeRoomCreate(id3,price3,num_people3,open_hour3, close_hour3, diff3);

    char* yuval_email="yunahon@gmail.com";
    Costumer yuval=costumerCreate(yuval_email,COMPUTER_SCIENCE,4);

    char* omri_email="omri@gmail.com";
    Costumer omri=costumerCreate(omri_email,COMPUTER_SCIENCE,4);

    escapeRoomOrder(escape_room1,yuval,1, 8, 5, true);
    escapeRoomOrder(escape_room2,omri,1, 7, 10, true);
    escapeRoomOrder(escape_room1,omri,1, 7, 6, true);
    escapeRoomOrder(escape_room2,yuval,2, 4, 3, false);
    escapeRoomOrder(escape_room3,omri,3, 9, 1, false);
    int money_earned_room11;
    int money_earned_room12;
    int money_earned_room13;
    int money_earned_room21;
    int money_earned_room22;
    int money_earned_room23;
    int money_earned_room31;
    int money_earned_room32;
    int money_earned_room33;
    List todays_orders_room11;
    List todays_orders_room12;
    List todays_orders_room13;
    List todays_orders_room21;
    List todays_orders_room22;
    List todays_orders_room23;
    List todays_orders_room31;
    List todays_orders_room32;
    List todays_orders_room33;
    todays_orders_room11=escapeRoomEndDay(escape_room1,&money_earned_room11,1);
    todays_orders_room12=escapeRoomEndDay(escape_room2,&money_earned_room12,1);
    todays_orders_room13=escapeRoomEndDay(escape_room3,&money_earned_room13,1);
    todays_orders_room21=escapeRoomEndDay(escape_room1,&money_earned_room21,2);
    todays_orders_room22=escapeRoomEndDay(escape_room2,&money_earned_room22,2);
    todays_orders_room23=escapeRoomEndDay(escape_room3,&money_earned_room23,2);
    todays_orders_room31=escapeRoomEndDay(escape_room1,&money_earned_room31,3);
    todays_orders_room32=escapeRoomEndDay(escape_room2,&money_earned_room32,3);
    todays_orders_room33=escapeRoomEndDay(escape_room3,&money_earned_room33,3);

    ASSERT_TEST(listGetSize(todays_orders_room11)==2);
    ASSERT_TEST(listGetSize(todays_orders_room12)==1);
    ASSERT_TEST(listGetSize(todays_orders_room13)==0);
    ASSERT_TEST(listGetSize(todays_orders_room21)==0);
    ASSERT_TEST(listGetSize(todays_orders_room22)==1);
    ASSERT_TEST(listGetSize(todays_orders_room23)==0);
    ASSERT_TEST(listGetSize(todays_orders_room31)==0);
    ASSERT_TEST(listGetSize(todays_orders_room32)==0);
    ASSERT_TEST(listGetSize(todays_orders_room33)==1);
    ASSERT_TEST(money_earned_room11==495);
    ASSERT_TEST(money_earned_room12==300);
    ASSERT_TEST(money_earned_room13==0);
    ASSERT_TEST(money_earned_room21==0);
    ASSERT_TEST(money_earned_room22==120);
    ASSERT_TEST(money_earned_room23==0);
    ASSERT_TEST(money_earned_room31==0);
    ASSERT_TEST(money_earned_room32==0);
    ASSERT_TEST(money_earned_room33==100);

    escapeRoomRemoveCostumerOrders(escape_room1,omri);
    escapeRoomRemoveCostumerOrders(escape_room2,omri);
    escapeRoomRemoveCostumerOrders(escape_room3,omri);
    escapeRoomRemoveCostumerOrders(escape_room1,yuval);
    escapeRoomRemoveCostumerOrders(escape_room2,yuval);
    escapeRoomRemoveCostumerOrders(escape_room3,yuval);

    listDestroy(todays_orders_room11);
    listDestroy(todays_orders_room12);
    listDestroy(todays_orders_room13);
    listDestroy(todays_orders_room21);
    listDestroy(todays_orders_room22);
    listDestroy(todays_orders_room23);
    listDestroy(todays_orders_room31);
    listDestroy(todays_orders_room32);
    listDestroy(todays_orders_room33);

    costumerDestroy(yuval);
    costumerDestroy(omri);

    escapeRoomDestroy(escape_room1);
    escapeRoomDestroy(escape_room2);
    escapeRoomDestroy(escape_room3);


    return true;

}

static bool testEscapeRoomGetId()
{
    int id1=69;
    int price1=60;
    int num_people1=10;
    int open_hour1=5;
    int close_hour1=13;
    int diff1=10;
    EscapeRoom  escape_room1=escapeRoomCreate(id1,price1,num_people1,open_hour1, close_hour1, diff1);


    int id2=70;
    int price2=-20;
    int num_people2=10;
    int open_hour2=5;
    int close_hour2=13;
    int diff2=10;
    EscapeRoom  escape_room2=escapeRoomCreate(id2,price2,num_people2,open_hour2, close_hour2, diff2);

    ASSERT_TEST(escapeRoomGetId(escape_room1)==69);
    escapeRoomDestroy(escape_room1);
    escapeRoomDestroy(escape_room2);

    return true;

}








int main(){
    RUN_TEST(testEscapeRoomOrder);
    RUN_TEST(testEscapeRoomCreate);
    RUN_TEST(testEscapeRoomDestroy);
    RUN_TEST(testEscapeRoomCopy);
    RUN_TEST(testEscapeRoomRecommendScore);
    RUN_TEST(testEscapeRoomEndDay);
    RUN_TEST(testEscapeRoomGetId);
    return 0;
}

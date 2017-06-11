#include <stdbool.h>
#include "test_utilities.h"
#include <string.h>
#include "EscapeRoom.h"
#include "Costumer.h"
#include "Order.h"


static bool testOrderCreate()
{
    int id3=36;
    int price3=40;
    int num_people3=55;
    int open_hour3=5;
    int close_hour3=17;
    int diff3=8;
    EscapeRoom  escape_room3=escapeRoomCreate(id3,price3,num_people3,open_hour3, close_hour3, diff3);


    Email yuval_email;
    yuval_email.address="yunahon@gmail.com";
    yuval_email.user_type=COSTUMER;
    Costumer yuval=costumerCreate(yuval_email,COMPUTER_SCIENCE,4);

    int order_day1=4;
    int order_hour1=13;
    int num_of_people1=8;
    bool discount1=false;

    int order_day2=0;
    int order_hour2=13;
    int num_of_people2=8;
    bool discount2=false;

    int order_day3=-4;
    int order_hour3=13;
    int num_of_people3=8;
    bool discount3=false;

    int order_day4=4;
    int order_hour4=5;
    int num_of_people4=8;
    bool discount4=false;

    int order_day5=4;
    int order_hour5=4;
    int num_of_people5=8;
    bool discount5=false;

    int order_day6=4;
    int order_hour6=18;
    int num_of_people6=8;
    bool discount6=false;

    int order_day7=4;
    int order_hour7=0;
    int num_of_people7=8;
    bool discount7=false;

    int order_day8=4;
    int order_hour8=24;
    int num_of_people8=8;
    bool discount8=false;

    int order_day9=4;
    int order_hour9=-20;
    int num_of_people9=8;
    bool discount9=false;

    int order_day10=4;
    int order_hour10=13;
    int num_of_people10=0;
    bool discount10=false;

    int order_day11=4;
    int order_hour11=13;
    int num_of_people11=-5;
    bool discount11=false;

    int order_day12=4;
    int order_hour12=13;
    int num_of_people12=8;
    bool discount12=true;

    ASSERT_TEST(orderCreate(order_day1,order_hour1,escape_room3,yuval,num_of_people1,discount1)!=NULL);
    ASSERT_TEST(orderCreate(order_day2,order_hour2,escape_room3,yuval,num_of_people2,discount2)!=NULL);
    ASSERT_TEST(orderCreate(order_day3,order_hour1,escape_room3,yuval,num_of_people3,discount3)==NULL);
    ASSERT_TEST(orderCreate(order_day4,order_hour1,escape_room3,yuval,num_of_people4,discount4)!=NULL);
    ASSERT_TEST(orderCreate(order_day5,order_hour1,escape_room3,yuval,num_of_people5,discount5)==NULL);
    ASSERT_TEST(orderCreate(order_day6,order_hour1,escape_room3,yuval,num_of_people6,discount6)==NULL);
    ASSERT_TEST(orderCreate(order_day7,order_hour1,escape_room3,yuval,num_of_people7,discount7)==NULL);
    ASSERT_TEST(orderCreate(order_day8,order_hour1,escape_room3,yuval,num_of_people8,discount8)==NULL);
    ASSERT_TEST(orderCreate(order_day9,order_hour1,escape_room3,yuval,num_of_people9,discount9)==NULL);
    ASSERT_TEST(orderCreate(order_day10,order_hour1,escape_room3,yuval,num_of_people10,discount10)==NULL);
    ASSERT_TEST(orderCreate(order_day11,order_hour1,escape_room3,yuval,num_of_people11,discount11)==NULL);
    ASSERT_TEST(orderCreate(order_day12,order_hour1,escape_room3,yuval,num_of_people12,discount12)!=NULL);



}
static bool testOrderCopy()
{

}
static bool testOrderDestroy()
{

}
static bool testOrdedrGetCostumer()
{

}
static bool testOrderGetOrderTime()
{
    int id3=36;
    int price3=40;
    int num_people3=55;
    int open_hour3=5;
    int close_hour3=17;
    int diff3=8;
    EscapeRoom  escape_room3=escapeRoomCreate(id3,price3,num_people3,open_hour3, close_hour3, diff3);


    Email yuval_email;
    yuval_email.address="yunahon@gmail.com";
    yuval_email.user_type=COSTUMER;
    Costumer yuval=costumerCreate(yuval_email,COMPUTER_SCIENCE,4);

    int order_day1=4;
    int order_hour1=13;
    int num_of_people1=8;
    bool discount1=false;

    int order_day2=4;
    int order_hour2=25;
    int num_of_people2=8;
    bool discount2=false;
    Order order1=orderCreate(order_day1,order_hour1,escape_room3,yuval,num_of_people1,discount1);
    Order order2=orderCreate(order_day2,order_hour2,escape_room3,yuval,num_of_people2,discount2);

    ASSERT_TEST((orderGetOrderTime(order1)).order_hour==13);
    ASSERT_TEST((orderGetOrderTime(order1)).order_day==4);
    ASSERT_TEST((orderGetOrderTime(order2)).order_hour==-1);
    ASSERT_TEST((orderGetOrderTime(order2)).order_day==-1);

}
static bool testOrderGetPrice()
{
    int id3=36;
    int price3=40;
    int num_people3=55;
    int open_hour3=5;
    int close_hour3=17;
    int diff3=8;
    EscapeRoom  escape_room3=escapeRoomCreate(id3,price3,num_people3,open_hour3, close_hour3, diff3);


    Email yuval_email;
    yuval_email.address="yunahon@gmail.com";
    yuval_email.user_type=COSTUMER;
    Costumer yuval=costumerCreate(yuval_email,COMPUTER_SCIENCE,4);

    int order_day1=4;
    int order_hour1=13;
    int num_of_people1=8;
    bool discount1=false;

    int order_day2=4;
    int order_hour2=25;
    int num_of_people2=8;
    bool discount2=false;

    int order_day3=4;
    int order_hour3=13;
    int num_of_people3=8;
    bool discount3=true;


    Order order1=orderCreate(order_day1,order_hour1,escape_room3,yuval,num_of_people1,discount1);
    Order order2=orderCreate(order_day2,order_hour2,escape_room3,yuval,num_of_people2,discount2);
    Order order3=orderCreate(order_day3,order_hour3,escape_room3,yuval,num_of_people3,discount3);

    ASSERT_TEST(orderGetPrice(order1)==320);
    ASSERT_TEST(orderGetPrice(order2)==-1);
    ASSERT_TEST(orderGetPrice(order3)==240);





}
static bool testOrderCheckOrderToday()
{

}
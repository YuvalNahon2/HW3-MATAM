
#include "EscapeRoom.h"
#define ASSERT_TEST(b) do { \
        if (!(b)) { \
                printf("\nAssertion failed at %s:%d %s\n",__FILE__,__LINE__,#b); \
                return false; \
        } \
} while (0)
int main(){
    EscapeRoom escape_room1=escapeRoomCreate(24,16,6,9,22,5);
    EscapeRoom escape_room2=escapeRoomCreate(10,40,2,3,14,10);
    EscapeRoom escape_room3=escapeRoomCopy(escape_room1);
    ASSERT_TEST(escapeRoomGetId(escape_room1)==24);
    ASSERT_TEST(escapeRoomGetId(escape_room2)==10);
    ASSERT_TEST(escapeRoomGetPrice(escape_room1)==16);
    ASSERT_TEST(escapeRoomGetPrice(escape_room2)==40);

    Email yuval_email;
    yuval_email.address="yunahon@gmail.com";
    yuval_email.user_type=COSTUMER;
    Costumer yuval=costumerCreate(yuval_email,COMPUTER_SCIENCE,4);

    Email omri_email;
    omri_email.address="omriporking@gmail.com";
    omri_email.user_type=COSTUMER;
    Costumer omri=costumerCreate(omri_email,MATHEMATICS,2);

    Email eyal_email;
    eyal_email.address="eyal@gmail.com";
    eyal_email.user_type=COSTUMER;
    Costumer eyal = costumerCreate(eyal_email,MECHANICAL_ENGINEERING,3);

    ASSERT_TEST(escapeRoomOrder(escape_room1,yuval,4,9,5,false)==ROOM_SUCCESS);
    ASSERT_TEST(escapeRoomOrder(escape_room2,omri,5,17,3,false)==ROOM_NOT_AVAILABLE);
    ASSERT_TEST(escapeRoomOrder(escape_room1,yuval,4,9,5,false)==ROOM_NOT_AVAILABLE);
    ASSERT_TEST(escapeRoomOrder(escape_room3,eyal,4,9,5,true)==ROOM_SUCCESS);


}

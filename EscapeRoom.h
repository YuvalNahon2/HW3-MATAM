#ifndef HW3_ESCAPEROOM_H
#define HW3_ESCAPEROOM_H

#include "Company.h"
typedef struct EscapeRoomS *EscapeRoom;
#endif //HW3_ESCAPEROOM_H
ListElement escapeRoomOrderCopy(ListElement order);
MtmErrorCode escapeRoomCreate (EscapeRoom escapeRoom,Company *company, int id,
                               int price, int num_people,int open_hour,
                               int close_hour, int diff);

MtmErrorCode escapeRoomDestroy(EscapeRoom escapeRoom);

MtmErrorCode escapeRoomOrder(EscapeRoom escapeRoom,Costumer costumer,
                             int day,int hour,int num_people);
int escapeRoomRecommendScore(EscapeRoom escapeRoom,int costumer_level,int num_people);
//we need to create a copy of the orders and then free the orders in the room.
// also calculates the earnings of the room
MtmErrorCode escapeRoomEndDay(EscapeRoom escapeRoom,List *roomOrders,int money_earned,int day);

//id geter
int getId(EscapeRoom escapeRoom);
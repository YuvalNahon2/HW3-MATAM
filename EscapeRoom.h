#ifndef HW3_ESCAPEROOM_H
#define HW3_ESCAPEROOM_H

#include "Company.h"
typedef struct WorkingHoursS{
    int open_hour;
    int close_hour;
}WorkingHours;
typedef struct EscapeRoomS *EscapeRoom;
#endif //HW3_ESCAPEROOM_H

MtmErrorCode escapeRoomCreate (EscapeRoom escapeRoom,Email email, int id,
                               int price, int num_of_people,int open_hour,
                               int close_hour, int diff);

MtmErrorCode escapeRoomDestroy(EscapeRoom escapeRoom);

MtmErrorCode escapeRoomOrder(EscapeRoom escapeRoom,Costumer costumer,
                             int day,int hour,int num_people);
MtmErrorCode escapeRoomRecommendScore(EscapeRoom escapeRoom,Costumer costumer,int num_people);
//we need to create a copy of the orders and then free the orders in the room.
// also calculates the earnings of the room
MtmErrorCode escapeRoomEndDay(EscapeRoom escapeRoom,List *roomOrders,int money_earned);
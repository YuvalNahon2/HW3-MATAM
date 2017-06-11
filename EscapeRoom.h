#ifndef HW3_ESCAPEROOM_H
#define HW3_ESCAPEROOM_H
#include <stdbool.h>
#include "Costumer.h"
#include "list.h"
typedef enum RoomErrorCodeE{
    ROOM_NULL_PARAMETER,
    ROOM_ORDERS_EXIST,
    ROOM_OUT_OF_MEMORY,
    ROOM_SUCCESS,
    ROOM_CLIENT_IN_ROOM,
    ROOM_NOT_AVAILABLE,
    ROOM_INVALID_ARGUMENT
}RoomErrorCode;
typedef struct EscapeRoomS *EscapeRoom;
EscapeRoom escapeRoomCreate ( int id,int price, int num_people, int open_hour,
                              int close_hour, int diff);
EscapeRoom escapeRoomCopy(EscapeRoom dest);
RoomErrorCode escapeRoomDestroy(EscapeRoom escapeRoom);

RoomErrorCode escapeRoomOrder(EscapeRoom escapeRoom,Costumer costumer,
                             int day,int hour,int num_people,bool discount);
int escapeRoomRecommendScore(EscapeRoom escapeRoom,int costumer_level,int num_people);
//we need to create a copy of the orders and then free the orders in the room.
// also calculates the earnings of the room
List escapeRoomEndDay(EscapeRoom escapeRoom,int *money_earned,int today);

//id geter
int escapeRoomGetId(EscapeRoom escapeRoom);
int escapeRoomGetPrice(EscapeRoom escapeRoom);

#endif //HW3_ESCAPEROOM_H
#ifndef HW3_ESCAPEROOM_H
#define HW3_ESCAPEROOM_H
#include <stdbool.h>
#include "list.h"
#include "Costumer.h"
typedef enum RoomErrorCodeE{
    ROOM_NULL_PARAMETER,
    ROOM_ORDERS_EXIST,
    ROOM_OUT_OF_MEMORY,
    ROOM_SUCCESS,
    ROOM_NOT_AVAILABLE,
    ROOM_INVALID_ARGUMENT
}RoomErrorCode;
typedef struct EscapeRoomS *EscapeRoom;

ListElement escapeRoomOrderCopy(ListElement order);

void escapeRoomOrderDestroy(ListElement order);


/**
 * creates a new EscapeRoom.
 * @param id - the id of the new room
 * @param price - the full price of the room
 * @param num_people - the number of people recommended.
 * @param open_hour - the open hour. a number between 0-23
 * @param close_hour - the close hour. a number between 1-24
 * @param diff - the difficulty level of the room.
 * @return the new escapeRoom in case of success.
 * if one of the parameters is not legal or the memory allocation failed(either
 * the inner list or the escapeRoom) a NULL will be returned.
 */
EscapeRoom escapeRoomCreate ( int id,int price, int num_people, int open_hour,
                              int close_hour, int diff);

/**
 * creates a copy of an escapeRoom.
 * @param src - the escapeRoom to copy
 * @return - an escapeRoom copy
 */
EscapeRoom escapeRoomCopy(EscapeRoom src);

/**
 * deletes an escape room without checking if threre are costumers inside.
 * only used to clean the system.
 * @param escape_room - the escape room to destroy.
 */
void escapeRoomDestroyNoPer(EscapeRoom escape_room);
/**
 * destroys an escapeRoom.
 * @param escapeRoom - the escapeRoom to destroy.
 * @return
 * ROOM_ORDERS_EXIST - if there are still some orders in the room.
 * ROOM_SUCCESS - if the room was successfully deleted.
 */
RoomErrorCode escapeRoomDestroy(EscapeRoom escapeRoom);

/**
 * creates an Order for a room.
 * @param escapeRoom - the escapeRoom to order a place at.
 * @param costumer - the costumer that makes the order.
 * @param day - the day of the order.
 * @param hour - the hour of the order.
 * @param num_people - the number of people to make the order for.
 * @param discount - if the person deserves a discount.
 * @return
 *ROOM_INVALID_ARGUMENT - if the order's hour is invalid (not 0-23).
 * ROOM_NOT_AVAILABLE - if the room is not operating in the order's hour.
 * ROOM_SUCCESS - the order was created.
 */
RoomErrorCode escapeRoomOrder(EscapeRoom escapeRoom,Costumer costumer,
                             int day,int hour,int num_people,bool discount);

/**
 *
 * @param escapeRoom - the escapeRoom.
 * @param costumer_level - the costumer skill level.
 * @param num_people - the number of people the costumer wants to make the order
 * for.
 * @return
 * returns the recommend score of the room according to the one supplied.
 * if any of the parameters are illegal the function will return -1.
 */
int escapeRoomRecommendScore(EscapeRoom escapeRoom,int costumer_level,int num_people);

/**
 * ends a day in the room by removing the orders of today and charging the
 * costumers.
 * @param escapeRoom - the escapeRoom to end the day in.
 * @param money_earned - a parameter used to return the amount of money the room
 * made today
 * @param today - the current day in the system.
 * @return
 * a list of orders that were for today.
 */
List escapeRoomEndDay(EscapeRoom escapeRoom,int *money_earned,int today);

/**
 *
 * @param escapeRoom - an escapeRoom.
 * @return the room's id
 */
int escapeRoomGetId(EscapeRoom escapeRoom);
/**
 *
 * @param escapeRoom - an escapeRoom.
 * @return the price of the escapeRoom.
 */
int escapeRoomGetPrice(EscapeRoom escapeRoom);

/**
 * @param escape_room - the escape room.
 * @return the rooms difficulty.
 */
int escapeRoomGetDiff(EscapeRoom escape_room);
/**
 * checks if the room has orders.
 * @param escape_room - the EscapeRoom.
 * @return
 * true-there are orders.
 * false-there are no orders.
 */
bool escapeRoomOrdersExist(EscapeRoom escape_room);
/**
 * removes a costumer's orders.
 * @param escape_room - the escape room.
 * @param costumer - the costumer to remove its orders.
 */
void escapeRoomRemoveCostumerOrders(EscapeRoom escape_room,Costumer costumer);
/**
 * orders the specified room to the closest time it's available for a costumer.
 * @param escape_room - the escape room to order.
 * @param costumer - the costumer.
 * @param num_people - the numer of people to make the order for.
 * @param discount - if the client deserves a discount.
 * @param today - the current system day.
 * @return
 * ROOM_NULL_PARAMETER - a null pointer(costumer/room) was sent to the function.
 * ROOM_OUT_OF_MEMORY - in case of a memory allocation failiure.
 */
RoomErrorCode escapeRoomOrderClosest(EscapeRoom escape_room,Costumer costumer,
                            int num_people,bool discount,int today);
/**
 * checks if a room has orders.
 * @param room - the escape room.
 * @param costumer
 * @param room_faculty
 * @param day
 * @param hour
 * @return
 */
bool escapeRoomCostumerHasOrder(EscapeRoom room,Costumer costumer,
                        TechnionFaculty room_faculty,int day,int hour);
#endif //HW3_ESCAPEROOM_H
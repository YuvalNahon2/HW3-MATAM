#ifndef HW3_COMPANY_H
#define HW3_COMPANY_H

#include "Email.h"
#include "mtm_ex3.h"
#include "Costumer.h"
#include "EscapeRoom.h"
#include "set.h"
#include "list.h"
typedef enum CompanyErrorCodeE{
    COMPANY_INVALID_ARGUMENT,
    COMPANY_NULL_PARAMETER,
    COMPANY_SUCCESS,
    COMPANY_OUT_OF_MEMORY,
    COMPANY_HAS_RESERVATION,
    COMPANY_ROOM_ALREADY_EXIST,
    COMPANY_ROOM_DOESNT_EXIST,
    COMPANY_CLIENT_IN_ROOM,
    COMPANY_ROOM_ORDERS_EXIST,
    COMPANY_ROOM_NOT_AVAILABLE,
    COMPANY_UNKNOWN
}CompanyErrorCode;
typedef struct CompanyS *Company;
/**
 * a function that creates a new Company.
 * @param email - the email of the company.
 * @param faculty - the faculty the company belongs to.
 * @return the created Company.in case of memory problem NULL will be returned.
 */
Company companyCreate(Email email,TechnionFaculty faculty);

/**
 * a function that destroys a company.
 * @param company - the company to destroy.
 * in case the company has orders left for any of the rooms the company will not
 * be deleted.
 */
void companyDestroy(Company company);

/**
 * adds a new room to the company.
 * @param company - the company to add room to.
 * @param id - the new room id.
 * @param price - the new room price.
 * @param open_hour - the new room open hour.
 * @param close_hour - the new room close hour.
 * @param num_people - the number of people of the new room.
 * @param difficulty - the new room difficulty.
 * @return
 * COMPANY_NULL_PARAMETER-if the company is NULL.
 * COMPANY_INVALID_ARGUMENT-if the arguments for the new room are invalid.
 * COMPANY_OUT_OF_MEMORY-if there was an allocation problem creating the new room.
 * COMPANY_ROOM_ALREADY_EXIST- if there is already a room with the same id in the company.
 * COMPANY_SUCCESS-a new room was created.
 */
CompanyErrorCode companyAddRoom(Company company,int id,int price,
                                int open_hour,int close_hour,int num_people,int difficulty);

/**
 *removes a room from the company.
 * @param company - the company the room will be removed from.
 * @param id - the id of the requested room.
 * @return
 * COMPANY_NULL_PARAMETER - if the company is NULL.
 * COMPANY_INVALID_ARGUMENT - if there is no room with the specified id.
 * COMPANY_SUCCESS - the room was removed successfully.
 */
CompanyErrorCode companyDeleteRoom(Company company,int id);

/**
 * a function for creating an Order to a specific room in the company
 * @param company - the company to make an order in.
 * @param costumer - the costumer that makes the order.
 * @param room_id - the requested room id.
 * @param day - the requested day.
 * @param hour - the requested hour.
 * @param num_people - the number of people.
 * @param today - the current system day.
 * @return
 * COMPANY_NULL_PARAMETER - in case company or costumer are null.
 * COMPANY_ROOM_DOESNT_EXIST - in case there is no room with the given id in the company.
 * COMPANY_INVALID_ARGUMENT - in case the given hour and day are invalid.
 * COMPANY_ROOM_NOT_AVAILABLE - in case the requested hour is not in the operating times of the room.
 * COMPANY_CLIENT_IN_ROOM - in case the room is already taken.
 * COMPANY_OUT_OF_MEMORY - in case the allocation of the new order failes.
 * COMPANY_SUCCESS - an order was created for a room successfully.
 */
CompanyErrorCode companyCreateOrder(Company company,Costumer costumer,
                                    int room_id,int day, int hour,
                                    int num_people,int today);

/**
 * returns the most recommended room in the company for a costumer.
 * @param company - the company.
 * @param costumer - the costumer.
 * @param num_people - the number of people to make the order for.
 * @return
 * the most recommended room in the company for the costumer or NULL if the company has no rooms.
 */
EscapeRoom companyGetRecommendedRoom(Company company,Costumer costumer,
                                     int num_people);

/**
 * a function that ends a day in the company by removing today's orders and
 * charging for them. this function returns an array of Lists that contains
 * every room's orders for today.
 * @param company - the company to end the day on.
 * @param day - the current system day
 * @param size - a parameter used to return the size of the array returned from
 * the function
 * @return - an array of Lists of orders that were executed today.
 */
List *companyEndDay(Company company,int day,int *size);

/**
 * @param company - the company.
 * @return the amount of money the company made.
 */
int companyGetMoney(Company company);
/**
 *
 * @param company - the company.
 * @return the faculty the company belongs to.
 */
TechnionFaculty companyGetFaculty(Company company);

/**
 *
 * @param company - a company.
 * @return the company's email address.
 */
char* companyGetEmailAddress(Company company);

/**
 * checks if any of the company's rooms hsa orders.
 * @param company - the company.
 * @return
 * true-the company has a room that has orders.
 * false-the company doesnt have a room with orders.
 */
bool companyOrdersExist(Company company);


//the Room set functions:
int companyCompareRooms(SetElement escapeRoom1,SetElement escapeRoom2);

SetElement companyCopyRoom(SetElement escapeRoom);

void companyDestroyRoom(SetElement escapeRoom);
#endif //HW3_COMPANY_H
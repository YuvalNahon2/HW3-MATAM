//
// Created by Yuval on 5/30/2017.
//

#ifndef HW3_ESCAPEROOM_H
#define HW3_ESCAPEROOM_H

#include "Company.h"
typedef struct WorkingHoursS{
    int open_hour;
    int close_hour;
}WorkingHours;
typedef struct EscapeRoomS *EscapeRoom;
#endif //HW3_ESCAPEROOM_H

MtmErrorCode escapeRoomCreate (Email email, int id, int price, int num_of_people,int open_hour, int close_hour, int diff);

MtmErrorCode escapeRoomDestroy(int faculty, int id);



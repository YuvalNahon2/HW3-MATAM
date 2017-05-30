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
typedef struct EscapeRoomS{
    int id;
    Company *company;
    int price;
    int num_people;
    WorkingHours workingHours;
    int dificulty;
}EscapeRoom;
#endif //HW3_ESCAPEROOM_H
//
// Created by Yuval on 5/30/2017.
//

#ifndef HW3_ESCAPEROOM_H
#define HW3_ESCAPEROOM_H

#include "Company.h"

typedef struct EscapeRoomS{
    int id;
    Company *company;
    int price;
    int num_people;
    int open_hour;
    int close_hour;
    int dificulty;
}EscapeRoom;
#endif //HW3_ESCAPEROOM_H

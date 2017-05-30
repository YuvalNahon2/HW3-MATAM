//
// Created by Yuval on 5/30/2017.
//

#ifndef HW3_EMAIL_H
#define HW3_EMAIL_H
typedef enum userTypeE{COMPANY,COSTUMER} userType;
typedef struct EmailS{
    char *address;
    userType user_type;
}Email;
#endif //HW3_EMAIL_H

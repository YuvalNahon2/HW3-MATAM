#ifndef HW3_E_MAIL_H
#define HW3_E_MAIL_H

typedef enum userTypeE{COSTUMER,COMPANY} userType;
typedef struct emailS{
    char *email_address;
    userType user_type;
}Email;
#endif //HW3_E_MAIL_H

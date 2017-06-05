//
// Created by Yuval on 5/30/2017.
//
#include <stdlib.h>
#include "Company.h"
#include <assert.h>
#include "costumer.c"
#include "EscapeRoom.h"

struct CompanyS{
    TechnionFaculty faculty;
    Email *email;
    Set EscapeRooms;
    int earned_money;
    int *day;
};
MtmErrorCode companyCreate (Company company,Email *email, TechnionFaculty faculty,int *day)
{
    company->email=email;
    company->faculty=faculty;
    company->day=day;
}
MtmErrorCode companyDestroy(Company company)
{
    free(company);
}

MtmErrorCode companyCreateOrder(Company company,Costumer costumer, TechnionFaculty faculty,int room_id,int day,
                                int hour,int num_people)
{
  assert(company!=NULL&&costumer!=NULL);
    {
        if(!setIsIn(company->EscapeRooms, (SetElement)room_id))
        {
            return MTM_ID_DOES_NOT_EXIST;
        }


    }
}

MtmErrorCode companyGetRecommendedRoom(EscapeRoom *result,Company company,Costumer costumer,int num_people)
{
    int level=costumer->skill_level;
    int min_score=-1;
    EscapeRoom minRoom=NULL;
    EscapeRoom room_iterator;
    SET_FOREACH(EscapeRoom,room_iterator,company->EscapeRooms){
        int curr_score=escapeRoomRecommendScore(room_iterator,level,num_people);
        if(curr_score<min_score || min_score==-1) {
            minRoom = room_iterator;
            min_score=curr_score;

        }
    }
    *result=minRoom;

}


MtmErrorCode companyEndDay(Company company,int day,List todayOrders)
{

}

MtmErrorCode companyGetMoney(Company company,int *money_earned)
{
    assert(company!=NULL);
    *money_earned=company->earned_money;
}
MtmErrorCode companyGetFaculty(Company company,TechnionFaculty *faculty)
{
    assert(company!=NULL);
    *faculty=company->faculty;
}

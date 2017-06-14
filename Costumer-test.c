#include <stdbool.h>
#include <string.h>
#include "test_utilities.h"
#include "EscapeRoom.h"

static bool testCostumerCreate()
{

    char* yuval_email="yunahon@gmail.com";
    Costumer yuval=costumerCreate(yuval_email,COMPUTER_SCIENCE,4);


    char* omri_email="omri@gmail.com";
    Costumer omri=costumerCreate(omri_email,COMPUTER_SCIENCE,4);

    char* yoni_email="yoni@gmail.com";
    Costumer yoni=costumerCreate(yoni_email,COMPUTER_SCIENCE,4);

    char* tal_email="tal@gmail.com";
    Costumer tal=costumerCreate(tal_email,COMPUTER_SCIENCE,4);

    char* kobi_email="koby@gmail.com";
    Costumer kobi=costumerCreate(kobi_email,COMPUTER_SCIENCE,0);

    char* nir_email="nir@gmail.com";
    Costumer nir=costumerCreate(nir_email,COMPUTER_SCIENCE,11);

    char* gal_email="gal@gmail.com";
    Costumer gal=costumerCreate(gal_email,COMPUTER_SCIENCE,-4);


    ASSERT_TEST(yuval!=NULL);
    ASSERT_TEST(omri!=NULL);
    ASSERT_TEST(yoni==NULL);
    ASSERT_TEST(tal!=NULL);
    ASSERT_TEST(kobi==NULL);
    ASSERT_TEST(nir==NULL);
    ASSERT_TEST(gal==NULL);

    costumerDestroy(yuval);
    costumerDestroy(omri);
    costumerDestroy(yoni);
    costumerDestroy(tal);
    costumerDestroy(kobi);
    costumerDestroy(nir);
    costumerDestroy(gal);
    return true;

}

static bool testCostumerGetSkillLevel()
{
    char* yuval_email="yunahon@gmail.com";
    Costumer yuval=costumerCreate(yuval_email,COMPUTER_SCIENCE,4);

    char* omri_email="omri@gmail.com";
    Costumer omri=costumerCreate(omri_email,COMPUTER_SCIENCE,4);

    ASSERT_TEST(costumerGetSkillLevel(yuval)==4);

    costumerDestroy(yuval);
    costumerDestroy(omri);

    return true;

}
static bool testCostumerGetFaculty()
{
    char* yuval_email="yunahon@gmail.com";
    Costumer yuval=costumerCreate(yuval_email,COMPUTER_SCIENCE,4);

    char* omri_email="omri@gmail.com";
    Costumer omri=costumerCreate(omri_email,COMPUTER_SCIENCE,4);
    ASSERT_TEST(costumerGetFaculty(yuval)==COMPUTER_SCIENCE);

    costumerDestroy(yuval);
    costumerDestroy(omri);

    return true;
}
static bool testCostumerGetEmail()
{
    char* yuval_email="yunahon@gmail.com";
    Costumer yuval=costumerCreate(yuval_email,COMPUTER_SCIENCE,4);

    char* omri_email="omri@gmail.com";
    Costumer omri=costumerCreate(omri_email,COMPUTER_SCIENCE,4);


    ASSERT_TEST(strcmp(costumerGetEmailAddress(yuval),"yunahon@gmail.com")==0);
    ASSERT_TEST(costumerGetEmailAddress(omri)==NULL);

    costumerDestroy(yuval);
    costumerDestroy(omri);

    return true;


}

static bool testCostumerCopy()
{
    char* yuval_email="yunahon@gmail.com";
    Costumer yuval=costumerCreate(yuval_email,COMPUTER_SCIENCE,4);

    char* omri_email="omri@gmail.com";
    Costumer omri=costumerCreate(omri_email,COMPUTER_SCIENCE,4);
    Costumer copy1=costumerCopy(yuval);
    Costumer copy2=costumerCopy(omri);

    ASSERT_TEST(copy1!=NULL);
    ASSERT_TEST(copy2==NULL);

    costumerDestroy(copy1);
    costumerDestroy(copy2);
    costumerDestroy(yuval);
    costumerDestroy(omri);

    return true;
}
static bool testGetEmailAddress()
{
    char* yuval_email="yunahon@gmail.com";
    Costumer yuval=costumerCreate(yuval_email,COMPUTER_SCIENCE,4);

    char* omri_email="omri@gmail.com";
    Costumer omri=costumerCreate(omri_email,COMPUTER_SCIENCE,4);
    ASSERT_TEST(strcmp(costumerGetEmailAddress(yuval),"yunahon@gmail.com")==0);
    ASSERT_TEST(costumerGetEmailAddress(omri)!=NULL);

    costumerDestroy(yuval);
    costumerDestroy(omri);
    return true;
}


int main()
{
    RUN_TEST(testCostumerCreate);
    RUN_TEST(testCostumerGetEmail);
    RUN_TEST(testCostumerGetFaculty);
    RUN_TEST(testCostumerGetSkillLevel);
    RUN_TEST(testCostumerCopy);
    RUN_TEST(testGetEmailAddress);
    return 0;
}






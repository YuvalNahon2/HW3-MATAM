#include <stdbool.h>
#include <string.h>
#include "test_utilities.h"
#include "EscapeRoom.h"
#include "Costumer.h"

static bool testCostumerCreate()
{
    Email yuval_email;
    yuval_email.address="yunahon@gmail.com";
    yuval_email.user_type=COSTUMER;
    Costumer yuval=costumerCreate(yuval_email,COMPUTER_SCIENCE,4);

    Email omri_email;
    omri_email.address="omri@gmail.com";
    omri_email.user_type=COSTUMER;
    Costumer omri=costumerCreate(omri_email,COMPUTER_SCIENCE,4);

    Email yoni_email;
    yoni_email.address="yoni@gmail.com";
    yoni_email.user_type=COMPANY;
    Costumer yoni=costumerCreate(yoni_email,COMPUTER_SCIENCE,4);

    Email tal_email;
    tal_email.address="tal@gmail.com";
    tal_email.user_type=COSTUMER;
    Costumer tal=costumerCreate(tal_email,COMPUTER_SCIENCE,4);

    Email kobi_email;
    kobi_email.address="koby@gmail.com";
    kobi_email.user_type=COSTUMER;
    Costumer kobi=costumerCreate(kobi_email,COMPUTER_SCIENCE,0);

    Email nir_email;
    nir_email.address="nir@gmail.com";
    nir_email.user_type=COSTUMER;
    Costumer nir=costumerCreate(nir_email,COMPUTER_SCIENCE,11);

    Email gal_email;
    gal_email.address="gal@gmail.com";
    gal_email.user_type=COSTUMER;
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
    Email yuval_email;
    yuval_email.address="yunahon@gmail.com";
    yuval_email.user_type=COSTUMER;
    Costumer yuval=costumerCreate(yuval_email,COMPUTER_SCIENCE,4);

    Email omri_email;
    omri_email.address="omrigmail.com";
    omri_email.user_type=COSTUMER;
    Costumer omri=costumerCreate(yuval_email,COMPUTER_SCIENCE,4);

    ASSERT_TEST(costumerGetSkillLevel(yuval)==4);

    costumerDestroy(yuval);
    costumerDestroy(omri);

    return true;

}
static bool testCostumerGetFaculty()
{
    Email yuval_email;
    yuval_email.address="yunahon@gmail.com";
    yuval_email.user_type=COSTUMER;
    Costumer yuval=costumerCreate(yuval_email,COMPUTER_SCIENCE,4);

    Email omri_email;
    omri_email.address="omrigmail.com";
    omri_email.user_type=COSTUMER;
    Costumer omri=costumerCreate(yuval_email,COMPUTER_SCIENCE,4);
    ASSERT_TEST(costumerGetFaculty(yuval)==COMPUTER_SCIENCE);

    costumerDestroy(yuval);
    costumerDestroy(omri);

    return true;
}
static bool testCostumerGetEmail()
{
    Email yuval_email;
    yuval_email.address="yunahon@gmail.com";
    yuval_email.user_type=COSTUMER;
    Costumer yuval=costumerCreate(yuval_email,COMPUTER_SCIENCE,4);

    Email omri_email;
    omri_email.address="omri@gmail.com";
    omri_email.user_type=COMPANY;
    Costumer omri=costumerCreate(omri_email,COMPUTER_SCIENCE,4);

    ASSERT_TEST(strcmp(costumerGetEmailAddress(yuval),"yunahon@gmail.com")==0);
    ASSERT_TEST(costumerGetEmailAddress(omri)==NULL);

    costumerDestroy(yuval);
    costumerDestroy(omri);

    return true;


}

static bool testCostumerCopy()
{
    Email yuval_email;
    yuval_email.address="yunahon@gmail.com";
    yuval_email.user_type=COSTUMER;
    Costumer yuval=costumerCreate(yuval_email,COMPUTER_SCIENCE,4);

    Email omri_email;
    omri_email.address="omri@gmail.com";
    omri_email.user_type=COMPANY;
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
    Email yuval_email;
    yuval_email.address="yunahon@gmail.com";
    yuval_email.user_type=COSTUMER;
    Costumer yuval=costumerCreate(yuval_email,COMPUTER_SCIENCE,4);

    Email omri_email;
    omri_email.address="omrigmail.com";
    omri_email.user_type=COSTUMER;
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






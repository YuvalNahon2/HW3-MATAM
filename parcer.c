#include <stdio.h>
#include "parcer.h"
#include <string.h>
#include <stdlib.h>

#define DELIMITER "- \t \n \r"
#define MAX_COMMAND_SIZE 250
static MtmErrorCode companySubCommand(EscapeTechnion escape_technion){
    char *sub_command=strtok(NULL,DELIMITER);
    if(strcmp(sub_command,"add")==0){
        char *email=strtok(NULL,DELIMITER);
        TechnionFaculty faculty=(TechnionFaculty)atoi(strtok(NULL,DELIMITER));
        return escapeTechnionAddCompany(escape_technion,email,faculty);
    }
    else if(strcmp(sub_command,"remove")==0){
        char *email=strtok(NULL,DELIMITER);
        return escapeTechnionDestroyCompany(escape_technion,email);
    }
    return MTM_INVALID_PARAMETER;
}

static MtmErrorCode roomSubCommand(EscapeTechnion escape_technion){
    char *sub_command=strtok(NULL,DELIMITER);
    if(strcmp(sub_command,"add")==0){
        char *email=strtok(NULL,DELIMITER);
        int id=atoi(strtok(NULL,DELIMITER));
        int price=atoi(strtok(NULL,DELIMITER));
        int num_people=atoi(strtok(NULL,DELIMITER));
        int open_hour=atoi(strtok(NULL,DELIMITER));
        int close_hour=atoi(strtok(NULL,DELIMITER));
        int difficulty=atoi(strtok(NULL,DELIMITER));
        return escapeTechnionAddRoom(escape_technion,email,id,price,num_people,
                              open_hour,close_hour,difficulty);
    }
    if(strcmp(sub_command,"remove")==0){
        TechnionFaculty faculty=(TechnionFaculty)atoi(strtok(NULL,DELIMITER));
        int id=atoi(strtok(NULL,DELIMITER));
        return escapeTechnionDeleteRoom(escape_technion,faculty,id);
    }
    return MTM_INVALID_PARAMETER;
}

static MtmErrorCode costumerSubCommand(EscapeTechnion escape_technion){
    char *sub_command=strtok(NULL,DELIMITER);
    if(strcmp(sub_command,"add")==0){
        char *email=strtok(NULL,DELIMITER);
        TechnionFaculty faculty=(TechnionFaculty)atoi(strtok(NULL,DELIMITER));
        int skill_level=atoi(strtok(NULL,DELIMITER));
        return escapeTechnionAddCostumer(escape_technion,email,faculty,
                                         skill_level);
    }
    if(strcmp(sub_command,"remove")==0){
        char *email=strtok(NULL,DELIMITER);
        return escapeTechnionDestroyCostumer(escape_technion,email);
    }
    if(strcmp(sub_command,"order")==0){
        char *email=strtok(NULL,DELIMITER);
        TechnionFaculty faculty=(TechnionFaculty)atoi(strtok(NULL,DELIMITER));
        int id=atoi(strtok(NULL,DELIMITER));
        int day=atoi(strtok(NULL,DELIMITER))+escapeTechnionGetDay(escape_technion);
        int hour=atoi(strtok(NULL,DELIMITER));
        int num_people=atoi(strtok(NULL,DELIMITER));
        return escapeTechnionCreateOrder(escape_technion,email,
                                         faculty,id,day,hour,num_people);
    }
    if (strcmp(sub_command,"recommend")==0){
        char *email=strtok(NULL,DELIMITER);
        int num_people=atoi(strtok(NULL,DELIMITER));
        return escapeTechnionOrderRecommended(escape_technion,email,num_people);
    }
    return MTM_INVALID_PARAMETER;
}

static void reportSubCommand(EscapeTechnion escape_technion,FILE *output){
    char *sub_command=strtok(NULL,DELIMITER);
    MtmErrorCode result;
    if(strcmp(sub_command,"day")==0){
        result=escapeTechnionEndDay(escape_technion,output);
    }
    if(strcmp(sub_command,"best")==0){
        escapeTechnionPrintWinningFaculties(escape_technion,output);
    }
}






void getCommands(FILE *input_file,FILE *output_file,
                 EscapeTechnion escape_technion){
    if(escape_technion==NULL) {
        mtmPrintErrorMessage(stderr, MTM_OUT_OF_MEMORY);
    }
    char line[MAX_COMMAND_SIZE];
    char *command=NULL;
    MtmErrorCode result;
    while(fgets(line, MAX_COMMAND_SIZE, input_file)) {

        command=strtok(line,DELIMITER);
        if(command==NULL ||command[0]=='\n' || command[0]=='#'){
            continue;
        }
        if(strcmp(command,"company")==0){
            result=companySubCommand(escape_technion);
            if(result!=MTM_SUCCESS) {
                mtmPrintErrorMessage(stderr, result);
            }
        }
        else if(strcmp(command,"room")==0){
            result=roomSubCommand(escape_technion);
            if(result!=MTM_SUCCESS) {
                mtmPrintErrorMessage(stderr, result);
            }

        }
        else if(strcmp(command,"escaper")==0){
            result=costumerSubCommand(escape_technion);
            if(result!=MTM_SUCCESS) {
                mtmPrintErrorMessage(stderr, result);
            }
        }
        else if(strcmp(command,"report")==0){
            reportSubCommand(escape_technion,output_file);
        }
        else{
            mtmPrintErrorMessage(stderr,MTM_INVALID_PARAMETER);
            return;
        }
    }
}
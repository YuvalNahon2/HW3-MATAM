#include <stdio.h>
#include "parcer.h"
#include "mtm_ex3.h"
#include <string.h>
#include <stdlib.h>
#include "EscapeTechnion.h"

#define DELIMITER " \t"
#define MAX_COMMAND_SIZE 250
static MtmErrorCode companySubCommand(EscapeTechnion escape_technion){
    char *sub_command=strtok(NULL," ");
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
    char *sub_command=strtok(NULL," ");
    if(strcmp(sub_command,"add")==0){
        char *email=strtok(NULL,DELIMITER);
        int id=atoi(strtok(NULL,DELIMITER));
        int price=atoi(strtok(NULL,DELIMITER));
        int num_people=atoi(strtok(NULL,DELIMITER));
        char *working_hours=strtok(NULL,DELIMITER);
        if(strlen(working_hours)<5 || working_hours[2]!='-'){
            return MTM_INVALID_PARAMETER;
        }
        int difficulty=atoi(strtok(NULL,DELIMITER));
        int open_hour=atoi(strtok(working_hours,"-"));
        int close_hour=atoi(strtok(NULL," -"));
        return escapeTechnionAddRoom(escape_technion,email,id,price,num_people,
                              open_hour,close_hour,difficulty);
    }
    if(strcmp(sub_command,"remove")){
        TechnionFaculty faculty=(TechnionFaculty)atoi(strtok(NULL,DELIMITER));
        int id=atoi(strtok(NULL,DELIMITER));
        return escapeTechnionDeleteRoom(escape_technion,faculty,id);
    }
    return MTM_INVALID_PARAMETER;
}

static MtmErrorCode costumerSubCommand(EscapeTechnion escape_technion){
    char *sub_command=strtok(NULL," ");
    if(strcmp(sub_command,"add")==0){
        char *email=strtok(NULL,DELIMITER);
        TechnionFaculty faculty=(TechnionFaculty)strtok(NULL,DELIMITER);
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
        char *time=strtok(NULL,DELIMITER);
        int num_people=atoi(strtok(NULL,DELIMITER));
        int day=atoi(strtok(time,"-"));
        int hour=atoi(strtok(time," -"));
        return escapeTechnionCreateOrder(escape_technion,email,
                                         faculty,id,day,hour,num_people);
    }
    if (strcmp(sub_command,"recommend")==0){
        char *email=strtok(NULL,DELIMITER);
        int num_people=atoi(strtok(NULL,DELIMITER));
        escapeTechnionOrderRecommended(escape_technion,email,num_people);
    }
    return MTM_INVALID_PARAMETER;
}

static MtmErrorCode reportSubCommand(EscapeTechnion escape_technion,FILE *output){
    char *sub_command=strtok(NULL," ");
    if(strcmp(sub_command,"day")){
        return escapeTechnionEndDay(escape_technion,output);
    }
    if(strcmp(sub_command,"best")){
        int *company_earnings;
        TechnionFaculty *faculty;
        faculty=escapeTechnionPrintWinningFaculties(escape_technion,
                                                    &company_earnings);

    }
}






void getCommands(FILE *input_file,FILE *output_file,
                 EscapeTechnion escape_technion){
    char* line;
    char *command;
    MtmErrorCode result;
    while(fgets(line, MAX_COMMAND_SIZE, input_file)) {
        if(line==NULL){
            break;
        }

        command=strtok(line,DELIMITER);
        if(strcmp(command,"company")==0){
            result=companySubCommand(escape_technion);
            mtmPrintErrorMessage(stderr,result);
        }
        else if(strcmp(command,"room")==0){
            result=roomSubCommand(escape_technion);
            mtmPrintErrorMessage(stderr,result);

        }
        else if(strcmp(command,"escaper")==0){
            result=costumerSubCommand(escape_technion);
            mtmPrintErrorMessage(stderr,result);
        }
        else if(strcmp(command,"report")==0){
            result=reportSubCommand(escape_technion,output_file);
            mtmPrintErrorMessage(stderr,result);
        }
        else if(command[0]=='#'){
            continue;
        }
        else{
            mtmPrintErrorMessage(stderr,MTM_INVALID_PARAMETER);
            return;
        }
    }

}
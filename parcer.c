#include <stdio.h>
#include "parcer.h"
#include "mtm_ex3.h"
#include <string.h>
#define MAX_COMMAND_SIZE 250
MtmErrorCode companySubCommand(){
    char *sub_command=strtok(NULL," ");
    if(strcmp(sub_command,"add")==0){

    }
}







void getCommands(FILE *input_file,FILE *output_file){
    char* line;
    char *command;
    while(1) {
        line = NULL;
        line=fgets(line, MAX_COMMAND_SIZE, input_file);
        if(line==NULL){
            break;
        }

        command=strtok(line," ");
        if(strcmp(command,"company")==0){
            companySubCommand();
        }
        else if(strcmp(command,"room")==0){
            if(roomSubCommand()!=MTM_SUCCESS){
                return;
            }
        }
        else if(strcmp(command,"escaper")==0){
            costumerSubCommand();
        }
        else if(strcmp(command,"report")==0){
            reportSubCommand();
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
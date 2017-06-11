
#include <string.h>
#include "stdlib.h"
#include <stdio.h>
#include "mtm_ex3.h"
#include "EscapeTechnion.h"
void getCommands(FILE *input_file, FILE *output_file);

void subCommandCompany(FILE *input_file, FILE *output_file);

void subCommandRoom(FILE *input_file, FILE *output_file);

void subCommandCostumer(FILE *input_file, FILE *output_file);

void subCommandSystem(FILE *input_file, FILE *output_file);

int main(int argc, char **argv){
    FILE *input_file=stdin;
    FILE *output_file=stdout;
    if(argc!=1 && argc!=3 && argc!=5){
        mtmPrintErrorMessage(stderr,MTM_INVALID_COMMAND_LINE_PARAMETERS);
        return 0;
    }
    for(int k=1;k<argc-1;k+=2) {
        if (strcmp(argv[k], "-i")) {
            input_file=fopen(argv[k+1],"r");
            if (input_file==NULL) {
                mtmPrintErrorMessage(stderr, MTM_CANNOT_OPEN_FILE);
                return 0;
            }
            continue;
        }
        if (strcmp(argv[k], "-o")) {
            output_file=fopen(argv[k+1],"w");
            if (output_file==NULL) {
                mtmPrintErrorMessage(stderr, MTM_CANNOT_OPEN_FILE);
                return 0;
            }
            continue;
        }
        mtmPrintErrorMessage(stderr,MTM_INVALID_COMMAND_LINE_PARAMETERS);
        return 0;
    }
    EscapeTechnion system;
    escapeTechnionCreate(system);
    if(system==NULL)
        mtmPrintErrorMessage(stderr,MTM_OUT_OF_MEMORY);
    getCommands(input_file,output_file);

}

void getCommands(FILE *input_file, FILE *output_file) {
    char command_buffer[8];
    while(fscanf(input_file,"%s",command_buffer)!=EOF){
        if(*command_buffer=='#')
            continue;
        if(strcmp(command_buffer,"company")){
            subCommandCompany(input_file,output_file);
        }
        if(strcmp(command_buffer,"room")){
            subCommandRoom(input_file,output_file);
        }
        if(strcmp(command_buffer,"escaper")){
            subCommandCostumer(input_file,output_file);
        }
        if(strcmp(command_buffer,"report")){
            subCommandSystem(input_file,output_file);
        }
    }
}

void subCommandSystem(FILE *input_file, FILE *output_file) {

}

void subCommandCostumer(FILE *input_file, FILE *output_file) {

}

void subCommandRoom(FILE *input_file, FILE *output_file) {

}

void subCommandCompany(FILE *input_file, FILE *output_file) {

}


#include <string.h>
#include "stdlib.h"
#include <stdio.h>
#include "mtm_ex3.h"
#include "EscapeTechnion.h"
void getCommands(FILE *inputFile, FILE *outputFile);

void subCommandCompany(FILE *inputFile, FILE *outputFile);

void subCommandRoom(FILE *inputFile, FILE *outputFile);

void subCommandCostumer(FILE *inputFile, FILE *outputFile);

void subCommandSystem(FILE *inputFile, FILE *outputFile);

int main(int argc, char **argv){
    FILE *inputFile=stdin;
    FILE *outputFile=stdout;
    if((argc-1)%2){
        mtmPrintErrorMessage(stderr,MTM_INVALID_COMMAND_LINE_PARAMETERS);
        return 0;
    }
    for(int k=1;k<argc-1;k+=2) {
        if (strcmp(argv[k], "-i")) {
            inputFile=fopen(argv[k+1],"r");
            if (inputFile==NULL) {
                mtmPrintErrorMessage(stderr, MTM_CANNOT_OPEN_FILE);
                return 0;
            }
            continue;
        }
        if (strcmp(argv[k], "-o")) {
            outputFile=fopen(argv[k+1],"w");
            if (outputFile==NULL) {
                mtmPrintErrorMessage(stderr, MTM_CANNOT_OPEN_FILE);
                return 0;
            }
            continue;
        }
        mtmPrintErrorMessage(stderr,MTM_INVALID_COMMAND_LINE_PARAMETERS);
        return 0;
    }
    EscapeTechnion system=malloc(sizeof(*system));
    getCommands(inputFile,outputFile);

}

void getCommands(FILE *inputFile, FILE *outputFile) {
    char command_buffer[8];
    while(fscanf(inputFile,"%s",command_buffer)!=EOF){
        if(*command_buffer=='#')
            continue;
        if(strcmp(command_buffer,"company")){
            subCommandCompany(inputFile,outputFile);
        }
        if(strcmp(command_buffer,"room")){
            subCommandRoom(inputFile,outputFile);
        }
        if(strcmp(command_buffer,"escaper")){
            subCommandCostumer(inputFile,outputFile);
        }
        if(strcmp(command_buffer,"report")){
            subCommandSystem(inputFile,outputFile);
        }
    }
}

void subCommandSystem(FILE *inputFile, FILE *outputFile) {

}

void subCommandCostumer(FILE *inputFile, FILE *outputFile) {

}

void subCommandRoom(FILE *inputFile, FILE *outputFile) {

}

void subCommandCompany(FILE *inputFile, FILE *outputFile) {

}

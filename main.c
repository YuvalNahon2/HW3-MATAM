
#include <string.h>
#include "stdlib.h"
#include <stdio.h>
#include "mtm_ex3.h"
#include "EscapeTechnion.h"


int main(int argc, char **argv){
    FILE *input_file=stdin;
    FILE *output_file=stdout;
    bool recieved_input_file=false;
    bool recieved_output_file=false;
    if(argc!=1 && argc!=3 && argc!=5){
        mtmPrintErrorMessage(stderr,MTM_INVALID_COMMAND_LINE_PARAMETERS);
        return 0;
    }
    for(int k=1;k<argc-1;k+=2) {
        if (strcmp(argv[k], "-i")==0) {
            if(recieved_input_file){
                mtmPrintErrorMessage(stderr,MTM_INVALID_COMMAND_LINE_PARAMETERS);
            }
            input_file=fopen(argv[k+1],"r");
            if (input_file==NULL) {
                mtmPrintErrorMessage(stderr, MTM_CANNOT_OPEN_FILE);
                return 0;
            }
            recieved_input_file=true;
            continue;
        }
        if (strcmp(argv[k], "-o")) {
            if(recieved_output_file){
                mtmPrintErrorMessage(stderr,MTM_INVALID_COMMAND_LINE_PARAMETERS);
            }
            output_file=fopen(argv[k+1],"w");
            if (output_file==NULL) {
                mtmPrintErrorMessage(stderr, MTM_CANNOT_OPEN_FILE);
                return 0;
            }
            recieved_output_file=true;
            continue;
        }
        mtmPrintErrorMessage(stderr,MTM_INVALID_COMMAND_LINE_PARAMETERS);
        return 0;
    }
    EscapeTechnion system;
    escapeTechnionCreate(system);
    if(system==NULL) {
        mtmPrintErrorMessage(stderr, MTM_OUT_OF_MEMORY);
    }
    getCommands(input_file,output_file);

}

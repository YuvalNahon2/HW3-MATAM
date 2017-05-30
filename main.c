
#include <string.h>
#include <stdio.h>
#include "mtm_ex3.h"

void getCommands(FILE *inputFile, FILE *outputFile);

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

    getCommands(inputFile,outputFile);

}

void getCommands(FILE *inputFile, FILE *outputFile) {
while(fscanf(inputFile,""))
}
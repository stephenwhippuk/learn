#include <stdincludes.h>
#include "delete.h"

int main(){
    printf("recursive delete - rm -R\n");
    // first check we have a data folder
    DIR* dir = opendir("data");
    if (!dir){
        printf("\n*** please run setup first ***");
        exit(EXIT_FAILURE);
    }
    
    int result = recursiveDelete("data");
    switch(result){
        case CANNOT_OPEN_FOLDER:
            printf("folder cannot be opened\n");
            break;
        case CANNOT_FETCH_STAT:
            printf("cannot fetch file or folder stats\n");
            break;
        case ACCESSS_VIOLATION:
            printf("You do not have permission to perform this operation");
        default:
            printf("folder deleted\n");
    }
    if(!result)
        exit(EXIT_SUCCESS);
    exit(EXIT_FAILURE);
}
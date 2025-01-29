#include<stdincludes.h>
#include "permission.h"

const int BUFFER_LENGTH = 10;

int main(){

    char buffer[BUFFER_LENGTH];

    int result = getPermissions("../data/data.txt", buffer, BUFFER_LENGTH);

    switch(result){
        case ERROR_READING_FILE:
            printf("Unable to read file");
            break;
        case BUFFER_TO_SMALL:
            printf("insufficient space in buffer to hold permissions");
            break;
        default:
            printf("target\t%s\n", buffer);
    }
  
    if(result){
        exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);
}
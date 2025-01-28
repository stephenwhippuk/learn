#include<stdincludes.h>
#include "permission.h"

const int BUFFER_LENGTH = 10;

int main(){

    char buffer[BUFFER_LENGTH];

    int result = getPermissions("../data/data.txt", buffer);

    switch(result){
        case ERROR_READING_FILE:
            printf("Unable to read file");
            exit(EXIT_FAILURE);
    }
    printf("target\t%s\n", buffer);

    exit(EXIT_SUCCESS);
}
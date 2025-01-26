#include <stdincludes.h>

int main(){
    printf("Writing a file ... \n");

    const char* FILEPATH = "../data";
    const char* data = "Hello World!\n\0";

    char fullPath[1000] = {0};

    // build the path 
    strcat(fullPath, FILEPATH);
    strcat(fullPath, "/data.dat");

    // open file for writing only
    FILE* theFile = fopen(fullPath, "w");
    
    // error if file couldn;t be opened then error
    if(!theFile){
        printf("failed to open file\n");
        exit(EXIT_FAILURE);
    }

    // write data to file
    fprintf(theFile, "%s", data);

    // close the file
    fclose(theFile);

    // success
    exit(EXIT_SUCCESS);
}
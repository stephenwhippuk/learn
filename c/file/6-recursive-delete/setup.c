#include <stdincludes.h>

int main(){
    printf("Creating Test File Structure...\n");
    // open permissions
    int permissions = S_IRUSR | S_IWUSR | S_IXUSR | S_IRGRP | S_IROTH; 


    if(mkdir("data", permissions) == -1){
        printf("Error - creating directory root");
        exit(EXIT_FAILURE);
    }

    chdir("data");
    if(mkdir("sub", permissions) == -1){
        printf("Error - creating directory sub");
        exit(EXIT_FAILURE);
    }
    printf("Test data directory structure created...\n");
    chdir("sub");
    FILE* fptr = fopen("sub1.dat", "w");
    fclose(fptr);
    fptr = fopen("sub2.dat", "w");
    fclose(fptr);
    chdir("..");
    fptr = fopen("data1.dat", "w");
    fclose(fptr);
    printf("Test files created...\n");
    exit(EXIT_SUCCESS);
}
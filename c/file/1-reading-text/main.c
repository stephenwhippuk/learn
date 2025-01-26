#include <stdincludes.h>

int main(){
    printf("Reading Text File example... \n");
    FILE* theFile = fopen("../data/data.dat", "r");
    
    if(theFile == NULL){
        printf("Bad FIle\n");
        exit(EXIT_SUCCESS);
    }

    char content[10000];
    int i = 0;
    char c;
    while(!feof(theFile)){
        c = fgetc(theFile);
        content[i++] = c;
    }

    printf("\n%s\n", content);
    fclose(theFile);
    exit(EXIT_SUCCESS);
}
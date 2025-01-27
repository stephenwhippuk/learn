#include <stdincludes.h>

int main(){
    printf("reading and displaying csv file... \n");

    char** lines = NULL;
    // allocate enough for a 100 line CSV for now 
    lines = (char**) malloc(sizeof(char*) * 100);

    // open 2 read only pointers to the data file
    FILE* contentToRead = fopen("../data/data.csv", "r"); // this one is used to read content

    FILE* lineCounter = fopen("../data/data.csv", "r"); // this one is used to evaluate the length of each line

    // test files opened correctly
    if(!contentToRead || !lineCounter){
        printf("failed to open file for reading\n");
        exit(EXIT_FAILURE);
    }

    // calculate length of line, allocate the correct length of buffer and then read content of line
    int lineNumber = 0;
    while(!feof(lineCounter)){
        int lineLength = 0;
        int done = 0;
        while(!feof(lineCounter) && !done){
            char c = fgetc(lineCounter);
            if(c == '\n'){
                done=1;
            }
            lineLength ++;
            
        }
        char* buffer = (char*) malloc(sizeof(char) * lineLength);
        fgets(buffer, lineLength, contentToRead);
        fgetc(contentToRead);
        lines[lineNumber] = buffer;
        lineNumber++;
    }

    // display and clean up the lines 
    for(int i = 0; i < lineNumber; i++ ){
        printf("%s\n", lines[i]);
        free(lines[i]);
    }

    free(lines);

    // close the files 
    fclose(contentToRead);
    fclose(lineCounter);
    
    exit(EXIT_SUCCESS);
}
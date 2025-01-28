#include <stdincludes.h>
#include "contentreader.h"

int main(){
    char rootdir[1024] = {'\0'};  
    chdir("../");
    getcwd(rootdir, sizeof(rootdir));
    
    if(strlen(rootdir) == 0){
        printf("failed to get current working directory!\n");
        exit(EXIT_FAILURE);
    }
    // now we want to access the targetdir directory
    const char* target = "/targetdir";
    char* fullpath = (char*) malloc(sizeof(char) * (strlen(rootdir) + 11));
    
    strcpy(fullpath, rootdir);
    strcat(fullpath, target);

    printf("directory = '%s'\n", fullpath);

    struct DirectoryContent content = {0};

    int readResult = readDirectoryContents(fullpath, &content, USE_DIRECTORY_SIZE);
    switch(readResult){
        case NOT_FOUND:
            printf("unable to find find target\n");
            break;
        case NOT_DIRECTORY:
            printf("not a directory\n");
            break;
        case UNABLE_TOOPEN_DIRECTORY:
            printf("unable to open target\n");
            break;
        default:
            printContents(&content);

    }
    freeContent(&content);

    free(fullpath);
    
    if(readResult == READ_SUCCESS)
        exit(EXIT_SUCCESS);
    exit(EXIT_FAILURE);
}
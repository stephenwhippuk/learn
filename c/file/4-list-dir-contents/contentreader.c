#include <stdincludes.h>
#include "contentreader.h"

int readDirectoryContents(char* path, struct DirectoryContent* content, int maxLen){
  
    struct stat statBuf = {0};
    int statSuccess = stat(path, &statBuf) == 0;
    if(!statSuccess){
        printf("unable to find find target\n");
        return 1;
    }
    if( !S_ISDIR(statBuf.st_mode) ){
        printf("not a directory\n");
        return 2;
    }

    DIR *dir = NULL;
    dir = opendir(path);
    if(!dir){
        printf("unable to open target\n");
        return 3;
    }

    // now we need to get the contents of the directory
    statBuf = (const struct stat){0};
    struct dirent *dirp = {0};
    int numberOfFilesToRead = 0;
    if(maxLen == USE_DIRECTORY_SIZE){
        struct dirent *counter = {0};
        DIR * counterDir = opendir(path);
        while((counter = readdir(counterDir)) != NULL){
            numberOfFilesToRead++;
        }
        closedir(counterDir);
    }
    else{
        numberOfFilesToRead = maxLen;
    }

    content->content = (char**) malloc(sizeof(char*) * numberOfFilesToRead);
    int index = 0;
    while((dirp = readdir(dir)) != NULL && index < numberOfFilesToRead ){
        int bufLength = strlen(dirp->d_name);
        char* name = (char*) malloc(sizeof(char) * bufLength);
        strcpy(name, dirp->d_name);
        content->content[index] = name;    
        index++;
    }
    content->size = index;
    closedir(dir);
    return 0;
}

void printContents(struct DirectoryContent* content){
    int index = 0;
    printf(".\n..\n");
    while(index < content->size){
        if(strcmp(content->content[index], ".") != 0 && strcmp(content->content[index], "..") != 0)
            printf("%s\n", content->content[index]);
        index++;
    }
}

void freeContent(struct DirectoryContent* content){
    for (int i = 0 ; i < content->size; i++){
        free(content->content[i]);
    }
    free(content->content);
}
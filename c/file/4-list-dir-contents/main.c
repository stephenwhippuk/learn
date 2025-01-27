#include <stdincludes.h>

struct DirectoryContent {
    int size;
    char** content;
};

int readDirectoryContents(char* path, struct DirectoryContent* content, int maxLen){
    content->content = (char**) malloc(sizeof(char*) * maxLen);
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
    int index = 0;
    while((dirp = readdir(dir)) != NULL && index < maxLen ){
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
    int readResult = readDirectoryContents(fullpath, &content, 10);
    switch(readResult){
        case 1:
            printf("unable to find find target\n");
            break;
        case 2:
            printf("not a directory\n");
            break;
        case 3:
            printf("unable to open target\n");
            break;
        default:
            printContents(&content);

    }
    freeContent(&content);

    free(fullpath);
    
    if(readResult == 0)
        exit(EXIT_SUCCESS);
    exit(EXIT_FAILURE);
}
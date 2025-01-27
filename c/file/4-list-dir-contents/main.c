#include <stdincludes.h>

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

    // test if it is a directory
    struct stat statBuf = {0};
    int statSuccess = stat(fullpath, &statBuf) == 0;
    if(!statSuccess){
        printf("unable to find find target\n");
        exit(EXIT_FAILURE);
    }
    if( !S_ISDIR(statBuf.st_mode) ){
        printf("not a directory\n");
        exit(EXIT_FAILURE);
    }

    DIR *dir = NULL;
    dir = opendir(fullpath);
    if(!dir){
        printf("unable to open target\n");
        exit(EXIT_FAILURE);
    }

    // now we need to get the contents of the directory
    statBuf = (const struct stat){0};
    struct dirent *dirp = {0};
    printf(".\n..\n");
    while((dirp = readdir(dir)) != NULL){
        if(strcmp(dirp->d_name, ".") != 0 && strcmp(dirp->d_name, "..") != 0 ){

            printf("%s\t%c\n", dirp->d_name, dirp->d_type);
        }
    }

    closedir(dir);
    free(fullpath);
    exit(EXIT_SUCCESS);
}
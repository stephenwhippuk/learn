#include <stdincludes.h>
#include "delete.h"

void unwind(DIR* folder){
    closedir(folder);
    chdir("..");
}

int doCheckPermissions(const char* dirName){
      DIR* folder = opendir(dirName);
    if(!folder){
        return CANNOT_OPEN_FOLDER;
    }
    chdir(dirName);
    struct dirent* dirptr = NULL;
    struct stat statBuf = {0};
    while((dirptr = readdir(folder)) != NULL){
        if(strcmp(dirptr->d_name, "..") == 0 || strcmp(dirptr->d_name, ".") == 0){
            continue;
        }
        if(stat(dirptr->d_name, &statBuf) == 0){
            if(S_ISDIR(statBuf.st_mode)){
                int status = doCheckPermissions(dirptr->d_name);
                if(status != SUCCESS){
                    unwind(folder);
                    return status;
                }
            }
            if(!(statBuf.st_mode & S_IWUSR)){
                unwind(folder);
                return ACCESSS_VIOLATION;
            }
        }
        else{
            unwind(folder);
            return CANNOT_FETCH_STAT;
        }
    }
    unwind(folder);
    return 0;
}



int doDelete(const char* dirName){
    DIR* folder = opendir(dirName);
    if(!folder){
        return CANNOT_OPEN_FOLDER;
    }
    chdir(dirName);
    struct dirent* dirptr = NULL;
    struct stat statBuf = {0};
    while((dirptr = readdir(folder)) != NULL){
        if(strcmp(dirptr->d_name, "..") == 0 || strcmp(dirptr->d_name, ".") == 0){
            continue;
        }
        if(stat(dirptr->d_name, &statBuf) == 0){
            if(S_ISDIR(statBuf.st_mode)){
                int status = doDelete(dirptr->d_name);
                if(status != SUCCESS){
                    unwind(folder);
                    return status;
                }
            }
            remove(dirptr->d_name);
        }
        else{
            unwind(folder);
            return CANNOT_FETCH_STAT;
        }
    }
    unwind(folder);
    return 0;
}


int recursiveDelete(const char* path){
    
    int check =doCheckPermissions(path);
    if(check){
        return check;
    }
    return doDelete(path);
}
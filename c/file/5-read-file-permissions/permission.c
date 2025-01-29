#include <stdincludes.h>
#include "permission.h"


void writeFLag(char* buffer, int flag, char* symbol){
    if(flag){
        strcat(buffer, symbol);
    }
    else{
        strcat(buffer, "-");
    }
}

int getPermissions(const char* path, char* buffer, int bufferSize){
    if(bufferSize < 10){
        return BUFFER_TO_SMALL;
    }
    struct stat statBuf = (const struct stat){0};
    int statResult = stat(path, &statBuf) != 0;
    if(statResult){
        return ERROR_READING_FILE;
    }
    // CUrrent User
    writeFLag(buffer, statBuf.st_mode & S_IRUSR, "r");
    writeFLag(buffer, statBuf.st_mode & S_IWUSR, "w");
    writeFLag(buffer,  statBuf.st_mode & S_IXUSR, "x");

    // GROUP
    writeFLag(buffer, statBuf.st_mode & S_IRGRP, "r");
    writeFLag(buffer, statBuf.st_mode & S_IWGRP, "w");
    writeFLag(buffer,  statBuf.st_mode & S_IXGRP, "x");

    // OTHER USERS
    writeFLag(buffer, statBuf.st_mode & S_IROTH, "r");
    writeFLag(buffer, statBuf.st_mode & S_IWOTH, "w");
    writeFLag(buffer,  statBuf.st_mode & S_IXOTH, "x");

    return OPERATION_SUCCESS;
}
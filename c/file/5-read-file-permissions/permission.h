#ifndef _PERMISSION
#define _PERMISSION

#define OPERATION_SUCCESS 0
#define ERROR_READING_FILE 1
#define BUFFER_TO_SMALL 2

int getPermissions(const char* path, char* buffer, int bufferSize);

#endif
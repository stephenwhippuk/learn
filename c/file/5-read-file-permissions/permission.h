#ifndef _PERMISSION
#define _PERMISSION

#define OPERATION_SUCCESS 0
#define ERROR_READING_FILE 1

int getPermissions(const char* path, char* output);

#endif
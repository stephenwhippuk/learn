#ifndef _DELETE
#define _DELETE

#define SUCCESS 0
#define CANNOT_OPEN_FOLDER 1
#define CANNOT_FETCH_STAT 2
#define ACCESSS_VIOLATION 3

int recursiveDelete(const char* path);

#endif
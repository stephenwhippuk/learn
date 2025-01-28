#ifndef _CONTENT_READER
#define _CONTENT_READER

#define USE_DIRECTORY_SIZE -1

#define READ_SUCCESS 0
#define NOT_FOUND 1
#define NOT_DIRECTORY 2
#define UNABLE_TOOPEN_DIRECTORY 3

struct DirectoryContent {
    int size;
    char** content;
};

int readDirectoryContents(char* path, struct DirectoryContent* content, int maxLen);
void printContents(struct DirectoryContent* content);
void freeContent(struct DirectoryContent* content);

#endif
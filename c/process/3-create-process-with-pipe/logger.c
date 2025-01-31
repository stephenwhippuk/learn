#include <stdincludes.h>
int main(){

    int done = 0;
    char buffer[1024];
    while(!done){
        read(STDIN_FILENO, buffer, 1024);
        if(strcmp(buffer, "quit") == 0){
            done = 1;

        }
        else{
            fprintf(stderr, "log : %s", buffer);
        }
        write(STDOUT_FILENO, &done, sizeof(int));
    }

    exit(EXIT_SUCCESS);
}
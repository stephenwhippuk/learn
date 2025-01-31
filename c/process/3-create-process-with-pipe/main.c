#include <stdincludes.h>

int main(){
    int fd[2];
    pipe(fd);
    __pid_t pid = fork();
    if(pid == 0){
        dup2(fd[0], STDIN_FILENO);
        dup2(fd[1], STDOUT_FILENO);
        close(fd[0]);
        close(fd[1]);
        execl("logger", "logger", NULL);
    }
    else{
        char input[30] = {0};
        int done = 0;
        while(!done){
            printf("please enter command\n");
            scanf("%s", input);
            write(fd[1], input, strlen(input));
            read(fd[0], &done, sizeof(int));
        }
        close(fd[0]);
        close(fd[1]);
    }

}
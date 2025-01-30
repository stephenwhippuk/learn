#include <stdincludes.h>

int main(){
    int x[10] = {0,1,2,3,4,5,6,7,8,9};
    int startIndex = 0, endIndex = 4;
    __pid_t pid = fork();
    if(!pid){
        // child process
        startIndex = 5;
        endIndex = 9;
    }
    for(int i = startIndex; i <= endIndex; i++){
        printf("process %d : %d\n", pid, x[i]);
    }
    exit(EXIT_SUCCESS);
}
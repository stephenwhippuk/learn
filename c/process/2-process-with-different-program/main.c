#include <stdincludes.h>

int main(){
    execl("./hello", "hello", NULL);
    exit(EXIT_SUCCESS);
}
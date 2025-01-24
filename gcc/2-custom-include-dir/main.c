#include <stdlib.h>
#include <stdio.h>
#include <custom.h>

int main(){

    struct Custom cust;
    cust.v1 = 10;
    cust.v2 = 20;

    printf("data = { v1 : %d, v2 : %d}\n", cust.v1, cust.v2);

    return EXIT_SUCCESS;
}
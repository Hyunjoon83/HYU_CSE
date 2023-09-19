#include <stdio.h>
#include <stdlib.h>

int binary(int n){
    if(n>1)
        binary(n/2);
    printf("%d",n%2);
}

int main(void){
    int num;
    scanf("%d",&num);
    binary(num);

    return 0;
}

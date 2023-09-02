#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int* pi=&n;
    
    printf("%d\n",n);
    (*pi)+=10;
    printf("%d\n",n);
    return 0;
}
#include <stdio.h>

int main(){
    int i;
    double d;
    char c;

    int* pi=&i;
    double* pd=&d;
    char* pc=&c;

    scanf("%d %lf %c",&i,&d,&c);
    printf("i: %i, %p\n",i,pi);
    printf("d: %f, %p\n",d,pd);
    printf("c: %c, %p\n",c,pc);
    printf("\n");

    (*pi)+=1;
    (*pd)+=1.0;
    (*pc)+=1;
    
    printf("i+1: %i\n",i);
    printf("d+1: %f\n",d);
    printf("c+1: %c\n",c);
    printf("\n");

    printf("size of pi: %d\n",sizeof(pi));
    printf("size of pd: %d\n",sizeof(pd));
    printf("size of pc: %d\n",sizeof(pc));
}
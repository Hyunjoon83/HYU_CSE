#include <stdio.h>
#include <stdlib.h>

typedef unsigned char *pointer;

void show_bytes(pointer start, size_t len){
    size_t i;
    for(i=0;i<len;i++)
        printf("%p\t%.2x\n",start+i,start[i]);
    printf("\n");
}

int main(void){
    int val=15213;
    show_bytes((pointer)&val, sizeof(int));
    return 0;
}

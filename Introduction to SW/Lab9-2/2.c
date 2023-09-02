#include <stdio.h>

int main(){
    int num[5];
    int* a=num;
    int* b=num+4;
    scanf("%d %d %d %d %d",a ,a+1,a+2,a+3,a+4);
    while(a<b){
        int tmp=*a;
        *a=*b;
        *b=tmp;
        a++;b--;
    }
    for(a=num;a<num+5;a++){
        printf("%d ",*a);
    }
    printf("\n");
    return 0;
}
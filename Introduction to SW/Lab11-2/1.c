#include <stdio.h>

void getSumDiff(int a, int b, int* pSum, int *pDiff){
    *pSum=a+b;
    *pDiff=a-b;
}

int main(){
    int a,b,sum,diff;
    int* ptrS=&sum;
    int* ptrD=&diff;
    scanf("%d %d",&a,&b);
    getSumDiff(a,b,ptrS,ptrD);
    printf("sum: %d\n",sum);
    printf("diff: %d\n",diff);
    return 0;
}
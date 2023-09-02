#include <stdio.h>

int addTotal(int n){
    if(n>0){
        return n + addTotal(n-1);
    }else if(n==0){
        return 0;
    }
}
int gMul=1;
void mulTotal(int n){
    if (n > 0) {
        gMul *= n;
        mulTotal(n-1);
    }
}

int main(){
    int num;
    scanf("%d",&num);
    printf("addTotal(): %d\n",addTotal(num));
    mulTotal(num);
    printf("gMul: %d",gMul);
    return 0;
}
#include <stdio.h>

int recur(int n){
    if(n>0){
        return n + recur(n-1);
    }else if(n==0){
        return 0;
    }
}

int main(){
    int num;
    scanf("%d",&num);
    printf("%d\n",recur(num));
}
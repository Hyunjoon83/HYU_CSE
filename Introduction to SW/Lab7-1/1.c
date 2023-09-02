#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    if(n<-10){
        printf("n<-10");
    }
    else if(n>=-10&&n<0){
        printf("-10<=n<0");
    }
    else if(n>=0&&n<10){
        printf("0<=n<10");
    }
    else{
        printf("n>=10");
    }
    return 0;
}
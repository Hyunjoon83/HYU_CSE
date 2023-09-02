#include <stdio.h>

long long int combi(int n,int r){
    long long int a = 1;
    long long int b = 1;
    for(int i=0;i<r;i++){
        a*=(n-i);
        b*=(i+1);
    }// {n!/((n-r)!*r!)}
    return a/b;
}
int main(){
    int N,R;
    scanf("%d %d",&N,&R);
    printf("%lld\n",combi(N,R));
    return 0;
}
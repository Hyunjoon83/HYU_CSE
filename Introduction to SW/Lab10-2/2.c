#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    char str[9];
    scanf("%s",str);
    int n=strlen(str);
    int isPalin=1;

    if(n>=10){
        return 0;
    }
    for(int i=0;i<n;i++){
        if(tolower(str[i])!=tolower(str[n-i-1])){
            isPalin=0;
            break;
        }
    }
    if(isPalin==0){
        printf("This is not a palindrome\n");
    }else{
        printf("This is a palindrome\n");
    }
    return 0;
}
#include <stdio.h>
#include <string.h>

int main(){
    char word[10];
    scanf("%s",word);
    int n=strlen(word);
    
    for(int i=0;i<n;i++){
        int count=0;
        int isCounted=0;
        for(int j=i-1;j>=0; j--){
            if(word[i]==word[j]){
                isCounted=1;
                break;
            }
        }
        if(isCounted)
            continue;
        for (int j=i+1;j<n;j++) {
            if (word[i]==word[j]) {
                count++;
            }
        }
        printf("'%c' : %d\n",word[i],count+1);
    }
    return 0;
}
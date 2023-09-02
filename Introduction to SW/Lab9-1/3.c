#include <stdio.h>

int main(){
    char word[100];
    int length=0;
    scanf("%s",word);
    for(int i=0;word[length]!='\0';i++)
        length+=1;
    printf("%d\n",length);
    return 0;
}
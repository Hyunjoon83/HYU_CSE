#include <stdio.h>
#include <string.h>

#define MAX_WORDS 10
#define MAX_LENGTH 20

char name[MAX_WORDS][MAX_LENGTH];
int count=0;

void enterWord(){
    char input[MAX_LENGTH];
    int exist=0;

    while(1){
        printf("Enter a word (Enter 'end' to quit): ");
        scanf("%s",input);

        if(strcmp(input,"end")==0){
            break;
        }
        for(int i=0;i<count;i++){
            if(strcmp(name[i],input)==0){
                exist=1;
                break;
            }
            exist=0;
        }
        if(exist){
            printf("This word already exists. Please enter another word.\n");
        }else if(count==MAX_WORDS){
            break;
        }else{
            strcpy(name[count++],input);
        } 
    }
    printf("%d words in the list:\n",count);
    for(int i=0;i<count;i++){
        printf("%s ",name[i]);
    }
    printf("\n");
}
void searchWord(){
    char input[MAX_LENGTH];

    while(1){
        printf("Enter a word to search (Enter 'end' to quit): ");
        scanf("%s", input);

        if(strcmp(input,"end")==0){
            break;
        }
        int found=0;
        for(int i=0;i<count;i++) {
            if (strcmp(name[i],input)==0){
                found=1;
                break;    
            }
        }
        if(found){
            printf("This word is in the list.\n");
        }else{
            printf("This word is NOT in the list.\n");
        }
    }
}
int main(){
    enterWord();
    searchWord();
    return 0;
}
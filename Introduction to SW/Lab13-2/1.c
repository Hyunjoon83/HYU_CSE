#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 20

char** name=NULL;
int count=0;

void enterWord(){
    while(1){
        printf("Enter a word (Enter 'end' to quit): ");
        char input[MAX_LENGTH];
        scanf("%s",input);

        if(strcmp(input,"end")==0){
            break;
        }
        int exist=0;
        for(int i=0;i<count;i++){
            if(strcmp(name[i],input)==0){
                exist=1;
                break;
            }
        }
        if(exist){
            printf("This word already exists. Please enter another word.\n");
        }else{
            char** temp=(char**)malloc(sizeof(char*)*(count+1));//count의 기본값이 0이기 때문에
           
            if(temp==NULL)
                exit(1);
            for(int i=0;i<count;i++){
                temp[i]=name[i];
            }

            temp[count]=(char*)malloc(sizeof(char)*MAX_LENGTH);
            
            if(temp[count]==NULL)
                exit(1);
            strcpy(temp[count],input);
            name=temp;
            
            count++;
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
void freeMemory(){
    for(int i=0;i<count;i++){
        free(name[i]);
    }
    free(name);
}
int main(){
    enterWord();
    searchWord();
    freeMemory();
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char name[10];
    int score;
}Person;

void printScoreStars(Person* persons, int len){
    for(int i=0;i<len;i++){
        printf("%-7s",persons[i].name);
        for (int j=0;j<persons[i].score/5;j++)
            printf("*");
        printf("\n");
    }
}
int main(){
    int count=1;
    Person* persons=(Person*)malloc(sizeof(Person)*10);

    for(int i=0;i<count;i++){
        scanf("%s %d",persons[i].name,&persons[i].score);
        if(strcmp(persons[i].name,"END")==0&&persons[i].score==0){
            count--;
            break;
        }
        count++;
    }
    printScoreStars(persons,count);    
    free(persons);
    return 0;
}
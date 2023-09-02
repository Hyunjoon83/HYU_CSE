#include <stdio.h>
#include <string.h>

typedef struct{
    char name[7];
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
    Person persons[3];
    int score;
    for(int i=0;i<3;i++){
        scanf("%s %d",persons[i].name,&score);
        persons[i].score=score;
    }
    printScoreStars(persons,3);    
    return 0;
}
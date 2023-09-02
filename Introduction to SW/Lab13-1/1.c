#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int xpos;
    int ypos;
}Point;

int main(){
    Point* pp1=(Point*)malloc(sizeof(Point));
    int num1,num2;
    scanf("%d %d",&num1,&num2);
    
    pp1->xpos=num1;
    pp1->ypos=num2;

    printf("%d %d\n",num1,num2);
    
    free(pp1);
    return 0;
}
#include <stdio.h>

typedef struct{
    int xpos;
    int ypos;
}Point;

Point getScale2xPoint(const Point* p){
    Point p_new;
    p_new.xpos=p->xpos*2;
    p_new.ypos=p->ypos*2;
    return p_new;
}
int main(){
    Point x,y;
    scanf("%d %d",&x.xpos,&y.ypos);
    x=getScale2xPoint(&x);
    y=getScale2xPoint(&y);
    printf("%d %d\n",x.xpos,y.ypos);
    return 0;
}
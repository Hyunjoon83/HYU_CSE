#include <stdio.h>
#include <stdlib.h>

typedef struct _Queue{
    int size;
    int *key;
    int front;
    int rear;
    int maxSize;
}Queue;

Queue *CreateQueue(int X) {
    Queue *Q=(Queue*)malloc(sizeof(Queue));
    Q->size=0;
    Q->key=(int*)malloc(X*sizeof(int));
    Q->maxSize=X;
    Q->front=0;
    Q->rear=-1;
    return Q;
}
int IsEmpty(Queue *Q){
    return Q->size==0;
}
int IsFull(Queue *Q){
    return Q->size==Q->maxSize;
}
void Enqueue(Queue *Q, int item){
    if (IsFull(Q)){
        return;//queue가 다 차있으면 중단
    }else{
        Q->rear=(Q->rear+1)%(Q->maxSize);//queue의 크기를 넘어서는 경우 rear 포인터를 처음 위치로 돌려주기 위해 나머지 연산을 수행
        Q->key[Q->rear]=item;//rear가 가리키는 key값에 item을 할당
        Q->size=Q->size+1;//item을 queue에 Enqueue한 뒤 queue의 크기 1 증가
    }
}
int Dequeue(Queue *Q){
    if (IsEmpty(Q)){
        return -1;//queue가 비어있으면 -1을 반환  
    }else{
        int item=Q->key[Q->front];//front가 가리키는 key값을 int형의 item으로 설정    
        Q->front=(Q->front+1)%(Q->maxSize);//queue의 크기를 넘어서는 경우 front 포인터를 처음 위치로 돌려주기 위해 나머지 연산을 수행
        Q->size=Q->size-1;//Dequeue한 뒤 queue의 크기를 1만큼 감소시킴
        return item;//Dequeue한 item을 반환
    }
}

typedef struct _Graph{
    int size;
    int *vertex;
    int **edge;
}Graph;

Graph *CreateGraph(int X){
    Graph *G = (Graph*)malloc(sizeof(Graph));
    G->size=X;
    G->vertex=(int*)malloc(X*sizeof(int));
    G->edge=(int**)malloc(X*sizeof(int*));
    for (int i=0;i<X;i++) {
        G->edge[i]=(int*)malloc(X*sizeof(int));
    }
    return G;
}
void InsertEdge(Graph *G, int u, int v){
    int i,j;
    for(i=0;i<G->size;i++){
        if(G->vertex[i]==u)
            break;    
    }//size크기 만큼 Graph의 내부를 돌다가 vertex[i]와 u가 같은 지점에서 중단 
    for(j=0;j<G->size;j++){
        if(G->vertex[j]==v)
            break;
    }//size크기 만큼 Graph의 내부를 돌다가 vertex[i]와 v가 같은 지점에서 중단
    G->edge[i][j]=1;//for문을 통해 얻은 i,j에 해당하는 이차원 배열 위치에 해당하는 값을 반환
}
void checkIndegree(int* Indegree, Graph *G){
    for(int i=0;i<G->size;i++){
        Indegree[i]=0;//Indegree[i] 초기화
        for(int j=0;j<G->size;j++){
            if(G->edge[j][i]==1){
                Indegree[i]++;
            }//엣지의 방향을 역으로 확인(G->edge[j][i])하고 Indegree를 계산한 뒤, 1이면 Indegree의 값을 1만큼 증가
        }
    }
}
void Topsort(Graph *G){
    Queue *Q=CreateQueue(G->size);
    int *Indegree=(int*)malloc(sizeof(int)*G->size);
    checkIndegree(Indegree,G);   

    for(int i=0;i<G->size;i++){
        if(Indegree[i]==0)
            Enqueue(Q,i);
    }//for문을 돌면서 Indegree가 없으면 queue에 i값을 Enqueue
    //위상 정렬에서 진입차수가 0인 정점을 시작으로 정렬을 수행하기 위한 초기 설정
    while(!IsEmpty(Q)){
        int V=Dequeue(Q);//queue에서 Dequeue한 값을 int형 V에 할당
        printf("%d ",G->vertex[V]);//V에 해당하는 값을 vertex에서 찾아서 출력

        for(int y=0;y<G->size;y++){
            if(G->edge[V][y]==1){//V와 y 사이에 edge가 존재하면
                Indegree[y]--;//Indegree를 1만큼 감소
                G->edge[V][y]--;//edge의 개수 1만큼 감소
                if(Indegree[y]==0)
                    Enqueue(Q,y);//y의 Indegree의 값이 0이면 y를 queue에 Enqueue
            }
        }   
    }//queue가 비어있을때까지 반복
    printf("\n");
    free(Indegree);
}

int main(int argc, char *argv[]){
    FILE *fi=fopen(argv[1],"r");
    int X,u,v;

    fscanf(fi,"%d",&X);

    Graph *G=CreateGraph(X);

    for(int i=0; i<X; i++){
        fscanf(fi,"%d",&G->vertex[i]);
    }

    while(fscanf(fi,"%d %d",&u,&v)!=EOF){
        InsertEdge(G,u,v);
    }

    Topsort(G);
    fclose(fi);
    free(G);
    return 0;
}
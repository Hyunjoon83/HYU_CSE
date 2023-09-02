#include <stdio.h>
#include <stdlib.h>

const int INF=(int)2e9;

typedef struct Node{
    int vertex;//vertex 번호
    int dist;//거리
    int prev;//이전 노드
}Node;

typedef struct Graph{
    int size;//그래프 크기(노드의 수)
    Node* nodes;//각 노드의 정보를 담고 있는 배열
    int** matrix;//인접 행렬 표현을 저장하는 2차원 배열
}Graph;

Graph* createGraph(int X){
    Graph* G=(Graph*)malloc(sizeof(Graph));
    G->size=X;
    G->nodes=(Node*)malloc(sizeof(Node)*(X+1));//X+1개의 노드 생성
    G->matrix=(int**)malloc(sizeof(int*)*X);//X개의 행을 가지는 2차원 배열 생성
    for(int i=0;i<X;i++) {
        G->nodes[i].vertex=i+1;//노드의 vertex번호를 1번부터 설정
        G->nodes[i].dist=INF;//거리를 INF로 초기화
        G->nodes[i].prev=-1;//이전 노드의 개수=0개
        G->matrix[i]=(int*)malloc(sizeof(int)*X);
        for (int j=0;j<X;j++){
            G->matrix[i][j]=INF;//인접 행렬을 INF로 초기화
        }
    }
    return G;
}
Graph* findShortestPath(Graph* G, int s){
    G->nodes[s-1].dist=0;//제일 첫번째 노드의 거리를 0으로 초기화
    int size=G->size;
    int visited[size];//방문한 노드를 표시하기 위해 size를 index로 갖는 visited 배열을 생성
    for(int i=0;i<size;i++){
        visited[i]=0;
    }//아직 방문한 노드가 없기 때문에 모든 노드의 방문횟수를 0으로 설정

    for(int count=0;count<size-1;count++){
        int minDist=INF;//최단거리를 INF로 초기화
        int minIndex=-1;//최단거리의 index를 -1로 초기화

        for (int i=0;i<size;i++) {
            if (!visited[i]&&G->nodes[i].dist<minDist) {
                minDist=G->nodes[i].dist;
                minIndex=i;
            }//방문하지 않았고, 최소거리보다 짧다면 최소거리를 i번째 노드까지의 거리로 설정하고 minIndex를 i로 설정
        }
        visited[minIndex]=1;//방문한 노드를 1로 설정
        for (int i = 0; i < size; i++) {
            if (!visited[i]&&G->matrix[minIndex][i]!=INF&&G->nodes[minIndex].dist!=INF&&G->nodes[minIndex].dist+G->matrix[minIndex][i]<G->nodes[i].dist) {
                G->nodes[i].dist=G->nodes[minIndex].dist+G->matrix[minIndex][i];
                G->nodes[i].prev=minIndex;
            }//방문하지 않았고, minIndex 행에 있는 원소들이 INF도 아니고, 최단거리가 INF도 아니며 minIndex 노드까지의 거리와 minIndex행의 노드까지의 거리의 합이 i번째 노드까지의 거리보다 작다면
            //i번째 노드의 거리를 최단거리 및 minIndex로 설정
        }
    }
    return G;
}
void printShortestPath(Graph* G){
    int size=G->size;
    for(int i=0;i<size;i++){
        if(G->nodes[i].vertex!=1){//i번째 노드의 vertex 번호가 1이 아니고
            if(G->nodes[i].dist==INF) {//i번째 노드까지의 거리가 INF라면
                printf("%d can not be reached.\n",G->nodes[i].vertex);
            }else{
                int j=i;
                while(j!=-1) {//이전 노드가 없을 때까지 반복
                    printf("%d",G->nodes[j].vertex);
                    j=G->nodes[j].prev;//j에 j번째 노드의 이전 노드를 할당
                    if(j!=-1) {
                        printf(" <-");
                    }//이전 노드가 존재하는 경우 <- 출력
                }//이전노드를 따라가면서 최단 경로를 출력
                printf(" cost: %d\n",G->nodes[i].dist);            
            }
        }
    }
}

typedef struct Heap{
    int capacity;//힙의 전체 크기
    int size;//힙에 저장된 element의 개수
    Node** elements;//힙에 저장된 노드 요소들의 배열
}Heap;

Heap* createMinHeap(int X){
    Heap* H=(Heap*)malloc(sizeof(Heap));
    H->capacity=X;//heap의 크기를 X로 할당
    H->size=0;
    H->elements=(Node**)malloc(sizeof(Node)*(X+1));//배열의 index가 1부터 시작하기 때문에 X+1
    return H;
}
void insert(Heap* H, Node N){
    int i;
    for(i=++H->size;H->elements[i/2]->dist>N.dist&&i/2>0;i/=2){
        H->elements[i]=H->elements[i/2];
    }//노드까지의 거리가 부모 노드까지의 거리 보다 작은 동안 i를 부모 index에 업데이트
    H->elements[i]=&N;//노드의 주소를 elements 배열의 i번째 index에 저장
}
Node deleteMin(Heap* H){
    int i,Child;
    Node* MinElement,* LastElement;

    MinElement=H->elements[1];//minElement를 elements배열의 1번 index에 할당
    LastElement=H->elements[H->size--];//LastElement를 elements배열에 저장하고 힙의 크기를 감소시킴

    for(i=1;i*2<=H->size;i=Child){
        Child=i*2;//왼쪽 자식노드를 Child로 설정
        if(Child!=H->size && H->elements[Child+1]->dist<H->elements[Child]->dist)
            Child++;//오른쪽 자식 노드가 존재하고, 오른쪽 자식노드가 왼쪽 자식노드보다 작으면 Child를 왼쪽 자식에서 오른쪽 자식으로 설정
        if(LastElement > H->elements[Child])
            H->elements[i]=H->elements[Child];//LastElement가 자식노드보다 크다면 현재 위치에 자식 노드를 저장
        else
            break;
    }
    H->elements[i]=LastElement;
    return *MinElement;
}
void swap(Node** a, Node** b){
    Node* temp=*a;
    *a=*b;
    *b=temp;
}//*a와 *b가 가리키는 값을 교환
void decreaseKey(Heap* H, Node N){
    int i=0;
    while(i<H->size){
        if(H->elements[i]->vertex==N.vertex){
            H->elements[i]->dist=N.dist;//현재의 vertex와 노드의 vertex가 같으면 update
            break;
        }
        i++;
    }//요소의 개수만큼 반복
    while(i>0&&H->elements[i]->dist<H->elements[(i-1)/2]->dist)//현재 노드의 우선순위가 부모 노드의 우선순위보다 작을 때까지 반복
        swap(&H->elements[i],&H->elements[(i-1)/2]);//현재 노드와 부모 노드를 swap
        i=(i-1)/2;//상위 레벨의 노드로 이동
}
int main(int argc, char* argv[]){
    FILE *fi=fopen(argv[1],"r");
    int size;

    fscanf(fi,"%d",&size);

    Graph* G=createGraph(size);

    int node_s, node_d, weight;
    while(fscanf(fi,"%d %d %d", &node_s, &node_d, &weight)!=EOF){
        G->matrix[node_s-1][node_d-1]=weight;//노드 번호가 1번부터 시작하기 때문에 배열 index로 바꿔주기 위해 -1
    }//출발노드, 도착노드, 가중치를 입력받는 것을 파일 끝에 도달하기 전까지 반복

    G=findShortestPath(G,1);
    printShortestPath(G);

    free(G);
    return 0;
}
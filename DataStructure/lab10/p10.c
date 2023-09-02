#include <stdio.h>
#include <stdlib.h>
#include <time.h>
    
typedef struct _DisjointSet{
    int size;
    int *ptr_arr;
}DisjointSets;
typedef struct _PrintDisjointSets{
    int size;
    int *ptr_arr;
}PrintDisjointSets;
    
void init(DisjointSets *S,PrintDisjointSets *maze,int n){
    int total=n*n;
    S->size=total;
    S->ptr_arr=(int*)malloc(sizeof(int)*(total+1));

    maze->size=2*n*(n+1);
    maze->ptr_arr=(int*)malloc(sizeof(int)*(maze->size));

    for(int i=0;i<=maze->size;i++){
        if(i==n||i==2*n*(n+1)-(n+1))
            maze->ptr_arr[i]=0;
        else
            maze->ptr_arr[i]=1;
    }//입구랑 출구랑 문 열어두기
    for (int i=0;i<=total;i++){
        S->ptr_arr[i]=0;
    }//초기 상태에는 다 연결되지 않은 상태
}
int find(DisjointSets *S, int x){
    if(S->ptr_arr[x]<=0)
        return x;
    else    
        return find(S,S->ptr_arr[x]);
}//S->ptr_arr[x]<=0 : root 이면 root값을 반환, 아니면 계속 root를 찾기 (by 재귀)
void union_(DisjointSets *S, int i, int j){
    int p1=find(S,i);//p1 - S에서 i값 찾기
    int p2=find(S,j);//p2 - S에서 j값 찾기
        
    if(p1!=p2){
        if(S->ptr_arr[p2]<S->ptr_arr[p1]){
            S->ptr_arr[p1]=p2;
        }else{
            if(S->ptr_arr[p2]==S->ptr_arr[p1])
                S->ptr_arr[p1]--;
            S->ptr_arr[p2]=p1;
        }
    }//p1이랑 p2랑 다르고 p2가 가리키는 값이 p1이 가리키는 값보다 작으면 p1의 값을 p2와 연결
     //p1이랑 p2랑 다르고 p2가 가리키는 값과 p1이 가리키는 값이 같으면 p1의 index를 감소시키고 p2와 p1을 연결
}

void createMaze(DisjointSets *S,PrintDisjointSets *maze,int n){
    srand(time(NULL));
    int i;
    int skip=0;
    int last_wall=n*(2*n+1)-1;

    while(find(S,1)!=find(S,n*n)){
        skip=0;
        int wall=rand()%(2*n*(n+1));
        for(i=0;i<n;i++){
            if(wall==i||wall==(2*n+1)*n+i||wall==n+(2*n+1)*i||wall==2*n+(2*n+1)*i){
                skip=1;
                break;
            }//사각형을 구성하는 벽은 skip
        }
        if(skip==1)
            continue;//skip한 벽은 건너뛰기
        if(wall%(2*n+1)<n){//위아래 cell
            int cell1=(wall/(2*n+1)-1)*n+wall%(2*n+1)+1;
            int cell2=cell1+n;
            printf("%d\n",cell1);
            if(find(S,cell1)!=find(S,cell2)){
                union_(S,cell1,cell2);
                maze->ptr_arr[wall]=0;
            }//cell1이랑 cell2가 다르면 합친 뒤 벽을 부수기
        }else{//이웃하는 cell
            int cell1=wall/(2*n+1)*n+wall%(2*n+1)-n;
            int cell2=cell1+1;
            printf("%d\n",cell1);
            if(find(S,cell1)!=find(S,cell2)){
                union_(S,cell1,cell2);
                maze->ptr_arr[wall]=0;
            }//cell1이랑 cell2가 다르면 합친 뒤 벽을 부수기
        if(wall==last_wall)
            break;
        }//wall이 마지막에 도착하면 while문 멈추기
    }//1번 cell과 마지막 cell이 연결될 때까지 find 반복
}
void printMaze(DisjointSets *S,PrintDisjointSets *maze,int n){
    for(int i=0; i<maze->size; i++){
        if(maze->ptr_arr[i]==1){
            if(i%(2*n+1)<n){
                printf(" -");
            }else{
                printf("| ");
            }
        //벽이 있으면 가로는 -, 세로는 |로 출력
        }else{
            printf("  ");
        }//벽이 없으면 공백 출력
        if(i%(2*n+1)==n-1||i%(2*n+1)==2*n)
            printf("\n");
        //제일 오른쪽의 경우는 한칸 뛰기
    }
}
void freeMaze(DisjointSets *S,PrintDisjointSets *maze){
    free(S->ptr_arr);
    free(maze->ptr_arr);
    free(S);
    free(maze);
}//maze에 할당한 메모리 해제
int main(int argc, char* argv[]){
    int n;
    FILE *fi=fopen(argv[1],"r");
    if(fi==NULL){
        return 1;
    }
    fscanf(fi,"%d",&n);
    
    DisjointSets *S=(DisjointSets*)malloc(sizeof(DisjointSets));
    PrintDisjointSets *maze=(PrintDisjointSets*)malloc(sizeof(PrintDisjointSets));

    init(S,maze,n);
    createMaze(S,maze,n);
    printMaze(S,maze,n);
    freeMaze(S,maze);

    fclose(fi);
    return 0;
}
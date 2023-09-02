#include<stdio.h>
#include<stdlib.h>

struct TreeStruct{
    int size;
    int numOfNode;
    int* element;
};

typedef struct TreeStruct* Tree;

Tree CreateTree(int size){
    Tree tree=(Tree)malloc(sizeof(struct TreeStruct));
    tree->size=size;
    tree->numOfNode=0;
    tree->element=(int*)malloc(sizeof(int)*size);
    return tree;
}
/*Tree구조체의 동적할당(트리의 크기, 노드의 개수를 저장할 변수, 노드의 값을 저장할 배열)
int 포인터를 사용하여 주어진 크기에 맞게 초기화된 트리 반환*/
void Insert(Tree tree, int value){
    if(tree->numOfNode==tree->size){
        printf("Error! Tree is full.\n");
        return;
    }
    tree->element[++tree->numOfNode]=value;
}
/*tree의 노드개수(numOfNode)와 크기(size)를 비교하여 트리가 가득 찼는지 확인
가득찼으면 error message 출력 그렇지 않다면 노드 개수를 1만큼 증가시키고 해당 index에 값 대입
(노드의 index는 1부터 시작이므로 ++tree->numOfNode로 작성)
*/

void PrintPreorder(Tree tree, int index){
    if(index>tree->numOfNode){
        return;
    }
    printf("%d ",tree->element[index]);
    PrintPreorder(tree,index*2);
    PrintPreorder(tree,index*2+1);
}
/*현재 노드의 인덱스(index)와 트리의 노드 개수(numOfNode)를 비교하여, 인덱스가 더 크다면 (즉, 해당 인덱스에 노드가 없다면) 함수를 종료
그렇지 않은 경우, 현재 노드의 값을 출력하고, 왼쪽 자식 노드(index*2)와 오른쪽 자식 노드(index*2+1)를 순서대로 방문
함수는 재귀 호출을 사용하여, 트리의 모든 노드를 방문하고 출력
*/
void PrintInorder(Tree tree,int index){
    if(index>tree->numOfNode){
        return;
    }
    PrintInorder(tree,index*2);
    printf("%d ",tree->element[index]);
    PrintInorder(tree,index*2+1);
}
/*함수는 현재 노드의 인덱스(index)와 트리의 노드 개수(numOfNode)를 비교하여, 인덱스가 더 크다면 (즉, 해당 인덱스에 노드가 없다면) 함수를 종료
그렇지 않은 경우, 왼쪽 자식 노드(index*2)를 먼저 방문하고, 현재 노드의 값을 출력한 후, 오른쪽 자식 노드(index*2+1)를 순서대로 방문
함수는 재귀 호출을 사용하여, 트리의 모든 노드를 방문하고 출력
*/
void PrintPostorder(Tree tree, int index){
    if(index>tree->numOfNode){
        return;
    }
    PrintPostorder(tree, index*2);
    PrintPostorder(tree, index*2+1);
    printf("%d ",tree->element[index]);
}
/*함수는 현재 노드의 인덱스(index)와 트리의 노드 개수(numOfNode)를 비교하여, 인덱스가 더 크다면 (즉, 해당 인덱스에 노드가 없다면) 함수를 종료
그렇지 않은 경우, 왼쪽 자식 노드(index2)를 먼저 방문하고, 오른쪽 자식 노드(index2+1)를 순서대로 방문한 후, 현재 노드의 값을 출력
함수는 재귀 호출을 사용하여, 트리의 모든 노드를 방문하고 출력
*/
void PrintTree(Tree tree){
    printf("Preorder: ");
    PrintPreorder(tree,1);
    printf("\n");
    printf("Inorder: ");
    PrintInorder(tree,1);
    printf("\n");
    printf("Postorder: ");
    PrintPostorder(tree,1);
    printf("\n");
}
/*주어진 트리(tree)의 노드를 전위 순회(preorder traversal), 중위 순회(inorder traversal), 후위 순회(postorder traversal)하여 출력하는 함수인 PrintTree
함수는 먼저 Preorder, Inorder, Postorder 각각에 대해 printf 함수를 사용하여 각각의 순회 방법을 출력
PrintPreorder, PrintInorder, PrintPostorder 함수를 호출하여 각각의 순회 방법에 따라 트리의 노드를 출력
*/
void DeleteTree(Tree tree){
    free(tree->element);
    free(tree);
} 
/*함수는 먼저 malloc 함수를 사용하여 할당한 배열 메모리를 해제하고, 그 다음에 malloc 함수를 사용하여 할당한 트리 메모리를 해제
->트리와 관련된 모든 메모리를 해제하여 메모리 누수(memory leak)를 방지
*/

void main(int argc, char* argv[]){
    FILE *fi;
    Tree tree;
    int treeSize;
    int tmpNum;

    fi=fopen(argv[1],"r");
    fscanf(fi,"%d",&treeSize);
    tree=CreateTree(treeSize);

    while(fscanf(fi,"%d",&tmpNum)==1){
        Insert(tree, tmpNum);
    }

    PrintTree(tree);
    DeleteTree(tree);
}
/*함수는 먼저 입력 파일(argv[1])을 fopen 함수를 사용하여 읽기 모드(r)로 열고,
fscanf 함수를 사용하여 파일에서 트리의 크기(treeSize)와 노드 값을 읽어들입니다.
그리고 CreateTree 함수를 호출하여 주어진 크기(treeSize)만큼의 노드를 가진 트리를 생성
while 루프를 사용하여 파일에서 읽어들인 노드 값을 하나씩 Insert 함수를 사용하여 트리에 추가
트리에 노드를 모두 추가한 후에는, PrintTree 함수를 호출하여 전위, 중위, 후위 순회한 결과를 출력
마지막으로, DeleteTree 함수를 호출하여 메모리를 해제 

fscanf(fi,"%d",&tmpNum)==1 : 파일(fi)에서 정수 데이터를 읽어들인 후에, 성공적으로 읽어들인 데이터의 개수를 반환. 만약 반환값이 1이 아니면, 읽어들인 데이터가 없거나 혹은 읽어들이는 도중 에러가 발생했다는 의미
*/
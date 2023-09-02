#include<stdio.h>
#include<stdlib.h>

typedef struct Node* PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
typedef int ElementType;

struct Node{
    ElementType Element;
    Position Next;
};

List MakeEmptyList();
int IsLast(Position p, List l);//l에서 position p가 마지막 위치인지 확인
void Delete(ElementType x, List l);//l에서 x를 삭제
Position FindPrevious(ElementType x, List l);//l에서 x이전의 위치를 반환
Position Find(ElementType x, List l);//l에서 x의 위치를 반환
void Insert(ElementType x, Position p, List l);//l에서 p 바로 뒤에 x를 삽입
void DeleteList(List l);//l을 삭제
void PrintList(List l);//l을 print

int main(int argc, char *argv[]){

    char command;//입력 파일에서 읽은 명령어를 저장하는 변수
    int key1, key2;/*입력 파일에서 읽은 인자를 저장하는 변수
                    -key1: 삽입, 삭제, 찾기 함수에서 사용되는 값
                    -key2: 삽입 함수에서 새로운 노드를 삽입할 위치를 찾을 때 사용*/
    FILE *input, *output;
    Position header = NULL, tmp = NULL;//연결 리스트에서의 위치를 가리키는 포인터

    if(argc <=1){
        printf("Please enter an input file.\n");
        return 0;
    }
    else
        input=fopen(argv[1],"r");

    header = MakeEmptyList();
    while(1){
        command=fgetc(input);
        if(feof(input)) break;

        switch(command){
        case 'i':
            fscanf(input,"%d %d", &key1, &key2);
            tmp=Find(key2,header);//header에서 key2
            Insert(key1,tmp,header);//header의 tmp뒤에 key1 삽입
            break;
        case 'd':
            fscanf(input,"%d",&key1);
            Delete(key1,header);//header에서 key1을 삭제
            break;
        case 'f':
            fscanf(input,"%d",&key1);
            tmp=FindPrevious(key1,header);//header에서 key1 이전의 위치를 반환
            if(IsLast(tmp,header))
                printf("Could not find %d in the list.\n",key1);
                else if(tmp->Element>0)//tmp의 element값이 0보다 크면
                    printf("Key of the previous node of %d is %d.\n",key1,tmp->Element);
                else
                    printf("key of the previous node of %d is header.\n",key1);
            break;
        case 'p':
            PrintList(header);
            break;
        case '\n':
            continue;
        default:
            printf("Invalid command line\n");
        }
    }
    /*  1. case 'i': fscanf로 key1과 key2 값을 읽어들입니다. 그리고 key2를 찾아서 tmp에 저장
                     이후 Insert 함수를 호출하여 key1 값을 가지는 노드를 tmp 다음에 삽입
        2. case 'd': fscanf로 key1 값을 읽어들입니다. 이후 Delete 함수를 호출하여 key1 값을 가지는 노드를 삭제
        3. case 'f': fscanf로 key1 값을 읽어들입니다. 그리고 FindPrevious 함수를 호출하여 key1 값을 가지는 노드의 이전 노드를 찾습니다. 
                     만약 이전 노드가 없다면 해당 노드가 리스트에 존재하지 않는다는 메시지를 출력하고, 이전 노드가 존재한다면 해당 노드의 값을 출력
        4. case 'p': PrintList 함수를 호출하여 리스트의 모든 원소를 출력
        5. case '\n': 개행 문자인 경우, continue를 통해 다음 명령어를 읽어들임
        6. default: 잘못된 명령어가 입력된 경우, "Invalid command line" 메시지를 출력                 
    */
    DeleteList(header);
    fclose(input);

    return 0;  
}
List MakeEmptyList(){
    List l=(List)malloc(sizeof(struct Node));
    l->Element=-999;
    l->Next=NULL;
    return l;
}
/*먼저 리스트의 헤더 노드를 동적으로 할당하고, 이 노드의 Element 값을 -999로 초기화
Next 포인터를 NULL로 설정하여 리스트의 마지막 노드를 가리키게 합니다. 마지막으로 헤더 노드를 반환
*/
int IsLast(Position p,List l){
    Position current=l;
    while(current->Next != NULL)
        current=current->Next;
    return p == current;
}
/*먼저 리스트의 첫 번째 노드인 헤더 노드를 current에 할당
current가 NULL이 아닌 동안, current의 Next 포인터가 NULL인지 검사하여 리스트의 마지막 노드를 찾습니다.
그리고 특정 노드 p가 마지막 노드인지 검사하여 결과를 반환
*/
Position FindPrevious(ElementType x, List l){
    Position P;
    P=l;
    while(P -> Next != NULL && P -> Next -> Element != x)
        P=P->Next;

    return P;
}
/*리스트의 첫 번째 노드인 헤더 노드를 P에 할당
P가 리스트의 마지막 노드가 아니고, P의 Next 노드의 Element 값이 x가 아닐 때까지 P를 Next 노드로 이동합니다. 
그리고 찾은 이전 노드 P를 반환
*/
Position Find(ElementType x, List l){
    Position p;

    if(x==-1)
        return l;
        p=l -> Next;
        while(p != NULL && p -> Element != x)
            p = p -> Next;
        
        return p;
}
/*먼저 x가 -1인 경우, 즉 헤더 노드를 찾는 경우, 헤더 노드를 반환
그렇지 않은 경우, 리스트의 첫 번째 노드인 헤더 노드의 Next 노드를 p에 할당
p가 NULL이 아니고, p의 Element 값이 x가 아닐 때까지 p를 Next 노드로 이동
찾은 노드 p를 반환
*/
void Insert(ElementType x, Position p, List l){
    Position TmpCell;

    TmpCell = malloc(sizeof(struct Node));

    if(p==NULL){
        printf("Insertion(%d) Failed: cannot find the location to be inserted.\n",x);
        return;
    }
    TmpCell -> Element = x;
    TmpCell -> Next = p -> Next;
    p -> Next = TmpCell;
}
/* x 값을 갖는 노드를 리스트 l의 p 다음에 삽입합니다. 삽입 위치를 찾지 못했을 경우 오류 메시지를 출력하고 함수를 종료
그렇지 않은 경우, 새로운 노드 TmpCell을 동적으로 할당하고, TmpCell의 Element 멤버를 x로 초기화
TmpCell의 Next 멤버를 p 다음 노드의 포인터로 설정하고, p의 Next 포인터를 TmpCell로 설정하여 삽입을 완료
*/
void Delete(ElementType x, List l){
    Position p, TmpCell;//값이 x인 노드를 찾아서 삭제

    p=FindPrevious(x,l);//FindPrevious 함수를 사용하여 삭제 대상 노드의 이전 노드인 p를 찾음
    if(!IsLast(p,l))
    {
        TmpCell=p->Next;
        p -> Next = TmpCell -> Next;
        free(TmpCell);
    }//p가 리스트의 마지막 노드이거나, 삭제 대상 노드가 리스트에 없을 경우 오류 메시지를 출력하고 함수를 종료
    else
        printf("Deletion Failed: element %d is not in the list.\n",x);
}//그렇지 않은 경우, 삭제 대상 노드 TmpCell을 p의 다음 노드로부터 분리시키고, TmpCell을 해제하여 삭제를 완료
void PrintList(List l){
    PtrToNode tmp = NULL;
    tmp = l->Next;//리스트의 모든 노드를 출력
    if(tmp==NULL){
        printf("list is empty!\n");
        return;
    }//함수는 리스트의 첫 번째 노드를 받아와서, 첫 번째 노드가 NULL이 아니면 리스트의 모든 노드를 순회하며 각 노드의 key 값을 출력
    while(tmp != NULL){
        printf("key: %d\t", tmp->Element);
        tmp=tmp->Next;
    }//만약 리스트가 비어있다면 "list is empty!"를 출력
    printf("\n");
}
void DeleteList(List l){
    Position p =NULL, tmp = NULL;//리스트의 모든 노드를 삭제
    p=l->Next;
    l->Next=NULL;//마지막으로 리스트의 첫 번째 노드를 NULL로 바꿔줌
    while(p != NULL)
    {
        tmp=p->Next;
        free(p);
        p=tmp;
    }
}//함수는 리스트의 첫 번째 노드를 받아와서, 첫 번째 노드가 NULL이 아니면 리스트의 모든 노드를 순회하며 각 노드를 삭제하고 메모리를 해제
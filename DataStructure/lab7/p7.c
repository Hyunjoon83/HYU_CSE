#include <stdio.h>
#include <stdlib.h>

struct AVLNode;
typedef struct AVLNode *position;
typedef struct AVLNode *AVLTree;
typedef int ElementType;

struct AVLNode{
    ElementType Element;
    AVLTree Left;
    AVLTree Right;
    int Height;
};
int FindValue(position P,ElementType x){
    if(P==NULL){
        return 0;
    }else if(x==P->Element){
        return 1;
    }else if(x<P->Element){
        return FindValue(P->Left,x);
    }else if(x>P->Element){
        return FindValue(P->Right,x);
    }
}
int Height(position P){
    if(P==NULL)
        return -1;
    else
        return P->Height;
}
int Max(int a, int b){
   if(a>b){
      return a;
   }else{
      return b;
   }
}
void DeleteTree(AVLTree T){
    if(T->Left!=NULL)
        DeleteTree(T->Left);
    if(T->Right!=NULL)
        DeleteTree(T->Right);
    free(T);
}

position SingleRotateWithLeft(position K2){
    position K1;
    K1=K2->Left;

    K2->Left=K1->Right;
    K1->Right=K2;

    K2->Height=Max(Height(K2->Left),Height(K2->Right))+1;
    K1->Height=Max(Height(K1->Left),K2->Height)+1;

    return K1;
}
position SingleRotateWithRight(position K2){
    position K1;
    K1=K2->Right;

    K2->Right=K1->Left;
    K1->Left=K2;

    K2->Height=Max(Height(K2->Right),Height(K2->Left))+1;
    K1->Height=Max(Height(K1->Right),K2->Height)+1;

    return K1;
}
static position DoubleRotateWithLeft(position K3){
    K3->Left=SingleRotateWithRight(K3->Left);
    return SingleRotateWithLeft(K3);
}
static position DoubleRotateWithRight(position K3){
    K3->Right=SingleRotateWithLeft(K3->Right);
    return SingleRotateWithRight(K3);
}
void PrintInorder(position tree){
    if(tree==NULL)
        return;
    PrintInorder(tree->Left);
    printf("%d(%d) ",tree->Element,tree->Height);
    PrintInorder(tree->Right);
}
AVLTree Insert(ElementType x, AVLTree T){
    if(T==NULL){
        T=malloc(sizeof(struct AVLNode));
        if(T==NULL)
            printf("Out of space!!!");
        else
        {
            T->Element=x;
            T->Left=T->Right=NULL;
        }
    }else if(x==T->Element){
        printf("Insertion Error: %d is already in the tree!\n",x);  
    }else if(x<T->Element){
        T->Left=Insert(x,T->Left);
        if(Height(T->Left)-Height(T->Right)==2)
            if(x<T->Left->Element)
                T=SingleRotateWithLeft(T);
            else
                T=DoubleRotateWithLeft(T);
    }else if(x>T->Element){
        T->Right=Insert(x,T->Right);
        if(Height(T->Right)-Height(T->Left)==2)
            if(x>T->Right->Element)
                T=SingleRotateWithRight(T);
            else
                T=DoubleRotateWithRight(T);
    }
    T->Height=Max(Height(T->Left),Height(T->Right))+1;
    FindValue(T,x);
    return T;
}
int main(int argc,char **argv){
    AVLTree myTree=NULL;
    int key;

    FILE *fi=fopen(argv[1],"r");
    while(fscanf(fi,"%d",&key)!=EOF){
        myTree=Insert(key,myTree);
        PrintInorder(myTree);
        printf("\n");
    }
    fclose(fi);

    DeleteTree(myTree);
    return 0;
}
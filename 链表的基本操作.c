#include <stdio.h>
#include <stdlib.h>

#define ERROR NULL
typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

Position Find( List L, ElementType X );
List Insert( List L, ElementType X, Position P );
List Delete( List L, Position P );

int main()
{
    List L;
    ElementType X;
    Position P, tmp;
    int N;

    L = NULL;
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        L = Insert(L, X, L);
        if ( L==ERROR ) printf("Wrong Answer\n");
    }
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        P = Find(L, X);
        if ( P == ERROR )
            printf("Finding Error: %d is not in.\n", X);
        else {
            L = Delete(L, P);
            printf("%d is found and deleted.\n", X);
            if ( L==ERROR )
                printf("Wrong Answer or Empty List.\n");
        }
    }
    L = Insert(L, X, NULL);
    if ( L==ERROR ) printf("Wrong Answer\n");
    else
        printf("%d is inserted as the last element.\n", X);
    P = (Position)malloc(sizeof(struct LNode));
    tmp = Insert(L, X, P);
    if ( tmp!=ERROR ) printf("Wrong Answer\n");
    tmp = Delete(L, P);
    if ( tmp!=ERROR ) printf("Wrong Answer\n");
    for ( P=L; P; P = P->Next ) printf("%d ", P->Data);
    return 0;
}

/* 你的代码将被嵌在这里 */
Position Find(List L,ElementType X)//该函数 自己 写对了 遍历查找 
    {
        while(L)
        {
            if(L->Data==X)
            {
                return L;
            }
            L=L->Next;
        }
        return ERROR;
    }
List Insert( List L, ElementType X, Position P )//对头指针的优化   注意如果是插在第一个结点前的特殊情况

{
    List a;
    a=(List)malloc(sizeof(List));//正确 
    a->Next=NULL;
    a->Data=X;
    Position head;
    if(P==L)
    {
      a->Next=L;
      head=a;
      return head;
    }//正确 
    head=L;
    while(L)
    {
        if(L->Next==P)
        {
        a->Next=L->Next;
        L->Next=a;
        return head;
        }
        L=L->Next;
    }
    printf("Wrong Position for Insertion");
    return ERROR;  
}//Insert函数正确 

//第二个插入函数的纠正 查看是否有代码逻辑错误 注意特殊点的插入


//大概率是Delete函数出错（Tm的原因竟然是我在Delete函数遍历的时候忘了让L=L->next)

List Delete( List L, Position P )
{
Position head=L;
if(P==L)
{
    L=L->Next;
    return L;
}

while(L)
{
    if(P==L->Next)
    {
        L->Next=P->Next;//原本是L->next->next 
        return head;
    }
    L=L->Next;
}
printf("Wrong Position for Deletion\n");
return ERROR;

}//完成链表中结点的删除操作

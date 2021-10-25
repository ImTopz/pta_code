#include <iostream>
#define MaxSize 50
using namespace std;
typedef int ElemType; 
typedef struct {    
     ElemType data[MaxSize];        //存放顺序表元素
       int length ;                    //存放顺序表的长度
}List;    
typedef List *SqList;
void CreateSqList(SqList &L,int n);
void InsertSq(SqList &L,int x) ;
void DispSqList(SqList L);

int main()
{
     int n;
    SqList L;
    cin>>n; 
    CreateSqList(L,n)  ;
     if(n>0)
    {
     cin>>n;
     InsertSq(L,n) ;
    }
     DispSqList(L);  
    
}
/* 请在这里填写答案 */
void CreateSqList(SqList &L,int n)
{
	L=new List; 
	if(n==0)
	{
		L=NULL;
		return ;
	}
	for(int i=0;i<n;i++)
	{
    cin>>L->data[i];
	L->length++;
	 }
} 
void InsertSq(SqList &L,int x)//插入函数  
{
	for(int i=0;i<L->length;i++)
	{
		if(x<L->data[i])
		{
			for(int j=L->length;j>i;j--)
			{
				L->data[j]=L->data[j-1];
			}
			L->data[i]=x;
			L->length++;
      
			return ;
		}
	}
    L->data[L->length]=x;
		L->length++;
        return ;
}

void DispSqList(SqList L)
{
	if(L==NULL)
	{
		cout<<"error"<<endl;
		return ;
	 } 
	for(int i=0;i<L->length;i++)
	{
		if(i==0)
		{
			printf("%d",L->data[i]);
		}
		else
		printf(" %d",L->data[i]);
	}
}

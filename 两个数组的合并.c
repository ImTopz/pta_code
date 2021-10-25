#include <stdio.h>
#include <stdlib.h>

void printArray(int* arr, int arr_size);          /* 打印数组,细节不表 */
void merge(int* a, int m, int* b, int n, int* c); /* 合并a和b为c */

int main(int argc, char const *argv[])
{
    int m, n, i;
    int *a, *b, *c;

    scanf("%d", &m);
    a = (int*)malloc(m * sizeof(int));
    for (i = 0; i < m; i++) {
        scanf("%d", &a[i]);
    }

    scanf("%d", &n);
    b = (int*)malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }
    c = (int*)malloc((m + n) * sizeof(int));
    merge(a, m, b, n, c);
    printArray(c, m + n);

    return 0;
}

/* 请在这里填写答案 */
void merge(int* a, int m, int* b, int n, int* c)//特殊情况就是两个元素相等的时候应该怎么处理 
{ 
    int i=0;
    int j=0;
    int k=0;
    while(i<m&&j<n)//这里表示两个数组都没有遍历结束的情况下 
    {
      if(a[i]<b[j])
      {
      	c[k++]=a[i++];
	  }
	  if(a[i]==b[j])
	  {
	  	c[k++]=a[i++];
	  	c[k++]=b[j++];
	  }
	  if(a[i]>b[j])
	  {
	  	c[k++]=b[j++];
	  }
	}
	while(i<m)
	{
		c[k++]=a[i++];
	}
	while(j<n)
	{
		c[k++]=b[j++]; 
	}
} 
void printArray(int* arr, int arr_size)
{
	for(int i=0;i<arr_size;i++)
	{
		printf("%d ",arr[i]);
	}
}

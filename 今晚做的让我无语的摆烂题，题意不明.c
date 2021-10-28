#include <stdio.h>
#include <math.h>
int main()
{
	int K,N;
	scanf("%d%d",&K,&N);
	if(N==0)
	{
		return 0;
	}
	if(N<0)
	{
		int tmp=K;
		for(int i=1;i<=-N;i++)
		{
		K=tmp;
		for(int i=1;i<=-N;i++)
		{
		  if(K<=-2147483648)
		  {
		  	return 0;
		  }
		 
		 else if(i==1)
		  {
		  	K=K+N+1;
		  	printf("%d",K);
		  	K+=1;
		  }
		  else{
		  printf(" %d",K);
		  K+=1;
		  }
		}
		}
	}
	if(N>0)
	{
		int tmp=K;
		int flag=0;
		for(int i=1;i<=N;i++)
		{
			
			if(K>=2147483647)
			{
				flag++;
			}
			K+=i; 
		}
		K=tmp;
		if(flag!=0)
		{
			return 0;
		}
		else
		{
		
		for(int i=1;i<=N;i++)
		{
		  if(i==1)
		  {
		  	printf("%d",K);
		  	K+=1;
		  }
		  else{
		  printf(" %d",K);
		  K+=1;
		  }
		}
		}
	}
}

#include<stdio.h>
#include<stdlib.h>

int IsObstacle(int x,int y,int Cx,int Cy);
int Abs(int m);

int main()
{
	unsigned long int *p;
	int m, n, x, y;
	scanf("%d %d %d %d",&m,&n,&x,&y);
	p = (unsigned long int*)malloc(sizeof(unsigned long int) * (m+1) * (n+1));
	
	for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(IsObstacle(i,j,x,y))
			{
				*(p + i*(n+1)+j) = 0;
			}
			else if(i==0 && j==0)
			{
				*(p + i*(n+1)+j) = 1;
			}
			else if(i==0)
			{
				*(p + i*(n+1)+j) = *(p + i*(n+1)+(j-1));
			}
			else if(j==0)
			{
				*(p + i*(n+1)+j) = *(p + (i-1)*(n+1)+j);
			}
			else
			{
				*(p + i*(n+1)+j) = *(p + (i-1)*(n+1)+j) + *(p + i*(n+1)+(j-1));
			}
			printf("%8lu",*(p + i*(n+1)+j));
		}
		printf("\n");
	}
	
	printf("%lu",*(p + (m+1)*(n+1)-1));
		
	return 0;
}

int IsObstacle(int x,int y,int Cx,int Cy)
{
	if(Abs(Cx - x)+Abs(Cy - y) == 3)
	{
		if((Cx != x) && (Cy != y))
		{
			return 1;
		}
	}
	else if((Cx == x) && (Cy == y))
	{
		return 1;
	}
	
	return 0;	
}

int Abs(int m)
{
	return m>0?m:-m;
}

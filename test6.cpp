#include<stdio.h>

int main()
{
	int x,y,i,j;
	printf("Length : ", y);
	scanf("%d", &y);
	printf("\nWidth : ", x);
	scanf("%d", &x);
	printf("\n");
	for(i=1;i<=x;i++)
	{
		for(j=1;j<=y;j++)
		{
			if(i==1 || j==1 || i==x || j==y)
			{
				printf("*");
			}
			else
			{
				printf("*");
			}
		}
		printf("\n");
	}
	return 0;
}

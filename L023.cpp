#include<stdio.h>
int main()
{
	int x,y,z;
	printf("Enter number : ");
	scanf("%d",&z);
	for(x=1;x<=z;x++)
	{
		for(y=1;y<=z;y++)
		{
			if(x==1 || x==z || y==1 || y==z)
			{
				printf("*");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}

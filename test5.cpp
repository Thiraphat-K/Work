#include<stdio.h>

int main()
{
	int sum=0;
	printf("sum of num < 1000 : ");
	for(int x=3;x<1000;x++)
	{
		if(x%3==0 || x%5==0)
		{
			sum=sum+x;
			if(x!=3)
			{
				printf(" + %d", x);
			}
			else
			{
				printf("%d", x);
			}
		}

	}
	printf("\nsum = %d", sum);
	return 0;
}

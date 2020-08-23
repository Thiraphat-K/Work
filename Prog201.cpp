#include<stdio.h>

int main()
{
	int i,a,sum;
	printf("Enter number : ");
	scanf("%d", &i);
	sum=0;
	for(a=1;a<=i;a++)
	{
		sum=sum+a;
	}
	printf("Summary from 1 to %d : %d", i, sum);
	return 0;
}

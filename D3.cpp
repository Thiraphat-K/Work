#include<stdio.h>

int main()
{
	int a,b,minus1,minus2;
	printf("Input 1st num : ");
	scanf("%d", &a);
	printf("\nInput 2nd num : ");
	scanf("%d", &b);
	if(a>b)
	{
		minus1 = a-b;
		printf("\n Solution is %d ", minus1);
	}
	else
	{
		minus2 = b-a;
		printf("\n Solution is %d ", minus2);
	}
	return 0;
}

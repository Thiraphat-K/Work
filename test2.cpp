#include<stdio.h>

int main()
{
    int a,b,c;
    printf("enter num : ");
    scanf("%d", &a);
    for(b=0;b<=a;b++)
    {
    	for(c=a-b;c>0;c--)
    	{
        	printf("*");
    	}
    	printf("\n");
	}
    return 0;
}

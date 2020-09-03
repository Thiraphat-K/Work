#include<stdio.h>

int main()
{
	int a,b,c;
	scanf("%d%d%d", &a, &b, &c);
	if(a>=65 && a<90)
	{
		printf("\n%c  %c  %c", a, b, c);
	}
	else printf("\nplease input a number between 65 to 90");
	return 0;
}

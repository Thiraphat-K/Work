#include<stdio.h>

int main()
{
	char y[100];
	scanf("%s", y);
	int x = 0;
	while ( y[x] != '\0')
	{
		if (y[x] != y[x+1])
		{
			printf("%c", y[x]);
		}
		x++;
	}
	return 0;
}

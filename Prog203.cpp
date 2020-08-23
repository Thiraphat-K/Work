#include<stdio.h>

int main()
{
	int i,j;
	printf("Enter number : ");
	scanf("%d", &i);
	printf("\nFactoring Result %d : ", i);
	if(i!=1)
		{
			for(j=2;j<=i;)
				{
					if(i%j==0)
					{
						i=i/j;
						printf("%d ", j);
						if(i!=1)
						{
							printf("x ");
						}
						j=2;
					}
					else j++;
				}
		}
	else printf("%d", i);
	return 0;
}

#include<stdio.h>

int main()
{
long long int lm;
scanf("%lld" , &lm);
int a=1, b=1,sum=0, h;
if(lm % 2 != 0)
    {
        printf("Please put event num");
    }
else if(lm/2 <= 1)
    {
        printf("put num > 2");
    }
else
{
    while (b<lm)
    {
        if(b % 2==0)
        {
            sum = sum+b;
        }
        h=a+b;
        a=b;
        b=h;
    }
    printf("%lld" , sum);
}
return 0;
}
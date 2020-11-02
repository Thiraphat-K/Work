#include<stdio.h>

int main()
{
long long int lm;
scanf("%d" , &lm);
int a=1, b=1,sum=0, h;
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

return 0;
}
#include<stdio.h>
void fib(int*);
void getInt(int*);

int main()
{
int lm[100];
int* Plm = lm;
getInt(Plm);
fib(Plm);
return 0;
}

void fib(int*Plm)
{
    int a=1, b=1,sum=0, h;
    if(*Plm % 2 != 0)
    {
        printf("Please put event num");
    }
else if(*Plm /2 <= 1)
    {
        printf("put num > 2");
    }
else
{
    while (b < *Plm)
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
}

void getInt(int *Pln)
{
    scanf("%d",Pln);
}
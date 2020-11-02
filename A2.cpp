#include<stdio.h>

int main()
{
    long long int n = 600851475143;
    int ln = 0;
    for(int i=2;n!=1;++i)
    {
        while ( n%i==0 )
        {
            n/=i;
            ln=i;
        }
        
    }
    printf("%lld" , ln);
}
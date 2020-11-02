#include<stdio.h>

int main()
{
    long long int n;
    scanf("%lld" ,&n);
    int ln = 0;
    if(n>1000000000)
    {
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
    else{
        printf("Be put num > 1 billion");
    }
    
    return 0;
}
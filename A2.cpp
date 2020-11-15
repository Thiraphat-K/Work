#include<stdio.h>
void lpn(int*);
void getInt(int*);

int main()
{
    int n[100];
    int *pn = n;
    getInt(pn);
    lpn(pn);
    return 0;
}

void lpn(int*pn)
{
    int ln = 0;
    if(*pn <= 4000000000 && *pn > 1000000)
    {
        for(int i=2;*pn!=1;i++)
        {
            while ( *pn%i==0 )
            {
                *pn/=i;
                ln=i;
            }
        }
        printf("%d" , ln);
    }
    else if(*pn < 1000000){
        printf("Be put num > 1 million");
    }
    else{
        printf("Be put num < 4 billion");
    }
}

void getInt(int *pm)
{
    scanf("%d",pm);
}
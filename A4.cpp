#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void getInt(int*);
void Pnt(int*);

int main() {
    int n[1000];
    int *Pn=n;
    getInt(Pn);
    Pnt(Pn);
    return 0;
}

void Pnt(int*Pn)
{
    double n = 3.0, p, d;
    int s, np = 1;
      do {
         s = 1;
         d = 2.0; 
            do {
               if (!(n - trunc(n/d)*d)) s = 0;
               d += 1.0;
            } while (s && d < n/2);
         if (s) np++; 
         n += 1.0;
      } while (np < *Pn);
    if(*Pn >= 1000 && *Pn <= 1000000000)
        printf("Prime Num at %d point : %.0f\n",*Pn, n-1.0);
    else
    {
        printf("Put num >= 1000 & <= 1000000000");
    }
    
}

void getInt(int*Pmn)
{
    printf("Put num : ");
    scanf("%d", Pmn);
}
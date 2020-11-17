#include<stdio.h>
int rPld(int n);

int main()
{
  int largePld ;
  int x = 999, y, dy;
  while(x>=100)
  {
    if(x % 11 == 0)
    {
      y = 999;
      dy = 1;
    }
    else
    {
      y = 990;
      dy = 11;
    }
    while(y>=x)
    {
      if(x*y <= largePld)
      {
        break;
      }
      if(x*y == rPld(x*y))
      {
        largePld = x*y;
      }
      y = y-dy;
    }
    x = x-1;
  }
  printf("%d" , largePld);
  return 0;
}

int rPld(int n)
{
  int rPld = 0;
  while(n>0)
  {
    rPld = (10*rPld) + (n%10);
    n = n/10;
  }
  return rPld;
}
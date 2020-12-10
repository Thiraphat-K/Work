//???sec
// #include <stdio.h>

// int len(long long int n)  {
//      int s=0;
//      while(n)  s++,n/=10;
//      return s;
// }

// int main()  {

//     int ct,L,i;
//     long long int first=10000000000000LL,last=10*first-1;
//     long long int total=0,up,up2,pre,x,y,n,p10[20];
//     n=first;
//     p10[0]=1;
//     for(i=1;i<20;i++)  p10[i]=10*p10[i-1];

//     while(n<=last)  {
//          // L=len(n);
//          L=14;
//          if(L%2)  x=2*p10[(L-1)/2];
//          else     x=7*p10[(L-2)/2];
//          up=last;
//          ct=0;
//          while(1)  {
//               ct++;
//               pre=x;
//               y=(x+((n+x-1)/x))/2;
//               up2=((n+x-1)/x)*x;
//               if(up2<up)  up=up2;
//               x=y;
//               if(x==pre)  break;
//          }
//          total+=ct*(up-n+1);
//          n=up+1;
//     }
//     printf("%.10lf\n",(double) total/(9*first));
//     return 0;
// }

//2sec
#include<stdio.h>
#include<stdlib.h>

long long count_iters(long long start, long long end, long long x) {
  long long iters = end-start+1, k = ((start-1)/x) + 1;
  if (x%2 == k%2) ++k;
  long long curr=k*x, y=(k+x)/2;
  while (true) {
    if (curr >= end) return iters + (x==y?0:count_iters(start,end,y));
    if (x != y) iters += count_iters(start,curr,y);
    start = curr + 1;
    curr += 2*x;
    y = ((((start-1)/x)+1) + x)/2;
  }
}

int main(void) {
  long long n = 10000000000000LL;
  long long total_iters = count_iters(n,10*n-1,7000000LL);
  printf("%.010f\n",(double)total_iters/(double)(9*n));
  return 0;
}
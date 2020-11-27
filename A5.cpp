#include <stdio.h>
void getipn(int*);

int sqr(int x) {
  return x * x;
}

int p_find_trip(int final_sum) {
  for (int a = 1; a < final_sum; a++) {
    for (int b = 1; b < final_sum; b++) {
      if(a<b){
      for (int c = 1; c < final_sum; c++) {
        if (sqr(a) + sqr (b) == sqr(c) && (a+b+c) == final_sum) {
            int d = a*b*c;
            printf("%d %d %d %d\n", a, b, c, d);
        }
      }
      }
    }
  }
  return 0;
}

int main() {
    int ip[100];
    int* ipp = ip;
    getipn(ipp);
    return p_find_trip(*ipp);
}

void getipn(int* ipn)
{
  scanf("%d", ipn);
}
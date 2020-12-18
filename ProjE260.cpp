// #include <stdio.h>
// #define n 1001
// #define hash(x,y) ((x)*n+(y))
// //#define hash(x,y) (((x)<<10)+(y))
// char // hashtables
//   hx[hash(n,0)], // one pile changes 
//   hxy[hash(n,0)], // two piles change 
//   hxyz[hash(n,0)]; // all piles change

// int main() {
//   int i,x,y,z,xx,yy,zz;
//   char *h1,*h2,*h3,*h4,*h5,*h6,*h7;
//   long long int s=0,c=0;

//   for (i=0;i<n*n;i++)
//     hx[i]=hxy[i]=hxyz[i]=0;
  
//   for (x=0,xx=0; x<n; x++,xx+=n) {
//     for (y=x,yy=xx,h1=hx+xx+y; y<n; y++,yy+=n,h1++) {
//       if (*h1/*hx[hash(x,y)]*/) continue;
//       for (z=y,zz=yy; z<n; z++,zz+=n) {
//         if (*(h6=hxy+xx+z-y)/*hxy[hash(x,z-y)]*/
//           ||*(h7=hxyz+yy-xx+z-x)/*hxyz[hash(y-x,z-x)]*/
//           ||*(h3=hx+yy+z)/*hx[hash(y,z)]*/
//           ||*(h2=hx+xx+z)/*hx[hash(x,z)]*/
//           ||*(h5=hxy+yy+z-x)/*hxy[hash(y,z-x)]*/
//           ||*(h4=hxy+zz+y-x)/*hxy[hash(z,y-x)]*/
//         ) continue;
//         c++;
//         s+=(x+y+z);
//         *h1=1;
//         *h2=1;
//         *h3=1;
//         *h4=1;
//         *h5=1;
//         *h6=1;
//         *h7=1;
//         break;
//       }
//     }
//   }
//   printf("c=%lld, s=%lld\n",c,s);
// }

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

long p260(int N) {
	typedef unsigned char elemtype;
	 long size = N+1;
	int sz = sizeof(elemtype);

	elemtype (*foundlosses)[size] = (elemtype (*)[size]) calloc(size*size, sz);
	elemtype (*lossesfromdelt)[size] = (elemtype (*)[size]) calloc(size*size, sz);
	elemtype (*lossesfromtridelt)[size] = (elemtype (*)[size]) calloc(size*size, sz);
	elemtype *isdelt = (elemtype*)calloc(size, sz);

    long answer = 0;
    for (int a=0; a<size; a++) {
    	for (int n=0; n<size-a; n++) {
    		isdelt[n] = 1;
    	}
    	if (a%50==0) {
            printf(".");
            fflush(stdout);
    	}

        for (int b=a; b<size; b++) {
            if (foundlosses[a][b])
                continue;
            for (int c=b; c<size; c++) {
                int delt = c-b;
                if (!isdelt[delt] ||
                	lossesfromtridelt[b-a][c-b] ||
                	lossesfromdelt[c-b][a] ||
                	foundlosses[b][c] ||
                	foundlosses[a][c] ||
                	lossesfromdelt[b-a][c] ||
                	lossesfromdelt[c-a][b])
                        continue;
                foundlosses[a][b] = 1;
                foundlosses[a][c] = 1;
                foundlosses[b][c] = 1;
                lossesfromdelt[b-a][c] = 1;
                lossesfromdelt[c-a][b] = 1;
                lossesfromtridelt[b-a][c-b] = 1;
                answer+= a+b+c;
                isdelt[delt] = 0;
                break;
            }
        }
    }
    printf("\n");

    return answer;
}


int main() {
	const int N=1000;
	clock_t begin = clock();
	long result = p260(N);
	clock_t end = clock();
	printf("\n%5d: Result is %ld in %f seconds\n", N, result, (double)(end-begin)/CLOCKS_PER_SEC);
}
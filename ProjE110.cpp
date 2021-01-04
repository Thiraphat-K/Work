#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int p[15] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
int t = 0;
long long mn = 614889782588491410LL;

void dfs(long long n, int now, int cnt, int pp){
	if(now == 15) return;
	if((cnt>>1)+1 > 4000000){
//		printf("%d: %I64d\n", ++t, n);
		if(mn > n){
			mn = n;
		}
		return;
	}
	int tp = 0;
	int np = 0;
	while(1){
		++np;
		if(np > pp) return;
		n *= p[now];
		if(n >= mn) return;
		if(n > 0) dfs(n, now+1, cnt*(((++tp)<<1)+1), np);
	}
}

int main(int argc, char **argv) {
//	freopen("out", "w", stdout);
	dfs(1LL, 0, 1, 20);
	printf("%I64d\n", mn);
	
	return 0;
}
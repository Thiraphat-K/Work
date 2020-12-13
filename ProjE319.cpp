// #include <vector>
// #include <list>
// #include <map>
// #include <set>
// #include <queue>
// #include <deque>
// #include <stack>
// #include <bitset>
// #include <algorithm>
// #include <functional>
// #include <numeric>
// #include <utility>
// #include <sstream>
// #include <iostream>
// #include <iomanip>
// #include <cstdio>
// #include <cmath>
// #include <cstdlib>
// #include <ctime>
// #include <cstring>
// #include <cassert>
// #if __cplusplus > 201103L
// #include <initializer_list>
// #include <unordered_map>
// #include <unordered_set>
// #endif

// using namespace std;

// #ifndef ONLINE_JUDGE
// #define DEBUG
// #endif

// #define inf 0x3F3F3F3F
// #define fst first
// #define snd second
// #define PB push_back
// #define SZ(x) (int)((x).size())
// #define ALL(x) (x).begin(), (x).end()
// #define FOR(i, a, b) for (int _end_ = (b), i = (a); i <= _end_; ++i)
// #define ROF(i, a, b) for (int _end_ = (b), i = (a); i >= _end_; --i)

// typedef unsigned int uint;
// typedef long long int64;
// typedef unsigned long long uint64;
// typedef long double real;

// int64 fpm(int64 b, int64 e, int64 m) { int64 t = 1; for (; e; e >>= 1, b = b * b % m) e & 1 ? t = t * b % m : 0; return t; }
// template<class T> inline bool chkmin(T &a, T b) {return a > b ? a = b, true : false;}
// template<class T> inline bool chkmax(T &a, T b) {return a < b ? a = b, true : false;}
// template<class T> inline T sqr(T x) {return x * x;}
// template <typename T> T gcd(T x, T y) {for (T t; x; ) t = x, x = y % x, y = t; return y; }

// template<class edge> struct Graph {
//     vector<vector<edge> > adj;
//     Graph(int n) {adj.clear(); adj.resize(n + 5);}
//     Graph() {adj.clear(); }
//     void resize(int n) {adj.resize(n + 5); }
//     void add(int s, edge e){adj[s].push_back(e);}
//     void del(int s, edge e) {adj[s].erase(find(iter(adj[s]), e)); }
//     vector<edge>& operator [](int t) {return adj[t];}
// };

// const int64 N = 1e10;
// const int64 MOD = 1e9;

// const double eps = 1e-10;

// int Q[200], T[200];
// int cnt = 0;

// void show() {
//     int x = 0;
//     for (int i = 1; i <= N; ++i)
//         x += Q[i] != T[i];
//     if (x != 1) {
//         for (int i = 1; i <= N; ++i)
//             cout << T[i] << " ";
//         cout << endl;
//         for (int i = 1; i <= N; ++i)
//             cout << Q[i] << " ";
//         cout << endl;
//         cout << endl;
//     }
// }

// void dfs(double L, double R, int n) {
//     if (n == N + 1) {
//         // if (cnt) show();
//         for (int i = 1; i <= N; ++i)
//             T[i] = Q[i];
//         ++cnt;
//         // for (int i = 1; i < n; ++i)
//         //     for (int j = 1; j < n; ++j)
//         //         if (pow(Q[i], j) >= pow(Q[j] + 1, i))
//         //             cout << i << " " << j << endl, assert(0);
//         return ;
//     }
//     double lo = pow(L, n) + eps, hi = pow(R, n) - eps;
//     for (int x = lo; x < hi; ++x) {
//         Q[n] = x;
//         dfs(max(L, pow(x, 1.0 / n)), min(R, pow(x + 1, 1.0 / n)), n + 1);
//     }
// }

// const int LMT = 1e7;

// map<int64, int64> f;
// int prime[LMT + 1], mu[LMT + 1];

// int64 premiu(int64 n) {
//     if (n <= LMT) return mu[n];
//     if (f.count(n)) return f[n];
//     int64 &ret = f[n];
//     ret = 1;
//     for (int64 i = 2, j; i <= n; i = j) {
//         j = n / (n / i) + 1;
//         ret += MOD - (j - i) * premiu(n / i);
//     }
//     return ret %= MOD;
// }

// typedef int64 mat[2][2];

// mat A, B, C;

// void matmul(mat a, mat b, mat c) {
//     mat t;
//     memset(t, 0, sizeof(mat));
//     for (int i = 0; i < 2; ++i)
//         for (int j = 0; j < 2; ++j)
//             for (int k = 0; k < 2; ++k)
//                 (t[i][k] += a[i][j] * b[j][k] % MOD) %= MOD;
//     memcpy(c, t, sizeof(mat));
// }

// int64 G(int v, int64 x) {
//     A[0][0] = v, A[0][1] = 1;
//     A[1][0] = 0, A[1][1] = 1;
//     memset(B, 0, sizeof(B)), B[0][0] = B[1][1] = 1;
//     for (; x; x >>= 1, matmul(A, A, A))
//         x & 1 ? matmul(B, A, B), 0 : 0;
//     return v * B[0][1] % MOD;
// }

// int64 g(int64 x) {
//     return (G(3, x) - G(2, x) + MOD) % MOD;
// }

// int main(int argc, char **argv) {
//     ios_base::sync_with_stdio(false);
//     // dfs(2, 3, 1);
//     // cout << cnt << endl;

//     for (int i = 2; i <= LMT; ++i) {
//         if (!prime[i]) prime[++prime[0]] = i, mu[i] = -1;
//         for (int j = 1, k = LMT / i, t; prime[j] <= k; ++j) {
//             prime[t = i * prime[j]] = 1;
//             if (i % prime[j]) mu[t] = -mu[i];
//             else {mu[t] = 0; break; }
//         }
//     }
//     mu[1] = 1;
//     for (int i = 1; i <= LMT; ++i)
//         (mu[i] += mu[i - 1] + MOD) %= MOD;

//     int64 ans = 0, lx = 0;
//     for (int64 i = 1, j; i <= N; i = j) {
//         j = N / (N / i) + 1;
//         int64 t = premiu(j - 1);
//         ans += (t - lx + MOD) * g(N / i) % MOD;
//         lx = t;
//         // cout << i << endl;
//     }
//     cout << ans % MOD << endl;
//     return 0; 
// }

//--------------------------------------------------------------------------------------//

#include<stdio.h>
#define I __int64
#define MD 1000000000
#define REC 100000000
#define N 10000000000LL
I c;
I ipow(I x,I k){
//(x^k)%c
	if(!k)return 1;
	x%=c;
	if(k&1)return (x*ipow(x,k-1))%c;
	else return ipow((x*x)%c,k>>1);
}
I sum_32(I n){
//sum{3^i-2^i,i=1..n}=1/2*(3^(n+1)-2^(n+2)+1)
	c=MD*2; //for the 1/2
	I ret=ipow(3,n+1)-ipow(2,n+2)+1;
	return ((ret%c+c)/2)%MD;
}
I record_t[REC];
I sum_d(I n){
//t(n)=sum{d(i), i=1..n}
//    =sum{3^i-2^i, i=1..n}-sum{t(n/i), i=2..n}
	if(n<REC&&record_t[n]>=0)return record_t[n];
	I left=sum_32(n),right=(n-n/2)%MD;
	I i;
	for(i=2;i*i<=n;i++){
		right=(right+sum_d(n/i))%MD;
		if(i<n/i)
			right=(right+sum_d(i)*((n/i-n/(i+1))%MD))%MD;
	}
	I ret=(left-right+MD)%MD;
	if(n<REC)return record_t[n]=ret;
	return ret;
}
int main(){
	I i;
	for(i=0;i<REC;i++)record_t[i]=-1;
	record_t[0]=0;
	record_t[1]=1;
	record_t[2]=5;
	printf("%I64d\n",sum_d(N));
	getchar();
	return 0;
}
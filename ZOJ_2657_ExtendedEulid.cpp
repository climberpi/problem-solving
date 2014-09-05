#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;

#define LL long long
LL d, x, y;

void gcd(LL a, LL b, LL& d, LL& x, LL& y){
    if(!b){d = a; x = 1; y = 0;}
    else { gcd(b, a%b, d, y, x); y -= x*(a/b); }
}

LL mod(LL a, LL n) {
    return a < 0 ? a%n+n : a%n;
}

int main() {
   LL X, Y, M, N, L;
   while(scanf("%lld%lld%lld%lld%lld", &X, &Y, &M, &N, &L) == 5) {
       LL a, b = L, c;
       if(M > N) a = M-N, c = mod(Y-X, L);
       else a = N-M, c = mod(X-Y, L);
       gcd(a, b, d, x, y);
       //printf("##%lld %lld %lld %lld %lld\n", a, b, d, x, y);
       if(c % d || M == N) {
           printf("Pat\n");
           continue;
       }
       printf("%lld\n", mod(x*c/d, b/d));
   }
   return 0;
}

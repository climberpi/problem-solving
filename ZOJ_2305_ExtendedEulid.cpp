#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;

#define LL long long
LL d, x, y;

void gcd(LL a, LL b, LL& d, LL& x, LL& y) {
    if(!b) {d = a; x = 1; y = 0;}
    else {gcd(b, a%b, d, y, x); y -= x*(a/b); }
}

int main() {
    LL A, B, C, k;
    while(scanf("%lld%lld%lld%lld", &A, &B, &C, &k) && (A||B||C||k)) {
        gcd(C, 1LL<<k, d, x, y);
        LL Right = B-A;//(B-A<0 ? B-A+(1LL<<k) : B-A);
        if (Right % d) {
            printf("FOREVER\n");
            continue;
        }
        //printf("(%lld, %lld) %lld %lld\n", x, y, Right, d);
        //printf("%lld\n", (x*(Right/d) % (1<<k) + (1<<k)) % ((1<<k) / d));
        LL n = 1LL<<k;
        printf("%lld\n", (x*(Right/d) % n+n) % (n/d));
    }
    return 0;
}

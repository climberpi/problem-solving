#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define lowbit(k) ((k)&(-(k)))
#define LL long long
#define CLR(c) memset((c), 0, sizeof(c))

const int MAXn = 100000 + 5, MAXm = 20000 + 5;

int C[MAXn], A[MAXm], c[MAXm], d[MAXm];

int query(int k) {
    int ans = 0;
    for(; k; k -= lowbit(k)) ans += C[k];
    return ans;
}

void change(int k, int v) {
    for(; k <= 100000; k += lowbit(k)) C[k] += v;
}

int main() {
    int T;
    scanf("%d", &T);
    while(T --) {
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) scanf("%d", &A[i]);

        CLR(C), CLR(c); 
        for(int i = 1; i <= n; i++) {
            c[i] = query(A[i]);
            change(A[i], 1);
        }
        CLR(C), CLR(d);
        for(int i = n; i > 0; i--) {
            d[i] = query(A[i]);
            change(A[i], 1);
        }

        LL ans = 0;
        for(int i = 1; i <= n; i++)
            ans += (LL)c[i]*(n-i-d[i]) + (LL)(i-1-c[i])*d[i];
        printf("%lld\n", ans);
        
    }
    return 0;
}

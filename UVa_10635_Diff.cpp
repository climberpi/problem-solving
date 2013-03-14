//UVa 10635, Prince and Princess
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXn = 62500 + 5, INF = ~0U>>1;

int Cnt[MAXn], A[MAXn], f[MAXn], g[MAXn];

int main() {
    int T;
    scanf("%d", &T);
    for(int kase = 1; kase <= T; kase ++) {
        int n = 0, N, p, q, x;
        scanf("%d%d%d", &N, &p, &q);
        p++, q++;
        memset(Cnt, 0, sizeof(Cnt));
        for(int i = 1; i <= p; i++) {
            scanf("%d", &x);
            Cnt[x] = i;
        }
        for(int i = 1; i <= q; i++) {
            scanf("%d", &x);
            if(Cnt[x]) A[++n] = Cnt[x];
        }

        for(int i = 1; i <= n; i++) g[i] = INF;
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            int k = lower_bound(g+1, g+n+1, A[i]) - g;
            f[i] = k;
            g[k] = A[i];
            ans = max(ans, f[i]);
        }
        printf("Case %d: %d\n", kase, ans);
    }
    return 0;
}

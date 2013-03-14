#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXn = 16, MAXm = 100 + 5;

int A[MAXn], sum[1<<MAXn];
bool f[1<<MAXn][MAXm], vis[1<<MAXn][MAXm];

int bitcount(int S) {return !S ? 0 : (S&1) + bitcount(S/2);}

bool dp(int S, int x) {
    if(vis[S][x]) return f[S][x];
    vis[S][x] = 1;
    bool& ans = f[S][x];

    if(bitcount(S) == 1) return ans = 1;
    
    int y = sum[S]/x;
    for(int S0 = (S-1)&S; S0; S0 = (S0-1)&S) {
        int S1 = S^S0;
        if(sum[S0]%x==0&&dp(S0, min(x, sum[S0]/x))&&dp(S1, min(x, sum[S1]/x))) return ans = 1;
        if(sum[S0]%y==0&&dp(S0, min(y, sum[S0]/y))&&dp(S1, min(y, sum[S1]/y))) return ans = 1;
    }

    return ans = 0;
}

int main() {
    int kase = 0, n;
    while(scanf("%d", &n) == 1 && n) {
        int x, y, ALL = (1<<n)-1;
        scanf("%d%d", &x, &y);
        for(int i = 0; i < n; i++) scanf("%d", &A[i]);
        for(int S = 0; S < (1<<n); S++) {
            sum[S] = 0;
            for(int i = 0; i < n; i++) if(S & (1<<i)) sum[S] += A[i];
        }

        memset(vis, 0, sizeof(vis));
        printf("Case %d: %s\n", ++kase, (x*y != sum[ALL]||!dp(ALL, min(x, y))) ? "No" : "Yes");
    }
    return 0;
}

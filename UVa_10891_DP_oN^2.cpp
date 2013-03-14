#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXn = 100 + 5, INF = ~0U>>1;

int d[MAXn][MAXn], s[MAXn], n;
bool vis[MAXn][MAXn];

int dp(int i, int j) {
    if(vis[i][j]) return d[i][j];
    vis[i][j] = 1;
    d[i][j] = 0;
    for(int k = i; k <= j; k++) d[i][j] = min(d[i][j], min(dp(k, j), dp(i, k)));
    return d[i][j] = s[j]-s[i-1] - d[i][j];
}

int main() {
    while(scanf("%d", &n) == 1 && n) {
        s[0] = 0;
        int x;
        for(int i = 1; i <= n; i++)
            scanf("%d", &x),
            s[i] = s[i-1] + x;
        memset(vis, 0, sizeof(vis));
        printf("%d\n", 2*dp(1, n) - s[n]);
    }
}

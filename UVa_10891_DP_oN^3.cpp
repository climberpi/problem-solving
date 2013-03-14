#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXn = 100 + 5, INF = ~0U>>1;

int d[MAXn][MAXn], f[MAXn][MAXn], g[MAXn][MAXn], s[MAXn], n;

int main() {
    while(scanf("%d", &n) == 1 && n) {
        s[0] = 0;
        int x;
        for(int i = 1; i <= n; i++)
            scanf("%d", &x),
            s[i] = s[i-1] + x,
            f[i][i-1] = g[i+1][i] = INF;
        for(int l = 0; l < n; l++)
            for(int i = 1; i+l <= n; i++) {
                int j = i + l;
                d[i][j] = s[j] - s[i-1] - min(0, min(f[i+1][j], g[i][j-1]));
                f[i][j] = min(f[i+1][j], d[i][j]);
                g[i][j] = min(g[i][j-1], d[i][j]);
            }
        printf("%d\n", 2*d[1][n] - s[n]);
    }
}

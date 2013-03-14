#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXn = 300+5, INF = ~0U>>1;
int f[MAXn][MAXn], s[MAXn];

int main() {
    int n;
    while(scanf("%d", &n) == 1 && n) {
        for(int i = 1; i <= n; i++) 
            for(int j = 1; j <= n; j++)
                f[i][j] = INF;
        s[0] = f[n+1][n] = 0;
        for(int i = 1; i <= n; i++)
            scanf("%d", &f[i][i]),
            s[i] = s[i-1] + f[i][i],
            f[i][i-1] = 0;
        for(int l = 1; l < n; l++)
            for(int i = 1; i+l <= n; i++) {
                int j = i+l;
                for(int k = i; k <= j; k++)
                    f[i][j] = min(f[i][j], f[i][k-1] + f[k+1][j] + s[j] - s[i-1]);
            }
        printf("%d\n", f[1][n] - s[n]);
    }
    return 0;
}

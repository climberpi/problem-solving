#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define REP(i, n) for(int i = 1; i <= (n); i++)

const int MAXn = 2000 + 5;

bool G[MAXn][MAXn];
int f[MAXn][MAXn];

int main() {
    int m, n;
    while(scanf("%d%d", &m, &n) == 2 && m && n) {
       int ans = 0, x;
       REP(i, m) REP(j, n) { 
           scanf("%d", &x);
           G[i][j] = x;
       }
       memset(f, 0, sizeof(f));
       REP(i, m) REP(j, n) if(G[i][j]) {
           f[i][j] = min(min(f[i-1][j], f[i][j-1]), f[i-1][j-1]) + 1;
           ans = max(ans, f[i][j]);
       }
       printf("%d\n", ans);
    } 
    return 0;
}

//UVa 103, Stacking Boxes
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define REP(i, n) for(int i = 1; i <= (n); i++)
#define FOR(i, n) for(int i = 0; i < (n); i++)
const int MAXn = 35;

int f[MAXn], size[MAXn][15], p[MAXn], n;
bool G[MAXn][MAXn];

int dfs(int k) {
    if(f[k] == -1) {
        f[k] = 0;
        REP(i, n) if(G[k][i])
            f[k] = max(f[k], dfs(i));
        f[k]++;
    }
    return f[k];
}

void print(int k, int d) {
    p[d] = k;
    if(f[k] == 1) return;
    REP(i, n) if(G[k][i] && f[k] == f[i]+1) {
        print(i, d+1);
        return;
    }
}

int main() {
    int d;
    while(scanf("%d%d", &n, &d) == 2) {
        REP(i, n) {
            FOR(j, d) scanf("%d", &size[i][j]);
            sort(size[i], size[i]+d);
        }
        REP(i, n) REP(j, n) {
            bool flag = 1;
            FOR(k, d) if(size[i][k] <= size[j][k]) {
                flag = 0;
                break;
            }
            G[i][j] = flag;
        }

        memset(f, -1, sizeof(f));
        int ans = 0, ansK;
        REP(i, n) if(dfs(i) > ans)
            ans = f[i],
            ansK = i;
        /*REP(i, n) {
            REP(j, n) printf(" (%d, %d)=%d", i, j, G[i][j]);
            printf("\n");
        }
        REP(i, n) printf(" %d", f[i]); printf("\n");*/
        printf("%d\n", ans);
        print(ansK, 1);
        bool first = 1;
        for(int i = ans; i > 0; i--)
            printf("%s%d", first ? "" : " ", p[i]),
            first = 0;
        printf("\n");
    }
    return 0;
}

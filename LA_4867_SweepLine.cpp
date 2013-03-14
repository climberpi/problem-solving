#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
#define REP(i, n) for(int i = 1; i <= (n); i++)
#define PER(i, n) for(int i = (n); i > 0; i--)
#define CLR(c) memset(c, 0, sizeof(c))

const int MAXn = 2000 + 5;

int left[MAXn], right[MAXn], up[MAXn];
bool G[MAXn][MAXn];

int main() {
    int m, n;
    while(scanf("%d%d", &m, &n) == 2 && m && n) {
        int ans = 0;
        REP(i, m) REP(j, n) scanf("%d", &G[i][j]);
        CLR(up); CLR(left); REP(j, n) right[j] = n+1;
        REP(i, m) {
            int lo = 0, ro = n+1;
            REP(j, n) if(G[i][j]) 
                up[j] = up[j] + 1,
                left[j] = max(left[j], lo+1);
            else
                lo = j,
                up[j] = left[j] = 0;
            PER(j, n) if(G[i][j]) {
                right[j] = min(right[j], ro-1);
                ans = max(ans, min(right[j]-left[j]+1, up[j]));
            }
            else
                ro = j,
                right[j] = n+1;                    
        }
        printf("%d\n", ans);
    }
    return 0;
}

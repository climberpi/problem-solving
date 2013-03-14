#include<cstdio>
#include<algorithm>
#define LL long long
#define FOR(i, s, t) for(int i = (s); i <= (t); i++)
#define expand(i, j) int j = (i); b0 = (j&1); j >>= 1; b1 = (j&1); j >>= 1; b2 = (j&1);
#define sign(b0, b1, b2) (((b0)+(b1)+(b2)) % 2 == 1 ? 1 : -1)
using namespace std;

const int MAXn = 30;
const LL INF = 1LL<<60;

LL S[MAXn][MAXn][MAXn];

int main() {
    int T;
    scanf("%d", &T);
    while(T --) {
        int X, Y, Z, b0, b1, b2;
        scanf("%d%d%d", &X, &Y, &Z);
        FOR(i, 1, X) FOR(j, 1, Y) FOR(k, 1, Z) scanf("%lld", &S[i][j][k]);
        FOR(x, 1, X) FOR(y, 1, Y) FOR(z, 1, Z) FOR(i, 1, 7) {
            expand(i, j);
            S[x][y][z] += S[x-b0][y-b1][z-b2] * sign(b0, b1, b2);
        }
        LL ans = -INF;
        FOR(x1, 1, X) FOR(x2, x1, X) FOR(y1, 1, Y) FOR(y2, y1, Y) {
            LL M = 0;
            FOR(z, 1, Z) {
                int x = x2-x1+1, y = y2-y1+1;
                LL s = 0;
                FOR(i, 0, 7) {
                    expand(i, j);
                    s -= S[x2-b0*x][y2-b1*y][z-b2*z] * sign(b0, b1, b2);
                }               
                ans = max(ans, s - M);
                M = min(M, s);
            }
        }
        printf("%lld\n", ans);
        if(T) printf("\n");
    }
    return 0;
}

#include<cstdio>
#include<cstring>
#include<algorithm>
#define LL long long
#define CLR(c) memset((c), 0, sizeof(c))
#define FOR(i, s, t) for(int i = (s); i <= (t); i++)
using namespace std;

const int MAXn = 30;
const LL INF = 1LL<<60;

LL A[MAXn][MAXn][MAXn], B[MAXn][MAXn], C[MAXn], f[MAXn];

int main() {
    int T;
    scanf("%d", &T);
    while(T --) {
        int X, Y, Z;
        scanf("%d%d%d", &X, &Y, &Z);
        FOR(x, 1, X) FOR(y, 1, Y) FOR(z, 1, Z) scanf("%lld", &A[x][y][z]);
        LL ans = -INF;
        FOR(z1, 1, Z) {
            CLR(B);
            FOR(z2, z1, Z) {
                FOR(x, 1, X) FOR(y, 1, Y) B[x][y] += A[x][y][z2];
                FOR(y1, 1, Y) {
                    CLR(C);
                    FOR(y2, y1, Y) {
                        FOR(x, 1, X) C[x] += B[x][y2];
                        f[0] = 0; FOR(i, 1, X)
                            f[i] = max(0LL, f[i-1]) + C[i],
                            ans = max(ans, f[i]);
                    }
                }
            }
        }
        printf("%lld\n", ans);
        if(T) printf("\n");
    }
    return 0;
}

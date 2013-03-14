#include<cstdio>
#include<algorithm>
#define LL long long
#define FOR(i, s, t) for(int i = (s); i <= (t); i++)
using namespace std;

const int MAXn = 30;
const LL INF = 1LL<<60;

LL S[MAXn][MAXn][MAXn];

inline void expand(int i, int& b0, int& b1, int& b2) {
    b0 = i&1, i >>= 1;
    b1 = i&1, i >>= 1;
    b2 = i&1;
}

inline int sign(int b0, int b1, int b2) {
    return (b0 + b1 + b2) % 2 == 1 ? 1 : -1;
}

inline LL sum(int x1, int x2, int y1, int y2, int z1, int z2) {
    int dx = x2-x1+1, dy = y2-y1+1, dz = z2-z1+1;
    LL s = 0;
    FOR(i, 0, 7) {
        int b0, b1, b2;
        expand(i, b0, b1, b2);
        s -= S[x2-b0*dx][y2-b1*dy][z2-b2*dz] * sign(b0, b1, b2);
    }
    return s;
}

int main() {
    int T;
    scanf("%d", &T);
    while(T --) {
        int X, Y, Z, b0, b1, b2;
        scanf("%d%d%d", &X, &Y, &Z);
        FOR(i, 1, X) FOR(j, 1, Y) FOR(k, 1, Z) scanf("%lld", &S[i][j][k]);
        FOR(x, 1, X) FOR(y, 1, Y) FOR(z, 1, Z) FOR(i, 1, 7) {
            expand(i, b0, b1, b2);
            S[x][y][z] += S[x-b0][y-b1][z-b2] * sign(b0, b1, b2);
        }
        LL ans = -INF;
        FOR(x1, 1, X) FOR(x2, x1, X) FOR(y1, 1, Y) FOR(y2, y1, Y) {
            LL M = 0;
            FOR(z, 1, Z) {
                LL s = sum(x1, x2, y1, y2, 1, z);
                ans = max(ans, s - M);
                M = min(M, s);
            }
        }
        printf("%lld\n", ans);
        if(T) printf("\n");
    }
    return 0;
}

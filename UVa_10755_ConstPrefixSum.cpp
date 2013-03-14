#include<cstdio>
#include<cstring>
#include<algorithm>
#define LL long long
#define FOR(i, s, t) for(int i = (s); i <= (t); i++)
using namespace std;

const int MAXn = 30;
const LL INF = 1LL<<60;

LL S[MAXn][MAXn][MAXn], A[MAXn][MAXn][MAXn]; 

int main() {
    int T;
    scanf("%d", &T);
    while(T --) {
        int X, Y, Z;
        scanf("%d%d%d", &X, &Y, &Z);
        memset(S, 0, sizeof(S));
        FOR(i, 1, X) FOR(j, 1, Y) FOR(k, 1, Z) 
            scanf("%lld", &A[i][j][k]),
            S[i][j][k] = A[i][j][k] + S[i-1][j][k] + S[i][j-1][k] + S[i][j][k-1] 
                         - S[i-1][j-1][k] - S[i-1][j][k-1] - S[i][j-1][k-1] + S[i-1][j-1][k-1];
        LL ans = -INF;
        FOR(x1, 1, X) FOR(x2, x1, X) FOR(y1, 1, Y) FOR(y2, y1, Y) {
            LL M = -INF;
            FOR(z, 0, Z){
                if(z) ans = max(ans, M + S[x2][y2][z]-S[x1-1][y2][z]-S[x2][y1-1][z]+S[x1-1][y1-1][z]);
                M = max(M, -S[x2][y2][z]+S[x1-1][y2][z]+S[x2][y1-1][z]-S[x1-1][y1-1][z]);
            }
        }
        printf("%lld\n", ans);
        if(T) printf("\n");
    }
    return 0;
}

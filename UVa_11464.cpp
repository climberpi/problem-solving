#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define REP(i, s, t) for(int i = (s); i <= (t); i++)

const int MAXn = 20, INF = ~0U>>1;

int A[MAXn][MAXn], B[MAXn][MAXn], n;

int check(int S) {
    memset(B, 0, sizeof(B));
    REP(i, 0, n-1) 
        if(S & (1 << i)) B[1][i+1] = 1;
        else if(A[1][i+1]) return INF;

    REP(i, 1, n-1) REP(j, 1, n) {
        B[i+1][j] = B[i][j-1]^B[i][j+1]^B[i-1][j];
        if(!B[i+1][j] && A[i+1][j]) return INF;
    }

    REP(j, 1, n) if(B[n][j-1]^B[n][j+1]^B[n-1][j]) return INF;

    int Cnt = 0;
    REP(i, 1, n) REP(j, 1, n) if(A[i][j]^B[i][j]) ++ Cnt;
    return Cnt;
}

int main(){
    int T;
    scanf("%d", &T);
    REP(Kase, 1, T) {
        int ans = INF;
        scanf("%d", &n);
        REP(i, 1, n) REP(j, 1, n) scanf("%d", &A[i][j]);
        REP(S, 0, (1<<n)-1) ans = min(ans, check(S));
        printf("Case %d: %d\n", Kase, ans == INF ? -1 : ans);
    }
    return 0;
}


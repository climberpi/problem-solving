#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define REP(i, n) for(int i = 0; i < (n); i++)
#define CLR(c, a) memset((c), (a), sizeof(c))

const int INF = 111111111;

int G[10][10], nrows, ncols, f[9][9][59049];

struct State {
    int up[9], left;

    int encode() const {
        int key = left;
        REP(i, ncols) key = key*3 + up[i];
        return key;
    }

    bool next(int row, int col, int U, int D, int L, int R, State& T) const {
        if((row == nrows-1 && D) || (col == ncols-1 && R)) return 0;

        bool must_left = col && left, must_up = row && up[col];
        if((must_left && L != left) || (!must_left && L)) return 0;
        if((must_up && U != up[col]) || (!must_up && U)) return 0;
        if(must_left && must_up && left != up[col]) return 0;

        REP(i, ncols) T.up[i] = up[i];
        T.up[col] = D, T.left = R;
        printf("(%d, %d) %d%d%d%d left:%d up:%d\n", row, col, U, D, L, R, left, up[col]);
        return 1;
    }
};

int rec(int row, int col, const State& S) {
    if(col == ncols) { col = 0; row++; }
    if(row == nrows) return 0;

    int key = S.encode();
    int& res = f[row][col][key];
    if(res >= 0) return res;
    res = INF;

    State T;
    if(G[row][col] <= 1) {
        if(S.next(row, col, 0, 0, 0, 0, T)) res = min(res, rec(row, col+1, T));
        if(!G[row][col]) for(int t = 1; t <= 2; t++) {
            if(S.next(row, col, t, t, 0, 0, T)) res = min(res, rec(row, col+1, T) + 2);
            if(S.next(row, col, t, 0, t, 0, T)) res = min(res, rec(row, col+1, T) + 2);
            if(S.next(row, col, t, 0, 0, t, T)) res = min(res, rec(row, col+1, T) + 2);
            if(S.next(row, col, 0, t, t, 0, T)) res = min(res, rec(row, col+1, T) + 2);
            if(S.next(row, col, 0, t, 0, t, T)) res = min(res, rec(row, col+1, T) + 2);
            if(S.next(row, col, 0, 0, t, t, T)) res = min(res, rec(row, col+1, T) + 2);
        }
    }
    else {
        int t = G[row][col] - 1;
        if(S.next(row, col, t, 0, 0, 0, T)) res = min(res, rec(row, col+1, T) + 1);
        if(S.next(row, col, 0, t, 0, 0, T)) res = min(res, rec(row, col+1, T) + 1);
        if(S.next(row, col, 0, 0, t, 0, T)) res = min(res, rec(row, col+1, T) + 1);
        if(S.next(row, col, 0, 0, 0, t, T)) res = min(res, rec(row, col+1, T) + 1);
    }
    return res;
}

int main() {
    freopen("out1.txt", "w", stdout);
    while(scanf("%d%d", &nrows, &ncols) == 2 && nrows && ncols) {
        REP(i, nrows) REP(j, ncols) scanf("%d", &G[i][j]);
        State S; memset(&S, 0, sizeof(S));
        CLR(f, -1);
        int ans = rec(0, 0, S);
        printf("%d\n", ans == INF ? 0 : ans/2);
    }
    return 0;
}

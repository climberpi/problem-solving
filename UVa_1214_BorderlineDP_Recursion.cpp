#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define REP(i, n) for(int i = 0; i < (n); i++)

const int INF = 111111111;

int G[10][10], nrows, ncols, f[9][9][59049], buf[15];

inline bool next(int row, int col, int U, int D, int L, int R, int S, int& T) {
    int left = S & 3, up = S >> (ncols*2);
    if((row == nrows-1 && D) || (col == ncols-1 && R)) return 0;

    bool must_left = (col && left), must_up = (row && up);
    if((must_left && L != left) || (!must_left && L)) return 0;
    if((must_up && U != up) || (!must_up && U)) return 0;
    if(must_up && must_left && left != up) return 0;

    T = (S<<2) & ((1<<(ncols*2+2))-1); //shift bit_{0,2col-1} to bit_{2,2col+1}
    T = ((T>>4)<<4) | (D<<2) | R; //add Right in bit_{0,1}, Down in bit_{2, 3}
    return 1;
}

int rec(int row, int col, int S) {
    if(col == ncols) { col = 0; row++; }
    if(row == nrows) return 0;

    int Cnt = 0, S0 = S;
    while(S0) buf[++Cnt] = S0%4, S0 /= 4;
    int key = 0;
    for(int i = Cnt; i > 0; i --) key = key*3 + buf[i];

    int& res = f[row][col][key];
    if(res >= 0) return res;
    res = INF;

    int T;
    if(G[row][col] <= 1) {
        if(next(row, col, 0, 0, 0, 0, S, T)) res = min(res, rec(row, col+1, T));
        if(!G[row][col]) for(int t = 1; t <= 2; t++) {
            if(next(row, col, t, t, 0, 0, S, T)) res = min(res, rec(row, col+1, T) + 2);
            if(next(row, col, t, 0, t, 0, S, T)) res = min(res, rec(row, col+1, T) + 2);
            if(next(row, col, t, 0, 0, t, S, T)) res = min(res, rec(row, col+1, T) + 2);
            if(next(row, col, 0, t, t, 0, S, T)) res = min(res, rec(row, col+1, T) + 2);
            if(next(row, col, 0, t, 0, t, S, T)) res = min(res, rec(row, col+1, T) + 2);
            if(next(row, col, 0, 0, t, t, S, T)) res = min(res, rec(row, col+1, T) + 2);
        }
    }
    else {
        int t = G[row][col] - 1;
        if(next(row, col, t, 0, 0, 0, S, T)) res = min(res, rec(row, col+1, T) + 1);
        if(next(row, col, 0, t, 0, 0, S, T)) res = min(res, rec(row, col+1, T) + 1);
        if(next(row, col, 0, 0, t, 0, S, T)) res = min(res, rec(row, col+1, T) + 1);
        if(next(row, col, 0, 0, 0, t, S, T)) res = min(res, rec(row, col+1, T) + 1);
    }
    return res;
}

int main() {
   while(scanf("%d%d", &nrows, &ncols) == 2 && nrows && ncols) {
        REP(i, nrows) REP(j, ncols) scanf("%d", &G[i][j]);
        memset(f, -1, sizeof(f));
        int ans = rec(0, 0, 0);
        printf("%d\n", ans == INF ? 0 : ans/2);
    }
    return 0;
}

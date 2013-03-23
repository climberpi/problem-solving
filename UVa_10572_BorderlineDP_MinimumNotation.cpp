#include<cstdio>
#include<cstring>
#include<map>
#include<algorithm>
using namespace std;
#define REP(i, n) for(int i = 0; i < (n); i++)

const char ch[] = {'o', '#'};
int ncols, nrows;
char partial[8][8], grid[8][8], sol[8][8];
bool has_sol;
map<unsigned, int> f[8][8][2];

struct State {
    char up_left, color[8], comp[8], ncomp, ncolor_comp[2];

    void normalize() {
        int rep[9];
        memset(rep, -1, sizeof(rep));
        ncomp = ncolor_comp[0] = ncolor_comp[1] = 0;
        REP(i, ncols) {
            if(rep[comp[i]] < 0)
                rep[comp[i]] = ncomp ++,
                ncolor_comp[color[i]] ++;
            comp[i] = rep[comp[i]];
        }
    }

    void merge(int x, int y) {
        if(x == y) return;
        REP(i, ncols) if(comp[i] == x) comp[i] = y;
    }

    unsigned encode() {
        unsigned key = 0;
        REP(i, ncols) key = key*16 + color[i]*8 + comp[i];
        return key;
    }
};

int rec(int row, int col, State& S, int force_color) {
    if(col == ncols) { col = 0, row++; }
    S.normalize();
    if(row == nrows) {
        if(S.ncolor_comp[0] > 1 || S.ncolor_comp[1] > 1) return 0;
        if(!has_sol) {
            has_sol = 1;
            REP(i, nrows) REP(j, ncols) sol[i][j] = grid[i][j];
        }
        return 1;
    }

    if(row > 0 && col > 0 && S.color[col] != S.color[col-1]) S.up_left = 0;

    unsigned key;
    if(force_color < 0) {
        key = S.encode();
        if(f[row][col][S.up_left].count(key)) return f[row][col][S.up_left][key];
    }

    int res = 0;
    REP(color, 2) {
        if(force_color == 1-color || partial[row][col] == ch[1-color]) continue;
        if(row && col && S.color[col-1] == color && S.up_left == color && S.color[col] == color) continue;

        State T = S;
        T.color[col] = color;
        T.up_left = S.color[col];
        T.comp[col] = (row && S.color[col] == color) ? S.comp[col] : S.ncomp;
        if(col && T.color[col-1] == color) T.merge(T.comp[col], T.comp[col-1]);

        grid[row][col] = ch[color];

        if(row && S.color[col] == 1-color) if(find(T.comp, T.comp+ncols, S.comp[col]) == T.comp+ncols) {
            if(S.ncolor_comp[1-color] > 1 || nrows - row > 2) continue;
            res += rec(row, col+1, T, color);
            continue;
        }

        res += rec(row, col+1, T, force_color);
    }

    if(force_color < 0) f[row][col][S.up_left][key] = res;
    return res;
}

int main() {
    int T;
    scanf("%d", &T);
    while(T --) {
        scanf("%d%d", &nrows, &ncols);
        REP(i, nrows) scanf("%s", partial[i]);

        State S;
        memset(&S, 0, sizeof(S));
        REP(i, 8) REP(j, 8) REP(k, 2) f[i][j][k].clear();

        has_sol = 0;
        printf("%d\n", rec(0, 0, S, -1));
        if(has_sol) {
            REP(i, nrows) {
                REP(j, ncols) putchar(sol[i][j]);
                putchar('\n');
            }
        }
        printf("\n");
    }
}


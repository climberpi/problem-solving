#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
#define REP(i, n) for(int i = 0; i < (n); i++)

const int MAXn = 4;

int left[] = {1, 5, 2, 3, 0, 4}, up[] = {3, 1, 0, 5, 4, 2}, r[MAXn], color[MAXn][6], dice[MAXn][6], dice24[24][6], n, ans;
vector<string> ID;

void trans(int* T, int* p) {
    int q[6];
    memcpy(q, p, sizeof(q));
    REP(i, 6) p[i] = T[q[i]]; //p[T[i]] = q[i];
}

void enumerate_permutations(){
    int p0[6] = {0, 1, 2, 3, 4, 5}, p[6];
    REP(i, 6) {
        memcpy(p, p0, sizeof(p0));
        switch (i){
            case 0: trans(up, p); break;
            case 1: trans(left, p); trans(up, p); break;
            case 3: trans(up, p); trans(up, p); break;
            case 4: REP(j, 3) trans(left, p); trans(up, p); break;
            case 5: REP(j, 2) trans(left, p); trans(up, p); break;
        }
        REP(j, 4) {
            memcpy(dice24[i*4+j], p, sizeof(p));
            trans(left, p);
        }
    }
}

int getID(const char* name) {
    string s(name);
    int n = ID.size();
    REP(i, n) if(ID[i] == s) return i;
    ID.push_back(s);
    return n;
}

void check() {
    int colcnt[ID.size()], Cnt = 0;
    REP(i, n) REP(j, 6) dice[i][dice24[r[i]][j]] = color[i][j];
    REP(j, 6) {
        int maxcol = 0;
        memset(colcnt, 0, sizeof(colcnt));
        REP(i, n) maxcol = max(maxcol, ++colcnt[dice[i][j]]);
        Cnt += n - maxcol;
    }
    ans = min(ans, Cnt);
}

void dfs(int d) {
    if(d == n) check();
    else REP(i, 24) {
        r[d] = i;
        dfs(d+1);
    }
}

int main(){
    char str[30];
    enumerate_permutations();
    r[0] = 0;
    while(scanf("%d", &n) == 1 && n) {
        ID.clear();
        REP(i, n) REP(j, 6) {
            scanf("%s", str);
            color[i][j] = getID(str);
        }
        ans = n*6;
        dfs(1);
        printf("%d\n", ans);
    }
    return 0;
}

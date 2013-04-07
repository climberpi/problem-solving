#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<map>
#include<string>
#include<vector>
using namespace std;
#define REP(i, n) for(int i = 1; i <= (n); i++)
#define CLR(c) memset((c), 0, sizeof(c))

const int MAXn = 2000 + 5, MAXm = 200 + 5,  Size = 50, MAXnode = 40000 + 10;

char T[MAXn][MAXn], P[MAXm][MAXm];
int n, m, x, y;
map<string, vector<int> > ms;

struct AhoCorasickAutomata {
    int ch[MAXnode][Size], f[MAXnode], val[MAXnode], last[MAXnode], Cnt, cnt[MAXn][MAXn];

    void init() { Cnt = 1; CLR(ch[0]); CLR(val), CLR(last), CLR(cnt); ms.clear(); }

    void insert(char *s, int v) {
        int u = 0, n = strlen(s);
        for(int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            if(!ch[u][c]) CLR(ch[Cnt]), val[Cnt] = 0, ch[u][c] = Cnt++;
            u = ch[u][c];
        }
        val[u] = v;
        if(!ms.count(string(s))) ms[string(s)] = vector<int>();
        ms[string(s)].push_back(v);
    }
    
    void print(int k, int i, int j) { 
        if(j) {
            int N = ms[string(P[val[j]])].size();
            for(int ii = 0; ii < N; ii++) {
                int loc = k - ms[string(P[val[j]])][ii];
                if(loc >= 0) cnt[loc+1][i-y+1]++;
            }
            print(k, i, last[j]);
        }
    }

    void find(int k, char *T) {
        int n = strlen(T), j = 0;
        for(int i = 0; i < n; i++) {
            int c = T[i] - 'a';
            j = ch[j][c];
            if(val[j]) print(k, i, j);
            else if(last[j]) print(k, i, last[j]);
        }
    }

    void getFail() {
        queue<int> q;
        f[0] = 0;
        for(int c = 0; c < Size; c++) {
            int u = ch[0][c];
            if(u) f[u] = 0, q.push(u), last[u] = 0;
        }
        while(!q.empty()) {
            int r = q.front(); q.pop();
            for(int c = 0; c < Size; c++) {
                int u = ch[r][c];
                if(!u) {ch[r][c] = ch[f[r]][c]; continue;}
                q.push(u);
                f[u] = ch[f[r]][c];
                last[u] = val[f[u]] ? f[u] : last[f[u]];
            }
        }
    }
} ac;

int main() {
    int kase;
    scanf("%d", &kase);
    while(kase --) {
        ac.init();
        scanf("%d%d", &n, &m);
        REP(i, n) scanf("%s", T[i]);
        scanf("%d%d", &x, &y);
        REP(i, x)
            scanf("%s", P[i]),
            ac.insert(P[i], i);
        ac.getFail();

        REP(i, n) ac.find(i, T[i]);

        int ans = 0;
        REP(i, n) for(int j = 0; j < m; j++)
            if(ac.cnt[i][j] == x) ans++;
        printf("%d\n", ans);
    }
}

#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
#define REP(i, n) for(int i = 1; i <= (n); i++)
#define CLR(c) memset((c), 0, sizeof(c))

const int MAXn = 500, Size = 64, MAXs = 30;
int idx[256], n;
double prob[Size];

struct AhoCorasickAutomata {
    int ch[MAXn][Size], f[MAXn], match[MAXn], Cnt;

    void init() { Cnt = 1; CLR(ch[0]); }

    void insert(char *s) {
        int u = 0, n = strlen(s);
        for(int i = 0; i < n; i++) {
            int c = idx[(int)s[i]];
            if(!ch[u][c]) CLR(ch[Cnt]), match[Cnt] = 0, ch[u][c] = Cnt++;
            u = ch[u][c];
        }
        match[u] = 1;
    }

    void getFail() {
        queue<int> q;
        f[0] = 0;
        for(int c = 0; c < Size; c++) {
            int u = ch[0][c];
            if(u) f[u] = 0, q.push(u);
        }
        while(!q.empty()) {
            int r = q.front(); q.pop();
            for(int c = 0; c < Size; c++) {
                int u = ch[r][c];
                if(!u) { ch[r][c] = ch[f[r]][c]; continue; }
                q.push(u);
                int v = f[r];
                f[u] = ch[v][c];
                match[u] |= match[f[u]];
            }
        }
    }
} ac;

bool vis[MAXn][105];
double d[MAXn][105];

double getProb(int u, int L) {
    if(!L) return 1.0;
    if(vis[u][L]) return d[u][L];
    vis[u][L] = 1;
    double &ans = d[u][L];
    ans = 0.0;
    for(int i = 0; i < n; i++) if(!ac.match[ac.ch[u][i]])
        ans += prob[i] * getProb(ac.ch[u][i], L-1);
    return ans;
}

int main() {
    int T, k, L;
    char P[MAXs][MAXs];
    scanf("%d", &T);
    REP(kase, T) {
        scanf("%d", &k);
        REP(i, k) scanf("%s", P[i]);

        char ch[9];
        scanf("%d", &n);
        REP(i, n) scanf("%s%lf", ch, &prob[i-1]), idx[(int)ch[0]] = i-1;
        
        ac.init();
        REP(i, k) ac.insert(P[i]);
        ac.getFail();

        scanf("%d", &L);
        CLR(vis);
        printf("Case #%d: %.6lf\n", kase, getProb(0, L));
    }
    return 0;
}

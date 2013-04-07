#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
#define REP(i, n) for(int i = 0; i < (n); i++)
#define CLR(c) memset((c), 0, sizeof(c))

const int MAXn = 1000 + 5, MAXm = 100 + 5, Size = 26, MAXnode = 10000 + 10;

char T[MAXn][MAXn], P[MAXm][MAXm];
int n, m, x, y, tr, repr[MAXm], next[MAXm], cnt[MAXn][MAXn];

void process_match(int pos, int v) {
    int pr = repr[v-1], c = pos-y+1;
    while(pr >= 0) {
        if(tr >= pr) cnt[tr - pr][c]++;
        pr = next[pr];
    }
}

struct AhoCorasickAutomata {
    int ch[MAXnode][Size], f[MAXnode], val[MAXnode], last[MAXnode], Cnt;

    void init() { Cnt = 1; CLR(ch[0]); }

    void insert(char *s, int v) {
        int u = 0, n = strlen(s);
        for(int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            if(!ch[u][c]) CLR(ch[Cnt]), val[ch[u][c] = Cnt++] = 0;
            u = ch[u][c];
        }
        val[u] = v;
    }

    void report(int pos, int j) {
        if(j)
            process_match(pos, val[j]),
            report(pos, last[j]);
    }

    void find(char* T) {
        int n = strlen(T), j = 0;
        REP(i, n) {
            int c = T[i] - 'a';
            j = ch[j][c];
            if(val[j]) report(i, j);
            else if(last[j]) report(i, last[j]);
        }
    }

    void getFail() {
        queue<int> q;
        f[0] = 0;
        REP(c, Size) {
            int u = ch[0][c];
            if(u) f[u] = last[u] = 0, q.push(u);
        }
        while(!q.empty()) {
            int r = q.front(); q.pop();
            REP(c, Size) {
                int u = ch[r][c];
                if(!u) { ch[r][c] = ch[f[r]][c]; continue;}
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
        scanf("%d%d", &n, &m);
        REP(i, n) scanf("%s", T[i]);
        scanf("%d%d", &x, &y);
        ac.init();
        REP(i, x) {
            scanf("%s", P[i]);
            next[repr[i] = i] = -1;
            REP(j, i) if(!strcmp(P[i], P[j])) {
                repr[i] = j;
                next[i] = next[j];
                next[j] = i;
                break;
            }
            if(repr[i] == i) ac.insert(P[i], i+1);
        }
        ac.getFail();

        CLR(cnt);
        for(tr = 0; tr < n; tr++) ac.find(T[tr]);

        int ans = 0;
        REP(i, n-x+1) REP(j, m-y+1) if(cnt[i][j] == x) ans++;
        printf("%d\n", ans);
    }
    return 0;
}

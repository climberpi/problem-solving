#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<queue>
using namespace std;
#define REP(i, n) for(int i = 1; i <= (n); i++)
#define CLR(c) memset((c), 0, sizeof(c))

const int MAXn = 11000, Size = 26, MAXS = 150+10;

map<string, int> ms;

struct AhoCorasickAutomata {
    int ch[MAXn][Size], f[MAXn], val[MAXn], last[MAXn], cnt[MAXS], Cnt;

    void init() { Cnt = 1; CLR(ch[0]), CLR(cnt); ms.clear(); }

    void insert(char *s, int v) {
        int u = 0, n = strlen(s);
        for(int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            if(!ch[u][c]) CLR(ch[Cnt]), val[Cnt] = 0, ch[u][c] = Cnt++;
            u = ch[u][c];
        }
        val[u] = v;
        ms[string(s)] = v;
    }

    void print(int j) { if(j) cnt[val[j]]++, print(last[j]); }

    void find(char *T) {
        int n = strlen(T), j = 0;
        for(int i = 0; i < n; i++) {
            int c = T[i] - 'a';
            //while(j && !ch[j][c]) j = f[j];
            j = ch[j][c];
            if(val[j]) print(j);
            else if(last[j]) print(last[j]);
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
                //if(!u) continue;
                if(!u) {ch[r][c] = ch[f[r]][c]; continue;}
                q.push(u);
                int v = f[r];
                //while(v && !ch[v][c]) v = f[v];
                f[u] = ch[v][c];
                last[u] = val[f[u]] ? f[u] : last[f[u]];
            }
        }
    }
} ac;

char text[1000001], P[151][80];
int n, T;

int main() {
    while(scanf("%d", &n) == 1 && n) {
        ac.init();
        REP(i, n)
            scanf("%s", P[i]),
            ac.insert(P[i], i);
        ac.getFail();
        scanf("%s", text);
        ac.find(text);
        int best = -1;
        REP(i, n) best = max(best, ac.cnt[i]);
        printf("%d\n", best);
        REP(i, n) if(ac.cnt[ms[string(P[i])]] == best) printf("%s\n", P[i]);
    }
    return 0;
}

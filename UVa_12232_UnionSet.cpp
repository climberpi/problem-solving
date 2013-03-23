#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define REP(i, n) for(int i = 0; i < (n); i++)

const int MAXn = 20000 + 5;

int fa[MAXn], xo[MAXn], n;

int find(int k) {
    int pref = fa[k];
    if(fa[k] != k) 
        fa[k] = find(fa[k]),
        xo[k] = xo[pref] ^ xo[k];
    return fa[k];
}

bool merge(int p, int q, int v) {
    int x = find(p), y = find(q);
    if(x != y) {
        if(x == n) swap(x, y);
        fa[x] = y;
        xo[x] = xo[p] ^ xo[q] ^ v;
    } else if((xo[p] ^ xo[q]) != v) return 0;
    return 1;
}

int K, P[20];
int query() {
    bool used[20] = {0};
    int ans = 0, pa;
    REP(i, K) {
        int Cnt = 1;
        if(used[i]) continue; used[i] = 1;
        pa = find(P[i]), ans ^= xo[P[i]];
        for(int j = i+1; j < K; j++) {
            if(used[j]) continue;
            if(find(P[j]) == pa) 
                used[j] = 1, ++Cnt, ans ^= xo[P[j]];
        }
        if(pa != n && (Cnt % 2 == 1)) return -1;
    }
    return ans;
}

int main() {
    int Q, kase = 0;
    while(scanf("%d%d", &n, &Q) == 2 && n) {
        printf("Case %d:\n", ++kase);
        int T = 1;
        REP(i, n+1) fa[i] = i;
        memset(xo, 0, sizeof(xo));

        char op[30]; 
        int p, q, v;
        bool flag = 0;
        while(Q --) {
            scanf("%s", op);
            if(op[0] == 'Q') {
                scanf("%d", &K);
                REP(i, K) scanf("%d", &P[i]);
                if(flag) continue;
                int res = query();
                if(res != -1) printf("%d\n", res);
                else printf("I don't know.\n");
            }
            else {
                fgets(op, 30, stdin);
                if(sscanf(op, "%d%d%d", &p, &q, &v) == 2) v = q, q = n;
                if(flag) continue;
                if(!merge(p, q, v)) {
                    printf("The first %d facts are conflicting.\n", T);
                    flag = 1;
                }
                ++T;
            }
        }
        printf("\n");
    }
}

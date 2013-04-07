#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define CLR(c, a) memset((c), (a), sizeof(c))
#define REP(i, n) for(int i = 1; i <= n; i++)
#define FOR(i, s, t) for(int i = (s); i <= (t); i++)
#define isdigit(ch) ('0' <= ch && ch <= '9')

const int MAXn = 1<<17, INF = ~0U>>2;

int _sum, _min, _max, op, x1, y1, x2, y2, v;

struct SegmentTree {
    int sumv[MAXn], minv[MAXn], maxv[MAXn], setv[MAXn], addv[MAXn];

    void maintain(int o, int L, int R) {
        int lc = o<<1, rc = o<<1|1;
        if(L < R) 
            sumv[o] = sumv[lc] + sumv[rc],
            minv[o] = min(minv[lc], minv[rc]),
            maxv[o] = max(maxv[lc], maxv[rc]);
        if(setv[o] >= 0) minv[o] = maxv[o] = setv[o], sumv[o] = setv[o] * (R-L+1); 
        if(addv[o]) sumv[o] += addv[o] * (R-L+1), minv[o] += addv[o], maxv[o] += addv[o];
    }

    void pushdown(int o) {
        int lc = o<<1, rc = o<<1|1;
        if(setv[o] >= 0) 
            setv[lc] = setv[rc] = setv[o], 
            addv[lc] = addv[rc] = 0,
            setv[o] = -1;
        if(addv[o]) 
            addv[lc] += addv[o],
            addv[rc] += addv[o], 
            addv[o] = 0;
    }

    void update(int o, int L, int R) {
        int lc = o<<1, rc = o<<1|1, M = L + (R-L)/2;
        if(y1 <= L && R <= y2) {
            if(op == 1) addv[o] += v;
            else addv[o] = 0, setv[o] = v;
        } else {
            pushdown(o);
            if(y1 <= M) update(lc, L, M); else maintain(lc, L, M);
            if(M < y2) update(rc, M+1, R); else maintain(rc, M+1, R);
        }
        maintain(o, L, R);
    }

    void query(int o, int L, int R, int add) {
        if(setv[o] >= 0) {
            int v = setv[o] + add + addv[o];
            _sum += v * (min(R,y2)-max(L,y1)+1);
            _min = min(_min, v);
            _max = max(_max, v);
        } else if(y1 <= L && R <= y2) {
            _sum += sumv[o] + add * (R-L+1);
            _min = min(_min, minv[o] + add);
            _max = max(_max, maxv[o] + add);
        } else {
            int M = L + (R-L)/2;
            if(y1 <= M) query(o<<1, L, M, add + addv[o]);
            if(M < y2) query(o<<1|1, M+1, R, add + addv[o]);
        }
    }
}tree[21];

int GetInt() {
    char ch = getchar(); while(!isdigit(ch)) ch = getchar();
    int x = 0; while(isdigit(ch)) x = x*10 + ch - '0', ch = getchar();
    return x;
}

void PutInt(int x) {
    int buf[20], cur = 0;
    if(!x) buf[++cur] = x;
    else while(x) buf[++cur] = x%10, x /= 10;
    for(int i = cur; i > 0; i--) putchar(buf[i] + '0');
}

int main() {
    int r, c, m;
    while(scanf("%d%d%d", &r, &c, &m) == 3) {
        CLR(tree, 0);
        REP(x, r) CLR(tree[x].setv, -1), tree[x].setv[1] = 0;
        while(m --) {
            op = GetInt(); x1 = GetInt(), y1 = GetInt(), x2 = GetInt(), y2 = GetInt();
            if(op < 3) {
                v = GetInt();
                FOR(x, x1, x2) tree[x].update(1, 1, c);
            } else {
                _sum = 0, _min = INF, _max = -INF;
                FOR(x, x1, x2) tree[x].query(1, 1, c, 0);
                PutInt(_sum), putchar(' '), PutInt(_min), putchar(' '), PutInt(_max), putchar('\n');
            }
        }
    }
    return 0;
}

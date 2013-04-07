#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define isdigit(ch) ('0' <= ch && ch <= '9')

const int MAXn = 100000 + 10, INF = ~0U>>1;

int A[1 << 17];

struct SegmentTree {
    int minv[1 << 18];

    void build(int o, int L, int R) {
        if(L != R) {
            int M = L + (R-L)/2;
            build(2*o, L, M);
            build(2*o+1, M+1, R);
            minv[o] = min(minv[2*o], minv[2*o+1]);
        } else minv[o] = A[L];
    }

    int query(int qL, int qR, int o, int L, int R) {
        int M = L + (R-L)/2, ans = INF;
        if(qL <= L && R <= qR) return minv[o];
        if(qL <= M) ans = min(ans, query(qL, qR, o*2, L, M));
        if(M < qR) ans = min(ans, query(qL, qR, o*2+1, M+1, R));
        return ans;
    }

    void update(int p, int v, int o, int L, int R) {
        if(L != R) {
            int M = L + (R-L)/2;
            if(p <= M) update(p, v, o*2, L, M);
            else update(p, v, o*2+1, M+1, R);
            minv[o] = min(minv[o*2], minv[o*2+1]);
        } else minv[o] = v;
    }
}tree;

int GetInt() {
    char ch = getchar(); while(!isdigit(ch)) ch = getchar();
    int x = 0; while(isdigit(ch)) x = x*10 + ch - '0', ch = getchar();
    return x;
}

void PutInt(int x) {
    int buf[10], cur = 0;
    if(!x) buf[++cur] = 0;
    else while(x) buf[++cur] = x%10, x /= 10;
    for(int i = cur; i > 0; i--) putchar(buf[i] + '0');
    putchar('\n');
}

int main() {
    int n, q, B[30];
    char op[50];
    while(scanf("%d%d", &n, &q) == 2 && n && q) {
        for(int i = 1; i <= n; i++) A[i] = GetInt();
        tree.build(1, 1, n);
        while(q --) {
            fgets(op, 1000, stdin);
            if(op[0] == 'q') {
                int p, q;
                sscanf(op, "query(%d,%d)", &p, &q);
                PutInt(tree.query(p, q, 1, 1, n));
            }
            else {
                int Cnt = 0;
                for(int i = 0; op[i]; )
                    if(isdigit(op[i])) {
                        int x = 0;
                        while(isdigit(op[i])) x = x*10 + op[i++] - '0';
                        B[++Cnt] = x;
                    } else ++i;
                int x = A[B[1]];
                for(int i = 1; i < Cnt; i++)
                   tree.update(B[i], A[B[i]] = A[B[i+1]], 1, 1, n);
                tree.update(B[Cnt], A[B[Cnt]] = x, 1, 1, n);
            }
        }
    }
    return 0;
}

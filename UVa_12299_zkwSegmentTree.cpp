#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define isdigit(ch) ('0' <= ch && ch <= '9')

const int MAXn = 1 << 18, INF = ~0U>>1;

int A[MAXn], N;

struct zkwSegmentTree {
    int T[MAXn*2];
    
    void build() {
        for(int i = 2*N+1; i > 0; i--)
            if(i > N) T[i] = A[i-N];
            else T[i] = min(T[i<<1], T[i<<1|1]);
    }

    int query(int s, int t) {
        int ans = INF;
        for(s = s+N-1, t = t+N+1; s^t^1; s >>= 1, t >>= 1) {
            if(~s&1) ans = min(ans, T[s^1]);
            if(t&1) ans = min(ans, T[t^1]);
        }
        return ans;
    }

    void change(int p, int v) {
        for(T[p += N] = v, p >>= 1; p; p >>= 1)
            T[p] = min(T[p<<1], T[p<<1|1]);
    }

}tree;

int GetInt() {
    char ch = getchar(); while(!isdigit(ch)) ch = getchar();
    int x = 0; while(isdigit(ch)) x = x*10 + ch - '0', ch = getchar();
    return x;
}

void PutInt(int x) {
    int buf[20], cur = 0;
    if(!x) buf[++cur] = x;
    else while(x) buf[++cur] = x%10, x /= 10;
    for(int i = cur; i > 0; i--) putchar(buf[i] + '0'); putchar('\n');
}

int main() {
    int n, q, B[30];
    char op[50];
    while(scanf("%d%d", &n, &q) == 2 && n && q) {
        N = 1; while(N <= n) N<<=1; N--; 
        for(int i = 1; i <= n; i++) A[i] = GetInt();
        for(int i = n+1; i <= N+1; i++) A[i] = INF;
        tree.build();
        while(q --) {
            fgets(op, 1000, stdin);
            if(op[0] == 'q') {
                int p, q;
                sscanf(op, "query(%d,%d)", &p, &q);
                PutInt(tree.query(p, q));
            } else {
                int Cnt = 0;
                for(int i = 0; op[i]; )
                    if(isdigit(op[i])) {
                        int x = 0;
                        while(isdigit(op[i])) x = x*10 + op[i++] - '0';
                        B[++Cnt] = x;
                    } else ++i;
                int x = A[B[1]];
                for(int i = 1; i < Cnt; i++)
                    tree.change(B[i], A[B[i]] = A[B[i+1]]);
                tree.change(B[Cnt], A[B[Cnt]] = x);
            }
        }
    }
    return 0;
}

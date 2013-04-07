#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define isdigit(ch) ('0' <= ch && ch <= '9')

struct SegmentTree {
    int sum[(1 << 17) + 1];

    void build(int o, int L, int R) {
        if(L != R) {
            int M = L + (R-L)/2;
            build(o<<1, L, M);
            build(o<<1|1, M+1, R);
            sum[o] = sum[o<<1] + sum[o<<1|1];
        } else sum[o] = 1;
    }

    int query(int k, int o, int L, int R) {
        if(L != R) {
            int M = L + (R-L)/2;
            if(k <= sum[o<<1]) return query(k, o<<1, L, M);
            else return query(k-sum[o<<1], o<<1|1, M+1, R);
        } else return L;
    }

    void update(int p,  int o, int L, int R) {
        if(L != R) {
            sum[o]--;
            int M = L + (R-L)/2;
            if(p <= M) update(p, o<<1, L, M);
            else update(p, o<<1|1, M+1, R);
        } else sum[o]--;
    }
} Tree;

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
    int T;
    T = GetInt();
    while(T --) {
        int x, n;
        n = GetInt();
        Tree.build(1, 1, n);
        for(int i = 1; i <= n; i++) {
            x = GetInt();
            if(i > 1) putchar(' ');
            int idx = Tree.query(x+1, 1, 1, n);
            PutInt(idx);
            Tree.update(idx, 1, 1, n);
        }
        putchar('\n');
    }
    return 0;
}

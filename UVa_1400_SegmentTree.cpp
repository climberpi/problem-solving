#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define LL long long
#define isdigit(ch) ('0' <= ch && ch <= '9')

const int MAXn = 500000 + 10;
typedef pair<int, int> Interval;

LL prefix_sum[MAXn];

LL sum(int L, int R) {return prefix_sum[R] - prefix_sum[L-1];}

LL sum(Interval p) {return sum(p.first, p.second);}

Interval better(Interval a, Interval b) {
    if(sum(a) != sum(b)) return sum(a) > sum(b) ? a : b;
    return a < b ? a : b;
}

int qL, qR;

struct IntervalTree {
    int max_prefix[MAXn*2], max_suffix[MAXn*2];
    Interval max_sub[MAXn*2];

    void build(int o, int L, int R) {
        if(L == R) 
            max_prefix[o] = max_suffix[o] = L,
            max_sub[o] = make_pair(L, L);
        else {
            int M = L + (R-L)/2, lc = o<<1, rc = o<<1|1;
            build(lc, L, M);
            build(rc, M+1, R);
            //choose max_prefix in its son
            LL v1 = sum(L, max_prefix[lc]), v2 = sum(L, max_prefix[rc]);
            if(v1 == v2) max_prefix[o] = min(max_prefix[lc], max_prefix[rc]);
            else max_prefix[o] = v1 > v2 ? max_prefix[lc] : max_prefix[rc];
            //choose max_suffix in its son
            v1 = sum(max_suffix[lc], R), v2 = sum(max_suffix[rc], R);
            if(v1 == v2) max_suffix[o] = min(max_suffix[lc], max_suffix[rc]);
            //Why not use the shortest prefix?
            else max_suffix[o] = v1 > v2 ? max_suffix[lc] : max_suffix[rc];
            //maintain max_sub
            max_sub[o] = better(max_sub[lc], max_sub[rc]);
            max_sub[o] = better(max_sub[o], make_pair(max_suffix[lc], max_prefix[rc]));
        }
    }

    Interval query_prefix(int o, int L, int R) {
        if(max_prefix[o] <= qR) return make_pair(L, max_prefix[o]);
        int M = L + (R-L)/2, lc = o<<1, rc = o<<1|1;
        if(qR <= M) return query_prefix(lc, L, M);
        Interval i = query_prefix(rc, M+1, R);
        i.first = L;
        return better(i, make_pair(L, max_prefix[lc]));
    }

    Interval query_suffix(int o, int L, int R) {
        if(max_suffix[o] >= qL) return make_pair(max_suffix[o], R);
        int M = L + (R-L)/2, lc = o<<1, rc = o<<1|1;
        if(qL > M) return query_suffix(rc, M+1, R);
        Interval i = query_suffix(lc, L, M);
        i.second = R;
        return better(i, make_pair(max_suffix[rc], R));
    }

    Interval query(int o, int L, int R) {
        if(qL <= L && R <= qR) return max_sub[o];
        int M = L + (R-L)/2, lc = o<<1, rc = o<<1|1;
        if(qR <= M) return query(lc, L, M);
        if(qL > M) return query(rc, M+1, R);
        Interval i1 = query_prefix(rc, M+1, R),
                 i2 = query_suffix(lc, L, M),
                 i3 = better(query(lc, L, M), query(rc, M+1, R));
        return better(make_pair(i2.first, i1.second), i3);
    }
} tree;

int GetInt() {
    char ch = getchar(); while(!(isdigit(ch) || ch == '-')) ch = getchar();
    int op = 1;
    if(ch == '-') ch = getchar(), op = -1;
    int x = 0; while(isdigit(ch)) x = x*10 + ch - '0', ch = getchar();
    return op*x;
}

void PutInt(int x) {
    int buf[20], cur = 0;
    if(!x) buf[++cur] = x;
    else while(x) buf[++cur] = x%10, x /= 10;
    for(int i = cur; i > 0; i --) putchar(buf[i] + '0');
}

int main() {
    int kase = 0, n, Q, x;
    while(scanf("%d%d", &n, &Q) == 2) {
        prefix_sum[0] = 0;
        for(int i = 1; i <= n; i++) {
            //scanf("%d", &x);
            x = GetInt();
            prefix_sum[i] = prefix_sum[i-1] + x;
        }
        tree.build(1, 1, n);
        printf("Case %d:\n", ++kase);

        while(Q --) {
            qL = GetInt(), qR = GetInt();
            Interval ans = tree.query(1, 1, n);
            PutInt(ans.first), putchar(' '), PutInt(ans.second), putchar('\n');
        }
    }
    return 0;
}

#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define LL long long

const int MAXn = 1<<19;
typedef pair<int, int> Segment;

LL prefix_sum[MAXn];
int N;

LL sum(int L, int R) { return prefix_sum[R] - prefix_sum[L-1]; }

LL sum(Segment p) { return sum(p.first, p.second); }

Segment better(Segment a, Segment b) {
    if(sum(a) != sum(b)) return sum(a) > sum(b) ? a : b;
    return a < b ? a : b;
}

struct zkwSegmengTree {
    int max_prefix[MAXn*2], max_suffix[MAXn*2];
    Segment max_sub[MAXn*2], interval[MAXn*2];

    void build() {
        for(int o = 2*N-1; o > 0; o--)
            if(o >= N) interval[o] = make_pair(o-N, o-N);
            else interval[o] = make_pair(interval[o<<1].first, interval[o<<1|1].second);
        for(int o = 2*N-1; o > 0; o--) 
            if(o >= N) {
                int L = o-N;
                max_prefix[o] = max_suffix[o] = L;
                max_sub[o] = make_pair(L, L);
            } else {
                int lc = o<<1, rc = o<<1|1, L = interval[o].first, R = interval[o].second;
                //maintain max_prefix
                LL v1 = sum(L, max_prefix[lc]), v2 = sum(L, max_prefix[rc]);
                if(v1 == v2) max_prefix[o] = min(max_prefix[lc], max_prefix[rc]);
                else max_prefix[o] = v1 > v2 ? max_prefix[lc] :  max_prefix[rc];
                //maintain max_suffix
                v1 = sum(max_suffix[lc], R), v2 = sum(max_suffix[rc], R);
                if(v1 == v2) max_suffix[o] = min(max_suffix[lc], max_suffix[rc]);
                else max_suffix[o] = v1 > v2 ? max_suffix[lc] : max_suffix[rc];
                //maintain max_sub
                max_sub[o] = better(max_sub[lc], max_sub[rc]);
                max_sub[o] = better(max_sub[o], make_pair(max_suffix[lc], max_prefix[rc]));
            }
    }

    Segment query_prefix(int o) {
        if(o >= N) return make_pair(o-N, o-N);
        int L = interval[o].first, lc = o<<1, rc = o<<1|1;
        return better(make_pair(L, max_prefix[lc]), make_pair(L, max_prefix[rc]));
    }

    Segment query_suffix(int o) {
        if(o >= N) return make_pair(o-N, o-N);
        int R = interval[o].second, lc = o<<1, rc = o<<1|1;
        return better(make_pair(max_suffix[lc], R), make_pair(max_suffix[rc], R));
    }

    inline void query_node(int o, bool& used, Segment& ans) {
        Segment res;
        if(o < N) {
            int lc = o<<1, rc = o<<1|1;
            Segment i1 = query_prefix(rc),
                    i2 = query_suffix(lc),
                    i3 = better(max_sub[lc], max_sub[rc]);
            res = better(make_pair(i2.first, i1.second), i3);
        } else res = make_pair(o-N, o-N);
        if(!used) used = 1, ans = res;
        else ans = better(ans, res);
    }

    Segment query(int s, int t) {
        Segment ans; bool used = 0;
        for(s = s+N-1, t = t+N+1; s^t^1; s >>= 1, t >>= 1) {
            printf("(%d, %d)\n", s, t);
            if(~s&1) query_node(s^1, used, ans);
            if(t&1) query_node(t^1, used, ans);
            if(s+1==t) {
                int lc = s<<1|1, rc = t<<1;
                Segment res = make_pair(query_suffix(lc).first, query_prefix(rc).second);
                printf("(%d, %d) {%d, %d}\n", ans.first, ans.second, res.first, res.second);
                if(!used) used = 1, ans = res;
                else ans = better(ans, res);
            }
        }
        return ans;
    }
}tree;

int main() {
    int kase = 0, n, Q, x;
    while(scanf("%d%d", &n, &Q) == 2) {
        N = 1; while(N < n+3) N *= 2;
        printf("[%d\n", N);
        prefix_sum[1] = 0;
        for(int i = 1; i <= n; i++) {
            scanf("%d", &x);
            prefix_sum[i+1] = prefix_sum[i] + x;
        }
        tree.build();
        printf("Case %d:\n", ++kase);

        while(Q --) {
            int p, q;
            scanf("%d%d", &p, &q);
            Segment ans = tree.query(p+1, q+1);
            printf("%d %d\n", ans.first-1, ans.second-1);
        }
    }
    return 0;
}

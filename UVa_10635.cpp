//UVa 10635, Prince and Princess
#include<cstdio>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

const int MAXn = 62500 + 5, INF = ~0U>>1;

int s1[MAXn], A[MAXn], f[MAXn], g[MAXn];
map<int, int> Get;
vector<int> Loc[MAXn];

int main() {
    int T;
    scanf("%d", &T);
    for(int kase = 1; kase <= T; kase++) {
        int N, p, q, x, Cnt = 0;
        scanf("%d%d%d", &N, &p, &q);
        p++, q++;

        Get.clear();
        for(int i = 1; i <= p; i++) {
            scanf("%d", &s1[i]);
            if(!Get.count(s1[i]))
                Get[s1[i]] = ++Cnt;
        }
        for(int i = 1; i <= Cnt; i++) Loc[i].clear();
        for(int i = 1; i <= q; i++) {
            scanf("%d", &x);
            if(Get.count(x)) Loc[Get[x]].push_back(i);
        }

        int n = 0;
        for(int i = 1; i <= p; i++) {
            int m = Loc[Get[s1[i]]].size();
            for(int j = m-1; j >= 0; j--) A[++n] = Loc[i][j];
        }

        int ans = 0;
        for(int i = 1; i <= n; i++) g[i] = INF;
        for(int i = 1; i <= n; i++) {
            int k = lower_bound(g+1, g+n+1, A[i]) - g;
            g[k] = A[i];
            ans = max(ans, f[i] = k);
        }
        printf("Case %d: %d\n", kase, ans);
    }
    return 0;
}


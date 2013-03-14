#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

const int MAXn = 1000 + 5, INF = 2000;

int f[MAXn][2], vis[MAXn][2];
vector<int> G[MAXn];

int dfs(int i, int j, int fa) {
    if(vis[i][j]) return f[i][j];
    vis[i][j] = 1;

    int& ans = f[i][j];
    ans = INF;
    for(int k = 0; k < G[i].size(); k++) 
        if(fa != G[i][k])
            ans += dfs(G[i][k], 1, i);
    if(!j && fa >= 0) ans++;

    if(j || fa < 0) {
        int sum = 0;
        for(int k = 0; k < G[i].size(); k++) 
            if(fa != G[i][k])
                sum += dfs(G[i][k], 0, i);
        if(fa >= 0) sum++;
        ans = min(ans, sum);
    }
    return ans;
}

int main() {
    int kase;
    scanf("%d", &kase);
    while(kase --) {
        int n, m, u, v;
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; i++) G[i].clear();
        for(int i = 0; i < m; i++)
            scanf("%d%d", &u, &v),
            G[u].push_back(v),
            G[v].push_back(u);

        int ans = 0;
        memset(vis, 0, sizeof(vis));
        for(int i = 0; i < n; i++)
            if(!vis[i][0])
                ans += dfs(i, 0, -1);
        printf("%d %d %d\n", ans/INF, m-ans%INF, ans%INF);
    }
    return 0;
}

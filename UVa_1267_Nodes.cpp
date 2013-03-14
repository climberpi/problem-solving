#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

const int MAXn = 1000 + 5;

int k, fa[MAXn];
vector<int> G[MAXn], nodes[MAXn];
bool used[MAXn];

void dfs(int u, int f, int d, bool flag) {
    if(flag) {
        fa[u] = f;
        if(G[u].size() == 1 && d > k) nodes[d].push_back(u);
    } else {
        used[u] = 1;
        if(d == k) return;
    }
    for(int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        if(f != v) dfs(v, u, d+1, flag);
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int n, s, u, v, ans = 0;
        scanf("%d%d%d", &n, &s, &k);
        memset(used, 0, sizeof(used));
        for(int i = 1; i <= n; i++) G[i].clear(), nodes[i].clear();
        for(int i = 1; i < n; i++)
            scanf("%d%d", &u, &v),
            G[u].push_back(v),
            G[v].push_back(u);

        dfs(s, -1, 0, 1);
        for(int i = n; i > k; i--) {
            int m = nodes[i].size();
            if(!m) continue;
            for(int j = 0; j < m; j++) if(!used[nodes[i][j]]){
                int node = nodes[i][j];
                for(int l = 0; l < k; l++)
                    if(fa[node] != -1)
                        node = fa[node];
                dfs(node, -1, 0, 0);
                ++ans;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}


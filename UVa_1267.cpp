#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
#define CLR(A) memset((A), 0, sizeof(A))

const int MAXn = 1000 + 10;
int n, k, depth[MAXn], fa[MAXn], G[MAXn][MAXn], map[MAXn];
bool used[MAXn], vis[MAXn], nleaf[MAXn];

void addEdge(int u, int v) {
    G[u][++G[u][0]] = v;
    G[v][++G[v][0]] = u;
}

bool cmp(int i, int j) {return depth[i] > depth[j]; }

void dfs(int id, int dep, bool flag) {
    if(dep == 1) CLR(vis); 
    vis[id] = 1;

    if(flag) depth[id] = dep;
    else {
        if(!nleaf[id]) used[id] = 1;
        if(dep > k) return;
    }

    for(int i = 1; i <= G[id][0]; i++) {
        int v = G[id][i];
        if(!vis[v]) {
            if(flag) fa[v] = id;
            dfs(v, dep+1, flag);
        }
    }
}

bool check() {
    bool flag = 1;
    for(int i = 1; i <= n; i++) 
        if(!nleaf[i])
            flag &= used[i];
    return flag;
}

int main(){
    int T, u, v, s;
    scanf("%d", &T);
    while(T--) {
        CLR(G), CLR(nleaf), CLR(used), CLR(fa);
        scanf("%d%d%d", &n, &s, &k);
        for(int i = 1; i < n; i++)
            scanf("%d%d", &u, &v),
            addEdge(u, v);
        dfs(s, 1, 1);

        for(int i = 1; i <= n; i++)
            nleaf[fa[i]] = 1,
            map[i] = i;
        sort(map+1, map+n+1, cmp);
        dfs(s, 1, 0);
       
        int ans = 0;
        while(!check()) {
            int id;
            ++ans;
            for(int i = 1; i <= n; i++) {
                int I = map[i];
                if(!nleaf[I] && !used[I]) {
                    id = I;
                    break;
                }
            }
            for(int i = 1; i <= k; i++)
                if(fa[id]) id = fa[id];
            dfs(id, 1, 0);
        }
        printf("%d\n", ans);
    }
    return 0;
}


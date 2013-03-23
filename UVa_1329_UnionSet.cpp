#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXn = 20000 + 5;

int fa[MAXn], d[MAXn];

int find(int k) {
    if(fa[k] == k) return k;
    else {
        int root = find(fa[k]);
        d[k] += d[fa[k]];
        return fa[k] = root;
    }
}

int main() {
    int kase;
    scanf("%d", &kase);
    while(kase --) {
        int n, u, v;
        char cmd[2];
        scanf("%d", &n);
        for(int i = 0; i <= n; i++) fa[i] = i, d[i] = 0;
        while(scanf("%s", cmd) == 1 && cmd[0] != 'O')
            if(cmd[0] == 'I') {
                scanf("%d%d", &u, &v);
                fa[u] = v;
                d[u] = abs(u - v) % 1000;
            }
            else {
                scanf("%d", &u);
                find(u);
                printf("%d\n", d[u]);
            }
    }
    return 0;
}

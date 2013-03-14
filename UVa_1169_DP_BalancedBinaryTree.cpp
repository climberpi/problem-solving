#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;

#define func(i) (f[(i)] + manhattan[(i)+1] - dist[(i)+1])

const int MAXn = 100000 + 5;

int x[MAXn], y[MAXn], f[MAXn], w[MAXn], dist[MAXn], manhattan[MAXn];
map<int, int> tree;

int main() {
    int kase;
    scanf("%d", &kase);
    while(kase --) {
        int C, n;
        tree.clear();
        scanf("%d%d", &C, &n);
        x[0] = y[0] = w[0] = dist[0] = 0;
        for(int i = 1; i <= n; i++)
            scanf("%d%d%d", &x[i], &y[i], &w[i]),
            w[i] += w[i-1],
            dist[i] = dist[i-1] + abs(x[i] - x[i-1]) + abs(y[i] - y[i-1]),
            manhattan[i] = abs(x[i]) + abs(y[i]);

        f[0] = 0; tree[0] = 0;
        for(int i = 1; i <= n; i++) {
            int j = tree.begin()->second;
            while(!tree.empty() && w[i] - w[j] > C)
                tree.erase(tree.begin()->first),
                j = tree.begin()->second;
            f[i] = func(j) + dist[i] + manhattan[i];
            tree[func(i)] = i;
        } 

        printf("%d\n", f[n]);
        if(kase) printf("\n");
    }
    return 0;
}

//UVa 10130, SuperSale
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXn = 1000 + 5, MAXw = 30 + 5;

int P[MAXn], W[MAXn], f[MAXw];

int main() {
    int T;
    scanf("%d", &T);
    while(T --) {
        int n, g, G, ans = 0;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) scanf("%d%d", &P[i], &W[i]);
        memset(f, 0, sizeof(f));
        for(int i = 1; i <= n; i++)
            for(int j = 30; j >= W[i]; j--)
                f[j] = max(f[j], f[j-W[i]]+P[i]);

        scanf("%d", &g);
        for(int i = 1; i <= g; i++) 
            scanf("%d", &G),
            ans += f[G];
        printf("%d\n", ans);
    }
    return 0;
}

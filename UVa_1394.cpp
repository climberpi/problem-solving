//UVa 1394, LA 3882, And then there was one
#include<cstdio>

const int MAXn = 10000 + 5;

int f[MAXn];

int main() {
    int n, k, m;
    while(scanf("%d%d%d", &n, &k, &m) == 3 && n) {
        f[1] = 0;
        for(int i = 2; i <= n; i++)
            f[i] = (f[i-1] + k) % i;
        int ans = (m + f[n]-k+1) % n;
        printf("%d\n", ans <= 0 ? ans+n : ans);
    }
    return 0;
}

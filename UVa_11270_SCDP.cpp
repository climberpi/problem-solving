#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define LL long long

const int MAXn = 15, MAXm = 50 + 5;
int m, n;
LL f[MAXm][1<<MAXn], res[MAXm][MAXm];

void dp(int i, int s1, int s2, int k) {
    if(k > m) return;
    if(k == m){
        f[i+1][s2] += f[i][s1];
        return;
    }
    if(!(s2 & 1<<k) && !(s2 & 1<<(k+1))) dp(i, s1, s2, k+2);
    dp(i, s1, s2 ^ (1<<(k)), k+1);
}

void solve(int w, int h) {
    m = w, n = h;
    memset(f, 0, sizeof(f));
    f[1][0] = 1;
    for(int k = 1; k <= n; k++) {
        for(int i = 0; i < (1<<m); i++)
            dp(k, i, i, 0);
        res[m][k] = f[k+1][0];
    }
}

int main() {
    for(int i = 2; i <= 10; i++)
        solve(i, 100/i);
    while(scanf("%d%d", &m, &n) == 2) {
        if(m > n) swap(m, n);
        if(m == 1 && n % 2 == 0) printf("1\n");
        else if(!m) printf("0\n");
        else printf("%lld\n", res[m][n]);
    }
    return 0;
}

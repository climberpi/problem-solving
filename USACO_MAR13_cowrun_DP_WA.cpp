#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define LL long long

const int MAXn = 1000 + 5;
const LL INF = 1LL<<60;

LL f[MAXn][MAXn];
int g[MAXn][MAXn], A[MAXn], B[MAXn], An = 0, Bn = 0, n;

bool cmp(int i, int j) {return i > j;}

LL dp(int k, int i) {
    if(f[k][i] != -1) return f[k][i];
    int j = k - i, m = n - k + 1;
    f[k][i] = INF;
    if(i) {
        dp(k-1, i-1);
        if(f[k][i] > f[k-1][i-1] + abs(g[k-1][i-1] - A[i]) * m)
            f[k][i] = f[k-1][i-1] + abs(g[k-1][i-1] - A[i]) * m,
            g[k][i] = A[i];
    }
    if(j) {
        dp(k-1, i);
        if(f[k][i] > f[k-1][i] + abs(g[k-1][i] - B[j]) * m)
            f[k][i] = f[k-1][i] + abs(g[k-1][i] - B[j]) * m,
            g[k][i] = B[j];
    }
    return f[k][i];
}

int main() {
    freopen("cowrun.in", "r", stdin);
    freopen("cowrun.out", "w", stdout);
    int x;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &x);
        if(x > 0) A[++An] = x;
        else B[++Bn] = x;
    }
    sort(A+1, A+An+1), sort(B+1, B+Bn+1, cmp);
    
    memset(f, -1, sizeof(f));
    f[0][0] = g[0][0] = 0;
    printf("%lld\n", dp(n, An));
    /*for(int i = 1; i <= n; i++)
        for(int j = 0; j <= min(i, An); j++)
            if(f[i][j] != -1) printf("f(%d, %d, %d) = %lld\n", i, j, i-j, f[i][j]);*/
    fclose(stdin), fclose(stdout);
    return 0;
}


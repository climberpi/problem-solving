#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define LL long long

const int MAXn = 1000 + 5;
const LL INF = 1LL<<60;

LL f[MAXn][MAXn], ans = INF;
int g[MAXn][MAXn], A[MAXn], B[MAXn], An = 0, Bn = 0, n;
int used[MAXn], sol[MAXn];

bool cmp(int i, int j) {return i > j;}

void dfs(int* used, int i, int j, LL S, int k) {
    used[i+j] = k;
    if(i == An && j == Bn && S < ans) {
        ans = S;
        memcpy(sol, used, sizeof(sol));
    }
    if(i < An) dfs(used, i+1, j, S + abs(A[i+1] - k) * (n-(i+j)), A[i+1]);
    if(j < Bn) dfs(used, i, j+1, S + abs(B[j+1] - k) * (n-(i+j)), B[j+1]);
}

int main() {
    //freopen("cowrun.in", "r", stdin);
    //freopen("cowrun.out", "w", stdout);
    int x;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &x);
        if(x > 0) A[++An] = x;
        else B[++Bn] = x;
    }
    sort(A+1, A+An+1), sort(B+1, B+Bn+1, cmp);
    memset(used, 0, sizeof(used));
    dfs(used, 0, 0, 0, 0);
    printf("%lld\n", ans);
    for(int i = 1; i <= n; i++) printf(" %d", sol[i]); printf("\n");
    /*while(1) {
        scanf("%d", &n); A[0] = 0;
        for(int i = 1; i <= n; i++) scanf("%d", &A[i]);
        int ans = 0;
        for(int i = 1; i <= n; i++) ans += abs(A[i] - A[i-1]) * (23-i+1);
        printf("%d\n", ans);
    }*/
    fclose(stdin), fclose(stdout);
    return 0;
}


#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define LL long long

const int MAXn = 1000 + 5;

LL ans = 1LL<<62;
int A[MAXn], B[MAXn], n, nA = 0, nB = 0;

void dfs(int kA, int kB, bool op, LL sum, LL cost) {
    if(kA == nA && kB == nB) {
        ans = min(ans, sum);
        return;
    }
    if(kA == nA) {
        int delta = !op ? cost+B[kB+1]-B[kB] : cost+A[kA]+B[kB+1];
        dfs(kA, kB+1, 0, sum+(LL)delta, (LL)delta);
        return;
    }
    if(kB == nB) {
        int delta = op ? cost+A[kA+1]-A[kA] : cost+B[kB]+A[kA+1];
        dfs(kA+1, kB, 1, sum+(LL)delta, (LL)delta);
        return;
    }
    if(A[kA+1] < B[kB+1]) {
        int delta = op ? cost+A[kA+1]-A[kA] : cost+B[kB]+A[kA+1];
        dfs(kA+1, kB, 1, sum+(LL)delta, (LL)delta);
    }
    else if(A[kA+1] > B[kB+1]){
        int delta = !op ? cost+B[kB+1]-B[kB] : cost+A[kA]+B[kB+1];
        dfs(kA, kB+1, 0, sum+(LL)delta, (LL)delta);
    }
    else {
        int deltaA = op ? cost+A[kA+1]-A[kA] : cost+B[kB]+A[kA+1];
        int deltaB = !op ? cost+B[kB+1]-B[kB] : cost+A[kA]+B[kB+1];
        dfs(kA+1, kB, 1, sum+deltaA, deltaA),
        dfs(kA, kB+1, 0, sum+deltaB, deltaB);
    }
}

int main() {
    freopen("cowrun.in", "r", stdin);
    freopen("cowrun.out", "w", stdout);
    int x;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &x);
        if(x > 0) A[++nA] = x;
        else B[++nB] = -x;
    }
    A[0] = B[0] = 0;
    sort(A+1, A+nA+1);
    sort(B+1, B+nB+1);
    dfs(0, 0, 1, 0, 0);
    printf("%lld\n", ans);
    fclose(stdin), fclose(stdout);
    return 0;
}

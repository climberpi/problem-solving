/*
ID: liu.yu.pa1
PROG: poker
LANG: C++
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define LL long long

const int MAXn = 100000 + 5;

int A[MAXn];

int main() {
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &A[i]);
    A[0] = A[n+1] = 0;
    LL ans = 0;
    for(int i = 0; i <= n; i++) ans += (LL)abs(A[i+1] - A[i]);
    printf("%lld\n", ans/2LL);
    fclose(stdin), fclose(stdout);
    return 0;
}

#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXn = 20 + 5;

int A[MAXn], sol[MAXn];

int main() {
    //freopen("cowrun.in", "r", stdin);
    //freopen("cowrun.out", "w", stdout);
    int n, ans = ~0U>>1;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &A[i]);
    sort(A+1, A+n+1); A[0] = 0;
    do {
        int tmp = 0;
        for(int i = 1; i <= n; i++)
            tmp += abs(A[i]-A[i-1]) * (n-i+1);
        if(tmp <= ans) {
            ans = tmp;
            memcpy(sol, A, sizeof(A));
        }
    } while(next_permutation(A+1, A+n+1));
    printf("%d\n", ans);
    for(int i = 1; i <= n; i++) printf(" %d", sol[i]); printf("\n");
    while(1) {
        scanf("%d", &n);
        int tmp = 0; A[0] = 0;
        for(int i = 1; i <= n; i++) scanf("%d", &A[i]);
        for(int i = 1; i <= n; i++)
            tmp += abs(A[i]-A[i-1]) * (n-i+1);
        printf("%d\n", tmp);
    }
    fclose(stdin), fclose(stdout);
    return 0;
}


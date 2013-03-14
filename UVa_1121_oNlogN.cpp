#include<cstdio>
#include<algorithm>
using namespace std;

const int MAXn = 100000 + 5;

int B[MAXn];

int main() {
    int n, s;
    while(scanf("%d%d", &n, &s) == 2) {
        B[0] = 0;
        for(int i = 1; i <= n; i++)
            scanf("%d", &B[i]),
            B[i] += B[i-1];
        int ans = n+1;
        for(int j = 1; j <= n; j++) {
            int i = upper_bound(B, B+j, B[j] - s) - B;
            if(i) ans = min(ans, j - i + 1);
        }
        printf("%d\n", ans == n+1 ? 0 : ans);
    }
    return 0;
}

#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXn = 100000 + 5, MAXm = 18;

int f[1<<MAXm][MAXm], Val[MAXn], Cnt[MAXn], pos[MAXn], A[MAXn], left[MAXn], right[MAXn];

int main() {
    int n, q;
    while(scanf("%d", &n) == 1 && n) {
        scanf("%d", &q);
        int SegCnt = 0; A[0] = 111111;
        for(int i = 1; i <= n; i++) {
            scanf("%d", &A[i]);
            //Run Length Encoding
            if(A[i] != A[i-1]) {
                if(i-1) {
                    f[SegCnt][0] = Cnt[SegCnt] = i - left[SegCnt];
                    right[SegCnt] = i - 1;
                    for(int j = left[SegCnt]; j <= right[SegCnt]; j++)
                        pos[j] = SegCnt;
                }
                Val[++SegCnt] = A[i],
                left[SegCnt] = i;
            }
            if(i == n) {
                f[SegCnt][0] = Cnt[SegCnt] = i - left[SegCnt] + 1;
                right[SegCnt] = i;
                for(int j = left[SegCnt]; j <= right[SegCnt]; j++)
                    pos[j] = SegCnt;
            }
        }
        
        int k = 0; while((1<<(k+1)) <= SegCnt) ++k; ++k;
        for(int j = 1; (1<<j) <= SegCnt; j++)
            for(int i = 1; i + (1<<j) - 1 <= SegCnt; i++)
                f[i][j] = max(f[i][j-1], f[i+(1<<(j-1))][j-1]);

        while(q--) {
            int L, R;
            scanf("%d%d", &L, &R);
            if(pos[L] == pos[R]) {
                printf("%d\n", R-L+1);
                continue;
            }
            int ans = 0;
            if(pos[L] + 1 < pos[R]) {
                int le = pos[L] + 1, ri = pos[R] - 1;
                int k = 0; while((1<<(k+1)) <= ri-le+1) ++k;
                ans = max(f[le][k], f[ri-(1<<k)+1][k]);
            }
            printf("%d\n", max(ans, max(right[pos[L]]-L+1, R-left[pos[R]]+1)));
        }
    }
    return 0;
}

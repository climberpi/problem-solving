#include<cstdio>
#include<algorithm>
using namespace std;

const int MAXn = 100000 + 5;

int A[MAXn];

int main(){
    int T;
    scanf("%d", &T);
    while(T --) {
        int n, ans = -4*MAXn;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%d", &A[i]);
        
        int Min = A[n];
        for(int i = n-1; i >= 1; i--) {
            ans = max(ans, A[i] - Min);
            Min = min(Min, A[i]);
        }
        printf("%d\n", ans);
    }
    return 0;
}

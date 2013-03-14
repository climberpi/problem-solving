#include<cstdio>
#include<algorithm>
using namespace std;
#define LL long long
const int MAXn = 1000000 + 5;

LL S[MAXn], C[MAXn];

int main(){
    int i, j, N;
    LL M, el, ans;
    while(scanf("%d", &N) == 1){
        S[0] = ans = 0;
        for(i = 1; i <= N; i++)
            scanf("%lld", &el),
                S[i] = S[i-1] + el;
        M = S[N] / N;
        C[0];
        for(i = 1; i < N; i++)
            C[i] = S[i] - i*M;
        sort(C, C+N);
        for(i = 1; i < N; i++)
            ans += abs(S[i] - i*M - C[N/2]);
        ans += abs(C[N/2]);
        printf("%lld\n", ans);
    }
    return 0;
}

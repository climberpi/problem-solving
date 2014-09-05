#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAXn 11000

int is_prime[MAXn], loc[MAXn], ans[MAXn];
long long A[MAXn];

int main() {
    int M, N, i, j;
    scanf("%d%d", &M, &N);
    for(i = 0; i < N; i++)
        scanf("%lld", &A[i]);

    for(i = 0; i < MAXn; i++)
        is_prime[i] = 1,
        loc[i] = 0;
    is_prime[0] = is_prime[1] = 0;
    for(i = 2; i < MAXn; i++) {
        if(is_prime[i]) {
            int k = i;
            while(k+i <= MAXn) is_prime[k+=i] = 0;
        }
    }

    while(!is_prime[M]) M++;

    for(i = 0; i < N; i++) {
        int flag = 0;
        for(j = 0; j < M; j++) {
            int new_loc = (A[i] % M + (j*j)) % M;
            if(!loc[new_loc]) {
                loc[new_loc] = 1;
                ans[i] = A[i] % M;
                flag = 1;
            }
        }
        if(!flag)
            ans[i] = -1;
    }

    int first = 1;
    for(i = 0; i < N; i++) {
        if(first) first = 0;
        else printf(" ");
        if(ans[i] == -1) printf("-");
        else printf("%d", ans[i]);
    }
    printf("\n");
    return 0;
}

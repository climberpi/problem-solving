#include<cstdio>
#define LL long long

const int MAXn = 60 + 5;

int A[MAXn], B[MAXn];

LL f(int* P, int i, int final) {
    if(!i) return 0;
    if(P[i] == final) return f(P, i-1, final);
    else return f(P, i-1, 6-final-P[i]) + (1LL << (i-1)); 
}

int main(){
    int Cnt = 0, n;
    while(scanf("%d", &n) == 1 && n) {
        int k = 0;
        for(int i = 1; i <= n; i++) scanf("%d", &A[i]);
        for(int i = 1; i <= n; i++) scanf("%d", &B[i]);
        for(int i = n; i >= 1; i--) 
            if(A[i] != B[i]) {
                k = i;
                break;
            }
        printf("Case %d: %lld\n", ++Cnt, k ? f(A, k-1, 6-A[k]-B[k]) + f(B, k-1, 6-A[k]-B[k]) + 1 : 0);
    }
    return 0;
}

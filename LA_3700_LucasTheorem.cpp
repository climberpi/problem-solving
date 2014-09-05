#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;

int A[50], Cnt = 0;

int main() {
    int p, n, id = 0, ans;
    while(scanf("%d%d", &p, &n)) {
        if(!n && !p) break;
        ans = 1, Cnt = 0;
        if(n == 1 || !n)
            A[++Cnt] = n;
        else while(n)
            A[++Cnt] = n%p,
            n /= p;
        for(int i = 1; i <= Cnt; i++) {
            //printf("%d", A[i]),
            ans *= (A[i] + 1);
            if(ans > 10000)
                ans %= 10000;
        }
        //printf("\n");
        printf("Case %d: %04d\n", ++id, ans);
    }
    return 0;
}

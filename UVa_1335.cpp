#include<cstdio>
#include<algorithm>
using namespace std;

const int MAXn = 111111;

int left[MAXn], right[MAXn], A[MAXn], n;

bool check(int M) {
    int X = A[1], Y = M-A[1];
    left[1] = A[1], right[1] = 0;
    for(int i = 2; i <= n; i++)
        if(i % 2 == 1) {
            right[i] = min(Y-right[i-1], A[i]);
            left[i] = A[i]-right[i];
        }else{
            left[i] = min(X-left[i-1], A[i]);
            right[i] = A[i]-left[i];
        }
    return !left[n];
}

int main() {
    while(scanf("%d", &n) == 1 && n) {
        for(int i = 1; i <= n; i++) scanf("%d", &A[i]);
        int L = 0, R = 0;
        A[0] = A[n], A[n+1] = A[1];
        for(int i = 1; i <= n; i++)
            L = max(L, A[i-1]+A[i]),
            R = max(R, A[i-1]+A[i]+A[i+1]);
        if(n == 1) printf("%d\n", A[1]);
        else if(n % 2 == 0) printf("%d\n", L);
        else {
            while(L < R) {
                int M = L + (R-L)/2;
                if(check(M)) R = M;
                else L = M+1;
            }
            printf("%d\n", L);
        }
    }
    return 0;
}

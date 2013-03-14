#include<cstdio>

int main() {
    int n;
    while(scanf("%d", &n) == 1) {
        int ans = 1, k = 1;
        while(ans*2 <= n) 
            ans *= 2,
            k++;
        printf("%d\n", k);
    }
}

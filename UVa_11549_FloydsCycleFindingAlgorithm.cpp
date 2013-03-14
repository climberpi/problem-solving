#include<cstdio>
#define max(a, b) ((a) > (b) ? (a) : (b))

int next(int n, int k) {
    int buf[25], p = 0, x = 0;
    long long num = (long long)k * k;
    if(!num) buf[++p] = 0;
    else while(num) {
        buf[++p] = num % 10;
        num /= 10;
    }
    for(int i = p; i > 0 && p-i < n; i--)
        x = x*10 + buf[i];
    return x;
}

int main() {
    int T;
    scanf("%d", &T);
    while(T --) {
        int n, k;
        scanf("%d%d", &n, &k);
        int k1 = k, k2 = k, ans = k;
        do {
            k1 = next(n, k1);  
            k2 = next(n, k2); ans = max(ans, k2);
            k2 = next(n, k2); ans = max(ans, k2);
        } while(k1 != k2);
        printf("%d\n", ans);
    }
    return 0;
}

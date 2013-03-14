#include<cstdio>
#include<cmath>

int main() {
    int n, Cnt = 0;
    while(scanf("%d", &n) == 1 && n > 0) printf("Case %d: %d\n", ++Cnt, (int)ceil(log(n)/log(2)));
    return 0;
}


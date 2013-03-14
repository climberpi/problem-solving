#include<cstdio>
#include<iostream>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    while(T --) {
        int n, Ai, Max, ans = -333333;
        scanf("%d%d", &n, &Max);
        for(int i = 2; i <= n; i++) {;
            scanf("%d", &Ai);
            ans = max(ans, Max - Ai);
            Max = max(Ai, Max);
        }
        printf("%d\n", ans);
    }
    return 0;
}

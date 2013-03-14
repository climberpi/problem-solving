#include<cstdio>
#include<cstring>
#include<set>
#include<algorithm>
using namespace std;

int next(int n, int k) {
    char num[25];
    sprintf(num, "%lld\n", (long long)k*k);
    num[n] = '\0';
    int x;
    sscanf(num, "%d", &x);
    return x;
}

int main() {
    int T;
    scanf("%d", &T);
    while(T --) {
        int n, k, ans = 0;
        scanf("%d%d", &n, &k);
        set<int> s;
        while(!s.count(k)) {
            s.insert(k);
            ans = max(ans, k);
            k = next(n, k);
        }
        printf("%d\n", ans);
    }
    return 0;
}

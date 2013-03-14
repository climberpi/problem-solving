#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXn = 16;

int cover[1<<MAXn], f[1<<MAXn], set[MAXn];

int main() {
    int n, kase = 0;
    while(scanf("%d", &n) == 1 && n) {
        int ALL = (1<<n)-1; 
        f[0] = 0;
        for(int i = 0; i < n; i++) {
            int m;
            scanf("%d", &m);
            set[i] = 1<<i;
            for(int j = 1; j <= m; j++) {
                int x;
                scanf("%d", &x);
                set[i] |= (1<<x);
            }
        }

        for(int i = 0; i < (1<<n); i++) {
            cover[i] = 0;
            for(int j = 0; j < n; j++)
                if(i & (1<<j))
                    cover[i] |= set[j];
        }

        for(int S = 1; S < (1<<n); S++) {
            f[S] = 0;
            for(int S0 = S; S0; S0 = (S0-1)&S)
                if(cover[S0] == ALL) f[S] = max(f[S], f[S^S0]+1);
        }
        printf("Case %d: %d\n", ++kase, f[ALL]);
    }
    return 0;
}

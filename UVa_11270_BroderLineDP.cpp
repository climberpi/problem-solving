#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define LL long long

const int MAXn = 15, MAXm = 51;

int n, m, cur;
LL f[2][1<<MAXn], res[MAXm][MAXm];

#define update(A, B) {if((B)&(1<<m)) f[cur][(B)^(1<<m)] += f[1^cur][A];}

void solve(int m, int n) {
    memset(f, 0, sizeof(f));
    f[cur = 0][(1<<m)-1] = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cur ^= 1;
            memset(f[cur], 0, sizeof(f[cur]));
            for(int k = 0; k < (1<<m); k++) {
                update(k, k<<1);
                if(i && !(k&(1<<m-1))) update(k, (k<<1) ^ (1<<m) ^ 1);
                if(j && !(k&1)) update(k, (k<<1) ^ 3);
            }
        }
        res[m][i+1] = f[cur][(1<<m)-1];
    }
}

int main() {
    memset(res, -1, sizeof(res));
    for(int i = 2; i <= 10; i++)
        solve(i, 100/i);
    while(scanf("%d%d", &m, &n) == 2) {
        if(m > n) swap(m, n);

        if(!m || (m&1) && (n&1)) {printf("0\n"); continue;}
        if(m == 1) {printf("1\n"); continue;}
        if(res[m][n] != -1) {printf("%lld\n", res[m][n]); continue;}
/*
        memset(f, 0, sizeof(f));
        f[cur = 0][(1<<m)-1] = 1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cur ^= 1;
                memset(f[cur], 0, sizeof(f[cur]));
                for(int k = 0; k < (1<<m); k++) {
                    update(k, k<<1);
                    if(i && !(k&(1<<m-1))) update(k, (k<<1) ^ (1<<m) ^ 1);
                    if(j && !(k&1)) update(k, (k<<1) ^ 3);
                }
            }
            //if(res[m][i+1] == -1) res[m][i+1] = f[cur][(1<<m)-1];
        }
        printf("%lld\n", f[cur][(1<<m)-1]);*/
    }
    return 0;
}

/*
ID: liu.yu.pa1
PROG: nocow
LANG: C++
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

#define REP(i, n) for(int i = 1; i <=(n); ++i)

const int MAXn = 111, MAXm = 33;
int adj_cnt[MAXm], cnt[MAXm], map[MAXm][MAXn];
char adj_tmp[MAXm][MAXn], adj[MAXm][MAXn];

int main() {
    freopen("nocow.in", "r", stdin);
    freopen("nocow.out", "w", stdout);
    int N, K, M;
    char str[MAXm], end = "cow.";

    //read string
    scanf("%d%d", &N, &K);
    REP(i, N) {
        scanf("Farmer John has no %s", str);
        int j = 0, ii = 0;
        while(strcmp(str, end, sizeof(end))) {
            bool flag = 1; ++j;
            REP(k, i-1) if(!strcmp(str, adj_tmp[j][k], sizeof(str))) {
                flag = 0;
                break;
            }
            if(flag)
                memcpy(str, adj_tmp[j][++i], sizeof(str)),
                map[j][ii] = ii,
                adj_cnt[j] = ii;
            scanf("%s", str);
        }
        M = j;
    }

    //sort string, and let them be unique
    REP(j, M) {
        qsort(map + (j-1)*MAXn + 1, adj_cnt[j], sizeof(int), cmp);
        REP(i, adj_cnt[j]) memcpy(adj_tmp[j][i], adj[j][map[i]], sizeof(adj_tmp[j][i]));
    }
    
    //get k-th m-tuple
    cnt[M] = 1;
    for(i = M; i > 0; i--) cnt[i-1] = cnt[i] * adj_cnt[i];
    int loc = K, rank = 0, tuple[M];
    while(loc) {
        if(loc / cnt[++rank]) {
            tuple[rank] = loc / cnt[rank] + 1,
            loc -= (loc / cnt[rank] * cnt[rank]);
        } else {
            tuple[rank] = 0;
        }
    }


    fclose(stdin), fclose(stdout);
    return 0;
}

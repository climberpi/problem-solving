#include<cstdio>
#include<cstring>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

map<int, vector<int> > query;

int main() {
    int n, m;
    while(scanf("%d%d", &n, &m) == 2 && m && n) {
        int x;
        for(int i = 1; i <= n; i++) {
            scanf("%d", &x);
            if(!query.count(x)) query[x] = vector<int>();
            query[x].push_back(i);
        }

        int k;
        for(int i = 1; i <= m; i++) {
            scanf("%d%d", &k, &x);
            if(!query.count(x) || query[x].size() < k)
                printf("0\n");
            else
                printf("%d\n", query[x][k-1]);
        }
    }
    return 0;
}

#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define LL long long

const int MAXn = 4000 * 1000 + 10, MAXm = 1000 + 5;

struct Tire {
    int head[MAXn], next[MAXn], tot[MAXn], Cnt;
    char ch[MAXn];
    LL ans;

    void clear() { Cnt = 1; tot[0] = head[0] = next[0] = 0; }

    void insert(const char *s) {
        int u = 0, v, n = strlen(s);
        tot[0] ++;
        for(int i = 0; i <= n; i++) {
            bool found = false;
            for(v = head[u]; v; v = next[v]) if(ch[v] == s[i]) {
                found = true;
                break;
            }
            if(! found) {
                v = Cnt++;
                tot[v] = 0;
                ch[v] = s[i];
                next[v] = head[u];
                head[u] = v;
                head[v] = 0;
            }
            u = v;
            tot[u]++;
        }
    }

    void dfs(int depth, int u) {
        if(!head[u])
            ans += tot[u]*(tot[u]-1) * depth;
        else {
            int sum = 0;
            for(int v = head[u]; v != 0; v = next[v])
                sum += tot[v] * (tot[u] - tot[v]);
            ans += sum / 2 * (2*depth+1);
            for(int v = head[u]; v != 0; v = next[v])
                dfs(depth+1, v);
        }
    }

    LL count() {
        ans = 0;
        dfs(0, 0);
        return ans;
    }
}tire;

char word[MAXm];

int main() {
    int n, kase = 0;
    while(scanf("%d", &n) == 1 && n) {
        tire.clear();
        for(int i = 1; i <= n; i++)
            scanf("%s", word),
            tire.insert(word);
        printf("Case %d: %lld\n", ++kase, tire.count());
    }
    return 0;
}

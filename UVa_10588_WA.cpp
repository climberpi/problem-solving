#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

const int MAXn = 100000 + 5;

struct Person {
    int t, k;
    vector<int> g;
    
    bool operator < (const Person& a) const {return t < a.t;}
}P[MAXn];

int time[MAXn];

int main() {
    int kase, n, m, x;
    scanf("%d", &kase);
    while(kase --) {
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i++) {
            scanf("%d%d", &P[i].t, &P[i].k);
            P[i].g.clear();
            for(int j = 0; j < P[i].k; j++)
                scanf("%d", &x),
                P[i].g.push_back(x);
        }

        //sort(P+1, P+n+1);
        memset(time, -1, sizeof(time));
        for(int i = 1; i <= n; i++) {
            int T = P[i].t;
            for(int j = 0; j < P[i].k; j++) {
                int k = P[i].g[j];
                if(time[k] < T)
                    time[k] = T;
                else time[k] = max(time[k]+1, T);
                T = time[k] + 1;
            }
            //for(int j = 1; j <= m; j++) printf(" %d", time[j]); printf("\n");
        }
        int ans = 0;
        for(int i = 1; i <= m; i++) ans = max(ans, time[i]);
        printf("%d\n", ans);
    } 
    return 0;
}

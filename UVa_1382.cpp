#include<cstdio>
#include<algorithm>
using namespace std;

const int MAXn = 100 + 5;

struct Point{
    int x, y;
    bool operator < (const Point& a) const{return x < a.x;}
} P[MAXn];

int on[MAXn], on2[MAXn], left[MAXn], y[MAXn], n;

int solve() {
    sort(P+1, P+n+1);
    sort(y+1, y+n+1);
    int m = unique(y+1, y+n+1) - (y+1);
    if(m <= 2) return n;
    
    int ans = 0;
    for(int a = 1; a <= m; a++)
        for(int b = a+1; b <= m; b++) {
            int up = y[a], dn = y[b], k = 0;
            for(int i = 1; i <= n; i++) {
                if(i == 1 || P[i].x != P[i-1].x) {
                    on[k] = on2[++k] = 0;
                    left[k] = k == 1 ? 0 : left[k-1]+on2[k-1]-on[k-1];
                }
                if(up < P[i].y && P[i].y < dn) on[k] ++;
                if(up <= P[i].y && P[i].y <= dn) on2[k] ++;
            }

            int M = 0;
            for(int i = 1; i <= k; i++)
                ans = max(ans, M + left[i] + on2[i]),
                M = max(M, on[i] - left[i]);
        }
    return ans;
}

int main() {
    int kase = 0;
    while(scanf("%d", &n) == 1 && n) {
        for(int i = 1; i <= n; i++)
            scanf("%d%d", &P[i].x, &P[i].y),
            y[i] = P[i].y;
        printf("Case %d: %d\n", ++kase, solve());
    }
    return 0;
}

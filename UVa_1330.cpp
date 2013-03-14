#include<cstdio>
#include<algorithm>
using namespace std;
#define REP(i, n) for(int i = 1; i <= (n); i++)
#define PER(i, n) for(int i = n; i >= (1); i--)

const int MAXn = 1000 + 5;

int G[MAXn][MAXn], up[MAXn], left[MAXn], right[MAXn];

inline int GetChar() {
    char ch = getchar();
    while(ch != 'F' && ch != 'R') ch = getchar();
    return ch == 'F' ? 1 : 0;
}

int main() {
    int T;
    scanf("%d", &T);
    while(T --) {
        int m, n, ans = 0;
        scanf("%d%d", &m, &n);
        REP(i, m) REP(j, n) G[i][j] = GetChar();
        
        REP(i, m) {
            int lo = 0, ro = n+1;
            REP(j, n) if(!G[i][j])
                up[j] = left[j] = 0,
                lo = j;
            else
                up[j] = i == 1 ? 1 : up[j] + 1,
                left[j] = i == 1 ? lo+1 : max(left[j], lo+1);
            PER(j, n) if(!G[i][j])
                right[j] = n+1,
                ro = j;
            else 
                right[j] = i == 1 ? ro-1 : min(right[j], ro-1),
                ans = max(ans, up[j] * (right[j] - left[j] + 1));
        }
        printf("%d\n", ans*3);
    }
    return 0;
}

#include<cstdio>
#include<algorithm>
using namespace std;
#define REP(i, n) for(int i = 1; i <= (n); i++)
#define PER(i, n) for(int i = (n); i > 0; i--)

const int MAXn = 2000 + 5;

struct Node {int height, start;} s[MAXn];
int A[MAXn][MAXn];

int main() {
    int m, n;
    while(scanf("%d%d", &m, &n) == 2) {
        int x, ans = 0;
        REP(i, m) A[i][0] = 0;
        REP(i, m) REP(j, n) {
            scanf("%d", &x);
            A[i][j] = x ? A[i][j-1]+1 : 0;
        }
        
        REP(j, n) {
            int Cnt = 0; s[++Cnt] = (Node){0, 0};
            REP(i, m+1) {
                Node t = (Node){A[i][j], i};
                int height = i==m+1 ? 0 : A[i][j];
                while(s[Cnt].height > height) {
                    t = s[Cnt--];
                    ans = max(ans, (i-t.start)*t.height);
                }
                s[++Cnt] = (Node){height, t.start};
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

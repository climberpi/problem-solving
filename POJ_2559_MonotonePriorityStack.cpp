#include<cstdio>
#include<algorithm>
#define LL long long
using namespace std;

const int MAXn = 100000 + 5;

struct Node {int height; int start;};

Node s[MAXn];

int main() {
    int n, height, Cnt = 0;
    s[++Cnt] = (Node){0, 0};
    while(scanf("%d", &n) == 1 && n) {
        LL ans = 0;
        for(int i = 1; i <= n+1; i++) {
            if(i <= n) scanf("%d", &height);

            if(i == n+1) height = 0;
            Node t = (Node){height, i};
            while(s[Cnt].height > height) {
                t = s[Cnt--];
                //printf("%d [%d, %d]\n", t.height, t.start, i);
                ans = max(ans, (LL)(i - t.start) * t.height);
            }
            if(i <= n) s[++Cnt] = (Node){height, t.start};
        }
        printf("%lld\n", ans);
    }
    return 0;
}

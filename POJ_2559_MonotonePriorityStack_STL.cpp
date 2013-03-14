#include<cstdio>
#include<stack>
#include<algorithm>
#define LL long long
using namespace std;

struct Node {int height; int start;};

stack<Node> s;

int main() {
    int n, height;
    s.push((Node){0, 0});
    while(scanf("%d", &n) == 1 && n) {
        LL ans = 0;
        for(int i = 1; i <= n+1; i++) {
            if(i <= n) scanf("%d", &height);

            if(i == n+1) height = 0;
            Node t = (Node){height, i};
            while(s.top().height > height) {
                t = s.top(); s.pop();
                //printf("%d [%d, %d]\n", t.height, t.start, i);
                ans = max(ans, (LL)(i - t.start) * t.height);
            }
            if(i <= n) s.push((Node){height, t.start});
        }
        printf("%lld\n", ans);
    }
    return 0;
}

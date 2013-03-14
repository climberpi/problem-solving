#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

const int MAXn = 100000 + 5;
const double INF = ~0U>>1;

struct Event {
    double x;
    bool type;
    bool operator < (const Event& a) const {return x < a.x || (fabs(x - a.x) < 1e-6 && type < a.type);}
} event[MAXn * 2];

inline void update(int x, int a, int w, double& L, double& R) {
    if(!a) {
        if(x <= 0 || x >= w) R = L-0.5;
    }else if(a > 0){
        L = max(L, (double)-x/a);
        R = min(R, (double)(w-x)/a);
    }else{
        L = max(L, (double)(w-x)/a);
        R = min(R, (double)-x/a);
    }
}

inline void check(double& L, double& R) {
    if(L < 0 && R > 0)
        L = 0;
    else if(L < 0 && R < 0)
        R = L-0.5;
}

int main() {
    int T;
    scanf("%d", &T);
    while(T --) {
        int w, h, n, x, y, a, b, Cnt = 0;
        scanf("%d%d%d", &w, &h, &n);
        for(int i = 0; i < n; i++) {
            double L = 0, R = INF;
            scanf("%d%d%d%d", &x, &y, &a, &b);
            update(x, a, w, L, R);
            update(y, b, h, L, R);
            if(L < R)
                event[Cnt ++] = (Event){L, 1},
                event[Cnt ++] = (Event){R, 0};
        }
        int ans = 0, stat = 0;
        sort(event, event + Cnt);
        for(int i = 0; i < Cnt; i++)
            if(event[i].type)
                ans = max(ans, ++stat);
            else
                stat --;
        printf("%d\n", ans);
    }
    return 0;
}

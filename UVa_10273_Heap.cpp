#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define REP0(i, n) for(int i = 0; i < (n); i++)
#define REP1(i, n) for(int i = 1; i <= (n); i++)

const int MAXn = 1000 + 5;

struct Heap {
    int h[MAXn], n;

    void clear() {n = 0;}

    void up(int k) {
        while(k > 1) if(h[k/2] > h[k])
            swap(h[k/2], h[k]),
            k /= 2;
        else break;
    }

    void down(int k) {
        while(k*2 <= n) {
            k *= 2;
            if(k < n && h[k] > h[k+1]) k++;
            if(h[k/2] > h[k]) swap(h[k/2], h[k]);
            else break;
        }
    }

    void push(int k) { h[++n] = k; up(n); }

    int pop(int k, bool& only) {
        if(n >= 2 && h[2] == h[1]) only = 0;
        else if(n >= 3 && h[3] == h[1]) only = 0;
        else only = 1;
        swap(h[1], h[n--]); down(1);
        return h[n+1];
    }
}q[11][11];

int gcd(int x, int y) {return !y ? x : : gcd(y, x%y);}

int lcm(int x, int y) {if(x<y) swap(x, y); return x/gcd(x, y)*y;}

int main() {
    int T, days = 1;
    scanf("%d", &T);
    while(T--) {
        int n, m, x;
        scanf("%d", &n);
        REP1(i, 10) REP0(j, i) q[i][j].clear();
        REP0(i, n) {
            scanf("%d%d", &m, &x);
            days = lcm(days, m);
            q[m][i].push(x);
        }
        int Cnt, day;
        REP0(day, days+1) {
            if(day == days) {
                bool flag = 1;
                REP1(i, 10) flag &= q[i][day%i].empty();
                if(!flag) day = 0;
            }
            int Min = 1000, k;
            REP1(i, 10) if(Min > q[i][day%i].top() || (Min == q[i][day%i].top() && q[i][day%i].only()))
                Min = q[i][day%i], k = i;
            REP0(i, k) q[k][i].del(Min);
        }
    }
    return 0;
}

#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXn = 1000+5;

struct item {
    int Q_num, Period, Time;
    bool operator < (const item& a) const {
        return Time > a.Time || (Time == a.Time && Q_num > a.Q_num);
    }
};

struct heap {
    item h[MAXn];
    int n;

    void up(int k) {
        while(k > 1) if(h[k/2] < h[k]) {
            swap(h[k], h[k/2]);
            k /= 2;
        }else break;
    }

    void down(int k) {
        while(2*k <= n) {
            k *= 2;
            if(k < n && h[k] < h[k+1]) ++k;
            if(h[k/2] < h[k])
                swap(h[k/2], h[k]);
            else break;
        }
    }

    void push(const item& x) {
        h[++n] = x;
        up(n);
    }

    item pop() {
        swap(h[1], h[n--]);
        down(1);
        return h[n+1];
    }
}q;

int main() {
    char s[20];
    while(scanf("%s", s) == 1 && s[0] != '#') {
        int Q_num, Period;
        scanf("%d%d", &Q_num, &Period);
        q.push((item){Q_num, Period, Period});
    }

    int k;
    scanf("%d", &k);
    while(k --) {
        item now = q.pop();
        printf("%d\n", now.Q_num);
        now.Time += now.Period;
        q.push(now);
    }
    return 0;
}

#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;

struct item {
    int Q_num, Period, Time;
    bool operator < (const item& a) const {
        return Time > a.Time || (Time == a.Time && Q_num > a.Q_num);
    }
};

priority_queue<item> q;

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
        item now = q.top(); q.pop();
        printf("%d\n", now.Q_num);
        now.Time += now.Period;
        q.push(now);
    }
    return 0;
}

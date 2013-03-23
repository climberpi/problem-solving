#include<cstdio>
#include<cstring>
#include<set>
#include<algorithm>
using namespace std;
#define LL long long

const int MAXn = 100000 + 5;

struct Edge {
    int x1, y1, x2, y2, id;
    bool operator < (const Edge& o) const {
        if(x2 < o.x2)
            return (LL)(y2 - o.y1)*(LL)(o.x2 - o.x1) < (LL)(x2 - o.x1)*(LL)(o.y2 - o.y1);
        else
            return (LL)(o.y2 - y1)*(LL)(x2 - x1) > (LL)(o.x2 - x1)*(LL)(y2 - y1);
    }
} edges[MAXn];

struct Event {
    int x, y, id;
    bool operator < (const Event& o) const {
        return x < o.x || (x == o.x && y < o.y);
    }
} events[MAXn*2];

int main() {
    freopen("hillwalk.in", "r", stdin);
    freopen("hillwalk.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d%d%d%d", &edges[i].x1, &edges[i].y1, &edges[i].x2, &edges[i].y2);
        edges[i].id = i;
        events[i*2-1] = (Event){edges[i].x1, edges[i].y1, i};
        events[i*2] = (Event){edges[i].x2, edges[i].y2, i};
    }
    sort(events+1, events+n*2+1);

    set<Edge> s;
    s.insert(edges[1]);
    int CorrentEdge = 1, Cnt = 1;

    for(int k = 1; k <= 2*n; k++) {
        Event ev = events[k];
        Edge ew = edges[ev.id];
        if(ev.x == ew.x1) 
            s.insert(ew);
        else {
            if(ew.id == CorrentEdge) {
                set<Edge>::iterator iter = s.find(ew);
                if(iter == s.begin()) break;
                --iter;
                CorrentEdge = iter->id;
                ++Cnt;
            }
            s.erase(ew);
        }
    }
    printf("%d\n", Cnt);
    fclose(stdin), fclose(stdout);
    return 0;
}


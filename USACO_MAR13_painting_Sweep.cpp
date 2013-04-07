#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
#define REP(i, n) for(int i = 0; i < (n); i++)

const int MAXn = 50000 + 5, INF = ~0U>>1;

int n, rect[MAXn][4], Cnt = 0;
bool seen[MAXn];
pair<int, pair<int, int> > edges[2*MAXn];
multiset<pair<int, int> > s;

int main() {
    memset(seen, 0, sizeof(seen));
    scanf("%d", &n);
    REP(i, n) {
        REP(j, 4) scanf("%d", &rect[i][j]);
        edges[2*i] = make_pair(rect[i][0], make_pair(i, 1));
        edges[2*i+1] = make_pair(rect[i][2], make_pair(i, 0));
    }
    sort(edges, edges + 2*n);

    s.insert(make_pair(INF, 1));
    
    REP(i, 2*n) {
        int index = edges[i].second.first;
        int start = edges[i].second.second;

        pair<int, int> p = *(s.lower_bound(make_pair(rect[index][1], -1)));

        if (start) {
            if(p.second == 1) {
                ++Cnt;
                seen[index] = 1;

                s.insert(make_pair(rect[index][1], 1));
                s.insert(make_pair(rect[index][3], 0));
            }
        }
        else if(seen[index])
            s.erase(s.find(make_pair(rect[index][1], 1))),
            s.erase(s.find(make_pair(rect[index][3], 0)));
    }
    printf("%d\n", Cnt);
    return 0;
}

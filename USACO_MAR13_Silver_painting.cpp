#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<map>
#include<algorithm>
using namespace std;

const int MAXn = 50000 + 5;

struct Point{int x, y, type, id;}point[MAXn];

struct Rect {
    int x1, y1, x2, y2;
    bool operator < (const Rect& p) const {return x1 < p.x1 && y1 < p.y1 && x2 > p.x2 && y2 > p.y2;}
} rect[MAXn];

bool cmp(int i, int j) {return point[i].x < point[j].x;}

int fa[MAXn], id[MAXn];
map<int, int> set;

int find(int k) {return fa[k] == k ? k : fa[k] = find(fa[k]);}

int main() {
    freopen("painting.in", "r", stdin);
    freopen("painting.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) 
        scanf("%d%d%d%d", &rect[i].x1, &rect[i].y1, &rect[i].x2, &rect[i].y2),
        point[2*i-1] = (Point){rect[i].x1, rect[i].y1, 1, i},
        point[2*i] = (Point){rect[i].x2, rect[i].y2, 0, i},
        fa[i] = id[i] = i, id[n+i] = n+i;

    sort(id+1, id+2*n+1, cmp);
    for(int K = 1; K <= 2*n; K++) {
        int k = id[K];
        if(point[k].type) {
            for(map<int, int>::iterator iter = set.begin(); iter != set.end(); ++iter) {
                int i = point[k].id, j = iter->first;
                if(rect[j] < rect[i])
                    fa[i] = find(j);
            }
            set[point[k].id] = 0;
        } else 
            set.erase(point[k].id);
    }
    
    int ans = n;
    for(int i = 1; i <= n; i++)
        if(fa[i] != i) ans --;
    printf("%d\n", ans);
    fclose(stdin), fclose(stdout);
    return 0;
}

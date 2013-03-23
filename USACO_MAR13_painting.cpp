#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<map>
#include<algorithm>
#include<ctime>
#define is_digit(x) ('0' <= (x) && (x) <= '9' ? 1 : 0)
using namespace std;

const int MAXn = 50000 + 5;

struct Point{int x, y, type, id;}point[MAXn*2];

struct Rect {
    int x1, y1, x2, y2;
    bool operator < (const Rect& p) const {return x1 < p.x1 && y1 < p.y1 && x2 > p.x2 && y2 > p.y2;}
} rect[MAXn];

bool cmp(int i, int j) {return point[i].x < point[j].x;}

int fa[MAXn], id[MAXn*2], q[MAXn], Cnt[MAXn], prev[MAXn];
map<int, int> set;

int find(int k) {return fa[k] == k ? k : fa[k] = find(fa[k]);}

inline int GetInt() {
    char ch = getchar();
    while(!is_digit(ch)) ch = getchar();

    int x = 0;
    while(is_digit(ch)) {
        x = x*10 + ch - '0';
        ch = getchar();
    }
    return x;
}

int main() {
    freopen("painting.in", "r", stdin);
    freopen("painting.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) { 
        //scanf("%d %d %d %d\n", &rect[i].x1, &rect[i].y1, &rect[i].x2, &rect[i].y2);
        rect[i].x1 = GetInt(), rect[i].y1 = GetInt();
        rect[i].x2 = GetInt(), rect[i].y2 = GetInt();
        point[2*i-1] = (Point){rect[i].x1, rect[i].y1, 1, i};
        point[2*i] = (Point){rect[i].x2, rect[i].y2, 0, i};
        fa[i] = id[i] = i, id[n+i] = n+i;
    }

    sort(id+1, id+2*n+1, cmp);
    int cnt = 0;
    for(int i = 1; i <= 2*n; i++) {
        int k = id[i];
        if(point[k].type) {
            q[++cnt] = point[k].id;
            if(cnt-1 && rect[q[cnt-1]] < rect[q[cnt]])
                Cnt[q[cnt]] = Cnt[q[cnt-1]] + 1,
                prev[q[cnt]] = q[cnt-1];
            else Cnt[q[cnt]] = 1;
        }
    }

    //printf("%lf\n", (double)clock()/CLOCKS_PER_SEC);
    for(int K = 1; K <= 2*n; K++) {
        int k = id[K];
        if(point[k].type) {
            int i = point[k].id;
            if(Cnt[i] == 1)
                for(map<int, int>::iterator iter = set.begin(); iter != set.end(); ++iter) {
                    int j = iter->first, x = find(i), y = find(j);
                    if(rect[j] < rect[i] && x != y)
                        fa[x] = y;;
                }
            else {
                int j = prev[i], x = find(i), y = find(j);
                if(x != y) fa[x] = y;
            }
            set[point[k].id] = 0;
        } else 
            set.erase(point[k].id);
    }
    
    int ans = n;
    for(int i = 1; i <= n; i++)
        if(fa[i] != i) ans --;
    printf("%d\n", ans);
    //printf("%lf\n", (double)clock()/CLOCKS_PER_SEC);
    fclose(stdin), fclose(stdout);
    return 0;
}

#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define REP0(i, n) for(int i = 0; i < (n); i++)
#define REP1(i, n) for(int i = 1; i <= (n); i++)
#define isdigit(ch) ('0' <= ch && ch <= '9')

const int MAXn = 1000 + 5, INF = ~0U>>1;

struct Node { 
    int id, v; 
    bool operator > (const Node& o) const { return v > o.v; }
};

struct Heap {
    Node h[MAXn];
    int id[MAXn], n;

    inline void clear() {n = 0;}

    inline void exswap(int i, int j) { 
        swap(h[i], h[j]), 
        swap(id[h[i].id], id[h[j].id]);
    }

    inline void up(int k) {
        while(k > 1) if(h[k/2] > h[k])
            exswap(k/2, k),
            k /= 2;
        else break;
    }

    inline void down(int k) {
        while(k*2 <= n) {
            k *= 2;
            if(k < n && h[k] > h[k+1]) k++;
            if(h[k/2] > h[k]) exswap(k/2, k);
            else break;
        }
    }

    inline void push(int k) { 
        h[++n].v = k;
        h[n].id = id[n] = n;
        if(n > 1) up(n); 
    }

    inline Node top() {return h[1];}

    inline bool only() {
        if(n >= 2 && h[2].v == h[1].v) return 0;
        if(n >= 3 && h[3].v == h[1].v) return 0;
        return 1;
    }
    
    inline bool empty() { return !n; }

    inline void pop(int k) {
        int i = id[k];
        if(n > 1) {
            exswap(i, n); n--; 
            down(i);
        } else n = 0;
    }
}q[15][15];

inline int gcd(int x, int y) {return !y ? x : gcd(y, x%y);}

inline int lcm(int x, int y) {if(x<y) swap(x, y); return x/gcd(x, y)*y;}

int GetInt() {
    char ch = getchar(); while(!isdigit(ch)) ch = getchar();
    int x = 0;
    while(isdigit(ch)) x = x*10 + ch - '0', ch = getchar();
    return x;
}

void PutInt(int x) {
    int buf[10], cur = 0;
    if(!x) buf[++cur] = 0;
    else while(x) buf[++cur] = x%10, x /= 10;
    for(int i = cur; i > 0; i--) putchar(buf[i] + '0');
}

int main() {
    int T, days = 1;
    T = GetInt();
    while(T--) {
        int n, m, x, Cnt = 0;
        n = GetInt();
        REP1(i, 10) REP0(j, i) q[i][j].clear();
        REP0(i, n) {
            m = GetInt();
            days = lcm(days, m);
            Cnt += m;
            REP0(j, m) x = GetInt(), q[m][j].push(x);
        }

        int Day = 0;
        REP0(day, 3 * days) {
            int pMin = -1, Min = INF, k;
            Node now;
            REP1(i, 10) if(!q[i][day%i].empty()) {
                now = q[i][day%i].top();
                if(Min >= now.v)
                     pMin = Min,
                     Min = now.v, 
                     k = i;
            }
            if(pMin != Min && Min < INF) {
                now = q[k][day%k].top();
                if(!q[k][day%k].only()) continue;
                REP0(i, k) q[k][i].pop(now.id);
                Day = day + 1;
            } 
            if(Day + days == day + 1) break;
        }

        int sum = 0;
        REP1(i, 10) sum += q[i][0].n;
        PutInt(sum), putchar(' '), PutInt(Day), putchar('\n');
    }
    return 0;
}

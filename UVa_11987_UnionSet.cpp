#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define LL long long
#define is_digit(ch) ('0' <= ch && ch <= '9')
#define REP(i, n) for(int i = 1; i <= n; i++)

const int MAXn = 100000 + 5;

int fa[MAXn], Cnt[MAXn], id[2*MAXn];
LL sum[MAXn];

int find(int k) { return fa[k] == k ? k : fa[k] = find(fa[k]); }

int GetInt() {
    char ch = getchar(); 
    while(!is_digit(ch)) ch = getchar();
    int x = 0;
    while(is_digit(ch)) x = x*10 + ch - '0', ch = getchar();
    return x;
}

template<class T>
void PutInt(T x) {
    int buf[30], cur = 0;
    if(!x) buf[++cur] = 0;
    else while(x) buf[++cur] = x%10, x /= 10;
    for(int i = cur; i > 0; i--) putchar(buf[i] + '0');
}

int main() {
    int n, m;
    while(scanf("%d%d", &n, &m) == 2 && n && m) {
        REP(i, n)
            id[i] = fa[i] = i, 
            sum[i] = (LL)i,
            Cnt[i] = 1;
        int op, p, q, x, y;
        REP(i, m) {
            op = GetInt();
            switch (op) {
                case 1:
                    p = GetInt(), q = GetInt();
                    x = find(id[p]), y = find(id[q]);
                    if(x != y)
                        fa[x] = y,
                        sum[y] += sum[x],
                        sum[x] = 0,
                        Cnt[y] += Cnt[x],
                        Cnt[x] = 0;
                    break;
                case 2:
                    p = GetInt(), q = GetInt();
                    x = find(id[p]), y = find(id[q]);
                    if(x != y) {
                        sum[y] += p, sum[x] -= p,
                        Cnt[y] ++, Cnt[x] --,
                        sum[++n] = p, Cnt[n] = 1, id[p] = n, //add a new element instead of it
                        fa[n] = y;
                    }
                    break;
                case 3:
                    p = GetInt();
                    x = find(id[p]);
                    PutInt(Cnt[x]); putchar(' '); PutInt(sum[x]); putchar('\n');
            }
        }
    }
    return 0;
}

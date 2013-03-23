/*
ID: liu.yu.pa1
LAnG: C++
PROG: poker
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long
#define REP(i, n) for(int i = 1; i <= n; i++)
#define PER(i, n) for(int i = n; i >= 1; i--)
using namespace std;

const int MAXn = 100000 + 5;

struct node {
    int x, id;
    bool operator < (const node& a) const {return x < a.x;}
} A[MAXn];
int left[MAXn], right[MAXn], C[MAXn], n;

inline int lowbit(int x){return x & (-x);}

void change(int k, int v) {for(; k <= n; k += lowbit(k)) C[k] += v;}

int query(int k) {
    int ans = 0;
    for(; k; k -= lowbit(k)) ans += C[k];
    return ans;
}

int main() {
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    memset(C, 0, sizeof(C));
    scanf("%d", &n);
    REP(i, n) 
        scanf("%d", &A[i].x),
        A[i].id = i;

    A[0].x = A[n+1].x = -1;
    REP(i, n) left[i] = A[i].x <= A[i-1].x ? left[i-1] : i;
    PER(i, n) right[i] = A[i].x <= A[i+1].x ? right[i+1] : i;
    sort(A+1, A+n+1);

    LL ans = 0;
    REP(k, n) {
        int i = A[k].id, x = query(A[k].id) + A[k].x;
        if(!x) continue;
        change(left[i], -x),
        change(right[i]+1, x);
        ans += (LL)x;
    }
    printf("%lld\n", ans);
    fclose(stdin), fclose(stdout);
    return 0;
}

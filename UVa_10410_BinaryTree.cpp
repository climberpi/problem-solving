#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define is_digit(ch) ('0' <= ch && ch <= '9')
#define REP(i, n) for(int i = 1; i <= (n); i++)

const int MAXn = 1000 + 5;

int BFS[MAXn], DFS[MAXn], A[MAXn], B[MAXn], level[MAXn], loc[MAXn];
vector<int> son[MAXn];

int GetInt() {
    char ch = getchar();
    while(!is_digit(ch)) ch = getchar();
    int x = 0;
    while(is_digit(ch)) x = 10*x + ch - '0', ch = getchar();
    return x;
}

void PutInt(int x) {
    char buf[5], cur = 0;
    if(!x) buf[++cur] = x;
    else while(x) buf[++cur] = x%10, x /= 10;
    for(int i = cur; i > 0; i--) putchar(buf[i] + '0');
}

int main() {
    int n;
    while(scanf("%d", &n) == 1 && n) {
        memset(level, 0, sizeof(level));
        REP(i, n) B[i] = GetInt(), A[B[i]] = i, BFS[i] = i;
        REP(i, n) DFS[i] = GetInt(), DFS[i] = A[DFS[i]];

        int prev = 1;
        level[1] = 1;
        for(int i = 2; i <= n; i++) {
            if(DFS[i] > prev + 1 || (BFS[i-1] == DFS[i-1] && BFS[i] == DFS[i]))
                level[DFS[i]] = 1;
            prev = max(prev, DFS[i]);
        }
        REP(i, n) level[i] += level[i-1], son[i].clear();

        REP(i, n) {
            int Fa = DFS[i-1], Son = DFS[i];
            loc[level[Fa]] = Fa,
            loc[level[Son]] = Son;
            if(level[Fa] + 1 == level[Son]) son[Fa].push_back(Son);
            else son[loc[level[Son] - 1]].push_back(Son);
        }
       
        REP(j, n) {
            PutInt(j), putchar(':');
            int i = A[j];
            REP(k, (int)son[i].size()) 
                putchar(' '),
                PutInt(B[son[i][k-1]]);
            putchar('\n');
        }
    }
    return 0;
}

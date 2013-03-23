#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define is_digit(ch) (ch == '-' || ('0' <= ch && ch <= '9'))

const int MAXn = 1000 + 5, INF = ~0U>>1;

int f[MAXn][MAXn][2];
int A[MAXn], B[MAXn], An = 0, Bn = 0, n;

bool cmp(int i, int j) {return i > j;}

int GetInt() {
    char ch = getchar(); 
    while(!is_digit(ch)) ch = getchar();
    int x = 0, op = 1;
    if(ch == '-') op = -1, ch = getchar();
    while(is_digit(ch)) x = x*10 + ch - '0', ch = getchar();
    return op * x;
}

int main() {
    freopen("cowrun.in", "r", stdin);
    freopen("cowrun.out", "w", stdout);
    int x;
    n = GetInt();
    for(int i = 1; i <= n; i++) {
        x = GetInt();
        if(x > 0) A[++An] = x;
        else B[++Bn] = x;
    }
    A[0] = B[0] = 0;
    sort(A+1, A+An+1), sort(B+1, B+Bn+1, cmp);
    
    if(An) f[1][1][1] = A[1] * n;
    if(Bn) f[1][0][0] = -B[1] * n;
    for(int k = 2; k <= n; k++)
        for(int i = 0; i <= min(An, k); i++) if(k-i <= Bn && k-i >= 0) {
            int m = n - k + 1, j = k - i;
            f[k][i][1] = f[k][i][0] = INF;
            if(i-1 > 0) f[k][i][1] = min(f[k][i][1], f[k-1][i-1][1] + m*(A[i]-A[i-1]));
            if(j > 0) f[k][i][1] = min(f[k][i][1], f[k-1][i-1][0] + m*(A[i]-B[j]));
            if(i > 0) f[k][i][0] = min(f[k][i][0], f[k-1][i][1] + m*(A[i]-B[j]));
            if(k-i-1 > 0) f[k][i][0] = min(f[k][i][0], f[k-1][i][0] + m*(B[j-1]-B[j]));
        }
    printf("%d\n", min(An ? f[n][An][1] : INF, Bn ? f[n][An][0] : INF));
    fclose(stdin), fclose(stdout);
    return 0;
}


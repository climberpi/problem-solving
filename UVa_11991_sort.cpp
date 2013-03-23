#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXn = 1000000 + 5;

struct pair{
    int x, k;
    bool operator < (const pair& a) const {
        return x < a.x || (x == a.x && k < a.k);
    }
} A[MAXn];

int loc[MAXn];

int main() {
    int n, m;
    while(scanf("%d%d", &n, &m) == 2 && n && m) {
        for(int i = 1; i <= n; i++) 
            scanf("%d", &A[i].x),
            A[i].k = i;
        sort(A+1, A+n+1);
        A[0].x = -1;
        memset(loc, -1, sizeof(loc));
        for(int i = 1; i <= n; i++)
            if(A[i].x != A[i-1].x)
                loc[A[i].x] = i;

        int k, x;
        for(int i = 1; i <= m; i++) {
            scanf("%d%d", &k, &x);
            if(loc[x] == -1 || A[loc[x]+k-1].x != x)
                printf("0\n");
            else
                printf("%d\n", A[loc[x]+k-1].k);
        }
    }
    return 0;
}

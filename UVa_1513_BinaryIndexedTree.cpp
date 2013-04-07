#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define lowbit(x) (x&(-x))

const int MAXn = 100000+5, delta = 100000;

int C[MAXn * 2], A[MAXn], n, m;

void change(int k, int v) {
    for(; k <= n+m; k += lowbit(k)) C[k] += v;
}

int query(int k) {
    int x = 0;
    for(; k; k -= lowbit(k)) x += C[k];
    return x;
}

int main() {
    int T;
    scanf("%d", &T);
    while(T --) {
        scanf("%d%d", &n, &m);
        memset(C, 0, sizeof(C));
        int front = m+1;
        for(int i = 1; i <= n; i++) change(A[i] = m+i, 1);
        
        int op;
        bool first = 1;
        for(int i = 1; i <= m; i++) {
            scanf("%d", &op);
            
            printf("%s%d", first ? "" : " ", query(A[op]-1));
            first = 0;
            change(A[op], -1);
            change(A[op] = --front, 1);
        }
        printf("\n");
    }
    return 0;
}

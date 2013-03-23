#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;

const int MAXn = 750 + 5;
int A[MAXn], B[MAXn];

struct item {
    int s, b;
    item(int s, int b):s(s), b(b) { }
    bool operator < (const item& a) const {return s > a.s;}
};

void merge(int* A, int* B, int* C, int n) {
    priority_queue<item> q;
    for(int i = 1; i <= n; i++)
        q.push(item(A[i] + B[1], 1));
    for(int i = 1; i <= n; i++) {
        item now = q.top(); q.pop();
        int b = now.b, s = now.s; C[i] = now.s;
        if(b+1 <= n) q.push(item(s - B[b] + B[b+1], b+1));
    }
}

int main() {
    int n;
    while(scanf("%d", &n) == 1 && n) {
        for(int i = 1; i <= n; i++) scanf("%d", &A[i]);
        sort(A+1, A+n+1);
        for(int j = 1; j < n; j++) {
            for(int i = 1; i <= n; i++) scanf("%d", &B[i]);
            sort(B+1, B+n+1);
            merge(A, B, A, n);
        }

        bool first = 1;
        for(int i = 1; i <= n; i++)
            printf("%s%d", first ? "" : " ", A[i]),
            first = 0;;
        printf("\n");
    }
}

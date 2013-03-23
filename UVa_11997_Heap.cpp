#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define REP(i, n) for(int i = 1; i <= (n); i++)

const int MAXn = 750 + 5;
int A[MAXn], B[MAXn];

struct item {
    int s, b;
    bool operator < (const item& a) const {return s > a.s;}
};

struct heap {
    item h[MAXn]; 
    int n;

    void up(int k) {
        while(k > 1) if(h[k/2] < h[k])
            swap(h[k/2], h[k]),
            k /= 2;
        else break;
    }

    void down(int k) {
        while(k*2 <= n) {
            k *= 2;
            if(k < n && h[k] < h[k+1]) ++k;
            if(h[k/2] < h[k])
                swap(h[k/2], h[k]);
        }
    }

    void push(item x) {
        h[++n] = x;
        up(n);
    }

    item pop() {
        swap(h[1], h[n--]);
        down(1);
        return h[n+1];
    }
}q;

void merge(int* A, int* B, int* C, int n) {
    q.n = 0;  
    REP(i, n) q.push((item){A[i] + B[1], 1});
    REP(i, n) {
        item now = q.pop();
        int b = now.b; C[i] = now.s;
        if(b < n) q.push((item){C[i] - B[b] + B[b+1], b+1}); 
    }
}

int main() {
    int n;
    while(scanf("%d", &n) == 1 && n) {
        REP(i, n) scanf("%d", &A[i]); sort(A+1, A+n+1);
        REP(j, n-1) {
            REP(i, n) scanf("%d", &B[i]); sort(B+1, B+n+1);
            merge(A, B, A, n);
        }

        bool first = 1;
        REP(i, n) printf("%s%d", first?"":" ", A[i]), first = 0;
        printf("\n");
    }
    return 0;
}

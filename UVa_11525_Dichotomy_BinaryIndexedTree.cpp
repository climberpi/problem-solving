#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define lowbit(x) ((x)&(-(x)))
#define isdigit(ch) ('0' <= ch && ch <= '9')

const int MAXn = 50000 + 5;

int C[MAXn], n;

int query(int k) { int x = 0; for(; k; k -= lowbit(k)) x += C[k]; return x; }

void change(int k, int v) { for(; k <= n; k += lowbit(k)) C[k] += v; }

void initialize() {
    memset(C, 0, sizeof(C));
    for(int i = 1; i <= n; i++) {
        C[i] += 1;
        if(i+lowbit(i) <= n) C[i + lowbit(i)] += C[i];
    }
}

int GetInt() {
    char ch = getchar(); while(!isdigit(ch)) ch = getchar();
    int x = 0; while(isdigit(ch)) x = x*10 + ch - '0', ch = getchar();
    return x;
}

void PutInt(int x) {
    int buf[20], cur = 0;
    if(!x) buf[++cur] = 0;
    else while(x) buf[++cur] = x%10, x /= 10;
    for(int i = cur; i > 0; i--) putchar(buf[i] + '0');
}

int main() {
    int T, x;
    T = GetInt();
    while(T --) {
        n = GetInt();
        initialize();
        for(int i = 1; i <= n; i++) {
            x = GetInt();
            int L = 1, R = n;
            while(L < R) {
                int M = L + (R-L)/2;
                if(query(M) >= x+1) R = M;
                else L = M+1;
            }
            change(L, -1);
            if(i > 1) putchar(' ');
            PutInt(L);
        }
        putchar('\n');
    }
    return 0;
}

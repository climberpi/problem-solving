#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define isdigit(ch) ('0' <= ch && ch <= '9')

const int MAXn = 1 << 17;

int T[MAXn + 5];

int GetInt() {
    char ch = getchar(); while(!isdigit(ch)) ch = getchar();
    int x = 0; while(isdigit(ch)) x = x*10 + ch - '0', ch = getchar();
    return x;
}
void PutInt(int x) {
    int buf[20], cur = 0;
    if(!x) buf[++cur] = x;
    else while(x) buf[++cur] = x%10, x /= 10;
    for(int i = cur; i > 0; i--) putchar(buf[i] + '0');
}

int main() {
    int kase;
    kase = GetInt();
    while(kase --) {
        int x, n, M;
        n = GetInt();
        memset(T, 0, sizeof(T));
        for(M = 1; M < n+1; M <<= 1);
        for(int i = 2*M-1; i > 0; i--)
            if(i >= M) T[i] = 1;
            else T[i] = T[i<<1] + T[i<<1|1];

        for(int i = 1; i <= n; i++) {
            int idx = 1;
            x = GetInt(); x++;
            while(idx < M) 
                if(T[idx<<1] < x) x -= T[idx<<1], idx = idx<<1|1;
                else idx = idx << 1;
            if(i > 1) putchar(' ');
            PutInt(idx - M + 1);
            while(idx > 0) T[idx]--, idx >>= 1;
        }
        putchar('\n');
    }
    return 0;
}

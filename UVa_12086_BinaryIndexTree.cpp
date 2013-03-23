#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define is_digit(ch) ('0' <= ch && ch <= '9')
#define lowbit(k) ((k)&(-(k)))

const int MAXn = 200000 + 5;

int C[MAXn], A[MAXn], n;

int query(int k) {
    int ans = 0;
    for(; k; k -= lowbit(k)) ans += C[k];
    return ans;
}

void change(int k, int v) {
    for(; k <= n; k += lowbit(k)) C[k] += v;
}

int GetInt() {
    char ch = getchar();
    while(!is_digit(ch)) ch = getchar();
    int x = 0;
    while(is_digit(ch))
        x = x*10 + ch - '0',
        ch = getchar();
    return x;
}

int buf[30];
void PutInt(int x) {
    int cur = 0;
    if(!x) buf[++cur] = 0;
    else while(x) buf[++cur] = x%10, x /= 10;
    for(int i = cur; i > 0; i--) putchar(buf[i] + '0');
}

int main() {
    int kase = 0;
    while((n = GetInt()) && n) {
        if(kase) putchar('\n');
        memset(C, 0, sizeof(C));
        for(int i = 1; i <= n; i++)
            A[i] = GetInt(),
            change(i, A[i]);
        char op[5];
        printf("Case %d:\n", ++kase);
        while(scanf("%s", op) && op[0] != 'E') {
            if(op[0] == 'S') {
                int x, r;
                x = GetInt(), r = GetInt();
                change(x, r - A[x]);
                A[x] = r;
            }
            else {
                int x, y;
                x = GetInt(), y = GetInt();
                PutInt(query(y) - query(x-1));
                putchar('\n');
            }
        }
    }
    return 0;
}

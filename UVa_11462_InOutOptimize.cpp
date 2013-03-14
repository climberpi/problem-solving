#include<cstdio>
#include<cstring>
#define isdigit(c) (((c) >= '0' && (c) <= '9') ? 1 : 0)

const int MAXn = 100 + 5;

int Cnt[MAXn], buf[15];

int GetInt() {
    char ch = getchar();
    while(!isdigit(ch)) ch = getchar();

    int x = 0;
    while(isdigit(ch)) {
        x = x*10 + ch - '0';
        ch = getchar();
    }
    return x;
}

void PutInt(int x) {
    int p = 0;
    buf[1] = 0;
    if(x) while(x) {
        buf[++p] = x % 10;
        x /= 10;
    } else p++;
    for(int i = p; i > 0; i--) 
        putchar('0' + buf[i]);
}

int main() {
    int n, x;
    while(n = GetInt()) {
        memset(Cnt, 0, sizeof(Cnt));
        for(int i = 1; i <= n; i++)
            Cnt[x = GetInt()] ++;
        bool first = 1;
        for(int i = 1; i <= 100; i++)
            for(int j = 1; j <= Cnt[i]; j++) {
                if(!first) putchar(' '); else first = 0;
                PutInt(i);
            }
        printf("\n");
    }
    return 0;
}

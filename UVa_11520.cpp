#include<cstdio>
#include<cstring>

const int MAXn = 12;

char G[MAXn][MAXn];

int main(){
    int T, n;
    scanf("%d", &T);
    for(int kase = 1; kase <= T; kase ++) {
        memset(G, 0, sizeof(G));
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) scanf("%s", G[i]+1);
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                if(G[i][j] == '.')
                    for(char ch = 'A'; ch <= 'Z'; ch++)
                        if(G[i-1][j] != ch && G[i+1][j] != ch && G[i][j-1] != ch && G[i][j+1] != ch) {
                            G[i][j] = ch;
                            break;
                        }
        printf("Case %d:\n", kase);
        for(int i = 1; i <= n; i++) printf("%s\n", G[i]+1);
    }
    return 0;
}

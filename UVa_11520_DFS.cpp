#include<cstdio>
#include<cstring>

const int MAXn = 10 + 5;

int G[MAXn][MAXn], n;

bool dfs(int i, int j) {
    if(i == n+1) return 1;
    if(j == n+1) return dfs(i+1, 1);
    if(G[i][j] != -1) return dfs(i, j+1);
    
    for(int k = 0; k < 26; k++) 
        if(G[i-1][j] != k && G[i+1][j] != k && G[i][j-1] != k && G[i][j+1] != k) {
            G[i][j] = k;
            if(dfs(i, j+1)) return 1;
        }
    return 0;
}

int readit() {
    char x = 0;
    while(!(x == '.' || ('A' <= x && x <= 'Z'))) scanf("%c", &x);
    return x == '.' ? -1 : x - 'A';
}

int main(){
    int T;
    scanf("%d", &T);
    for(int k = 1; k <= T; k++) {
        memset(G, -1, sizeof(G));
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                G[i][j] = readit();
        
        dfs(1, 1);

        printf("Case %d:\n", k);
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++)
                printf("%c", G[i][j] + 'A');
            printf("\n");
        }
    }
    return 0;
}

#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)

const int MAXn = 10;
char G[MAXn][MAXn][MAXn], vis[6][MAXn][MAXn];
int N;

char rchar(){
    char x = 0;
    while(!(x == '.' || (x >= 'A' && x <= 'Z'))) scanf("%c", &x);
    return x;
}

void get(int id, int i, int j, int k, int& x, int & y, int& z){
    switch(id){
        case 0: x = i, y = j, z = k; break;
        case 1: x = i, y = k, z = N-1-j; break;
        case 2: x = i, y = N-1-j, z = N-1-k; break;
        case 3: x = i, y = N-1-k, z = j; break;
        case 4: x = k, y = j, z = N-1-i; break;
        case 5: x = N-1-k, y = j, z = i; break;
    }
}

int main(){
    int x, y, z;
    while(scanf("%d", &N) == 1 && N){
        REP(i, N) REP(k, 6) REP(j, N) vis[k][i][j]= rchar();
        REP(i, N) REP(j, N) REP(k, N) G[i][j][k] = '#';

        REP(k, 6) REP(i, N) REP(j, N) if(vis[k][i][j] == '.') REP(p, N) {
                get(k, i, j, p, x, y, z);
                G[x][y][z] = '.';
        }

        for(;;){
            bool flag = 1;
            REP(k, 6) REP(i, N) REP(j, N) if(vis[k][i][j] != '.') REP(p, N) {
                get(k, i, j, p, x, y, z);
                if(G[x][y][z] == '.') continue;
                if(G[x][y][z] == '#') {
                    G[x][y][z] = vis[k][i][j];
                    break;
                }
                if(G[x][y][z] == vis[k][i][j]) break;
                G[x][y][z] = '.';
                flag = 0;
            }
            if(flag) break;
        }
        
        int ans = 0;
        REP(i, N) REP(j, N) REP(k, N) if(G[i][j][k] != '.') ans++;

        printf("Maximum weight: %d gram(s)\n", ans);
    }
    return 0;
}

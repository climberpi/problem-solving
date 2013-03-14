#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
#define REP(i, s, t) for(int i = (s); i <= (t); i++)

const int MAXn = 20, INF = ~0U>>1;

int A[MAXn][MAXn], B[MAXn][MAXn];

int main(){
    int T, n;
    scanf("%d", &T);
    REP(K, 1, T) {
        int ans = INF;
        scanf("%d", &n);
        REP(i, 1, n) REP(j, 1, n) scanf("%d", &A[i][j]);

        for(int S = 0; S < (1<<n); S++) {
            int Cnt = 0;
            bool flag = 1;
            for(int i = 0; i < n; i++) {
                int& k = B[1][i+1] = ((1<<i) & S);
                if(!k && A[1][i+1]) {
                    flag = 0;
                    break;
                } else if(k && !A[1][i+1]) Cnt++;
            }

            REP(i, 1, n-1) {
                if(!flag) break;
                REP(j, 1, n) {
                    if(!flag) break;
                    B[i+1][j] = A[i+1][j];
                    if((B[i][j-1]^B[i][j+1]) && (!B[i+1][j]^B[i-1][j])) {
                        if(B[i-1][j]) {
                            flag = 0;
                            break;
                        }
                        Cnt++,
                        B[i+1][j] ^= 1;
                    }
                    if(!(B[i][j-1]^B[i][j+1]) && (B[i+1][j]^B[i-1][j])) {
                        if(!B[i-1][j]) {
                            flag = 0;
                            break;
                        }
                        Cnt++,
                        B[i+1][j] ^= 1;
                    }
                }   
            }
            
            REP(j, 1, n) if(B[n][j-1]^B[n][j+1]^B[n-1][j]^B[n+1][j]) {
                flag = 0;
                break;
            }

            if(!flag) continue;

            ans = min(ans, Cnt);
        }
        printf("Case %d: %d\n", K, ans != INF ? ans : -1);
    }
    return 0;
}

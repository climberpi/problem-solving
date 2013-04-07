#include<cstdio>
#include<cstring>
#include<map>
#include<string>
#include<algorithm>
using namespace std; 
#define REP(i, n) for(int i = 1; i <= (n); i++)

const int MAXn = 150 + 5, MAXm = 1000000 + 5, MAXs = 80;

map<string, int> ms;
char text[MAXm], P[MAXn][MAXs];
int Cnt[MAXn], f[MAXs];

void getFail(char* P, int* f) {
    int m = strlen(P);
    f[0] = f[1] = 0;
    for(int i = 1; i < m; i++) {
        int j = f[i];
        while(j && P[i] != P[j]) j = f[j];
        f[i+1] = (P[i] == P[j]) ? j+1 : 0;
    }
}


void find(char* T, char* P, int* f, int k) {
    int n = strlen(T), m = strlen(P);
    getFail(P, f);
    int j = 0;
    for(int i = 0; i < n; i++) {
        while(j && P[j] != T[i]) j = f[j];
        if(P[j] == T[i]) j++;
        if(j == m) Cnt[k]++;
    }
}

int main() {
    int n;
    while(scanf("%d", &n) == 1 && n) {
        memset(Cnt, 0, sizeof(Cnt));
        ms.clear();

        REP(i, n) scanf("%s", P[i]);
        scanf("%s", text);
        int best = -1;
        REP(i, n) {
            if(!ms.count(string(P[i])))
                getFail(P[i], f),
                find(text, P[i], f, i);
            else
                Cnt[i] = ms[string(P[i])];
            best = max(best, Cnt[i]);
        }
        printf("%d\n", best);
        REP(i, n) if(Cnt[i] == best) printf("%s\n", P[i]);
    }
    return 0;
}

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAXn 111111

int first[MAXn], next[MAXn], u[MAXn], v[MAXn], level[MAXn];
double need[MAXn];
int Cnt = 0;

void addEdge(int eu, int ev) {
    u[Cnt] = eu, v[Cnt] = ev;
    next[Cnt] = first[eu];
    first[eu] = Cnt;
    Cnt++;
}

void dfs(int k) {
    int e;
    for(e = first[k]; e != -1; e = next[e]) {
        level[v[e]] = level[k] + 1;
        dfs(v[e]);
    }
}

double pow(double x, int y) {
    double ans = 1;
    int i;
    for(i = 0; i < y; i++)
        ans *= x;
    return ans;
}

int main() {
    int i, j, N, cnt, ev;
    double P, r;
    memset(first, -1, sizeof(first));
    memset(need, 0, sizeof(need));
    scanf("%d%lf%lf", &N, &P, &r);
    for(i = 0; i < N; i++) {
        scanf("%d", &cnt);
        if(!cnt) scanf("%lf", &need[i]);
        for(j = 0; j < cnt; j++) {
            scanf("%d", &ev);
            addEdge(i, ev);
        }
    }

    level[0] = 0;
    dfs(0);

    double ans = 0;
    for(i = 0; i < N; i++) {
        if(abs(need[i]) < 1e-6) continue;
        ans += need[i]*P*pow(1.0+r/100.0, level[i]);
    }
    printf("%.1lf\n", ans);
    return 0;
}

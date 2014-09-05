#include<cstdio>
#include<cstring>
#include<cstdlib>

const int MAXn = 2000 + 4;
int x[MAXn], y[MAXn], map[MAXn*MAXn], 
    u[MAXn*MAXn], v[MAXn*MAXn], w[MAXn*MAXn], first[MAXn], next[MAXn*MAXn], Cnt = 0,
    fa[MAXn];

void addEdge(int eu, int ev, int ew) {
    v[++Cnt] = ev, u[Cnt] = eu, w[Cnt] = ew;
    next[Cnt] = first[eu]; first[eu] = Cnt;
    map[Cnt] = Cnt;
}

inline int dist(int i, int j){
    return (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
}

int cmp(const void *i, const void *j) {
    int I = *(int*)i, J = *(int*)j;
    return w[I] > w[J] ? 1 : -1;
}

int find(int k) {return fa[k] == k ? k : fa[k] = find(fa[k]);}

int main() {
    freopen("irrigation.in", "r", stdin);
    freopen("irrigation.out", "w", stdout);
    int N, C;
    memset(first, -1, sizeof(first));
    scanf("%d%d", &N, &C);
    for(int i = 1; i <= N; i++) {
        scanf("%d%d", &x[i], &y[i]);
        fa[i] = i;
        for(int j = 1; j < i; j++)
            addEdge(i, j, dist(i, j));
    }
    qsort(map+1, Cnt, sizeof(int), cmp);
    
    int ans = 0;
    for(int i = 1; i <= Cnt; i++) {
        int e = map[i], x = find(u[e]), y = find(v[e]);
        if(w[e] < C) continue;
        if(x != y)
            fa[x] = y,
            ans += w[e];
    }

    bool flag = 1;
    for(int i = 1; i < N; i++)
        if(fa[i] != fa[N]) {
            flag = 0;
            break;
        }
    if(!flag) ans = -1;

    printf("%d\n", ans);
    fclose(stdin), fclose(stdout);
    return 0;
}

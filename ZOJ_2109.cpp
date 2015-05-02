#include<cstdio>
#include<cstring>
#include<cstdlib>

const int MAXn = 111111;

int F[MAXn], J[MAXn], rank[MAXn];

int cmp(const void *x, const void *y) {
    int i = *(int*)x, j = *(int*)y;
    if (J[i]*F[j] < J[j]*F[i]) return 1;
    else return -1;
}

int main() {
    int M, N;
    while(scanf("%d%d", &M, &N) == 2 && M != -1 && N != -1) {
        for(int i = 0; i < N; i++)
            scanf("%d%d", &J[i], &F[i]),
            rank[i] = i;
        qsort(rank, N, sizeof(int), cmp);
        double ans = 0;
        for(int I = 0; I < N; I++) {
            int i = rank[I];
            if(M-F[i] >= 0)
                M -= F[i],
                ans += J[i];
            else
                ans += (double)M/F[i] * J[i],
                M = 0;
        }
        printf("%.3lf\n", ans);
    }
    return 0;
}

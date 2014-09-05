#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAXn 40000
#define MAXm 100

int Ge[MAXn], Gi[MAXn], map[MAXn], ds[MAXn][5];
int quota[MAXm], ad[MAXm][MAXn];

int cmp(const void* x, const void* y) {
    int i = *(int*)x, j = *(int*)y;
    if(Ge[i]+Gi[i] < Ge[j]+Gi[j])
        return 1;
    else if(Ge[i]+Gi[i] > Ge[j]+Gi[j])
        return -1;
    else if(Ge[i] < Ge[j]) return 1;
    else return -1;
}

int cmp1(const void *x, const void *y) {
    int i = *(int*)x, j = *(int*)y;
    return i > j ? 1: -1;
}

int main() {
   int i, j, N, M, K;
   memset(ad, 0, sizeof(ad));
   scanf("%d%d%d", &N, &M, &K);
   for(i = 0; i < M; i++)
       scanf("%d", &quota[i]);
   for(i = 0; i < N; i++)
       map[i] = i,
       scanf("%d%d%d%d%d", &Ge[i], &Gi[i], &ds[i][0], &ds[i][1], &ds[i][2]);

   qsort(map, N, sizeof(int), cmp);

   for(j = 0; j < N; j++) {
        i = map[j];
        int k;
        for(k = 0; k < 3; k++) {
            int sch = ds[i][k];
            if(ad[sch][0] < quota[sch]) {
                ad[sch][++ad[sch][0]] = i;
                break;
            }
            else if(Ge[i] == Ge[ad[sch][ad[sch][0]]] && Gi[i] == Gi[ad[sch][ad[sch][0]]]) {
                ad[sch][++ad[sch][0]] = i;
                break;
            }
        }
   }

   for(i = 0; i < M; i++) {
        int first = 1;
        qsort(ad[i]+1, ad[i][0], sizeof(int), cmp1);
        for(j = 1; j <= ad[i][0]; j++) {
            if(first) first = 0;
            else printf(" ");
            printf("%d", ad[i][j]);
        }
        printf("\n");
   }
   return 0;
}

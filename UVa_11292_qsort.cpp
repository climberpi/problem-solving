//@UVa. Jan 22, 2013.
#include<cstdio>
#include<cstdlib>
#include<cstring>
#define REP(i, n) for((i) = 1; (i) <= (n); (i)++)
const int MAXn = 22222;
int A[MAXn], B[MAXn];

int cmp(const void *a, const void *b){return *(int*)a > *(int*)b ? 1 : -1;}

int main(){
    int i, j, n, m;
    while(1){
        scanf("%d%d", &n, &m);
        if(n == 0 && m == 0) break;
        if(m < n){
            printf("Loowater is doomed!\n");
            continue;
        }
        REP(i, n) scanf("%d", &A[i]);
        REP(i, m) scanf("%d", &B[i]);
        qsort(A+1, n, sizeof(int), cmp);
        qsort(B+1, m, sizeof(int), cmp);

        bool flag = 1;
        int sum = 0, d = 0;
        REP(i, n){
            while(i+d <= m && A[i] > B[i+d]) ++d;
            if(i+d > m){
                flag = 0;
                break;
            }
            sum += B[i+d];
        }
        if(flag) printf("%d\n", sum);
        else printf("Loowater is doomed!\n");
    }
    return 0;

}


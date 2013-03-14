#include<cstdio>
#include<algorithm>
using namespace std;

const int MAXn = 1000 + 5;
int B[MAXn], J[MAXn], id[MAXn];

bool cmp(int i, int j){
    return (J[i] > J[j] || (J[i] == J[j] && B[i] > B[j])) ? 1 : 0;
}

int max(int x, int y){return x > y ? x : y;}

int main(){
    int i, j, N, Count = 0;
    while(scanf("%d", &N) == 1 && N){
        ++ Count;
        int t1 = 0, t2 = 0;
        for(i = 0; i < N; i++)
            id[i] = i,
            scanf("%d%d", &B[i], &J[i]);
        sort(id, id+N, cmp);
        for(i = 0; i < N; i++){
            int I = id[i];
            t1 += B[I];
            t2 = max(t2, t1 + J[I]);
        }
        printf("Case %d: %d\n", Count, t2);
    }
}

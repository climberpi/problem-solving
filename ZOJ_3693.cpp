#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

int main() {
    int N, K;
    double M;
    while(scanf("%d%lf%d", &N, &M, &K) == 3) {
        N += 2;
        int Cnt = N - N/K;
        printf("%.2lf\n", Cnt*M/2.0 + 1e-9);
    }
    return 0;
}

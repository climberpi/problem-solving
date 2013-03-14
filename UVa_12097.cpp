#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

const int MAXn = 10000 + 5;
const double pi = acos(-1.0);

int N, F;
double S[MAXn];

bool check(double M){
    int Cnt = 0;
    for(int i = 1; i <= N; i++)
        Cnt += floor(S[i] / M); 
    return Cnt > F;
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        double L = 0, R, r;
        scanf("%d%d", &N, &F);
        for(int i = 1; i <= N; i++)
            scanf("%lf", &r),
            S[i] = pi*r*r,
            R += S[i];
        R /= (double)F+1;

        while(R-L > 1e-5) {
            double M = (L+R) / 2.0;
            if(check(M)) L = M;
            else R = M;
        }

        printf("%.4lf\n", L);
    }
    return 0;
}

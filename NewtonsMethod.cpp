#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

double f[20], df[20];
int Nf, Ndf;

double calc(int n, double* f, double x0) {
    double ans = 0;
    for(int i = 0; i <= n; i++) {
        double tmp = f[i];
        for(int j = 0; j < i; j++)
            tmp *= x0;
        ans += tmp;
    }
    return ans;
}

void NewtonsMethod(int n, double x0, double& x1) {
    if(!n) return;
    n--;
    printf("[%lf]\n", x1);
    x1 =  x0 - calc(Nf, f, x0) / calc(Ndf, df, x0);
    NewtonsMethod(n, x1, x1);
}

int main() {
    int n;
    while(1) {
        scanf("%d%d", &n, &Nf); Ndf = Nf - 1;
        for(int i = Nf; i >= 0; i--) scanf("%lf", &f[i]);
        for(int i = 1; i <= Nf; i++) df[i-1] = f[i]*i;
        double x0;
        scanf("%lf", &x0);
        NewtonsMethod(n, x0, x0);
        printf("%lf\n", x0);
    }
}

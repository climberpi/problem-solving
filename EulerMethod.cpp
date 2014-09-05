#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

double derivitive(double x, double y) {
    return 
        -0.5*x*x-y
    ;
}

int main() {
    double x, y, n, gap;
    scanf("%lf%lf%lf%lf", &x, &y, &n, &gap);
    for(; x < n; x += gap) {
        y += gap*derivitive(x, y);
        //printf("(%lf, %lf)\n", x+gap, y);
    }
    printf("%lf\n", y);
    return 0;
}

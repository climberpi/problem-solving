#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXn = 1000 + 5, INF = ~0U>>1;

int circle[MAXn], product[MAXn][15];
bool dead[MAXn];

int gcd(int x, int y) {return !y ? x : gcd(y, x%y);}

int lcm(int x, int y) {if(x < y) swap(x, y); return x/gcd(x, y)*y;}

int main() {
    int T;
    scanf("%d", &T);
    while(T --) {
        int n, Days = 1;
        memset(dead, 0, sizeof(dead));
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) {
            scanf("%d", &circle[i]);
            Days = lcm(Days, circle[i]);
            for(int j = 0; j < circle[i]; j++)
                scanf("%d", &product[i][j]);
        }
        int Day = 0;
        for(int day = 0; day < n * Days; day++) {
            int pMin = -1, Min = INF, k;
            for(int i = 1; i <= n; i++) if(!dead[i]) {
                int produce = product[i][day % circle[i]];
                if(produce <= Min) 
                    pMin = Min,
                    Min = produce, 
                    k = i;
            }
            if(pMin != Min && Min < INF) 
                dead[k] = 1, Day = day + 1;
            if(Day + Days == day + 1) break;
        }

        int Cnt = 0;
        for(int i = 1; i <= n; i++) if(!dead[i]) Cnt++;
        printf("%d %d\n", Cnt, Day);
    }
    return 0;
}

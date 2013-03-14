#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

#define func(i) (f[(i)] + manhattan[(i)+1] - dist[(i)+1])

const int MAXn = 100000 + 5;

int x[MAXn], y[MAXn], f[MAXn], q[MAXn], dist[MAXn], manhattan[MAXn], w[MAXn];

int main() {
    int kase;
    scanf("%d", &kase);
    while(kase --) {
        int C, n; 
        scanf("%d%d", &C, &n);
        x[0] = y[0] = w[0] = dist[0] = 0;
        for(int i = 1; i <= n; i++) {
            scanf("%d%d%d", &x[i], &y[i], &w[i]);
            w[i] += w[i-1];
            manhattan[i] = abs(x[i]) + abs(y[i]);
            dist[i] = dist[i-1] + abs(x[i] - x[i-1]) + abs(y[i] - y[i-1]);
        }

        int front = 1, rear = 1; q[1] = 0;
        for(int i = 1; i <= n; i++) {
            while(front <= rear && w[i] - w[q[front]] > C) front++;
            f[i] = func(q[front]) + dist[i] + manhattan[i];
            while(front <= rear && func(q[rear]) >= func(i)) rear--;
            q[++rear] = i;
        }
        printf("%d\n", f[n]);
        if(kase) printf("\n");
    }
    return 0;
}

#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXn = 100000 + 5;

int fa[MAXn];

int find(int k) {return fa[k] == k ? k : fa[k] = find(fa[k]);}

int main() {
    int a, b;
    while(scanf("%d", &a) == 1) {
        for(int i = 0; i <= 100000; i++) fa[i] = i;
        int ans = 0;
        while(a != -1) {
            scanf("%d", &b);
            a = find(a), b = find(b);
            if(a == b) ++ans;
            else fa[a] = b;
            scanf("%d", &a);
        }
        printf("%d\n", ans);
    }
    return 0;
}

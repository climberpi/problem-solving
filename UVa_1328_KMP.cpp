#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXn = 1000000 + 5;

int f[MAXn];
char s[MAXn];

int main() {
    int n, kase = 0;
    while(scanf("%d", &n) == 1 && n) {
        scanf("%s", s);
        
        f[0] = f[1] = 0;
        for(int i = 1; i < n; i++) {
            int j = f[i];
            while(j && s[i] != s[j]) j = f[j];
            f[i+1] = (s[i] == s[j] ? j+1 : 0);
        }

        printf("Test case #%d\n", ++kase);
        for(int i = 2; i <= n; i++)
            if(f[i] > 0 && i % (i - f[i]) == 0)
                printf("%d %d\n", i, i / (i - f[i]));
        printf("\n");
    }
    return 0;
}

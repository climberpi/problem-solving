#include<cstdio>
#include<cstring>

int Cnt[100 + 5];

int main(){
    int n, x;
    while(scanf("%d", &n) == 1 && n) {
        memset(Cnt, 0, sizeof(Cnt));
        for(int i = 1; i <= n; i++)
            scanf("%d", &x),
            Cnt[x] ++;
        
        bool first = 1;
        for(int i = 1; i <= 100; i++)
            for(int j = 1; j <= Cnt[i]; j++) {
                if(!first) printf(" "); else first = 0;
                printf("%d", i);
            }
        printf("\n");
    }
    return 0;
}

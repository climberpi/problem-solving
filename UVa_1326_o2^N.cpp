//UVa 1326, LA 2965, Jurassic Remains
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXn = 1030;

char str[MAXn];
int A[30];

int getCode(const char* s) {
    int n = strlen(s), ans = 0;
    for(int i = 0; i < n; i++)
        ans ^= (1<<(s[i]-'A'));
    return ans;
}

int main() {
    int n;
    while(scanf("%d", &n) == 1 && n) {
        for(int i = 1; i <= n; i++) {
            scanf("%s", str);
            A[i] = getCode(str);
        }
        int Ans, Cnt = 0;
        for(int i = 1; i < (1<<n); i++) {
            int ok = 0, cnt = 0;
            for(int j = 0; j < n; j++) if(i & (1<<j)) {
                cnt ++;
                for(int k = 0; k < 26; k++) 
                    if(A[j+1] & (1<<k)) ok ^= (1<<k);
            }
            if(cnt > Cnt && !ok)
                Cnt = cnt,
                Ans = i;
        }
        bool first = 1;
        printf("%d\n", Cnt);
        for(int i = 0; i < n; i++)
            if(Ans & (1<<i))
                printf("%s%d", first ? "" : " ", i+1),
                first = 0;
        printf("\n");
    }
    return 0;
}

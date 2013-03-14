//UVa 1326, LA 2965, Jurassic Remains
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;

const int MAXn = 1030;

char str[MAXn];
int A[30];
map<int, int> table;

int getCode(const char* s) {
    int n = strlen(s), ans = 0;
    for(int i = 0; i < n; i++)
        ans ^= (1<<(s[i]-'A'));
    return ans;
}

int bitCnt(int x){return x == 0 ? 0 : bitCnt(x/2) + (x&1);}

int main() {
    int n;
    while(scanf("%d", &n) == 1 && n) {
        for(int i = 0; i < n; i++) {
            scanf("%s", str);
            A[i] = getCode(str);
        }
        table.clear();
        int n1 = n/2, n2 = n-n1;
        for(int i = 0; i < (1<<n1); i++) {
            int ans = 0;
            for(int j = 0; j < n1; j++) if(i & (1<<j)) ans ^= A[j];
            if(!table.count(ans) || bitCnt(table[ans]) < bitCnt(i))
                table[ans] = i;
        }
        int Ans = 0;
        for(int i = 0; i < (1<<n2); i++) {
            int ans = 0;
            for(int j = 0; j < n2; j++) if(i & (1<<j)) ans ^= A[n1+j];
            if(table.count(ans) && bitCnt(table[ans])+bitCnt(i) > bitCnt(Ans))
                Ans = (i<<n1) ^ table[ans];

        }

        bool first = 1;
        printf("%d\n", bitCnt(Ans));
        for(int i = 0; i < n; i++)
            if(Ans & (1<<i))
                printf("%s%d", first ? "" : " ", i+1),
                first = 0;
        printf("\n");
    }
    return 0;
}

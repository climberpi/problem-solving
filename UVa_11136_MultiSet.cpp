#include<cstdio>
#include<cstring>
#include<set>
#include<algorithm>
using namespace std;
#define is_digit(ch) ('0' <= ch && ch <= '9')

multiset<int> s;

int GetInt() {
    char ch = getchar();
    while(!is_digit(ch)) ch = getchar();
    int x = 0;
    while(is_digit(ch))
        x = x*10 + ch - '0',
        ch = getchar();
    return x;
}

int main() {
    int n;
    while(scanf("%d", &n) == 1 && n) {
        s.clear();
        int m, x;
        long long ans = 0;
        while(n --) {
            m = GetInt();
            for(int i = 1; i <= m; i++) 
                x = GetInt(),
                s.insert(x);
            multiset<int>::iterator min = s.begin(), max = s.end(); --max;
            ans += (long long)(*max - *min);
            s.erase(min), s.erase(max);
        }
        printf("%lld\n", ans);
    }
    return 0;
}

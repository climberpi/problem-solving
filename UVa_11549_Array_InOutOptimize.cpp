#include<cstdio>
#include<cstring>
#include<set>
#include<algorithm>
#include<cctype>
using namespace std;

int buf[25], p;

int GetInt() {
    char ch = getchar();
    while(!isdigit(ch)) ch = getchar();
    int x = 0;
    while(isdigit(ch)) {
        x = x*10 + ch - '0';
        ch = getchar();
    }
    return x;
}

void PutInt(int x) {
    p = 0;
    if(!x) buf[++p] = 0;
    else while(x) {
        buf[++p] = x % 10;
        x /= 10;
    }
    for(int i = p; i > 0; i--) 
        putchar(buf[i] + '0');
}

int next(int n, int k) {
    int ans = 0; p = 0;
    long long num = (long long)k*k;
    if(!num) buf[++p] = 0;
    else while(num) {
        buf[++p] = num % 10;
        num /= 10;
    }
    for(int i = p; i > 0 && p-i < n; i--)
        ans = ans*10 + buf[i];
    return ans;
}

int main() {
    int T;
    T = GetInt();
    while(T --) {
        int n, k, ans = 0;
        n = GetInt(), k = GetInt();
        set<int> s;
        while(!s.count(k)) {
            s.insert(k);
            ans = max(ans, k);
            k = next(n, k);
        }
       PutInt(ans), putchar('\n'); 
    }
    return 0;
}

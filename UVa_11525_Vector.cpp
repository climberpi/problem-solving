#include<cstdio>
#include<cstring>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
#define isdigit(ch) ('0' <= ch && ch <= '9')

int GetInt() {
    char ch = getchar(); while(!isdigit(ch)) ch = getchar();
    int x = 0; while(isdigit(ch)) x = x*10 + ch - '0', ch = getchar();
    return x;
}
void PutInt(int x) {
    int buf[20], cur = 0;
    if(!x) buf[++cur] = x;
    else while(x) buf[++cur] = x%10, x /= 10;
    for(int i = cur; i > 0; i--) putchar(buf[i] + '0');
}

int main() {
    int T;
    T = GetInt();
    while(T --) {
        int x, n;
        n = GetInt();
        vector<int> S;
        for(int i = 1; i <= n; i++) S.push_back(i);
        for(int i = 1; i <= n; i++) {
            x = GetInt();
            if(i > 1) putchar(' ');
            PutInt(S[x]);
            S.erase(S.begin() + x);
        }
        putchar('\n');
    }
    return 0;
}

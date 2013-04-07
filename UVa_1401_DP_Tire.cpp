#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define CLR(c) memset((c), 0, sizeof(c))
const int MAXl = 300000 + 5, MAXw = 4000 + 5, MAXwl = 100 + 5, MOD = 20071027;

int f[MAXl], len[MAXw];
char str[MAXl], word[MAXwl];

struct Tire {
    int ch[MAXw*MAXwl][26], val[MAXw*MAXwl], Cnt;

    void clear() { Cnt = 1; CLR(ch); }

    void insert(const char* str, int v) {
        int u = 0, len = strlen(str);
        for(int i = 0; i < len; i++) {
            int c = str[i] - 'a';
            if(!ch[u][c]) CLR(ch[Cnt]), val[Cnt] = 0, ch[u][c] = Cnt++;
            u = ch[u][c];
        }
        val[u] = v;
    }

    void find(const char* s, int len, vector<int>& ans) {
        int u = 0;
        for(int i = 0; i < len; i++) {
            if(s[i] == '\0') break;
            int c = s[i] - 'a';
            if(!ch[u][c]) break;
            u = ch[u][c];
            if(val[u] != 0) ans.push_back(val[u]);
        }
    }
}tire;

int main() {
    int kase = 0, L, n;
    while(scanf("%s%d", str, &n) == 2) {
        tire.clear();
        for(int i = 1; i <= n; i++) {
            scanf("%s", word);
            len[i] = strlen(word);
            tire.insert(word, i);
        }
        CLR(f);
        f[L = strlen(str)] = 1;
        for(int i = L-1; i >= 0; i--) {
            vector<int> p;
            tire.find(str+i,  L-i, p);
            for(int j = 0; j < (int)p.size(); j++) 
                f[i] = (f[i] + f[i+len[p[j]]]) % MOD;
        }
        printf("Case %d: %d\n", ++kase, f[0]);
    }
}

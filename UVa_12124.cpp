#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

const int MAXn = 1000 + 5;

int Cnt, n, b;
map<string, int> ID;
struct Comp {int price, quality;};
vector<Comp> C[MAXn];

int getID(string s) {
    if(!ID.count(s)) ID[s] = Cnt++;
    return ID[s];
}

bool check(int k) {
    int ans = 0;
    for(int i = 0; i < Cnt; i++) {
        int Min = b+1, m = C[i].size();
        for(int j = 0; j < m; j++)
            if(C[i][j].quality >= k) Min = min(Min, C[i][j].price);
        ans += Min;
        if(Min == b+1 || ans > b) return 0;
    }
    return 1;
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--) {
        int price, quality, MaxQ = 0;
        char sort[25], name[25];
        scanf("%d%d", &n, &b);
        Cnt = 0, ID.clear();
        for(int i = 0; i < n; i++) C[i].clear();
        for(int i = 1; i <= n; i++) {
            scanf("%s%s%d%d", sort, name, &price, &quality);
            C[getID(sort)].push_back((Comp){price, quality});
            MaxQ = max(MaxQ, quality);
        }

        int L = 0, R = MaxQ;
        while(L < R) {
            int M = L + (R-L+1)/2;
            if(check(M)) L = M;
            else R = M-1;
        }
        printf("%d\n", L);
    }
}

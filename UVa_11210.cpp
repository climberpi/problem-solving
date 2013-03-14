#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int A[34];
bool used[34];
vector<string> Ma;

void init() {
    for(int i = 1; i <= 3; i++)
        for(int j = 1; j <= 9; j++) {
            char str[6];
            sprintf(str, "%d", j);
            string s(str);
            switch (i) {
                case 1: s += "T"; break;
                case 2: s += "S"; break;
                case 3: s += "W"; break;
            }
            Ma.push_back(s);
        }
    Ma.push_back("DONG"); Ma.push_back("NAN"); Ma.push_back("XI"); Ma.push_back("BEI"); 
    Ma.push_back("ZHONG"); Ma.push_back("FA"); Ma.push_back("BAI"); 
}

int getID(const char* str) {
    string s(str);
    for(int i = 0; i < 34; i++)
        if(s == Ma[i])
            return i;
}

bool dfs(int k) {
    bool ok = 0;
    if(k == 34) return 1;
    if(!A[k]) return dfs(k+1);
   /* 
    if(ii == 12 && jj == 32){
        printf("{%d}   ", k);
        for(int i = 0; i < 34; i++)
            if(A[i]) printf("[%2d] %d ", i, A[i]);
        printf("\n");
    }*/

    if((0 <= k && k <= 6) || (9 <= k && k <= 15) || (18 <= k && k <= 24)) 
        if(A[k] && A[k+1] && A[k+2]) {
            A[k] --, A[k+1] --, A[k+2] --;
            ok = dfs(k);
            A[k] ++, A[k+1] ++, A[k+2] ++;
        }
    if(ok) return 1;

    if(A[k] >= 3) {
        A[k] -= 3;
        ok = dfs(k+1);
        A[k] += 3;
    }
    return ok;
}

int main(){
    int Cnt = 0;
    init();
    for(;;) {
        char str[6];
        memset(used, 0, sizeof(used));
        memset(A, 0, sizeof(A));
        for(int i = 1; i <= 13; i++) {
            scanf("%s", str);
            if(str[0] == '0') return 0;
            A[getID(str)] ++;
        }  

        printf("Case %d:", ++ Cnt);
        for(int i = 0; i < 34; i++) {
            bool ok = 0;
            A[i] ++;
            if(A[i] > 4) {
                A[i] --;
                continue;
            }
            for(int j = 0; j < 34; j++) {
                if(A[j] > 4) continue;
                if(A[j] >= 2)
                    A[j] -= 2,
                    ok = dfs(0),
                    A[j] += 2;
                if(ok) {
                    used[i] = 1;
                    break;
                }
            }
            A[i] --;
        }

        bool flag = 0;
        for(int i = 0; i < 34; i++)
            if(used[i]) {
                flag = 1;
                printf(" %s", Ma[i].c_str());
            }
        printf("%s\n", flag ? "" : " Not ready");
    }
    return 0;
}

#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXn = 20000 + 5;

int A[MAXn], B[MAXn];

bool cmp(int i, int j){return i < j;}

int main(){
    int i, j, n, m;
    while(scanf("%d%d", &n, &m) == 2 && n && m){
        bool flag = 1;
        for(i = 0; i < n; i++) scanf("%d", &A[i]);
        for(i = 0; i < m; i++) scanf("%d", &B[i]);
        sort(A, A+n, cmp), sort(B, B+m, cmp);
        
        int cost = 0, d = 0;
        if(m < n) flag = 0;
        else for(i = 0; i < n; i++){
            while(A[i] > B[i+d] && i+d < m) ++d;
            if(i+d == m){
                flag = 0;
                break;
            }
            else cost += B[i+d];
        }

        if(flag) printf("%d\n", cost);
        else printf("Loowater is doomed!\n");
    }
    return 0;
}


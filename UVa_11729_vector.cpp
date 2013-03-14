#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

struct Job {
    int J, B;
    bool operator < (const Job& x) const {return J > x.J;}
};

int main(){
    int N, B, J, Count = 0, i;
    while(scanf("%d", &N) == 1 && N){
        vector<Job>v;
        for(i = 0; i < N; i++)
            scanf("%d%d", &B, &J),
            v.push_back((Job){J, B});
        sort(v.begin(), v.end());
        int s = 0, ans = 0;
        for(i = 0; i < N; i++){
            s += v[i].B;
            ans = max(ans, s + v[i].J);
        }
        printf("Case %d: %d\n", ++Count, ans);
    }
}

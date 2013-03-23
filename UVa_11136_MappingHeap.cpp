#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define is_digit(ch) ('0' <= ch && ch <= '9')

const int MAXn = 1000000 + 5;

struct MaxMin_Heap {
    int MinQ[MAXn], MaxQ[MAXn], MaxL[MAXn], MinL[MAXn], n, A[MAXn], Cnt;

    inline void up(bool type, int* h, int* map, int k) {
        while(k > 1) {
            int &i = h[k/2], &j = h[k];
            if(type ? A[i] < A[j] : A[i] > A[j])
                swap(map[i], map[j]),
                swap(i, j),
                k /= 2;
            else break;
        }
    }

    inline void down(bool type, int* h, int* map, int k) {
        while(k*2 <= n) {
            k *= 2;
            if(k < n && (type ? A[h[k]] < A[h[k+1]] : A[h[k]] > A[h[k+1]])) k++;
            int &i = h[k/2], &j = h[k];
            if(type ? A[i] < A[j] : A[i] > A[j]) 
                swap(map[i], map[j]),
                swap(i, j);
            else break;
        }
    }

    void push(int x) {
        A[++Cnt] = x;
        ++n; 
        MinQ[MinL[Cnt] = n] = MaxQ[MaxL[Cnt] = n] = Cnt;
        up(1, MaxQ, MaxL, n);
        up(0, MinQ, MinL, n);
    }

    inline void del(int* h1, int* h2, int* map1, int* map2, int k1, int t) {
        int k2 = map2[h1[k1]];
        swap(map1[h1[k1]], map1[h1[t]]);
        swap(h1[k1], h1[t]);
        swap(map2[h2[k2]], map2[h2[t]]);
        swap(h2[k2], h2[t]);
    }

    void pop(int& Min, int& Max) {
        Min = A[MinQ[1]], Max = A[MaxQ[1]];
        del(MinQ, MaxQ, MinL, MaxL, 1, n--);
        del(MaxQ, MinQ, MaxL, MinL, 1, n--);
        down(1, MaxQ, MaxL, 1);
        down(0, MinQ, MinL, 1);
    }

}q;

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
        q.n = q.Cnt = 0;
        long long ans = 0;
        while(n --) {
            int m, x;
            m = GetInt();
            for(int i = 1; i <= m; i++) {
                x = GetInt();
                q.push(x);
            }
            int Min, Max;
            q.pop(Min, Max);
            ans += (long long)(Max - Min);
        }
        printf("%lld\n", ans);
    }
    return 0;
}

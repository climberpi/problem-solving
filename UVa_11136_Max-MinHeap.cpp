#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define is_digit(ch) ('0' <= ch && ch <= '9')

const int MAXn = 1000000 + 5;

struct MaxMin_Heap{
    int h[MAXn], n;

    inline bool get(int k) {
        int Cnt = 1;
        while(k /= 2) ++Cnt;
        return Cnt&1;
    }

    void up(int k) {
        bool flag = get(k);
        while(k > 1) 
            if(flag ? h[k/2] < h[k] : h[k/2] > h[k]) 
                swap(h[k/2], h[k]),
                flag ^= 1,
                k /= 2;
            else break;
        while(k > 3) 
            if(flag ? h[k/4] > h[k] : h[k/4] < h[k])
                swap(h[k/4], h[k]),
                k /= 4;
            else break;
    }

    void down(int k) {
        bool flag = get(k);
        while(k*2 <= n) {
            int x = flag ? ~0U>>1 : -1, xk;
            for(int i = 0; i < 4; i++) {
                int k1 = k*2+i, k2 = k*4+i;
                if(i < 2 && k1 <= n && (flag ? x > h[k1] : x < h[k1])) 
                    x = h[xk = k1];
                if(k2 <= n && (flag ? x > h[k2] : x < h[k2]))
                    x = h[xk = k2];
            }

            if(flag ? h[k] <= x : h[k] >= x) return;
            swap(h[k], h[xk]);
            if(xk >= k*4 && (flag ? h[xk/2] < h[xk] : h[xk/2] > h[xk]))
                swap(h[xk/2], h[xk]);

            if(xk < k*4) flag ^= 1;
            k = xk;
        }
    }

    void push(int x) {
        h[++n] = x;
        up(n);
    }
    
    void pop(int& Min, int& Max) {
        Min = h[1], Max = max(h[2], n>2 ? h[3] : 0);
        int k = (n > 2 && h[2]<h[3]) ? 3 : 2;
        swap(h[k], h[n--]); down(k);
        swap(h[1], h[n--]); down(1);
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
        q.n = 0;
        long long ans = 0;
        while(n --) {
            int m, x;
            m = GetInt();
            while(m --) {
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

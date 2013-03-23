#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXn = 1000 + 5;

int s[MAXn], q[MAXn];

struct Heap {
    int h[MAXn], n;

    void up(int k) {
        while(k > 1) if(h[k/2] < h[k]) {
            swap(h[k/2], h[k]);
            k /= 2;
        }else break;
    }

    void down(int k) {
        while(2*k <= n) {
            int l = 2*k, r = l<n ? l+1 : l;
            if(h[r] > h[l]) l++;
            if(h[k] < h[l]) {
                swap(h[k], h[l]);
                k = l;
            }else break;
        }
    }

    void insert(int x){ h[++n] = x, up(n); }

    void del(int k) { swap(h[k], h[n--]); down(k); }
} h;

int main() {
    int n;
    while(scanf("%d", &n) == 1 && n) {
        int front = 1, rear = 0, key = 0; h.n = 0;
        bool is_queue = 1, is_priority = 1, is_stack = 1;
        for(int i = 1; i <= n; i++) {
            int op, x;
            scanf("%d%d", &op, &x);
            if(op == 1) {
                if(is_queue) q[++rear] = x;
                if(is_priority) h.insert(x);
                if(is_stack) s[++key] = x;
            }
            else {
                if(is_queue) {
                    if(front > rear || q[front] != x)
                        is_queue = 0;
                    else
                        ++front;
                }
                if(is_stack) {
                    if(!key || s[key] != x)
                        is_stack = 0;
                    else 
                        key--;
                }
                if(is_priority) {
                    if(!h.n || h.h[1] != x)
                        is_priority = 0;
                    else
                        h.del(1);
                }
            }
        }
        
        int Cnt = is_queue + is_priority + is_stack;
        switch (Cnt) {
            case 0:
                printf("impossible\n");
                break;
            case 2: case 3:
                printf("not sure\n");
                break;
            default:
                if(is_queue) printf("queue\n");
                if(is_priority) printf("priority queue\n");
                if(is_stack) printf("stack\n");
        }
    }
    return 0;
}

#include<cstdio>
#include<cstring>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

queue<int> q;
priority_queue<int> p;
stack<int> s;

int main() {
    int n;
    while(scanf("%d", &n) == 1 && n) {
        bool is_queue = 1, is_pqueue = 1, is_stack = 1;
        while(!q.empty()) q.pop();
        while(!p.empty()) p.pop();
        while(!s.empty()) s.pop();
        for(int i = 1; i <= n; i++) {
            int op, x;
            scanf("%d%d", &op, &x);
            if(op == 1) {
                if(is_queue) q.push(x);
                if(is_pqueue) p.push(x);
                if(is_stack) s.push(x);
            }
            else {
                if(is_queue) {
                    if(q.empty() || q.front() != x) is_queue ^= 1;
                    else q.pop();
                }
                if(is_pqueue) {
                    if(p.empty() || p.top() != x) is_pqueue ^= 1;
                    else p.pop();
                }
                if(is_stack) {
                    if(s.empty() || s.top() != x) is_stack ^= 1;
                    else s.pop();
                }
            }
        }
        int Cnt = is_queue + is_pqueue + is_stack;
        switch (Cnt) {
            case 0:
                printf("impossible\n");
                break;
            case 2: case 3:
                printf("not sure\n");
                break;
            default:
                if(is_queue) printf("queue\n");
                if(is_pqueue) printf("priority queue\n");
                if(is_stack) printf("stack\n");
        }
    }
    return 0;
}

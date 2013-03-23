#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define is_legal(ch)  (('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z') || ch == '_' || ch == '[' || ch == ']')

const int MAXn = 100000 + 5;

char s[MAXn];
int next[MAXn], front_next[MAXn];

int main() {
    char ch;
    while((ch = getchar()) && ch != EOF) {
        int len = 0;
        while(!is_legal(ch)) ch = getchar();
        do { 
            s[len ++] = ch;
            ch = getchar();
        } while(is_legal(ch));
        //ch = getchar();

        memset(next, -1, sizeof(next));
        memset(front_next, -1, sizeof(front_next));
        int front = 0, tail = 0;
        for(int i = 0; i < len; i++) 
            if(s[i] != '[' && s[i] != ']') {
                if(i) next[i-1] = i;
            }
            else if(s[i] == '[')
                front_next[i] = front,
                front = i;
            else 
                front_next[tail] = i,
                tail = i;
        for(int cur = front; cur != -1; cur = front_next[cur])
            for(int k = cur; k != -1; k = next[k])
                if(s[k] != '[' && s[k] != ']')
                    putchar(s[k]);
        printf("\n");
    }
    return 0;
}

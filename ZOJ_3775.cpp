#include<cstdio>
#include<cstring>
#include<cstdlib>

const int MAXn = 1111;
char in[MAXn], ans[MAXn];

int main() {
    int T;
    scanf("%d\n", &T);
    while(T --) {
        fgets(in, 1111, stdin);
        in[strlen(in)-1] = 0;
        memset(ans, 0, sizeof(ans));
        int k = 0, L = strlen(in);
        for(int i = 0; i < L; i++) {
            if(in[i] == '!')  {
                sprintf(ans+k, "Hello, world!");
                k += 13;
            }
            if(in[i] == '_') {
                sprintf(ans+k, "%s", in);
                k += strlen(in);
            }
            if(strlen(ans) > strlen(in)) break;
        }
        //printf("#%s#$%s$\n", in, ans);
        printf("%s\n", !strcmp(in, ans) ? "Yes" : "No");
    }
    return 0;
}

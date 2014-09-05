#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char s[110][260] = {0};

int min(int x, int y) {return x < y ? x : y;}

int main() {
    int n, i, j, len = 300;;
    scanf("%d\n", &n);
    for(i = 0; i < n; i++) {
        fgets(s[i], 258, stdin);
        len = min(len, strlen(s[i]));
    }
    int ans = 0;
    for(j = 0; j < len; j++) {
        int flag = 1;
        char tag = s[0][strlen(s[0])-j-1];
        for(i = 0; i < n; i++)
            if(tag != s[i][strlen(s[i])-j-1]) {
                flag = 0;
                break;
            }
        if(flag) ans++;
        else break;
    }
    ans --;
    if(!ans) printf("nai\n");
    else printf("%s", s[0]+strlen(s[0])-1-ans);
    return 0;
}

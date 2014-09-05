#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

const int MAXn = 111;

int a[MAXn], s[MAXn];

int main() {
    int n, ans;
    memset(s, 0, sizeof(s));
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        s[i] = s[i-1] + a[i];
    }

    ans = s[n];
    for(int i = 1; i <= n; i++)
        for(int j = i; j <= n; j++) {
            ans = max(ans, (j-i+1 - s[j] + s[i-1]) + s[n] - s[j] + s[i-1]);
        }
    printf("%d\n", s[n] == n ? n-1 : ans);

    
    return 0;
}

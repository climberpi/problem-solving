#include<cstdio>
#include<cstring>
#include<cstdlib>

int main() {
    freopen("odometer.in", "r", stdin);
    freopen("odometer.out", "w", stdout);
    int A[10], ans = 0, L, R;
    char tmp[20];
    scanf("%d%d", &L, &R);
    for(int i = L; i <= R; i++) {
        memset(A, 0, sizeof(A));
        sprintf(tmp, "%d", i);
        for(int j = 0; j < strlen(tmp); j++)
            A[tmp[j] - '0']++;
        for(int j = 0; j < 10; j++)
            if(A[j] == strlen(tmp)-1) {
                ans++;
                break;
            }
    }
    printf("%d\n", ans);
    fclose(stdin), fclose(stdout);
    return 0;
}

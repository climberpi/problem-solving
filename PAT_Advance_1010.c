#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAXn 15

int pow(int x, int y) {
    int i, ans = 1;
    for(i = 0; i < y; i++)
        ans *= x;
    return ans;
}

int main() {
    char sN1[MAXn], sN2[MAXn], tmp[MAXn];
    int N1[MAXn], N2[MAXn], tag, radix, radix2, i, j, flag = 0;
    scanf("%s%s%d%d", sN1, sN2, &tag, &radix);
    if(radix >= 2) {
        if(tag == 2) {
            strcpy(tmp, sN1);
            strcpy(sN1, sN2);
            strcpy(sN2, tmp);
        }
        memset(N1, 0, sizeof(N1));
        memset(N2, 0, sizeof(N2));
        for(i = 0; i < strlen(sN1); i++) {
            char cur = sN1[strlen(sN1)-i-1];
            if('0' <= cur && cur <= '9')
                N1[i] = cur - '0';
            else 
                N1[i] = cur - 'a' + 10;
        }
        for(i = 0; i < strlen(sN2); i++) {
            char cur = sN2[strlen(sN2)-i-1];
            if('0' <= cur && cur <= '9')
                N2[i] = cur - '0';
            else 
                N2[i] = cur - 'a' + 10;
        }

        long long num1 = 0, num2 = 0;
        for(i = 0; i < strlen(sN1); i++)
            num1 += pow(radix, i) * N1[i];
        for(i = 2; i < num1; i++) {
            num2 = 0;
            for(j = 0; j < strlen(sN2); j++)
                if(N2[j] >= i) {
                    i++;
                    break;
                }
            for(j = 0; j < strlen(sN2); j++)
                num2 += pow(i, j) * N2[j];
            if(num1 == num2) {
                flag = 1;
                radix2 = i;
                break;
            }
        }
    }
    if(flag)
        printf("%d\n", radix2);
    else
        printf("Impossible\n");
    return 0;
}

#include<cstdio>
#include<cstring>
#include<cstdlib>
#define CLR(c) memset((c), 0, sizeof((c)))
const int MAXn = 100000+5, MAXm = 1000+5;
int P[MAXn], Q[MAXm], N, T;

inline int max(int x, int y){return x > y ? x : y;}

int main(){
	int i, j, M, SumA;
	while(scanf("%d%d", &N, &T) == 2){
		for(i = 1; i <= N; i++)
			scanf("%d%d", &P[i], &Q[i]);
		for(i = 1; i <= T; i++){
			scanf("%d", &M);
			int ans = 0;
			for(j = 1; j <= N; j++)
				ans += max(P[j], Q[j]-M);
			printf("%d\n", ans);
		} 
	}
	system("pause");
} 

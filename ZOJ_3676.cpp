#include<cstdio>
#include<cstring>
#include<cstdlib>
#define CLR(c) memset((c), 0, sizeof((c)))
#define puT(c) printf("%d\n", (c))
const int MAXm = 1000+5;
int P, Q, C1[MAXm], C2[MAXm], Count[MAXm], N, T;

inline int lowbit(int x){return x & (-x);}

void change(int k, int v, int* C){
	for(; k <= 1000; k += lowbit(k))
		C[k] += v;
}

int query(int k, int* C){
	int ans = 0;
	for(; k; k -= lowbit(k))
		ans += C[k];
	return ans;
}

int main(){
	int i, j, M, SumA;
	while(scanf("%d%d", &N, &T) == 2){
		CLR(C1), CLR(C2), CLR(Count);
		SumA = 0;
		for(i = 1; i <= N; i++){
			scanf("%d%d", &P, &Q);
			if(P < Q)
				Count[Q - P] ++; 
			SumA += P;
		}
		for(i = 1; i <= 1000; i++){
			change(i, i*Count[i], C1);
			if(Count[i])
				change(i, Count[i], C2);
		}
		for(i = 1; i <= T; i++){
			scanf("%d", &M);
        	printf("%d\n", SumA + query(1000, C1) - query(1000, C2)*M - query(M-1, C1) + query(M-1, C2)*M);
		}
	}
}

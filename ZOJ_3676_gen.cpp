#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>
int random(int k){return int((double)rand()/RAND_MAX * (k-1) + 1);}
int main(){
	srand(time(NULL));
	int i, j, N = random(10), T = random(10);
	printf("%d %d\n", N, T);
	for(i = 1; i <= N; i++)
		printf("%d %d\n", random(10), random(10));
	for(i = 1; i <= T; i++)
		printf("%d\n", random(10));
	system("pause");
}

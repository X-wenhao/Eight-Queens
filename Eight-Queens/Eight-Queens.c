#include<stdio.h>
#define N 8
int main()
{
	int queen[N] = { -1,-1,-1,-1,-1,-1,-1,-1 };
	int i = 0, count = 0;
	do {
		queen[i]++;
		if (queen[0] == N - 1 && queen[1] == N - 2)break;
		if (queen[i] >= N) {
			queen[i--] = -1;
			continue;
		}
		int tell = 1;
		for (int j = 0; j < i; j++) {
			if (queen[i] == queen[j] || (queen[i] + i) == (queen[j] + j) || (queen[i] - i) == (queen[j] - j)) {
				tell = 0; break;
			}
		}
		if (tell) {
			if (i == N - 1) {
				count++;
				queen[i--] = -1;
			}
			else i++;
		}
		else if (queen[i] == N - 1) queen[i--] = -1;
	} while (1);
	printf("%d", count);
	getchar();
}
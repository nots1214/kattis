#include<stdio.h>
#include<math.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>


int main() {
	int N,M;
	int ans;

	std::cin >> N >> M;
	
	ans = M-N;
	if (fabs(360 + M - N) < fabs(ans))
		ans = 360 + M - N;
	if (fabs(360 + N - M) < fabs(ans))
		ans = -(360 + N-M);
	if (ans == -180)
		ans = 180;

	printf("%d", ans);

	return 0;
}
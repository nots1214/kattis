#include<stdio.h>
#include<math.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>


int main() {
	int X,N;
	int P[100];
	int ans = 0;
	int sum = 0;
	
	std::cin >> X;
	std::cin >> N;
	for (int i = 0; i < N; i++) {
		std::cin >>P[i];
		sum += P[i];
	}
	ans = X * (N + 1);
	ans -= sum;
	

	printf("%d", ans);

	return 0;
}
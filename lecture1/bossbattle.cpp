#include<stdio.h>
#include<math.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>


int main() {
	int N;
	int ans;

	std::cin >> N;
	
	if (N <= 2)
		ans = 1;
	else
		ans = N - 2;
	printf("%d", ans);
	//ans = X * (N + 1);
	//ans -= sum;
	

	//printf("%d", ans);

	return 0;
}
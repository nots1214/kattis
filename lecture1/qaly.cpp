#include<stdio.h>
#include<math.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>


int main() {
	int N;
	double q[100], y[100];
	double ans = 0;
	
	std::cin >> N;
	for (int i = 0; i < N; i++) {
		std::cin >> q[i] >> y[i];
		ans += q[i] * y[i];
	}
	

	printf("%lf", ans);

	return 0;
}
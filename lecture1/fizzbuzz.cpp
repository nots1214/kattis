#include<stdio.h>
#include<math.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>


int main() {
	int X, Y, N;
	
	std::cin >> X >> Y >> N;
	for (int i = 1; i <= N; i++) {
		if (i % X == 0 && i % Y == 0)
		{
			printf("FizzBuzz\n");
		}
		else if (i % X == 0)
		{
			printf("Fizz\n");
		}
		else if (i % Y == 0) {
			printf("Buzz\n");
		}
		else
			printf("%d\n",i);
	}
	//ans = X * (N + 1);
	//ans -= sum;
	

	//printf("%d", ans);

	return 0;
}
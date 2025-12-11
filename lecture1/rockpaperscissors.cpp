#include<stdio.h>
#include<math.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>


int main() {
	int N[100], K;
	int battle;
	int win[100][101] = { 0 };
	int lose[100][101] = { 0 };

	std::string hand;
	int handA;
	int handB;
	int who[2];
	int j=0;
	
	
	while (1) {
		std::cin >> N[j];
		if (N[j] == 0)
			break;
		std::cin >> K;

		battle = K * N[j] * (N[j] - 1) / 2;
		for (int i = 0; i < battle; i++)
		{
			std::cin >> who[0];
			std::cin >> hand;
			if (hand == "rock")
				handA = 0;
			if (hand == "scissors")
				handA = 1;
			if (hand == "paper")
				handA = 2;
			std::cin >> who[1];
			std::cin >> hand;
			if (hand == "rock")
				handB = 0;
			if (hand == "scissors")
				handB = 1;
			if (hand == "paper")
				handB = 2;

			if (handA == handB)
			{
			}
			else if ((handA + 1) % 3 == handB) {
				win[j][who[0]]++;
				lose[j][who[1]]++;
			}
			else
			{
				win[j][who[1]]++;
				lose[j][who[0]]++;
			}
		}
		//for (int i = 1; i <= N; i++) {
		//	if (win[j][i] + lose[j][i] == 0) {
		//		printf("-\n");
		//	}
		//	else
		//		printf("%lf\n", (double)win[i] / (double)(win[i] + lose[i]));
		//	//win[i] = 0;
		//	//lose[i] = 0;
		//}
		j++;
		//printf("\n");
	}

	for (int i = 0; i < j; i++) {
		for (int a = 1; a <= N[i]; a++)
		{
			if (win[i][a] + lose[i][a] == 0) {
				printf("-\n");
			}
			else
				printf("%.3f\n", (float)win[i][a] / (float)(win[i][a] + lose[i][a]));
		}
		printf("\n");
	}
	return 0;
}
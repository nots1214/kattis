#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#include<numeric>
#include<map>

using namespace std;


int main() {

	int P, T;
	int N, M;
	int v[101][101];
	int u[101][101];
	int result = 0;
	int res;
	int person = 0;
	int count;

	
	cin >> P >> T;
		
	while (scanf("%d %d", &N, &M) != EOF)
	{
		v[N][M] = 1;
	}
	//for (int i = 0; i < 6; i++) {
	//	cin >> N >> M;
	//	v[N][M] = 1;
	//}

	for (int i = 1; i <= T; i++)
		u[0][i] = v[1][i];
	result++;
	for (int i = 2; i <= P; i++) {
		res = result;
		for (int j = 0; j < res; j++) {
			count = 0;
			for (int k = 1; k <= T; k++) {
				if (u[j][k] == v[i][k])
				{
					count++;
				}
			}
			if (count == T)
				break;
			if (j == res - 1)
			{
				for (int k = 1; k <= T; k++) {
					u[res][k] = v[i][k];
				}
				result++;
			}
		}
	}
	

	cout << result;


	return 0;
}


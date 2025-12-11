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
	int N;
	int M;

	vector<vector<int>> v(1000,vector<int> (1000));
	vector<vector<int>> result(1000,vector<int> (1000));

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> v[i][j];
		}
	}
	result[0][0] = v[0][0];
	for (int i = 1; i < M; i++) {
		result[0][i] = result[0][i - 1] + v[0][i];
	}
	for (int i = 1; i < N; i++) {
		result[i][0] = result[i - 1][0] + v[i][0];
	}
	for (int i = 1; i < M; i++) {
		for (int j = 1; j < N; j++) {
			result[j][i] = v[j][i] + max(result[j - 1][i], result[j][i - 1]);
		}
	}


	for (int i = 0; i < N; i++) {
		printf("%d ", result[i][M-1]);
	}
	
	
	
	//result.push_back(accumulate(v.begin(),v.end(),0));



	return 0;
}

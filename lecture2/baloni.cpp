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
	int ans = 0;

	cin >> N;
	vector<int> v(N), u(0);
	for (int i = 0; i < N; i++) {
		cin >> v[i];

	}
	//ans++;
	for (int i = 0; i < N; i++) {
		if (find(u.begin(), u.end(), v[i] + 1)!=u.end()) {
			u[distance(u.begin(), find(u.begin(), u.end(), v[i] + 1))]--;
			//printf("yes\n");
		}
		else
		{
			u.push_back(v[i]);
			ans++;
		}
	}


	cout << ans;
	cout << endl;
	//for (int i = 0; i <N; i++)
	//	cout << v[i];
	//cout << endl;
	//for (int i = 0; i < u.size(); i++) {
	//	cout << u[i];
	//}
	return 0;
}


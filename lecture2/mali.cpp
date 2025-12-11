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
	int a[101] = { 0 };
	int b[101] = { 0 };
	int a2[101] = { 0 };
	int b2[101] = { 0 };
	int a_loc;
	int b_loc;
	int maxnum;
	int min_freq;
	int k;
	int U, V;


	cin >> N;

	vector<int>v(0), u(0);
	for (int i = 0; i < N; i++) {
		cin >> V >>U ;
		v.push_back(V);
		u.push_back(U);
	}

	for (int i = 1; i <= N; i++) {
		a2[v[i-1]]++;
		b2[u[i-1]]++;
		for (int i = 1; i <= 100; i++) {
			a[i] = a2[i];
			b[i] = b2[i];
		}
		maxnum = 0;
		k = 0;
		a_loc = 1;
		b_loc = 100;
		while (k != i) {
			while (a[a_loc] == 0) {
				a_loc++;
			}
			while (b[b_loc] == 0) {
				b_loc--;
			}
			maxnum = max(maxnum, a_loc + b_loc);
			min_freq = min(a[a_loc], b[b_loc]);
			k += min_freq;
			a[a_loc] -= min_freq;
			b[b_loc] -= min_freq;
		}
		cout << maxnum << endl;
	}

	



	return 0;
}


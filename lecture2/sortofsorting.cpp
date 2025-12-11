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
	//int N;
	vector<vector<string>> str(500,vector<string> (200));
	int a[500];
	int k = 0;
	int l = 0;

	string temp;

	while (1) {
		cin >> a[k];
		
		if (a[k] == 0) {
			break;
		}
		for (int i = 0; i < a[k]; i++) {
			cin >> str[k][i];
		}
		k++;
	}
	for (int m = 0; m < k; m++) {

		for (int i = 0; i < a[m]; i++) {
			for (int j = 0; j < a[m] - i - 1; j++) {
				if (str[m][j][0] > str[m][j + 1][0])
				{
					temp = str[m][j];
					str[m][j] = str[m][j + 1];
					str[m][j + 1] = temp;
				}
				else if (str[m][j][0] == str[m][j + 1][0])
				{
					if (str[m][j][1] > str[m][j + 1][1])
					{
						temp = str[m][j];
						str[m][j] = str[m][j + 1];
						str[m][j + 1] = temp;
					}
				}
			}
		}
	}
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < a[i]; j++) {
			cout << str[i][j] << endl;
		}

		cout << endl;
	}
	

	return 0;
}


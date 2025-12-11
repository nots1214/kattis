#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#include<numeric>
#include<map>
#include<utility>
#include<queue>

using namespace std;

typedef pair<int, int> is;
int main() {

	int T;
	int N;
	string type, str;
	int x, y;
	priority_queue<is,vector<is>,less<is>> buy;
	priority_queue<is, vector<is>,greater<is>> sell;
	int stock = -1;
	int buy_value;
	int sell_value;
	int buy_num;
	int sell_num;
	int neg;
	int result[100000][3];
	int t = 0;

	cin >> T;
	for (int i = 0; i < T; i++) {
		while (!buy.empty())
			buy.pop();
		while (!sell.empty())
			sell.pop();
		cin >> N;
		stock = -1;
		for (int j = 0; j < N; j++) {
			cin >> type >> x >> str >> str >> y;

			if (type == "buy") {
				buy.push(make_pair(y, x));
			}
			else if (type == "sell")
			{
				sell.push({ y,x });
			}


			

			while (!buy.empty() && !sell.empty() && sell.top().first <= buy.top().first) {
				buy_value = buy.top().first;
				sell_value = sell.top().first;
				buy_num = buy.top().second;
				sell_num = sell.top().second;
				buy.pop();
				sell.pop();

				neg = min(buy_num, sell_num);
				stock = sell_value;
				if (neg < sell_num) {
					sell.push({ sell_value,sell_num - neg });
				}
				if (neg < buy_num) {
					buy.push({ buy_value,buy_num - neg });
				}
			}

			if (sell.empty()) {
				//cout << "- ";
				result[t][0] = -1;
			}
			else
			{//cout << sell.top().first << " ";
				result[t][0] = sell.top().first;
			}
			if(buy.empty()) {
				//cout << "- ";
				result[t][1] = -1;
			}
			else
			{	//cout << buy.top().first << " ";
				result[t][1] = buy.top().first;
			}if (stock == -1) {
				//cout << "-" << endl;
				result[t][2] = -1;
			}
			else
			{
				//cout << stock << endl;
				result[t][2] = stock;
			}
			t++;
		}
	}

	for (int i = 0; i < t; i++) {
		if (result[i][0] == -1) {
			cout << "- ";
		}
		else
			cout << result[i][0]<<" ";
		if (result[i][1] == -1) {
			cout << "- ";
		}
		else
			cout << result[i][1] << " ";
		if (result[i][2] == -1) {
			cout << "-";
		}
		else
			cout << result[i][2];
		cout << endl;

		
	}


	return 0;
}


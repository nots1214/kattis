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

	string a, b;
	int n;
	int def;
	int count = 0;
	int len;
	cin >> a;
	cin >> b;

	n = b.size() - 1;
	def = a.size() - b.size();
	if (def < 0)
	{
		while (a.back() == '0')
			a.pop_back();
		printf("0.");
		for (int i = 0; i <  - def-1; i++) {
			printf("0");
		}
		cout<<a;
		//0処理
	}
	else
	{

		//.↑
		cout<< a.substr(0, a.size()-b.size()+1);
		
		//cout << "  " << a.size() <<"  ";

		//.下
		
		len = a.size();
		
			while (a.back() == '0' && count < b.size() - 1)
			{
				a.pop_back();
				count++;
			}
			if (b.size() - 1 !=  count)
			{

				//cout << "  " << a.size() << "  ";
				printf(".");
				cout << a.substr(len - b.size() + 1, len - 1 - count);
			}
		
	}






	return 0;
}


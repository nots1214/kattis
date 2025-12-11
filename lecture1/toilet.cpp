#include<stdio.h>
#include<math.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

int main() {

	string moji;
	string sub;
	int ans1 = 0;
	int ans2 = 0;
	int ans3 = 0;

	cin >> moji;

	//case1
	if (moji[0] == 'D')
	{
		ans1 = 1;
	}
	else if (moji[1] == 'D')
		ans1 = 2;
	for (int i = 2; i < moji.length(); i++) {
	
		if (moji[i] == 'D')
			ans1+=2;
	}
	cout << ans1 << endl;

    //case2
	if (moji[0] == 'U')
	{
		ans2 = 1;
	}
	else if (moji[1] == 'U')
		ans2 = 2;
	for (int i = 2; i < moji.length(); i++) {

		if (moji[i] == 'U')
			ans2 += 2;
	}

	
	cout << ans2<<endl;

	//case3
	for (int i = 0; i < moji.length() - 1; i++) {
		if (moji[i] != moji[i + 1]) {
			ans3++;
		}
	}
	cout << ans3<<endl;
	
	return 0;
}
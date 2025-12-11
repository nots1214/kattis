#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
#include<numeric>
#include<map>
#include<queue>
#include<math.h>
#include<stack>


#define DELTA 1e-9
#define MAX 2000000000
using namespace std;

typedef vector<int> vi;
typedef vector<long long int> vll;
typedef long long int ll;
typedef vector<double> vd;
typedef pair<int, int> ii;

int sumdivisor(int x) {//long long 注意
    int ans = 1;
    for (int i = 2; i*i <= x; i++) {
        if (i * i == x)
            ans += i;
        else if (x % i == 0)
        {
            ans += (i + x/i);
        }

    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    int m;
    while (cin >> n)
    {
        m = sumdivisor(n);
        //cout << m << endl;
        if (n - m == 0)
        {
            cout << n << " perfect" << endl;
        }
        else if (n - m <= 2 && n - m >= -2)
            cout << n << " almost perfect" << endl;
        else
            cout << n << " not perfect" << endl;
    }


    return 0;
}


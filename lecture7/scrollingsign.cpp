#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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

int serach(string a,string b,int num) {
    int pass;
    int i;
    int j;
    for (i = num - 1; i >= 0; i--) {
        pass = 1;
        for (j = 0; i-j>=0; j++) {
            if (a[num-1 - j] != b[i - j])
            {
                pass = 0;
                break;
            }
        }
        if (pass)
        {
            return i+1;
        }
    }
    return 0;
}


int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int t;
    int m, n;
    int index;
    int ans;
    vector<string> sign;
    string str;


        cin >> t;
        for (int k = 0; k < t; k++) {
            cin >> m >> n;
            sign.resize(0);
            for (int i = 0; i < n; i++) {
                cin >> str;
                sign.push_back(str);
            }
            ans = m;
            for (int i = 1; i < n; i++) {
                index = serach(sign[i - 1], sign[i], m);
               // cout << index << endl;
                ans += m - index;
            }

            cout << ans<<endl;

        }

    return 0;
}


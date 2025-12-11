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


#define EPS 1e-9
#define MAX 2000000000
using namespace std;

typedef vector<int> vi;
typedef vector<long long int> vll;
typedef long long int ll;
typedef vector<double> vd;
typedef pair<int, int> ii;



int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    //m3+n3=x3+y3
    //400000→70
    int m;
    cin >> m;
    int ans=0;
    map<int, int > exist;
    for (int i = 1; i * i * i < m; i++) {
        for (int j = i; j * j * j + i*i*i<= m; j++) {
            if (exist[j * j * j + i * i * i] == 0)
                exist[j * j * j + i * i * i] = 1;
            else
            {
                ans = max(ans, j * j * j + i * i * i);
            }
        }
    }
    if (ans == 0)
        cout << "none" << endl;
    else
        cout << ans;

    return 0;
}

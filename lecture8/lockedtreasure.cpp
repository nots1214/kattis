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

vector<vi> comb;
int find_comb(int n,int r){
    if (comb[n][r] != -1) return comb[n][r];
    if (n == r || r == 0 || n == 1) return 1;

    return comb[n][r] = find_comb(n-1,r-1) + find_comb(n - 1, r);

}
int main() {
    ios::sync_with_stdio(0), cin.tie(0);


    int t;
    int n, m;
    int ans;
    comb.assign(31, vi(31, -1));
    for (int i = 1; i <= 30; i++) {
        for (int j = 0; j <= i; j++) {
            int k = find_comb(i, j);
          //  cout << k << endl;
        }
    }
    cin >> t;
    while (t--) {
        cin >> n >> m;
        ans = find_comb(n, m - 1);

        cout << ans << endl;
    }


    return 0;
}


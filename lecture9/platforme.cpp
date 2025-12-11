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
#include<math.h>


#define EPS 1e-8
#define MAX 2000000000
using namespace std;

typedef vector<int> vi;
typedef vector<long long int> vll;
typedef long long int ll;
typedef vector<double> vd;
typedef pair<int, int> ii;




int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    int y, x1, x2;
    int y2, x21, x22;
    vector<tuple<int, int, int>> plat;
    int ans=0;
    int flag;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> y >> x1 >> x2;
        plat.push_back(make_tuple(y, x1, x2));
    }

    sort(plat.begin(), plat.end());

    //for (int i = 0; i < n; i++) {
    //    cout << get<0>(plat[i]) << " " << get<1>(plat[i]) << " " << get<2>(plat[i]) << endl;
    //}

    ans = 2 * (get<0>(plat[0]));
    for (int i = 1; i < n; i++) {
        y2 = get<0>(plat[i]);
        x21 = get<1>(plat[i]);
        x22 = get<2>(plat[i]);
        flag = 0;
        for (int j = i - 1; j >= 0; j--) {
            x1 = get<1>(plat[j]);
            x2 = get<2>(plat[j]);
            y = get<0>(plat[j]);
            if (x21 >= x1 && x21 < x2)
            {
                ans += y2 - y;
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            ans += y2;
        }
        flag = 0;
        for (int j = i - 1; j >= 0; j--) {
            x1 = get<1>(plat[j]);
            x2 = get<2>(plat[j]);
            y = get<0>(plat[j]);
            if (x22 > x1 && x22 <= x2)
            {
                ans += y2 - y;
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            ans += y2;
        }
       // cout << ans << endl;
    }
    cout << ans << endl;



    return 0;
}


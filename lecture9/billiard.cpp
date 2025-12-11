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


#define DELTA 1e-9
#define MAX 2000000000
using namespace std;

typedef vector<int> vi;
typedef vector<long long int> vll;
typedef long long int ll;
typedef vector<double> vd;
typedef pair<int, int> ii;




int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int x, y, s, m, n;
    double deg;
    double v;
    while (1) {
        cin >> x >> y >> s >> m >> n;
        if (x == 0 && y == 0 && s == 0 && m == 0 && n == 0) break;
        if (m == 0)
            deg = 90;
        else
            deg = 180*atan((double)(y * n) / (x * m))/acos(-1);//xm=0を考慮
        v = sqrt((ll)(x * x)* (ll)(m * m) + (ll)(y * y) *(ll)(n * n)) / s;
        //cout << deg << " " << v << endl;
        printf("%.2lf %.2lf\n", deg, v);
    }

    return 0;
}

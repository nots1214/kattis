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

    int r, h, s;
    double knot, arc;
    double ans;

    while (1) {
        cin >> r >> h >> s;
        if (r == 0 && h == 0 && s == 0) break;
        knot = 2 * sqrt((double)(h * h - r * r));
        //cout << knot << endl;
        //shita=2*arccos(r/h)
        //pi=arccos(-1)
        arc = 2*r * (acos(-1) - acos((double)r / (double)h));
        //cout << arc + knot << endl;
        //cout << "弧" << arc << " " << "紐" << knot << endl;
        ans = (arc + knot) * (100 + s)/100;
        printf("%.2lf\n", ans);

    }

    return 0;
}


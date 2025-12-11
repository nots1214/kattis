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

int gcd(int x, int y) {
    if (x % y == 0) return y;
    int d = x / y;
    return gcd(y, x -d*y);
}

int trans(double x) {
    int t = (int)x;
    x -= t;
    int s = (int)(100*(x + 0.00001));
    int y = t * 100 + s;
    return y;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

  
    double dpt;
    double dp1, dp2;
    int pt, p1, p2;
    int a, b;
    int g;
    int exist = 0;
    double c=0.0;
    //for (int i = 0; i <= 100000; i++) {
    //    if (i - trans(c) != 0)
    //        cout << i<<" "<<trans(c) << endl;
    //    c = c + 0.01;
    //}
    //cout << "all is right" << endl;

    cin >> dpt >> dp1 >> dp2;
    pt = trans(dpt);
    p1 = trans(dp1);
    p2 = trans(dp2);
    
    for (int i = 0; i <= pt / p1; i++)//チェック
    {
        if ((pt - p1 * i) % p2 == 0)
        {
            cout << i << " " << (pt - p1 * i) / p2 << endl;
            a = i;
            b = (pt - p1 * i) / p2;
            exist = 1;
            break;
        }
    }
    if (exist) {
        if (p1 > p2) {
            g = gcd(p1, p2);
        }
        else
            g = gcd(p2, p1);

        p1 /= g; p2 /= g;
        while (1)
        {
            a += p2; b -= p1;
            if (b < 0) break;
            cout << a << " " << b << endl;
        }
    }
    else
        cout << "none" << endl;
    return 0;
}


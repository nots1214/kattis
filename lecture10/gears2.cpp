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


vector<tuple<int, int, int>> g;
vi cw;
vector<vi> nb;
queue<int> q;

int gcd(int x, int y) {
    int tmp;
    if (y > x) {
        tmp = y;
        y = x;
        x = tmp;
    }
    if (x % y == 0)
        return y;

    return gcd(y, x % y);
}

int check_move() {
    q.push(0);
    int num;
    cw[0] = 0;
    while (!q.empty()) {
        num = q.front();
        q.pop();
        for (int i : nb[num]) {
            if (cw[i] == -1) {
                q.push(i);
                if (cw[num])
                    cw[i] = 0;
                else
                    cw[i] = 1;
            }
            else {
                if (cw[i] == cw[num])
                    return 0;
            }
        }
    }
    return 1;


}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int t;
    

    int check;
    
    int a, b, c;
    int div;
    int rat1, rat2;
    cin >> t;
    nb.assign(t, vi(0,0));
    cw.assign(t, -1);
    for (int i = 0; i < t; i++) {//t=1を考慮
        cin >> a>>b>>c;
        g.push_back(make_tuple(a, b, c));
    }
    for (int i = 0; i < t; i++) {
        for (int j = i + 1; j < t; j++) {
            int dx = get<0>(g[i]) - get<0>(g[j]);
            int dy = get<1>(g[i]) - get<1>(g[j]);
            int R = get<2>(g[i]) + get<2>(g[j]);
            if (dx * dx + dy * dy == R * R)
            {
                nb[i].push_back(j);
                nb[j].push_back(i);
            }
        }
    }

    check = check_move();
    if (!check) {
        cout << "-1" << endl;
    }
    else if (check) {
        if (cw[t - 1] == -1)
        {
            cout << "0" << endl;
        }
        else
        {
            div = gcd(get<2>(g[0]), get<2>(g[t - 1]));
            rat1 = get<2>(g[t - 1]) / div;
            rat2 = get<2>(g[0]) / div;
            if (cw[t - 1] == 1)
                rat2 = rat2 * (-1);
            cout << rat1 << " " << rat2 << endl;
        }
    }

    return 0;
}


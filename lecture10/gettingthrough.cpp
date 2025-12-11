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


#define EPS 1e-8
#define MAX 2000000000
#define DELTA 1e-10

using namespace std;

typedef vector<int> vi;
typedef vector<long long int> vll;
typedef long long int ll;
typedef vector<double> vd;
typedef pair<int, int> ii;

int n;
int width;
vector<tuple<int,int,int>> circle;
vector<vector<long double>> nb;

long double dist(int i, int j) {
    return sqrt(pow((get<0>(circle[i])-get<0>(circle[j])),2) + pow((get<1>(circle[i]) - get<1>(circle[j])),2));
}
void make_graph() {
    int x, y, r;
    for (int i = 0; i < n; i++) {
        x = get<0>(circle[i]);
        y = get<1>(circle[i]);
        r = get<2>(circle[i]);
        if ((x - r) < 0)
        {
            nb[n][i] = 0;
            nb[i][n] = 0;
        }
        else
        {
            nb[n][i] = x - r;
            nb[i][n] = x - r;
        }if (x + r > width) {
            nb[n + 1][i] = 0;
            nb[i][n+1]= 0;
        }
        else
        {
            nb[n + 1][i] = width - x - r;
            nb[i][n + 1] = width - x - r;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (dist(i, j) < (long double)(get<2>(circle[i]) + (get<2>(circle[j]))))//ここ怪しい
            {
                nb[i][j] = 0;
                nb[j][i] = 0;
            }
            else
            {
                nb[i][j] = -(long double)(get<2>(circle[i]) + get<2>(circle[j])) +dist(i,j);
                nb[j][i] = nb[i][j];
            }
        }
    }

}

bool check_pass(long double l) {
    int num = n;
    queue<int> q;
    vi visited;
    visited.assign(n+2, 0);
    while (!q.empty())
        q.pop();

    q.push(num);
    visited[num] = 1;
    while (!q.empty()) {
        num = q.front();
        q.pop();
        if (num == n + 1) return 1;
        for (int i=0;i<n+2;i++)
        {
            if (visited[i] == 0 &&(nb[num][i]) < l) {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

  
    int t;
    int x, y, r;
    bool check;
    long double mx, mn, mid=0;
    

    cin >> t;
    while (t--) {
        cin >> width;
        cin >> n;
        //初期化
        circle.resize(0);

        for (int i = 0; i < n; i++) {
            cin >> x >> y >> r;
            circle.push_back(make_tuple(x, y, r));
        }

        nb.assign(n + 2, vector<long double>(n+2, width));
        make_graph();

        mx = width;
        mn = 0;
        while (!(mx<mn+DELTA)) {//mnとmidが10^-6以下になったら終了
            mid = (mx + mn) / 2;
           
            //printf("%.9lf", mx - mn);
            check=check_pass(mid);
            if (check) {
                mx = mid;
            }
            else {
                mn = mid;
            }
        }

        printf("%.6Lf\n", (mx+mn)/4.0);
    }

    return 0;
}


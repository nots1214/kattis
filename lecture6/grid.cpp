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

using namespace std;

typedef vector<int> vi;
typedef vector<long long int> vll;
typedef long long int ll;
typedef vector<double> vd;
typedef pair<int, int> ii;




int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
   
    int n, m;
    int x, y, num;
    int x_next, y_next;
    int next[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
    string str;
    vector<vi> grid;
    vector<vi> able;
    queue<tuple<int,int,int>> q;
    cin >> n >> m;
    grid.assign(m, vi(n, 0));
    able.assign(m, vi(n, -1));
    for (int i = 0; i < n; i++) {
        cin >> str;
        for (int j = 0; j < m; j++) {
            grid[j][i] = (int)(str[j] - '0');
        }
    }

    able[0][0] = 0;
    if (grid[0][0] < m)
        q.emplace(grid[0][0], 0, 0);
    if (grid[0][0] < n)
        q.emplace(0, grid[0][0], 0);

    while (!q.empty()) {
        x = get<0>(q.front());
        y = get<1>(q.front());
        num = get<2>(q.front());
        able[x][y] = num + 1;
        if (x == m - 1 && y == n - 1)
            break;
        q.pop();
        for (int i = 0; i < 4; i++) {
            x_next = x + next[i][0] * grid[x][y];
            y_next = y + next[i][1] * grid[x][y];
            if (x_next < m && x_next >= 0 && y_next < n && y_next >= 0) {
                if (able[x_next][y_next] == -1) {
                    q.emplace(x_next, y_next, num + 1);
                    able[x_next][y_next] = -2;
                }
            }
        }
    }

    cout << able[m - 1][n - 1]<<endl;
   /* for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << able[j][i] << " ";
        }
        cout << endl;
    }*/

    return 0;
}

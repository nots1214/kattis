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

int neigh[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    //#　壁, . 足場, G 金, T トラップ, P プレイヤー
    int x, y;
    int x_now, y_now;
    vector<vi> area;
    vector<vi> visited;
    vector<vi> draft;
    cin >> x >> y;
    area.assign(x, vi(y, 0));
    visited.assign(x, vi(y, 0));
    draft.assign(x, vi(y, 0));
    char str;
    stack<pair<int, int>> location;
    int ans = 0;
    
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            cin >> str;
            if (str == '#')
                area[j][i] = -1;
            else if (str == '.')
                area[j][i] = 0;
            else if (str == 'G')
                area[j][i] = 1;
            else if (str == 'T')
                area[j][i] = -2;
            else if (str == 'P')
            {
                area[j][i] = 2;
                location.push(make_pair(j,i));
                visited[j][i] = 1;
            }
        }
    }

    while (!location.empty())
    {
        x_now = location.top().first;
        y_now = location.top().second;
        //cout << "現在位置" << x_now << "," << y_now << endl;
        if (area[x_now][y_now] == 1)
            ans++;
        location.pop();
        for (int i = 0; i < 4; i++) {
            if (area[x_now + neigh[i][0]][y_now + neigh[i][1]] == -2)
            {
                draft[x_now][y_now] = 1;
            }
        }
        if (draft[x_now][y_now] == 0) {
            for (int i = 0; i < 4; i++) {
                if (area[x_now + neigh[i][0]][y_now + neigh[i][1]] >= 0)
                {
                    if (visited[x_now + neigh[i][0]][y_now + neigh[i][1]] == 0) {
                        location.push(make_pair(x_now + neigh[i][0], y_now + neigh[i][1]));
                        visited[x_now + neigh[i][0]][y_now + neigh[i][1]] = 1;
                    }
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}


//.......
//.P.....
//....#..
//..TG#..
//....#..
//.......

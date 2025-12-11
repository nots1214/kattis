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


int x, y;
int k = 0;
vector<vi> tile;
string tile_str;
vector<vi> visited;
queue<pair<int, int>> l;

int calc() {
    int num=0;
    int x_now, y_now;
    int next[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
    l.push(make_pair(0, 0));
    visited[0][0] = 1;
    while (!l.empty()) {
        x_now = l.front().first;
        y_now = l.front().second;
        for (int a = 0; a < 4; a++) {
            if (x_now + next[a][0] < x + 2 && x_now + next[a][0] >= 0 && y_now + next[a][1] < y + 2 && y_now + next[a][1] >= 0) {
                if (tile[x_now + next[a][0]][y_now + next[a][1]] == 0 && visited[x_now + next[a][0]][y_now + next[a][1]] == 0) {
                    l.push(make_pair(x_now + next[a][0], y_now + next[a][1]));
                    visited[x_now + next[a][0]][y_now + next[a][1]] = 1;
                }
                else if (tile[x_now + next[a][0]][y_now + next[a][1]] == 1) {
                    num++;
                }
            }
        }
        l.pop();
    }
    return num;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int ans = 0;
    cin >> y >> x;
    tile.assign(x+2, vi(y+2, 0));
    visited.assign(x+2, vi(y+2, 0));
    for (int i = 0; i < y; i++) {
        cin >> tile_str;
        for (int j = 0; j < x; j++) {
            tile[j+1][i+1] = (int)(tile_str[j] - '0');
        }
    }
    ans = calc();

    cout << ans;



    return 0;
}

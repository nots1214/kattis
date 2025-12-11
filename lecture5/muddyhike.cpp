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

queue<ii> able;
vector<vi> visited;
int x, y;
vector<vi> depth;

int check(int num) {
    int x_now, y_now;
    int x_next, y_next;
    visited.assign(x, vi(y, 0));
    while (!able.empty()) {
        able.pop();
    }
    for (int i = 0; i < y; i++) {
        if (depth[0][i] <= num) {
            able.push(make_pair(0, i));
            visited[0][i] = 1;
        }
    }

    while (!able.empty()) {
        int next[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
        x_now = able.front().first;
        y_now = able.front().second;
        able.pop();
        
        if (x_now == x-1) {
            return 1;
        }
        for (int i = 0; i < 4; i++) {
            x_next = x_now + next[i][0];
            y_next = y_now + next[i][1];
            if (x_next >= x || x_next < 0 || y_next >= y || y_next < 0) {
                continue;
            }
            if (visited[x_next][y_next]) {
                continue;
            }
            else if (depth[x_next][y_next] <= num) {
                able.push(make_pair(x_next, y_next));
                visited[x_next][y_next] = 1;
            }
        }
        
    }

    return 0;
}


int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    cin >> y >> x;
    depth.assign(x, vi(y));
    visited.assign(x,vi(y));
    int ans;
    int max = 0;
    int min =1000001;
    int num;
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            cin >> depth[j][i];
            if (max < depth[j][i])
                max = depth[j][i];
            if (min > depth[j][i])
                min = depth[j][i];
        }
    }
    
    while (min + 1<max) {//1 3→(2,3) → (2,3)   1 4→(2,4)→(3,4)
        num = (max + min) / 2;
        if (check(num))
        {
            max = num;
        }
        else {
            min = num;
        }
    }

    if (check(min))ans = min;
    else ans = max;


    cout << ans;
  




    return 0;
}

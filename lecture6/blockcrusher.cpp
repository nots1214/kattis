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
    int min;
    int minx, miny;
    int minkey;
    int x_next, y_next;
    int next[8][2] = { {1,0},{1,1}, {0,1},{-1,1}, {-1,0},{-1,-1}, {0,-1},{1,-1} };
    string str;
    vector<vi> block;
    vector<vi> able;
    vector<vi> minsum;
    vector<vi> exist;
    vector<vector<ii>> last;
    priority_queue < tuple<int, int, int>, vector<tuple<int, int, int>>, greater < tuple <int, int, int >>> q;
    queue<ii> nextq;
    while (1) {
        cin >> n >> m;
        if (n == 0) break;
        block.assign(m, vi(n, 0));
        able.assign(m, vi(n, 0));
        minsum.assign(m, vi(n, -1));
        exist.assign(m, vi(n, 1));
        last.assign(m, vector<ii>(n, make_pair(-1, -1)));
        while (!q.empty())
            q.pop();
        while (!nextq.empty())
            nextq.pop();
        min = 12000;
        minkey = 0;
        for (int i = 0; i < n; i++) {
            cin >> str;
            for (int j = 0; j < m; j++) {
                block[j][i] = (int)(str[j] - '0');
            }
        }

        for (int i = 0; i < m; i++) {
            q.emplace(block[i][0], i, 0);
            minsum[i][0] = block[i][0];
            if (minsum[minkey][0] > minsum[i][0])
                minkey = i;
        }
        while (!q.empty()) {
            x = get<1>(q.top());
            y = get<2>(q.top());
            num = get<0>(q.top());
            if (y == n - 1)break;
            q.pop();
            for (int i = 0; i < 8; i++) {
                x_next = x + next[i][0];
                y_next = y + next[i][1];
                if (x_next < m && x_next >= 0 && y_next < n && y_next >= 0)
                {
                    if (minsum[x_next][y_next] == -1)
                    {
                        minsum[x_next][y_next] = num + block[x_next][y_next];
                        last[x_next][y_next] = make_pair(x, y);
                        q.emplace(minsum[x_next][y_next], x_next, y_next);
                        if (y_next == n - 1)
                        {
                            if (min > minsum[x_next][y_next]) {
                                min = minsum[x_next][y_next];
                                minkey = x_next;
                            }
                        }
                    }
                }
            }
        }
        exist[minkey][n - 1] = 0;
        nextq.emplace(make_pair(minkey, n - 1));
        while (1) {
            x = get<0>(nextq.front());
            y = get<1>(nextq.front());
            nextq.pop();
            if (y == 0)
                break;
            nextq.emplace(make_pair(last[x][y].first, last[x][y].second));
            exist[last[x][y].first][last[x][y].second] = 0;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (exist[j][i])
                {
                    cout << block[j][i];
                }
                else cout << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}

//O(TMN)=O(240000)=
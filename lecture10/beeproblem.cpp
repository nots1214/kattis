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

int n, m;
vector<vi> hive;
vector<vi> visited;
int funnel(int x, int y) {
    int nexte[6][2] = { {1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1} };
    int nexto[6][2] = { {1,0},{-1,0},{0,1},{0,-1},{1,-1},{1,1} };
    int cnt = 0;
    int nextx, nexty;
    cnt = 1;
    for (int i = 0; i < 6; i++) {//even→{→,←,↑,↓,┌,└} odd→{→,←,↑,↓,┐,┘}
        if (y % 2 == 0)
        {
            nextx = x + nexte[i][0];
            nexty = y + nexte[i][1];
        }
        else {
            nextx = x + nexto[i][0];
            nexty = y + nexto[i][1];
        }
        if (nextx >= 0 && nextx < m && nexty >= 0 && nexty < n) {
            if (hive[nexty][nextx] == 0 && visited[nexty][nextx] == 0)
            {
                visited[nexty][nextx] = 1;
                cnt += funnel(nextx, nexty);
                
            }
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int h;
    char str;
    vi funnelcnt;
    int ans = 0;

    cin >> h >> n >> m;
    hive.assign(n, vi(m, 0));
    visited.assign(n, vi(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> str;
            if (str == ' ')
            {
                cin >> str;
            }
            if (str == '.')
                hive[i][j] = 0;
            else if (str == '#')
                hive[i][j] = 1;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (hive[i][j] == 0 && visited[i][j] == 0)
            {
                visited[i][j] = 1;
                funnelcnt.push_back(funnel(j, i));
            }
        }
    }
    sort(funnelcnt.begin(), funnelcnt.end(),greater<int>());
    for (int i = 0; i < funnelcnt.size(); i++) {
        if (h <= 0) break;
        ans++;
        h -= funnelcnt[i];
    }
    cout << ans << endl;
    return 0;
}


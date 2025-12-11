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

    int n1, n2, distance;
    int ans;
    int now, num;
    vector<vector<ii>> dis;
    int n, m, a, k;
    vi unsafe;
    vi invade;
    vi mindis;
    priority_queue<tuple<int, int>, vector<tuple<int, int>>, greater<tuple<int, int>>> q;
    while (1) {
        cin >> n >> m >> a >> k;
        if (n == 0 && m == 0 && a == 0 && k == 0)
            break;
        dis.assign(n+1, vector<ii>(0,make_pair(0,0)));
        unsafe.assign(n+1, 0);
        invade.assign(a, 0);
        mindis.assign(n + 1, 10000);
        while (!q.empty())
            q.pop();
        ans = n;
        for (int i = 0; i < m; i++) {
            cin >> n1 >> n2 >> distance;
            dis[n1].push_back(make_pair(n2,distance));
            dis[n2].push_back(make_pair(n1,distance));
        }
        for (int i = 0; i < a; i++) {
            cin >> invade[i];
        }
        for (int i = 0; i < a; i++) {
            mindis[invade[i]] = 0;
            q.emplace(mindis[invade[i]], invade[i]);
            while (!q.empty()) {
                
                now = get<1>(q.top());
                num = get<0>(q.top());
                q.pop();
                if (num >= k) break;
                if (unsafe[now] == 0) {
                    unsafe[now] = 1;
                    ans--;
                }
                for (int j = 0; j < dis[now].size(); j++) {
                    if (mindis[dis[now][j].first]>num+dis[now][j].second)
                    {
                        mindis[dis[now][j].first] = num + dis[now][j].second;
                        q.emplace(num + dis[now][j].second, dis[now][j].first);
                    }
                }
            }
            cout << ans << endl;
            while (!q.empty()) {
                q.pop();
            }
        }
        cout << endl;

    }
    return 0;
}


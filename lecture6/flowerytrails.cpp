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


    int n, m;
    int a,b,c;
    int next, nextnum,now,nownum;
    int ans = 0;
    vector<vector<ii>> edge;
    priority_queue< tuple<int, int, int>, vector<tuple<int, int, int>>, greater < tuple <int, int, int >> > q;
    queue<ii> q2;
    vi dis;
    vi visited;
    vi visited2;


    cin >> n >> m;
    dis.assign(n, MAX);
    visited.assign(n, 0);
    visited2.assign(n, 0);
    edge.assign(n, vector<ii>(0, make_pair(0,0)));
    
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        edge[a].push_back(make_pair(b, c));
        edge[b].push_back(make_pair(a, c));
    }

    dis[0] = 0;
    visited[0] = 1;
    for (int i = 0; i < edge[0].size(); i++) {
        next = edge[0][i].first;
        nextnum = edge[0][i].second;
        if (dis[next] == -1)
            dis[next] = nextnum;
        else
            dis[next] = min(dis[next], nextnum);
        q.emplace(dis[next], 0, next);//2つあったらどうするか？
    }

    while (!q.empty()) {
        now = get<2>(q.top());
        nownum = get<0>(q.top());
        q.pop();
        if (visited[now])
            continue;
        visited[now] = 1;
        
        if (now == n - 1)
            break;
        for (int i = 0; i < edge[now].size(); i++) {
            next = edge[now][i].first;
            nextnum = edge[now][i].second;
            dis[next] = min(dis[next], nextnum+dis[now]);
            if (visited[next] == 0)
                q.emplace(dis[next], now, next);

        }
    }

    /*for (int i = 0; i < n; i++) {
        cout << i << "番目は" << dis[i] << endl;
    }*/
    q2.push(make_pair(n - 1, dis[n - 1]));
    while (!q2.empty()) {
        now = q2.front().first;
        nownum = q2.front().second;
        q2.pop();
        if (visited2[now])
            continue;
        visited2[now] = 1;
        
        for (int i = 0; i < edge[now].size(); i++) {
            next = edge[now][i].first;
            nextnum = edge[now][i].second;
            if (dis[next] == nownum - nextnum)
            {
                ans += nextnum;
                q2.push(make_pair(next, dis[next]));
            }
        }
    }

    cout << 2 * ans << endl;

    return 0;
}


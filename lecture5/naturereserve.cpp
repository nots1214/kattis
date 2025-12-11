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

    int T;
    int n, m, l, S;
    int a,b,c;
    ll cost;
    int nownode;
    int neighnode;
    ll sum;
    ll visitednum;
    vi visited;
    priority_queue < tuple<int, int, int>, vector<tuple<int, int, int>>, greater < tuple <int, int, int >>> q;
    vector<queue<ii>> edge;
    vi initial;
    cin >> T;
    for (int t = 0; t < T; t++) {
        //初期化
        initial.resize(0);
        visitednum = 0;
        sum = 0;
        while (!q.empty() ){
            q.pop();
        }

        //入力
        cin >> n >> m >> l >> S;
        visited.assign(n + 1, 0);
        edge.assign(n + 1, queue<ii>());
        for (int s = 0; s < S; s++) {
            cin >> a;
            initial.push_back(a);
        }
        for (int i = 0; i < m; i++) {
            cin >> a >> b >> c;
            edge[a].push(make_pair(b, c));
            edge[b].push(make_pair(a, c));
        }

        
        for (int i : initial) {
            visited[i] = 1;
            for (int j = 0; !edge[i].empty(); j++) {
                q.emplace(edge[i].front().second, i, edge[i].front().first);
                edge[i].pop();
            }
        }

        while (!q.empty()) {

            cost = get<0>(q.top());
            nownode = get<1>(q.top());
            neighnode = get<2>(q.top());
            q.pop();
            if (visited[neighnode] == 1) {
                continue;
            }
            sum += cost;
            visited[neighnode] = 1;
            visitednum++;
            
            for (int i = 0; !edge[neighnode].empty(); i++) {
                if (visited[edge[neighnode].front().first] == 0)
                {
                    q.emplace(edge[neighnode].front().second, neighnode, edge[neighnode].front().first);
                }    edge[neighnode].pop();
                
            }
            if (visitednum == n)
                break;
        }
        sum += visitednum * l;
        cout << sum << endl;
    }



    return 0;
}

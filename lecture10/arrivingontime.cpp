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


//vector<vi> nb;
priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<tuple<ll, int, int>>> pq;
vector<vector<tuple<int, int, int, int>>> g;
vector<ll> dist;
int n, m, s;

int check_arrive(int start) {
    ll nowtime, cost;
    int next, num;
    ll k;
    while (!pq.empty())
        pq.pop();
    dist.assign(n, 1000000000000);
    dist[0] = start;
    pq.emplace(start, 0,0);

    while (!pq.empty()) {
        num = get<1>(pq.top());
        nowtime = get<0>(pq.top());
        pq.pop();
        if (dist[num] < nowtime)
            continue;
        if (num == n - 1) {
            break;
        }   
        if (nowtime > s) return 0;
        for (int i = 0; i < g[num].size(); i++) {
            next = get<0>(g[num][i]);
            if (nowtime <= get<1>(g[num][i]))
                cost = get<1>(g[num][i]) + get<3>(g[num][i]);
            else
            {
                k = (nowtime - get<1>(g[num][i])) / get<2>(g[num][i]);
                if (get<1>(g[num][i]) + get<2>(g[num][i]) * k < nowtime)
                    k++;
                cost = (ll)(get<1>(g[num][i]) + get<2>(g[num][i]) * k + get<3>(g[num][i]));
            }
            if (dist[next] <= cost)continue;
            else
                dist[next] = cost;
               // cout << "cost" << cost << endl;
            pq.emplace(cost, next, 0);
           
        }
    }
    return (dist[n-1]<=s);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int dep,mx,mn;
    int check;
    int ans=0;
    int a1,a2,a3,a4,a5;
    cin >> n >> m >> s;
    g.assign(n, vector<tuple<int,int,int,int>>(0, make_tuple(0,0,0,0)));
    for (int i = 0; i < m; i++) {
        cin >> a1 >> a2 >> a3 >> a4 >> a5;
        g[a1].push_back(make_tuple(a2, a3, a4, a5));
    }

  
    check = check_arrive(0);
    if (!check) {
        cout << "impossible" << endl;
    }
    else {
        mx = s;
        mn = 0;
        while (mn + 1 < mx) {
            dep = (mx + mn) / 2;
            // cout << "dep==" << dep << endl;
            check = check_arrive(dep);
            if (check) {
                mn = dep;
                ans = max(ans, dep);
            }
            else
                mx = dep;

        }
        cout << ans << endl;
    }
    return 0;
}

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

priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
vector<vector<ii>> nb;//全体的にll
int n,m,x;
ll capdist;
bool check_goal(ll maxdist) {
    vll dist;
    int num, next;
    ll cost;
    while (!pq.empty()) {
        pq.pop();
    }
    dist.assign(n + 1, -1);
    pq.emplace(0, 1);
    dist[1] = 0;
    while (!pq.empty()) {
        num = get<1>(pq.top());
        cost = get<0>(pq.top());
        pq.pop();
        if (dist[num] < cost) continue;
        for (int i = 0; i < nb[num].size(); i++) {
            next = nb[num][i].first;
            if (nb[num][i].second <= maxdist) {
                if (dist[next] > cost + (ll)nb[num][i].second || dist[next] == -1)
                {
                    dist[next] = cost + (ll)nb[num][i].second;
                    pq.emplace(dist[next], next);
                }
            }
        }
    }
    //cout << "dist=" << dist[n] << endl;
    /*for (int i : dist) {
        cout << "dist=" << i << endl;
    }*/
    if (dist[n] == -1) return 0;

    return (dist[n] * 100 <= capdist);

}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

  
    int num;
    ll cost;
    int next;
    int c1, c2, t;
    ll mx, mn;
    ll maxdist;
    int check;
    
    vll mindist;
    cin >> n >> m >> x;
    nb.assign(n+1, vector<ii>(0, make_pair(0,0)));
    for (int i = 0; i < m; i++) {
        cin >> c1 >> c2 >> t;
        nb[c1].push_back(make_pair(c2, t));
        nb[c2].push_back(make_pair(c1, t));
    }
    mindist.assign(n + 1, -1);
    pq.emplace(0, 1);
    mindist[1] = 0;
    while (!pq.empty()) {
        num = get<1>(pq.top());
        cost = get<0>(pq.top());
        pq.pop();
        if (cost > mindist[num])continue;
        for (int i = 0; i < nb[num].size(); i++) {
            next = nb[num][i].first;
            if (mindist[next] > cost + (ll)nb[num][i].second || mindist[next]==-1)
            {
                mindist[next] = cost + (ll)nb[num][i].second;
                pq.emplace(mindist[next], next);
            }
        }
    }

    //dist[n]*100<=mindist[n]*(100*x)/
    //cout << mindist[n] << endl;
    capdist = mindist[n] * (100 + x);
    mn = 1; mx = mindist[n] * (100 + x) / 100 + 1;//ここ怪しい
    while (mn + 1 < mx) {
        maxdist = (mn + mx) / 2;
        check = check_goal(maxdist);
        //cout << maxdist << endl;
        if (check) {
            mx = maxdist;
        }
        else
            mn = maxdist;
    }
    if (check_goal(mn))
        cout << mn << endl;
    else
        cout << mx << endl;


    return 0;
}


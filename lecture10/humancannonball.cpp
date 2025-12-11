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


double dist(double x, double y) {
    return sqrt(x * x + y * y);
}
priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

  
    double sx, sy;
    double ex, ey;
    int n;
    int num;
    double inputa, inputb;
    double cost;
    double ans;
    vector<double> mindist;
    
    vector<pair<double, double>> canon;
    cin >> sx >> sy;
    cin >> ex >> ey;
    cin >> n;
    mindist.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> inputa >> inputb;
        canon.push_back(make_pair(inputa, inputb));
    }
    ans = dist(sx - ex, sy - ey);
    for (int i = 0; i < n; i++) {
        mindist[i] = dist(canon[i].first - sx, canon[i].second - sy);
        pq.emplace(mindist[i],i);
    }
    while (!pq.empty()) {
        num = get<1>(pq.top());
        cost = get<0>(pq.top());
        pq.pop();
        if (cost > mindist[num]) continue;
        for (int i = 0; i < n; i++) {
            if (mindist[i] > fabs(dist(canon[i].first - canon[num].first, canon[i].second - canon[num].second) - 50) + 10 + cost)
            {
                mindist[i] = fabs(dist(canon[i].first - canon[num].first, canon[i].second - canon[num].second) - 50) + 10 + cost;
                pq.emplace(mindist[i], i);
            }
        }
        ans = min(ans, fabs(dist(canon[num].first - ex, canon[num].second - ey) - 50) + 10 + cost);
    }
    ans /= 5;
    printf("%.8lf\n", ans);

    return 0;
}


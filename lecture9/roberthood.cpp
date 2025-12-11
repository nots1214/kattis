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

ii ori;

int cross(ii a, ii b) {
    return a.first * b.second - a.second * b.first;
}

int dist(ii a, ii b) {
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

bool ccw(ii v1, ii v2, ii v3) {
    int a = v2.first - v1.first;
    int b = v2.second - v1.second;
    int c = v3.first - v1.first;
    int d = v3.second - v1.second;
    ii v, u;
    v.first = a;
    v.second = b;
    u.first = c;
    u.second = d;

    return cross(v,u) > 0;
}


bool cmp(ii v1,ii v2) {
    int a = v1.first - ori.first;
    int b = v1.second - ori.second;
    int c = v2.first - ori.first;
    int d = v2.second - ori.second;
    if (a * d - b * c == 0)
        return a * a + b * b < c * c + d * d;
    return (atan2((double)b,(double)a) < atan2((double)d,(double)c));
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int c;
    vector<ii> pos;
    vector<ii> pos2;
    int x,y;
    int index;
    int tmp;
    int n, m;
    double ans;
    int ans2;

    cin >> c;
    for (int i = 0; i < c; i++) {
        cin >> x >> y;
        pos.push_back(make_pair(x, y));
    }
    index = 0;
    for (int i = 1; i < c; i++) {
        if (pos[i].second < pos[index].second || (pos[i].second == pos[index].second && pos[i].first > pos[index].first))
            index = i;
    }

    tmp = pos[0].first;
    pos[0].first = pos[index].first;
    pos[index].first = tmp;
    tmp = pos[0].second;
    pos[0].second = pos[index].second;
    pos[index].second = tmp;
    //cout << pos[0].first << "   " << pos[0].second << endl;
    //ori.first = pos[0].first;
    //ori.second = pos[0].second;
    ori = make_pair(pos[0].first, pos[0].second);

    sort(++pos.begin(), pos.end(), cmp);

    //for (int i = pos.size()-10; i < pos.size(); i++) {
    //    cout << pos[i].first << "," << pos[i].second << endl;
    //}

    if (pos.size() > 20) {
        pos2.push_back(pos[c - 1]);//C<=3
        pos2.push_back(pos[0]);
        pos2.push_back(pos[1]);
        m = 2;
        while (m < c) {
            n = (int)(pos2.size());
            //cout << "m=" << m << endl;
            if (ccw(pos2[n - 2], pos2[n - 1], pos[m]))
            {
                pos2.push_back(pos[m++]);
            }
            else {
                pos2.pop_back();
            }
        }
    }
    else {
        for (int i = 0; i < pos.size(); i++) {
            pos2.push_back(pos[i]);
        }
    }
  /*  for (int i = 0; i < pos2.size(); i++) {
        cout << pos2[i].first << "," << pos2[i].second << endl;
    }*/
    //for (int i = 0; i < pos2.size(); i++) {
    //    cout << pos2[i].first << "," << pos2[i].second << endl;
    //}

  //  cout << pos2.size() << endl;
    ans2 = 0;
    for (int i = 0; i < pos2.size(); i++) {
        for (int j = i+1; j < pos2.size(); j++) {
                ans2 = max(ans2,dist(pos2[i], pos2[j]));
        }
    }
    ans = sqrt(ans2);
    printf("%.10lf\n", ans);
    return 0;
}


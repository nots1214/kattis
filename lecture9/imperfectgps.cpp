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
#include<math.h>


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

    int n, gpst;
    vi x, y, t;
    double acdis, gpdis;
    ll r;
    double rd;
    int count,now;
    double gpsx, gpsy, memx, memy;
    double ans;
    cin >> n >> gpst;
    x.assign(n, 0);
    y.assign(n, 0);
    t.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> t[i];
    }
    acdis = 0; gpdis = 0;
    for (int i = 1; i < n; i++) {
        r = (ll)(x[i] - x[i - 1]) * (ll)(x[i] - x[i - 1]) + (ll)(y[i] - y[i - 1]) * (ll)(y[i] - y[i - 1]);
        acdis += sqrt((double)r);
        //cout << r << endl;
        //cout << acdis << endl;
    }
    //cout << acdis << endl;
    count = 0;
    gpsx = x[0];
    gpsy = y[0];
    now = 0;
    while (count<t[n-1]) {
        count += gpst;
        if (count > t[n - 1]) {
            count = t[n - 1];
        }
        while (t[now + 1] < count)//now+1が外にでる
        {
            now++;
        }
        memx = gpsx; memy = gpsy;

        gpsx = (double)x[now] + (double)((x[now + 1] - x[now])) * ((double)(count - t[now])) / (double)(t[now + 1] - t[now]);
        gpsy = (double)y[now] + (double)((y[now + 1] - y[now])) * ((double)(count - t[now])) / (double)(t[now + 1] - t[now]);
        

        rd = (gpsx - memx) * (gpsx - memx) + (gpsy - memy) * (gpsy - memy);
        gpdis += sqrt(rd);
        //cout << gpsx << "," << gpsy << endl;

    }
    ans = (acdis - gpdis)*100 / acdis;
    printf("%.10lf\n", fabs(ans));

    return 0;
}


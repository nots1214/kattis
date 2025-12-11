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


#define EPS 1e-8
#define MAX 2000000000
using namespace std;

typedef vector<int> vi;
typedef vector<long long int> vll;
typedef long long int ll;
typedef vector<double> vd;
typedef pair<int, int> ii;

double find_radian(ii v1,ii v2, ii v3) {
    double rad;
    int a, b, c, d;
    a = v2.first - v1.first;
    b = v2.second - v1.second;
    c = v2.first - v3.first;
    d = v2.second - v3.second;
    //rad = (double)(a * d - b * c) / (sqrt(a * a + b * b) * sqrt(c * c + d * d));
    rad = (double)(a * c + b * d) / (sqrt(a * a + b * b) * sqrt(c * c + d * d));
    return rad;
}



int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    vector<ii> v;
    int x, y;
    double minrad;
    int mindex;
    int siz;
    double memrad;
    int memindex, memx, memy;
    int flag;
    while (1) {
        cin >> n;
        if (n == 0) break;
        flag = 0;
        v.resize(0);
        for (int i = 0; i < n; i++) {
            cin >> x >> y;
            v.push_back(make_pair(x, y));
        }

        //最初から3角形だったら虫
        minrad = find_radian(v[n - 1], v[0], v[1]);
        mindex = 0;
        //cout << minrad << endl;
        for (int i = 1; i < n - 1; i++) {
            if (minrad < find_radian(v[i - 1], v[i], v[i + 1])) {//負を確認
                minrad = find_radian(v[i - 1], v[i], v[i + 1]);
                mindex = i;
               
            }
            //cout << find_radian(v[i - 1], v[i], v[i + 1]) << endl;;
        } 
      //  cout << find_radian(v[n - 2], v[n-1], v[0])<<endl;
        if (minrad < find_radian(v[n - 2], v[n - 1], v[0]))
        {
            minrad = find_radian(v[n - 2], v[n - 1], v[0]);
            mindex = n - 1;
           
        }
        memrad = minrad;
        memindex = mindex;
        memx = v[mindex].first;
        memy = v[mindex].second;
        v.erase(v.begin()+mindex);

        while (1) {
            siz = v.size();
 
            //if (siz == 3) { flag = 1; break; }
            minrad = find_radian(v[siz - 1], v[0], v[1]);
            mindex = 0;
            //cout << minrad << endl;
            for (int i = 1; i < siz - 1; i++) {
                if (minrad <find_radian(v[i - 1], v[i], v[i + 1])) {//負を確認
                    minrad = find_radian(v[i - 1], v[i], v[i + 1]);
                    mindex = i;
                }
                //cout << find_radian(v[i - 1], v[i], v[i + 1]) << endl;
            }
           // cout << find_radian(v[siz - 2], v[siz - 1], v[0]) << endl;
            if (minrad <find_radian(v[siz - 2], v[siz - 1], v[0]))
            {
                minrad = find_radian(v[siz - 2], v[siz - 1], v[0]);
                mindex = siz - 1;
            }
           // cout << mindex << endl;
           // cout << minrad << " " << memrad << endl;
            if (minrad > memrad) {
                break;
            }
            else {
                if (v.size() == 3) { flag = 1; break; }
                memrad = minrad;
                memindex = mindex;
                memx = v[mindex].first;
                memy = v[mindex].second;
                v.erase(v.begin() + mindex);
                
            }
        }
        if (flag) {
        cout << v.size();
            for (int i = 0; i < v.size(); i++) {
                cout << " " << v[i].first << " " << v[i].second;
            }
        }
        else {
            cout << v.size() + 1;
            for (int i = 0; i < memindex; i++) {

                cout << " " << v[i].first << " " << v[i].second;
            }

            cout << " " << memx << " " << memy;
            for (int i = memindex; i < v.size(); i++) {

                cout << " " << v[i].first << " " << v[i].second;
            }
        }
        cout << endl;
        
        
    }

    return 0;
}


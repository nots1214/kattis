#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#include<iostream>
#include<numeric>
#include<map>
#include<set>
#include<queue>

using namespace std;

typedef vector<int> vi;
typedef vector<long long int> vll;
typedef long long int ll;

//sort(v.begin(), v.end(), [](const vector<int>& alpha, const vector<int>& beta) {return alpha[0] < beta[0]; });
//二次元配列を0番目の要素でソート
int equal(double a, double b) {
    if (abs(a - b) <= 1e-9)
        return 1;
    else
        return 0;
}

int main() {
   // ios::sync_with_stdio(0), cin.tie(0);
    int n;
    vector<double> table;
    int a;
    double b;
    double result[150];
    int resultright[150];
    int resultleft[150];
    int k=0;
    while (1) {
        cin >> n;
        if (n == 0)
            break;
        table.assign(1440, 0.00);
        double sum = 0.0;
        double ans = 0.0;
        /*int maxkeya = 0, maxkeyb = 0;
        int nowkeya = 0, nowkeyb = 0;*/
        int nowkey = 0, nowperiod = 0;
        int maxkey = 0, maxperiod = 0;
        
        for (int i = 0; i < n; i++) {
            scanf("%d %le", &a, &b);
            table[a] += b;
        }
        for (int i = 0; i < 1440; i++) {
            sum += table[i] - 0.08;
            
            if (sum <= 1e-9)
            {
                sum = 0.0;
                nowkey = i + 1;
                nowperiod = 0;
            }
            else
                nowperiod++;
            if (sum-ans>1e-9) {
                ans = sum;
                /*maxkeya = nowkeya;
                maxkeyb = i;*/
                maxkey = nowkey;
                maxperiod = nowperiod;
            }
            else if (equal(ans, sum)) {
                if (maxperiod > nowperiod) {
                    maxkey = nowkey;
                    maxperiod = nowperiod;
                }
            }
           // cout << sum << endl;
            
        }


       /* if (ans <= 0.0) 
            cout << "no profit" << endl;      
        else       
            printf("%.2lf %d %d\n", ans, maxkey, maxkey+maxperiod-1);*/
        result[k] = ans;
        resultleft[k] = maxkey;
        resultright[k] = maxkey + maxperiod - 1;
        k++;
    }
    for (int i = 0; i < k; i++) {
        if (equal(0,result[i])) {
            cout << "no profit" << endl;
        }
        else
            printf("%.2lf %d %d\n", result[i], resultleft[i], resultright[i]);
    }
    return 0;
}
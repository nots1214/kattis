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

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    int n;
    vi h, w;
    int result;
    

    vector<vector<int>> hsub;
    vector<vector<int>> hw;
    multiset<int> Set;


    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        hsub.assign(n ,vector<int>(2, 0));
        h.assign(n, 0);
        w.assign(n, 0);
        result = 0;
        Set.clear();
        for (int j = 0; j < n; j++) {
            cin >> hsub[j][0] >> hsub[j][1];
        }
        sort(hsub.begin(), hsub.end(), [](const vector<int>& alpha, const vector<int>& beta) {
            if (alpha[0] == beta[0])return alpha[1] > beta[1];
            return alpha[0] < beta[0]; 
            });
        for (int j = 0; j < n; j++) {
            //hw[0][j] = hsub[j][0];
            //hw[1][j] = hsub[j][1];
            h[j] = hsub[j][0];
            w[j] = hsub[j][1];
        }

        //for (int j = 0; j < n; j++) {
        //    cout << w[j] << endl;
        //}
        
        result = 1;
        Set.insert(-w[0]);
        for(int j=1;j<n;j++){
            auto index = Set.upper_bound(-w[j]);
            //cout << distance(Set.begin(), index);
            if (index == Set.end())
            {
                Set.insert(-w[j]);
                result++;
            }
            else
            {  
                Set.erase(index);
                Set.insert(-w[j]);
                
            }


        }
        cout << result<<endl;
    }
   
    return 0;
}

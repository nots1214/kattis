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

using namespace std;

typedef vector<int> vi;
typedef vector<long long int> vll;
typedef long long int ll;
typedef vector<double> vd;



int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;
    vi train;
    train.assign(n, 0);
    int maxtrain=0;
    int sum;
    vi dp1;
    vi dp2;
    for (int i = 0; i < n; i++) {
        cin >> train[i];
    }

    for (int k = 0; k < n; k++) {
        if (maxtrain > n - k)
        {
            break;
        }
     /*   if(!dp1.empty())
            dp1.pop_back();
        if (!dp2.empty())
            dp2.pop_back();*/
        dp1.resize(0);
        dp2.resize(0);
        sum = 0;
        //cout << dp2.size() << endl;
        // kより大きい数についてLIS＋kより小さい数についてLDSする
        

        for(int i=k+1;i<n;i++)
        {
            int index = train[i];
            if (index > train[k]) {
                auto it = lower_bound(dp1.begin(), dp1.end(), index);

                if (it == dp1.end())
                {
                    dp1.push_back(index);
                }
                else
                {
                    *it = index;
                }
            }
        }

        for (int i = n-1; i >=k+1; i--)
        {
            //cout << i << "番目";
            int index = train[i];
            if(index < train[k]){
                auto it = lower_bound(dp2.begin(), dp2.end(), index);

                if (it == dp2.end())
                {
                  //  cout << "Yes";
                    dp2.push_back(index);
                }
                else
                {
                   // cout << "No";
                    *it = index;
                }
            }
        }
        sum = dp1.size() + dp2.size() + 1;
        if (maxtrain < sum)
            maxtrain = sum;
       // cout << k << "番目 " << dp1.size()<<"  "<<dp2.size() << " "<< endl;
       
    }
  
    cout << maxtrain;

    return 0;
}


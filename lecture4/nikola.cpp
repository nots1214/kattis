#include <stdio.h>
#include<vector>
#include<map>
#include<iostream>
#include<algorithm>
#include<set>
#include<stdlib.h>
#include<math.h>

using namespace std;
typedef vector<int> vi;



int main() {
    ios::sync_with_stdio(0), cin.tie(0);
   
    int n;
    int minresult = 1000000;
    cin >> n;
    vi cost(n);
    vector<vector<int>> dp(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        cin >> cost[i];
    }

    //n-1進んでm個目の資格にいくのとn戻ってmコメの四角に行くのは一緒　それをn
    dp[0][0] = cost[0];
    dp[1][1] = cost[1];
    for (int i = 1; i < n; i++) {
        for (int j = n-1; j >= 0; j--) {
            if (dp[i][j])
            {
                if (j - i >= 0) {
                    if (dp[i][j - i] != 0)
                        dp[i][j - i] = min(dp[i][j] + cost[j - i], dp[i][j - i]);
                    else
                        dp[i][j - i] = dp[i][j] + cost[j - i];
                }
                if (j + i + 1 < n)
                    dp[i + 1][j + i + 1] = dp[i][j] + cost[j + i + 1];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (dp[i][n - 1] != 0)
        {
            if (dp[i][n - 1] < minresult) {
                minresult = dp[i][n - 1];
            }
        }
    }
    cout << minresult;
 /*   for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }*/

    return 0;
}
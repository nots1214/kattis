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


#define DELTA 1e-9
#define MAX 2000000000
using namespace std;

typedef vector<int> vi;
typedef vector<long long int> vll;
typedef long long int ll;
typedef vector<double> vd;
typedef pair<int, int> ii;

//int dp[200][200];
vector<vi> dp;

//PPOPPOPPOPP→P(POP)P or (P)(OPP)　or (PPO)(P)
//文字列を分割し,s=()^nまでいく
int calc(string str,int start, int end) {
    if (dp[start][end] != 300) return dp[start][end];
    if (start == end) return 1;

    int j;
    for (int i = 1; i <= (end - start+1) / 2;i++) {
        if ((end - start + 1) % i != 0) continue;
        for (j = start; j + i + i <= end + 1; j+=i) {
            if (str.substr(j, i) != str.substr(j + i, i)) {
                break;
            }
        }
        if (j + i == end + 1)
        {
            dp[start][end] = i;
            for (int p = start; p < start + i; p++) {
                dp[start][end] = min(dp[start][end], calc(str, start, p) + calc(str, p + 1, start + i - 1));
            }
            //cout << "    " << start << end << endl;
            break;
        }
    }

    for (int i = start; i < end; i++) {
        dp[start][end] = min(dp[start][end],calc(str, start, i) + calc(str, i + 1, end));
    }
    //cout << "dp[" << start << "][" << end << "]="<<dp[start][end] << endl;

    return dp[start][end];
}



int main() {
    ios::sync_with_stdio(0), cin.tie(0);


    string str;
    int len;
    int ans;
    cin >> str;
    len = str.length();
    dp.assign(len, vi(len, 300));
    ans = calc(str,0,len-1);
    cout << ans << endl;


    return 0;
}
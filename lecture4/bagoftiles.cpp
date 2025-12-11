#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#include<iostream>
#include<numeric>
#include<map>
#include<set>
#include<queue>
#include<cstring>

using namespace std;

typedef vector<int> vi;
typedef vector<long long int> vll;
typedef long long int ll;

//sort(v.begin(), v.end(), [](const vector<int>& alpha, const vector<int>& beta) {return alpha[0] < beta[0]; });
//二次元配列を0番目の要素でソート


vi tile;
int m;
ll keep_ans[10000][31][31] = { 0 };
vector<vector<long long int>> keep_comb;

ll comb(int n, int r) {
    if (keep_comb[n][r] != -1)
    {
        return keep_comb[n][r];
    }
    if (r == 0 || r==n) {
        return 1;
    }
    else
        return keep_comb[n][r] = comb(n - 1, r - 1) + comb(n - 1, r);
}

ll calc(int target,int n,int num) {
    //ダメな条件はtarget<0,n<0,num>m
    if (target == 0 && n == 0) {
        return 1;
    }
    else if (target <= 0)
    {
        return 0;
    }
    else if (n <= 0) {
        return 0;
    }
    if (num >= m)
        return 0;
    if (num + n > m)
        return 0;
    if (keep_ans[target][n][num] != -1)
    {
        return keep_ans[target][n][num];
    }
    return keep_ans[target][n][num]=calc(target,n,num+1) + calc(target - tile[num],n-1,num+1);
}

//答えがintで収まらない場合があるかも
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    keep_comb.assign(31, vector<long long int>(31, -1));
    int g;
    int n, t;
    ll ans;
    ll C;
    cin >> g;
    for (int i = 0; i < g; i++) {
        cin >> m;
        tile.assign(m, 0);
        memset(keep_ans, -1, sizeof(keep_ans));
        for (int j = 0; j < m; j++) {
            cin >> tile[j];
        }
        cin >> n >> t;

        //mCn=a+b?
        //30C15=1.5e8
        ans = calc(t, n, 0);
        C = comb(m,n);
        cout << "Game " << i + 1 << " -- "<< ans <<" : "<<C-ans <<endl;
    }
    return 0;
}

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
#include<stack>

#define DELTA 1e-9
#define MAX 2000000000
using namespace std;

typedef vector<int> vi;
typedef vector<long long int> vll;
typedef long long int ll;
typedef vector<double> vd;
typedef pair<int, int> ii;




int ishill(string num) {
    int change = 0;
    if (num.length() <= 2)
        return 1;
    else
    {
        if ((int)num[1] - (int)num[0] >= 0)
            change = 1;
        else
            change = -1;
        for (int i = 2; i < num.length(); i++) {
            if (change == -1 && (int)num[i] - (int)num[i - 1] > 0)
                return 0;
            else {
                if ((int)num[i] - (int)num[i - 1] > 0)
                {
                    change = 1;
                }
                else if ((int)num[i] - (int)num[i - 1] < 0)
                {
                    change = -1;
                }
            }
        }
        return 1;
    }
}

long long int calc(vi dig, int len, int index,int t,int u,int inccheck,vector<vll> inc,vector<vll> dec,vector<vll> hil,vector<vll> con) {
    long long int result = 0;
   // cout << index << endl;
    if (len == index + 1) return 1;
    if (u) {
        if (inccheck)
        {
            for (int i = 0; i < dig[index + 1]; i++) {
                if (dig[index] <= i)
                    result += calc(dig, len, index + 1,i, 0, 1,inc,dec,hil,con);
                else
                    result += calc(dig, len, index + 1,i, 0, 0, inc, dec, hil, con);
            }
        }
        else {
            for (int i = 0; i < dig[index + 1]; i++) {
                result += calc(dig, len, index + 1,i, 0, 0, inc, dec, hil, con);
            }
        }
        if (dig[index] <= dig[index +1])
            result += calc(dig, len, index + 1,dig[index+1], 1, 1, inc, dec, hil, con);
        else
            result += calc(dig, len, index + 1,dig[index+1], 1, 0, inc, dec, hil, con);
    }
    else {
        if (inccheck)
        {
            result += inc[t][len - index - 1];
            result += hil[t][len - index - 1];
            result += dec[t][len - index - 1];
            result += con[t][len - index - 1];
        }
        else
        {
            result += dec[t][len - index - 1];
            result += con[t][len - index - 1];
        }
    }
    return result;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);


    string num;
    int len;
    vi dig;
    ll ans = 0;

    vector<vll> inc;
    vector<vll> dec;
    vector<vll> hil;
    vector<vll> con;

    cin >> num;
    len = num.length();
    inc.assign(10, vll(len,0));
    dec.assign(10, vll(len,0));
    hil.assign(10, vll(len,0));
    con.assign(10, vll(len,0));
    dig.assign(len, 0);
    for (int i = 0; i < len; i++) {
        dig[i] = (int)(num[i] - '0');
    }

    if (ishill(num)) {

        //とりあえずnumの桁数-1のヒル数を求める。
        for (int i = 0; i <= 9; i++) {
            con[i][0] = 1;
        }
        for (int i = 1; i < len; i++) {
            for (int j = 0; j <= 9; j++) {
                inc[j][i] += inc[j][i - 1];
                for (int k = j+1; k <= 9; k++) {
                    inc[j][i] += inc[k][i - 1];
                    inc[j][i] += con[k][i - 1];
                }
                dec[j][i] += dec[j][i - 1];
                for (int k = j-1; k >= 0; k--) {
                    dec[j][i] += dec[k][i - 1];
                    dec[j][i] += con[k][i - 1];
                }
                hil[j][i] += hil[j][i - 1];
                for (int k = j+1; k <= 9; k++) {
                    hil[j][i] += hil[k][i - 1];
                    hil[j][i] += dec[k][i - 1];
                }
                con[j][i] = 1;
            }
        }

        for (int i = 0; i < dig[0];i++) {
           // ans += calc(dig, len, 0, 0, 1,inc,dec,hil,con);
            ans += inc[i][len - 1];
            ans += dec[i][len - 1];
            ans += hil[i][len - 1];
            ans += con[i][len - 1];
        }
        //cout <<inc[0][len-1]<<" " << dec[0][len - 1] << " " << hil[0][len - 1] << " " << con[0][len - 1] << " " << ans << endl;
        ans += calc(dig,len,0,dig[0], 1, 1, inc, dec, hil, con);

       // cout << "ind" << hil[0][16] << endl;
        cout << ans -1<< endl;
    }
    else
        cout << -1 << endl;


    return 0;
}
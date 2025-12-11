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

vi p;
vector<vi> pf;
vector<vi> fac;

void find_prime(int N) {
    p.push_back(2);
    int check;

    for (int i = 3; i <= N; i++) {
        check = 1;
        for (int j : p) {
            if (j * j > N) { break; }
            if (i % j == 0)
            {
                check = 0;
                break;
            }
        }
        if (check)
            p.push_back(i);

    }
}
void find_primefactorization(int x) {
    int num;
    for (int i = 2; i <= x; i++) {
        num = i;
        for (int j = 0; j < p.size();j++) {
            while (num % p[j] == 0) {
                num /= p[j];
                pf[i][j]++;
            }
            if (num == 1) break;
        }
    }
}

void find_facfac(int x) {
    for (int i = 2; i <= x; i++) {
        for (int j = 0; j < p.size(); j++) {
            fac[i][j] = pf[i][j] + fac[i - 1][j];
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    int m;
    int x;
    ll ans = 1;
    pf.assign(432, vi(83, 0));
    fac.assign(432, vi(83, 0));
    find_prime(431);//431は83番目の素数
    find_primefactorization(431);
    find_facfac(431);
    
    while (cin >> n)
    {
        cin >> m;
        ans = 1;
        for (int i = 0; i < 83; i++) {
            ans *= (fac[n][i] -fac[m][i]-fac[n-m][i] + 1);
            //cout << fac[n][i] << " " << fac[m][i] << " " << fac[n - m][i] + 1 << endl;
        }
        cout << ans << endl;


    }


    return 0;
}


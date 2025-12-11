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

ll comb[51][51] = { 0 };

ll find_comb(int n, int r) {
    if (comb[n][r] != 0)return comb[n][r];
    if (comb[n][n - r] != -1) {
        comb[n][r] = comb[n][n - r];
    }
    if (n == r || r == 0 || n == 1) {
        comb[n][r] = 1;
        return 1;
    }
    
    comb[n][r] = find_comb(n - 1, r - 1) + find_comb(n - 1, r);
    return comb[n][r];

}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);


    int t;
    int n,v, u, w;
    int rem;
    int min;
    ll divide;
    ll pro;
    double mpro;
    for (int i = 0; i <= 50; i++) {
        for (int j = 0; j <= i; j++) {
            ll pp = find_comb(i, j);
            //cout << pp << " ";
        }
        //cout << endl;
    }

    cin >> t;
    for (int t2 = 0; t2 < t; t2++) {
        cin >> n >> v >> u >> w;
 
        if (u*2 >= n)
            cout << "RECOUNT!" << endl;
        else if (v < u) {
            cout << "PATIENCE, EVERYONE!" << endl;
        }
        else if (v*2 > n)
        {
            cout << "GET A CRATE OF CHAMPAGNE FROM THE BASEMENT!" << endl;
        }
        else if (u == v)
            cout << "PATIENCE, EVERYONE!" << endl;
        else {
            rem = n - u - v;
            min = n / 2 + 1 - v;
            divide = 1;
            for (int i = 0; i < rem; i++) {
                divide *= 2;
                  //cout << divide << endl;
            }
            pro = 0;
            for (int i = min; i <= rem; i++) {
                pro += comb[rem][i];
                //cout <<pro<<" "<< divide << endl;
            }
            //cout << pro << " " << divide << endl;
            
            //cout << "確率" << mpro << endl;
            if (pro*100 > w*divide)
            {
                cout << "GET A CRATE OF CHAMPAGNE FROM THE BASEMENT!" << endl;

            }
            else cout << "PATIENCE, EVERYONE!" << endl;
        }

    }

    return 0;
}


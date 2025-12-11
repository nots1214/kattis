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



int main() {
    ios::sync_with_stdio(0), cin.tie(0);


    int n;
    int same=0, dif=0;
    string me, frd;

    cin >> n;
    cin >> me;
    cin >> frd;

    for (int i = 0; i < me.length(); i++) {
        if (me[i] == frd[i])
            same++;
        else
            dif++;
    }

    if (n > same)
        cout << same + me.length() - n << endl;
    else
        cout << n + me.length() - same << endl;
    return 0;
}
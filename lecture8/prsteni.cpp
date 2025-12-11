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


int gcd(int x, int y) {
    if (x % y == 0)
        return y;
    int d = x / y;

    return gcd(y, x-d*y);;
}


int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int N;
    int first;
    vi next;
    cin >> N;
    next.assign(N, 0);
    int c;
    cin >> first;
    for (int i = 0; i < N-1; i++) {
        cin >> next[i];
    }
    for (int i = 0; i < N-1; i++) {
        if (first >= next[i]) {
            c = gcd(first, next[i]);
        }
        else c = gcd(next[i], first);

        cout << first / c << "/" << next[i] / c << endl;
    }


 

    return 0;
}


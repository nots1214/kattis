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

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, k;
    vi num;
    int now;
    int ans = 0;
    int pindex = 0;
    cin >> n >> k;
    num.assign(n+1, 1);
    num[0] = 0;
    num[1] = 0;
    find_prime(n);



    while (k)
    {
        now = p[pindex];
        pindex++;
        k--;
        num[now] = 0;
        if(k==0)
        {
            ans = now;
            break;
        }
        for (int i = now * 2; i <= n; i += now) {
            if (num[i] == 1)
            {
                num[i] = 0;
                k--;
                if (k == 0)
                {
                    ans = i;
                    break;
                }
            }
        }
    }


    cout << ans << endl;
 

    return 0;
}


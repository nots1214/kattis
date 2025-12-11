#include<stdio.h>
#include<stdlib.h>
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

    int N, M, K;
    double a;
    vd n, m;
    int ans = 0;
    cin >> N >> M >> K;
    
   // n.assign(N, 0);
    //m.assign(M + K, 0);

    for (int i = 0; i < N; i++) {
        cin >> a;
        n.push_back(a);
    }
    for (int i = 0; i < M; i++) {
        cin >> a;
        m.push_back(a);
    }
    for (int i = 0; i < K; i++) {
        cin >> a;
        a = a * sqrt(2) / 2;
        m.push_back(a);
    }

    sort(n.begin(), n.end());
    sort(m.begin(), m.end());
    int t = M + K;
    while (N > 0 && t > 0)
    {
        N--; t--;
        if (n[N] > m[t])
        {
            ans++;
        }
        else {
            while (n[N] <= m[t] && t>=0) {
                t--;
                if (t < 0)
                    break;
            }
            if (t >= 0)
                ans++;
        }
    }

    cout << ans;

  /*  for (int i = 0; i < 6; i++) {
        cout << m[i] << endl;
    }*/
    return 0;
}




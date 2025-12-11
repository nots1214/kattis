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

using namespace std;

typedef vector<int> vi;
typedef vector<long long int> vll;
typedef long long int ll;
typedef vector<double> vd;


int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int N;
    vi min, max;
    vi check;
    int m;
    int result;
    int cmp;
    cin >> N;
    result = N;
    min.assign(N, 0);
    max.assign(N, 0);
    check.assign(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> min[i] >> max[i];
    }

    while (!max.empty()) {
        auto minmax_ind = min_element(max.begin(), max.end());//最大値が小さいのを探す
        m = distance(max.begin(), minmax_ind);
        cmp = max[m];
        for (int i = distance(max.begin(), max.end()) - 1; i >= 0; i--) {
            if (i != m) {
              //  printf("i=%d m=%d\n", i, m);
              //  printf("%dと%d", min[i], cmp);
                if (min[i] <= cmp)
                {
                    result--;
                    max.erase(max.begin() + i);
                    min.erase(min.begin() + i);

                }
            }
        }

      //  printf("%d", m);
        minmax_ind = min_element(max.begin(), max.end());
        m = distance(max.begin(), minmax_ind);
        max.erase(max.begin() + m);
        min.erase(min.begin() + m);

    }

    cout << result;
    return 0;
}



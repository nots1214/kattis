#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#include<iostream>
#include<numeric>
#include<map>
#include<queue>

using namespace std;

typedef vector<int> vi;
typedef vector<long long int> vll;
typedef long long int ll;

int N, M;

int solve(vi box, int m) {
    int min, check, clo;
    int a, b;
    vector<int>::iterator index;


    a = 0;
    b = N - 1;
    min = labs(box[a] + box[b] - m);
    clo = labs(box[a] + box[b]);
    while (a < b) {
        check = box[a] + box[b];
        if (check == m) {
            min = 0;
            clo = check;
            break;
        }
        else if (check > m)
        {
            if (check - m < min)
            {
                min = check - m;
                clo = check;
            }
            b--;
        }
        else if (check < m) {
            if (m - check <= min)
            {
                min = m - check;
                clo = check;
            }
            a++;
        }
    }
    return clo;
}


int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    //int N, M;
    vi box;
    int num;
    int closest;
    int k = 1;
    while (cin >> N)
    {
        box.assign(N, 0);
        for (int i = 0; i < N; i++) {
            cin >> box[i];
        }
        sort(box.begin(), box.end());
        cin >> M;
        cout << "Case " << k << ":" << endl;
        for (int i = 0; i < M; i++) {
            cin >> num;
            closest = solve(box, num);
            cout << "Closest sum to " << num << " is " << closest << "." << endl;
        }
        k++;
    }

    return 0;
}
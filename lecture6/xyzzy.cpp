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


    int n, m, l;
    bool updated;
    vi energy;
    vi maxenergy;
    vector<vi> next;
    vector<ii> edge;
    vi caninf;
    int E;
    queue<int> q;

    while (1) {
        cin >> n;
        if (n == -1)break;
        E = 0;
        energy.assign(n + 1, 0);
        maxenergy.assign(n + 1, -MAX);
        caninf.assign(n + 1, 0);
        next.assign(n + 1, vi(0, 0));
        edge.assign(0, make_pair(0,0));
        while (!q.empty()) {
            q.pop();
        }
        for (int i = 1; i <= n; i++) {
            cin >> energy[i] >> m;
            for (int j = 0; j < m; j++) {
                cin >> l;
                edge.push_back(make_pair(i, l));
                next[i].push_back(l);
            }
            E += m;
        }


        maxenergy[1] = 100;
        updated = true;
        int s, d;
        for(int j=0;j<n;j++){
            if (!updated) break;
            updated = false;
            for (int i = 0; i < E; i++) {
                s = get<0>(edge[i]);
                d = get<1>(edge[i]);
                if (maxenergy[s] <= 0) continue;
                if (maxenergy[s] != -MAX && maxenergy[d] < maxenergy[s] + energy[d]) {
                    maxenergy[d] = maxenergy[s] + energy[d];
                    updated = true;
                }
            }
        }

      /*  for (int i = 1; i <= n; i++) {
            cout << i << " " << maxenergy[i] << endl;
        }*/

        for (int i = 0; i < E; i++) {
            s = get<0>(edge[i]);
            d = get<1>(edge[i]);
            if (maxenergy[s] <= 0)continue;
            if (maxenergy[d] < maxenergy[s] + energy[d])
                caninf[d] = 1;
        }

        for (int i = 1; i <= n; i++) {
            if (caninf[i] == 1)
            {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int x = q.front();
            q.pop();
            caninf[x] = 1;
            for (int i : next[x])
            {
                if (caninf[i] == 0) {
                    q.push(i);
                }
            }
            if (caninf[n] == 1) break;
        }
        

 /*       for (int i = 1; i <= n; i++) {
            cout << i << " " << caninf[i] << endl;
        }*/


        if (maxenergy[n]>0 || caninf[n])
            cout << "winnable" << endl;
        else
            cout << "hopeless" << endl;

    }

    return 0;
}


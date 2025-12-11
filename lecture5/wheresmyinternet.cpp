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

using namespace std;

typedef vector<int> vi;
typedef vector<long long int> vll;
typedef long long int ll;
typedef vector<double> vd;
typedef pair<int, int> ii;


int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, m;
    int a, b;
    stack<int> net;
    int v;
    int check = 0;

    cin >> n >> m;
    vi visited(n+1);
    vector<vector<int>> conected;
    visited[1] = 1;
    conected.assign(n+1, vector<int>(0, 0));


    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        conected[a].push_back(b);
        conected[b].push_back(a);
    }
    for (auto iter = conected[1].begin(); iter != conected[1].end();++iter) {
        //cout << *iter << endl;
        visited[*iter] = 1;
        net.push(*iter);
    }
    while (!net.empty())
    {
        v = net.top();
        net.pop();
        for (auto iter = conected[v].begin(); iter!=conected[v].end(); ++iter) {
            if (!visited[*iter])
            {
                net.push(*iter);
                visited[*iter] = 1;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (visited[i] == 0) {
            check = 1;
        }
        //cout << i << "番目" << visited[i] << endl;
    }
    if (check == 0) {
        cout << "Connected" << endl;
    }
    else
    {
        for (int i = 1; i <= n; i++) {
            if (visited[i] == 0) {
                cout << i << endl;
            }
        }
    }

    return 0;
}


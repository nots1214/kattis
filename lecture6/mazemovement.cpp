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
#define V 1000
using namespace std;

typedef vector<int> vi;
typedef vector<long long int> vll;
typedef long long int ll;
typedef vector<double> vd;
typedef pair<int, int> ii;

int n;

int gcd(int x,int y) {
    int a, b;
    a = max(x, y);
    b = min(x, y);
    if (a % b == 0)
        return b;
    else
        return gcd(a%b, b);
}


bool bfs(int path[V][V], int s, int t, int parent[],int n)
{
    int visited[V];
    memset(visited, 0, sizeof(visited));
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < n; v++) {
            if (visited[v] == 0 && path[u][v] > 0) {
                if (v == t) {
                    parent[v] = u;
                    return true;
                }
                q.push(v);
                parent[v] = u;
                visited[v] = 1;
            }
        }
    }


    return 0;
}

int fordFulkerson(int path[V][V], int s, int t,int n)
{
    int u, v;
    int rGraph[V][V];

    for (u = 0; u < n; u++)
        for (v = 0; v < n; v++)
            rGraph[u][v] = path[u][v];

    int parent[V]; 

    int max_flow = 0;

    while (bfs(rGraph, s, t, parent,n)) {

        int path_flow = MAX;
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }

        max_flow += path_flow;
    }

    return max_flow;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);


    vi num;
    int g;
    int path[V][V] = { 0 };
    cin >> n;
    num.assign(n,0);
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    sort(num.begin(), num.end());
    for (int i = 0; i < n-1; i++) {
        for (int j = i + 1; j < n; j++) {
            g = gcd(num[i], num[j]);
            if (g >= 2)
            {
                path[i][j] = g;
                path[j][i] = g;
            }
        }
    }

    cout << fordFulkerson(path, 0, n-1, n);
    

    return 0;
}


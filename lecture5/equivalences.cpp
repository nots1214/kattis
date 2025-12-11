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

vector<vi> graph;
vector<vi> graph_rev;
vi scc_num;
vi scc_num_rev;
vi visited;
vi visited2;
vi scc_num2;
vi sccin;
vi sccout;
int label;
int label2;
void SCC(int now) {
    visited[now] = 1;
    for (int i : graph[now]) {
        if (scc_num[i] != -1)continue;
        if (!visited[i])
        {
            SCC(i);
        }
    }/*
    cout <<"now="<< now << endl;*/
    scc_num[now] = label;
    scc_num_rev[label] = now;
    label++;

}

void SCC2(int now) {
    scc_num2[now] = label2;
    visited2[now] = 1;
    for (int i : graph_rev[now]) {
        if (visited2[i] == 0)
            SCC2(i);
    }

}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int T;
    int a, b;
    int ans;
    int needin;
    int needout;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n, m;
        cin >> n >> m;
        graph.assign(n+1, vi(0));
        graph_rev.assign(n + 1, vi(0));
        scc_num.assign(n + 1, -1);
        scc_num_rev.assign(n + 1, -1);
        scc_num2.assign(n + 1, -1);
        visited.assign(n + 1, 0);
        visited2.assign(n + 1, 0);
        sccin.assign(n, 0);
        sccout.assign(n, 0);
        ans = 0;
        needin = 0, needout = 0;
        label = 0;
        label2 = 0;
        for (int i = 0; i < m; i++) {
            cin >> a >> b;
            graph[a].push_back(b);
            graph_rev[b].push_back(a);
        }
        for (int i = 1; i <= n; i++) {
            if (scc_num[i] == -1)
                SCC(i);
        }
        for (int i = n-1; i >=0; i--) {
            if (scc_num2[scc_num_rev[i]] == -1)
            {
                SCC2(scc_num_rev[i]);
                label2++;
            }
        }
        //for (int i : scc_num) {
        //    cout << i << endl;
        //}
       /* for (int i : scc_num2) {
            cout << i << endl;
        }*/
        for (int i = 1; i <= n; i++) {
            for (int j : graph[i]) {
                if (scc_num2[i] == scc_num2[j])continue;
                sccin[scc_num2[j]]++;
                sccout[scc_num2[i]]++;
            }
        }
        for (int i = 0; i < label2; i++) {
            if (sccin[i] == 0)needin++;
            if (sccout[i] == 0)needout++;
        }
        if (label2 == 1)
            ans = 0;
        else
            ans = max(needin, needout);

        cout << ans << endl;


    }




    return 0;
}

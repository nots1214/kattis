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

    int T, n, m;
    int a, b;
    queue<int> comp1, comp2;
    int v;
    int sum, ans,ans2;
    int now;
    int check1, check2;
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> n >> m;
        ans = 0;
        ans2 = 0;
        sum = 0;
        vi stage;
        vi in, in2;
        check1 = 0;
        check2 = 0;

        in.assign(n + 1, 0);
        in2.assign(n + 1, 0);
        stage.assign(n + 1, 0);

        vector<vi> graph;
        graph.assign(n + 1, vi(0, 0));

        for (int i = 1; i <= n; i++) {
            cin >> stage[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> a >> b;
            graph[a].push_back(b);
            in[b]++;
            in2[b]++;
        }

        //lab1スタート
        for (int i = 1; i <= n; i++) {
            if (in[i] == 0) {
                if (stage[i] == 1) {
                    comp1.push(i);
                }
                else
                    comp2.push(i);
            }
        }

        while (!comp1.empty() || !comp2.empty()) {
            if (ans % 2 == 0) {
                if (comp1.empty()) {
                    ans++;
                    continue;
                }
                v = comp1.front();
                comp1.pop();
            }
            if (ans % 2 == 1) {
                if (comp2.empty()) {
                    ans++;
                    continue;
                }
                v = comp2.front();
                comp2.pop();
            }
            for (auto iter = graph[v].begin(); iter != graph[v].end(); ++iter) {
                now = *iter;
                if (in[now] == 1 && stage[now] == 1) {
                    comp1.push(now);
                }
                else if (in[now] == 1 && stage[now] == 2) {
                    comp2.push(now);
                }
                in[now]--;
            }
        }
        

        //lab2スタート

        for (int i = 1; i <= n; i++) {
            if (in2[i] == 0) {
                if (stage[i] == 1) {
                    comp1.push(i);
                }
                else
                    comp2.push(i);
            }
        }

        while (!comp1.empty() || !comp2.empty()) {

            if (sum % 2 == 1) {
                if (comp1.empty()) {
                    sum++;
                    continue;
                }
                v = comp1.front();
                comp1.pop();
            }
            if (sum % 2 == 0) {
                if (comp2.empty()) {
                    sum++;
                    continue;
                }
                v = comp2.front();
                comp2.pop();
            }
            for (auto iter = graph[v].begin(); iter != graph[v].end(); ++iter) {
                now = *iter;
                if (in2[now] == 1 && stage[now] == 1) {
                    comp1.push(now);
                }
                else if (in2[now] == 1 && stage[now] == 2) {
                    comp2.push(now);
                }
                in2[now]--;
            }
        }

        ans2 = min(ans, sum);
        
        
        cout << ans2 << endl;
    }
   

    return 0;
}
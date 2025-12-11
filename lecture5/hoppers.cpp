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
    int a,b;
    vector<vi> next;
    queue<int> q;
    vi num;
    int now;
    int cycle = 0;
    int ans = 0;
    cin >> n >> m;
    next.assign(n+1, vi(0, 0));
    num.assign(n + 1, 0);
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        next[a].push_back(b);
        next[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (num[i] == 0) {
            q.push(i);
            num[i] = 1;
            while (!q.empty()) {
                now = q.front();
                q.pop();
                for (int neigh : next[now]) {
                    if (num[neigh] == 0)
                    {
                        q.push(neigh);
                        num[neigh] = num[now]+1;
                    }
                    else if ((num[neigh] - num[now]+500010)%2==0)
                        cycle = 1;

                }
            }
        }
        //cout << i << "番目" << num[i] << endl;
    }

    for (int i = 1; i <= n; i++) {
        if (num[i] == 1)
            ans++;
    }

    if (cycle)
        cout << ans - 1 << endl;
    else
        cout << ans;


    return 0;
}

#include <stdio.h>
#include<vector>
#include<map>
#include<iostream>
#include<algorithm>
#include<set>
#include<stdlib.h>
#include<math.h>
#include<stack>

using namespace std;
typedef vector<int> vi;


int main() {
    ios::sync_with_stdio(0), cin.tie(0);
   
  
    int n, m;
   
    
    vi check;
    vi root;
    stack<int> st;
    int k;

    cin >> n;
     vi item(n);
     for (int i = 0; i < n; i++) {
        cin >> item[i];
    }
    cin >> m;
    vi order(m);
    for (int i = 0; i < m; i++) {
        cin >> order[i];
    }
    check.assign(30001, 0);
    check[0] = 1;
   
    for (int j = 0; j < n; j++) {
        for (int i = item[j]; i <= 30000; i++) {      
            if (i - item[j] >= 0)
            {
                if (check[i - item[j]] == 1)
                    check[i] += check[i - item[j]];
                else if (check[i - item[j]] > 1)
                    check[i] = 2;
            }
        }
    }
 
  /*  for (int i = 0; i < 100; i++) {
        cout << i << "=" << check[i] << endl;
    }*/

    for (int i = 0; i < m; i++) {
        if (check[order[i]] == 0)
        {
            cout << "Impossible" ;
        }
        else if (check[order[i]] > 1) {
            cout << "Ambiguous";
        }
        else if (check[order[i]] == 1) {
            k = order[i];
            while (k>0) {
                for (int j = n-1; j >=0; j--) {
                    if (k - item[j] < 0)
                        continue;
                    if (check[k - item[j]])
                    {
                        st.push(j+1);
                        k -= item[j];
                        break;
                    }
                }
            }
            while (!st.empty())
            {
                cout << st.top();
                st.pop();
                if (!st.empty())
                    cout << " ";
            }
            
        }
        if (i < m - 1)
            cout <<endl;
    }


    return 0;
}
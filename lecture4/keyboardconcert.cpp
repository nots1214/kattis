#include <stdio.h>
#include<vector>
#include<map>
#include<iostream>
#include<algorithm>
#include<set>
#include<stdlib.h>

using namespace std;
typedef vector<int> vi;



int main() {

    int n, m;
    cin >> n >> m;
    vi k(n);
    vector<vector<int>> l(n, (vector<int>(1001)));
    int min = 0;
    int a;
    vi o(m);
    //vector<vector<int>> T(n, (vector<int>(m)));
    vector<vector<int>> T(m, (vector<int> (n)));
    int check;
    int loc_index;

    //T.assign(n,vector<int>(1001,0));
    T.assign(m, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        cin >> k[i];
        for (int j = 0; j < k[i]; j++) {
            cin >> a;
            l[i][a] = 1;
        }
    }
    for (int i = 0; i < m; i++) {
        cin >> o[i];
    }
    for (int j = 0; j < n; j++) {
        if (l[j][o[0]])
        {
            T[0][j] = 1;
        }
    }
    for (int i = 1; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (l[j][o[i]])
            {
                T[i][j] = T[i - 1][j] + 1;
            }
        }
    }
 /*   for (int i = 0; i < n; i++) {
        for(int j=0;j<m;j++){
            cout << T[j][i] << " ";
        }
        cout << endl;
    }*/
    check = m-1;
    while (check>=0) {
        auto index = max_element(T[check].begin(), T[check].end());
        loc_index = distance(T[check].begin(), index);
        //cout << loc_index <<"  " << T[check][loc_index] << endl;
        check -= T[check][loc_index];
        
        min++;
    }
    min--;
    cout << min;


    return 0;
}
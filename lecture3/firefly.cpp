#include<stdio.h>
#include<stdlib.h>
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
    vi wall;
    vi wallx;
    int N, H;
    int num;
    int des, despoint = 0;
    int maxunder, maxup;
    cin >> N >> H;
    wall.assign(H, 0);
    for (int i = 0; i < N/2; i++) {
        cin >> num;
        wall[num]++;
        cin >> num;
        wall[H-num]--;
    }
    wallx.assign(H, 0);
    wallx[0] = N / 2;
    //cout << endl;
   // cout << wallx[0];
   // cout << endl;
    for (int i = 1; i < H; i++) {
        wallx[i] = wallx[i - 1] - wall[i];
     //   cout << wallx[i]<<endl;
    }

 /*   maxunder = 0;
    maxup = H - 1;
    for (int i = 0; i < N/2; i++) {
        cin >> num;
        if (maxunder < num)
            maxunder=num;
        cin >> num;
        if (maxup < num)
        {
            maxup < num;
        }
    }
    if (maxunder < H - maxup)
    {
        des = 0;
        despoint = H - maxup - maxunder;
    }
    else {*/




        auto desindex = min_element(wallx.begin(), wallx.end());
        des = *desindex;
        for (int i = 0; i < H; i++)
        {
            if (wallx[i] == des)
                despoint++;
        }
    //}
    cout << des << " " << despoint;

    return 0;
}




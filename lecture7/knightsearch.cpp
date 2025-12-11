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

int n;
string moji = { "ICPCASIASG" };
vector<vector<char>> land;
int check = 0;

void dig(int x, int y, int num) {
    int next[8][2] = { {2,1},{1,2},{-2,1},{1,-2},{-1,2},{2,-1},{-1,-2},{-2,-1} };
    int xn, yn;
    for (int i = 0; i < 8; i++) {
        xn = x + next[i][0];
        yn = y + next[i][1];
        if (xn < n && xn >= 0 && yn >= 0 && yn < n) {
           // cout << land[xn][yn] << "と" << moji[num] << endl;
            if (num == 9 && land[xn][yn] == moji[num])
                check = 1;
            else if (land[xn][yn] == moji[num]) {
                dig(xn, yn, num + 1);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    
    string str;
    
    cin >> n;
    land.assign(n, vector<char>(n, NULL));
    cin >> str;


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            land[i][j] = str[i * n + j];
        }
    }

    for (int i = 0; i < n; i++) {
        if (check) break;
        for (int j = 0; j < n; j++) {
            if (check) break;
            if (land[i][j] == 'I') {
                dig(i, j, 1);
            }
        }
    }

    if (check)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;


    return 0;
}


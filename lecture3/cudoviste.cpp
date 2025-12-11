#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#include<iostream>
#include<numeric>
#include<map>
#include<queue>

using namespace std;

typedef vector<int> vi;
typedef vector<long long int> vll;
typedef long long int ll;


int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int R, C;
    char matrix[50][50];
    int ans[5] = { 0 };
    int check;
    cin >> R >> C;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < R - 1; i++) {
        for (int j = 0; j < C - 1; j++) {
            check = 0;
            if (matrix[i][j] == '.') {
                check++;
                if (matrix[i][j + 1] == '.') {
                    check++;
                }
                else if (matrix[i][j + 1] == '#')
                {
                    check = -100;
                }
                if (matrix[i + 1][j] == '.') {
                    check++;
                }
                else if (matrix[i + 1][j] == '#')
                {
                    check = -100;
                }
                if (matrix[i + 1][j + 1] == '.') {
                    check++;
                }
                else if (matrix[i + 1][j + 1] == '#')
                {
                    check = -100;
                }
            }
            else if (matrix[i][j] == 'X') {
                if (matrix[i][j + 1] == '.') {
                    check++;
                }
                else if (matrix[i][j + 1] == '#')
                {
                    check = -100;
                }
                if (matrix[i + 1][j] == '.') {
                    check++;
                }
                else if (matrix[i + 1][j] == '#')
                {
                    check = -100;
                }
                if (matrix[i + 1][j + 1] == '.') {
                    check++;
                }
                else if (matrix[i + 1][j + 1] == '#')
                {
                    check = -100;
                }
            }
            else check = -100;
            if (check >= 0) {
                ans[4 - check]++;
            }
        }
    }

    for (int i = 0; i < 5; i++) {
        cout << ans[i] << endl;
    }

        return 0;
}




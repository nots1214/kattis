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
using namespace std;

typedef vector<int> vi;
typedef vector<long long int> vll;
typedef long long int ll;
typedef vector<double> vd;
typedef pair<int, int> ii;

map<string, int> code;

int neq(double d)
{
    if (d < -DELTA)
        return 1;
    else
        return 0;
}



int main() {
    ios::sync_with_stdio(0), cin.tie(0);


    int C, R;
    int a, b;
    int key;
    int check;
    vector<vd> profit;
    string str, str2, str3;
    string strint;
    string cpy;


    while (1) {
        cin >> C;
        if (C == 0)
            break;
       
        //init
        {
            profit.assign(C, vd(C, 0));
            check = 0; 
        }
        //input
        {
            for (int i = 0; i < C; i++) {
                cin >> str;
                code[str] = i;
                profit[i][i] = 1.0;
            }
            cin >> R;
            for (int i = 0; i < R; i++) {
                cin >> str >> str2 >> str3;
                for (int j = 0; j < str3.size(); j++) {
                    if (str3[j] == ':')
                    {
                        key = j; break;
                    }
                }
                a = 0;
                for (int j = 0; j < key; j++) {
                    a *= 10;
                    a += (int)(str3[j] - '0');
                }
                b = 0;
                for (int j = key + 1; j < str3.size(); j++) {
                    b *= 10;
                    b += (int)(str3[j] - '0');
                }
                profit[code[str]][code[str2]] = (double)b / (double)a;
            }
        }
        
        //calc
        for (int k = 0; k < C; k++) {
            for (int i = 0; i < C; i++) {
                for (int j = 0; j < C; j++) {
                    profit[i][j] = max(profit[i][j], profit[i][k] * profit[k][j]);
                    if (i == j && profit[i][i] > 1.0)
                        check = 1;
                }
                if (check) break;
            }
            if (check) break;
        }



        if (check)
            cout << "Arbitrage" << endl;
        else
            cout << "Ok" << endl;
    }


    return 0;
}


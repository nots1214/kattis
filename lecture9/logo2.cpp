#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
#include<numeric>
#include<map>
#include<queue>
#include<math.h>
#include<stack>
#include<math.h>


#define EPS 1e-8
#define MAX 2000000000
using namespace std;

typedef vector<int> vi;
typedef vector<long long int> vll;
typedef long long int ll;
typedef vector<double> vd;
typedef pair<int, int> ii;




int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int t;
    int n;
    string str;
    int num;
    string num2;
    long double startx,starty;
    long double startx2, starty2;
    int rad2;
    int rad;
    long double ans;
    int flag;
    long double testx, testy;

    cin >> t;
    while (t--) {
        cin >> n;
        startx = 0; starty = 0;
        rad = 0;
        startx2 = 0; starty2 = 0;
        rad2 = 0;
        flag = 0;
        for (int i = 0; i < n; i++) {
            cin >> str >> num2;
            if (num2 == "?")
            {
                if (str == "lt")
                    flag = 1;
                else if (str == "rt")
                    flag = 2;
                else if (str == "fd")
                {
                    flag = 3;
                }
                else {
                    flag = 4;
                }

            }
            else
            {
                num = atoi(num2.c_str());


                if (flag == 0 || flag == 3 || flag == 4)
                {
                    if (str == "lt")
                    {
                        rad += num;
                        rad = rad % 360;
                    }
                    else if (str == "rt")
                    {
                        rad -= num;
                        rad = (rad + 360) % 360;
                    }
                    else if (str == "fd")
                    {
                        startx += (long double)num * cos((long double)(rad)*acos(-1) / 180);
                        starty += (long double)num * sin((long double)(rad)*acos(-1) / 180);
                    }
                    else if (str == "bk") {
                        startx -= (long double)num * cos((long double)(rad)*acos(-1) / 180);
                        starty -= (long double)num * sin((long double)(rad)*acos(-1) / 180);
                    }
                }
                else {
                    if (str == "lt")
                    {
                        rad2 += num;
                        rad2 = rad2 % 360;
                    }
                    else if (str == "rt")
                    {
                        rad2 -= num;
                        rad2 = (rad2 + 360) % 360;
                    }
                    else if (str == "fd")
                    {
                        startx2 += (long double)num * cos((long double)(rad2)*acos(-1) / 180);
                        starty2 += (long double)num * sin((long double)(rad2)*acos(-1) / 180);
                    }
                    else if (str == "bk") {
                        startx2 -= (long double)num * cos((long double)(rad2)*acos(-1) / 180);
                        starty2 -= (long double)num * sin((long double)(rad2)*acos(-1) / 180);
                    }
                }
            }
        }
        if (flag == 3 || flag == 4) {
            ans = sqrt(startx * startx + starty * starty);
            cout << (int)round(ans) << endl;//int
        }
        else
        { 
           
            for (int i = 0; i < 360; i++) {
                testx = startx + startx2 * cos((long double)(rad + i) * acos(-1) / 180) - starty2 * sin((long double)(rad + i) * acos(-1) / 180);
                testy = starty + startx2 * sin((long double)(rad + i) * acos(-1) / 180) + starty2 * cos((long double)(rad + i) * acos(-1) / 180);
                if (fabs(testx) < EPS && fabs(testy) < EPS)
                {
                    if (flag == 1)
                    {
                        cout << i << endl;
                    }
                    else
                        cout << (360 - i)%360 << endl;

                    break;
                }
                
            }
        }
    }

    return 0;
}
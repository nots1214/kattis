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

vi p;
vi pcount;
int maxprime;
void get_prime() {
    int n = 1;
    int isdevided;
    p.push_back(2);
    for (int j = 3; j <= 2000000; j++) {
        isdevided = 0;
        for (int i = 0; i < n && p[i]*p[i] <= j; i++) {
            if (j % p[i] == 0)
            {
                isdevided = 1;
                break;
            }
        }
        if (!isdevided)
        {
            p.push_back(j); n++;
        }
    }
}
void primefactoring(int num) {
    for (int i = 0; i < p.size() && num>=p[i]; i++) {
        while (num % p[i] == 0) {
            pcount[i]++;
            num /= p[i];
            maxprime = i;
        }
    }
}

int candivid(string str, int num) {
    string sub = str.substr(0, num);
    int len = str.length();
    //cout << sub << endl;

    string sub2;
    for (int i = 0; num * i < len;i++) {
        sub2 = str.substr(num * i, num);
        if (sub.compare(sub2) != 0)
        {
            return 0;
        }
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    string str;
    int len;
    int ans;
    int d;
    get_prime();
    
    //for (int i = 0; i < 30; i++) {
    //    cout << p[i] << endl;
    //}
    while (1) {
        cin >> str;
        if (str == ".")
            break;
        pcount.assign(p.size(), 0);
        len = str.length();
        maxprime = 0;
        primefactoring(len);
   /*     for (int i = 0; i < 10; i++)
        {
            cout << p[i] << "は" << pcount[i] << "個持ちます" << endl;
        }
        cout << "最大素数は" << p[maxprime] << endl;*/
        for (int i = 0; i <= maxprime ; i++) {
            d = str.length();
            for(int j=0;j<pcount[i];j++){
                d /= p[i];
                if (candivid(str, d)) {
                    str = str.substr(0, d);
                }
                else break;
            }
        }
        //if (candivid(str, 1)) {
        //    str = str.substr(0, 1);
        //}
        ans = len/str.size();
        cout << ans << endl;
    }
    return 0;
}


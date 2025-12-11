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


#define DELTA 1e-9
#define MAX 2000000000
using namespace std;

typedef vector<int> vi;
typedef vector<long long int> vll;
typedef long long int ll;
typedef vector<double> vd;
typedef pair<int, int> ii;

vi lesdig;
vi lesdig2;

void find_ans(int x) {
    lesdig[0] = 1;
    lesdig[1] = 1;
    lesdig2[1] = 1;
    int div2 = 0;
    int div5 = 0;
    int j;
    for (int i = 2; i <= x; i++) {
        j = i;
        while (j % 2 == 0)
        {
            div2++; j /= 2;
        }
        while (j % 5 == 0)
        {
            div5++; j /= 5;
        }
        lesdig[i] = (lesdig[i - 1] * (j % 10)) % 10;
        lesdig2[i] = lesdig[i];
        for (int k = 0; k < (div2 - div5 - 1) % 4 + 1; k++)
            lesdig2[i] = (lesdig2[i] * 2) % 10;
       
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    int ans = 0;
    lesdig.assign(1000001, 0);
    lesdig2.assign(1000001, 0);
    find_ans(1000000);
    //for (int i = 1; i <= 100; i++) { cout << lesdig2[i]<<endl; }
    while (1)
    {
        cin >> n;
        if (n == 0)break;
        ans = lesdig2[n];
        cout << ans << endl;


    }


    return 0;
}

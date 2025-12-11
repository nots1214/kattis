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

string word;
string exword;
string minword ="zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";

int comp(int x, int y) {
    if (x == 0) {
        //cbadcbaXXXX→x
        //dcbacbaXXXX→y(ここに来ない)
        //cbacbacbaXXXX→?
        //cbacbacbad→abcabcabcd
        //cbadacba→abcabcad  abcadabc  x
        return x;
    }
    else
    {
        x--; y--;
        if ((int)(word[x] - 'a') < (int)(word[y] - 'a')) {
            return x + 1;
        }
        else if ((int)(word[x] - 'a') > (int)(word[y] - 'a'))
        {
            return y + 1;
        }
        else if ((int)(word[x] - 'a') == (int)(word[y] - 'a'))
            return comp(x - 1, y - 1) + 1;
    }
}

string asses(string X, string Y,int n) {
    if (n == word.length()) {
        return Y;
    }
    if ((int)X[n] - (int)Y[n] > 0)
        return Y;
    else if ((int)X[n] - (int)Y[n] < 0) {
        return X;
       
    }
    else if ((int)X[n] - (int)Y[n] == 0)
    {
        return asses(X, Y,n + 1);
    }
}
void reve(int x,int y) {
    int temp;

    while (x <= y) {
        //temp = word[x];
        //word[x] = word[y];
        //word[y] = temp;
      //  cout << x<<y;
        exword[y] = word[x];
        //cout << exword;
        exword[x] = word[y];
        x++;
        y--;
    }
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    /*int min,minkey,minkey2;
    
    int length;
    cin>> word;
    length = word.length();
    min = int(word[0] - 'a');
    minkey = 0;
    for (int i = 1; i < length - 2; i++) {
        if (min > int(word[i] - 'a'))
        {
            min = int(word[i] - 'a');
            minkey = i;
        }
        else if (min == int(word[i] - 'a'))
        {
            minkey = comp(minkey - 1, i - 1);
        }
    }
    reve(0, minkey);
    min = int(word[minkey+1] - 'a');
    minkey2 = minkey + 1;
    for (int i = minkey2 + 1; i < length - 1; i++) {
        if (min > int(word[i] - 'a'))
        {
            min = int(word[i] - 'a');
            minkey2 = i;
        }
        else if (min == int(word[i] - 'a'))
        {
            minkey2 = comp(minkey2 - 1, i - 1);
        }
    }
    reve(minkey + 1, minkey2);
    reve(minkey2 + 1, length - 1);*/

    int min, div1, div2;

    int length;
    cin >> word;
    exword = word;
    length = word.length();
    for (int i = 0; i < length - 2; i++) {
        for (int j = i + 1; j < length - 1; j++) {
            reve(0, i);
            reve(i+1, j);
            reve(j + 1, length - 1);
            minword = asses(minword, exword,0);
        }
    }

    cout << minword;
    return 0;
}




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

int search(string str, int size) {
    string str2;
    string str3;
    int max, count;
    map<string, int> trans,exit;
    max = 0;
    for (int j = 0; j+size-1 <str.length() ; j++) {
        str2 = str.substr(j, size);
        if (exit[str2])
        {
            trans[str2]++;
        }
        else
        {
            exit[str2] = 1;
            trans[str2] = 1;
        }
        //cout <<str2<<" " << trans[str2] << endl;
        /*count = 0;
        for (int i = j; i + size - 1 < str.length(); i++) {
            str3 = str.substr(i, size);
            if (str2.compare(str3) == 0)
                count++;
        }*/
        if (max < trans[str2])
            max = trans[str2];
    }

    
    return max;
}


int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    string inputstr;
    string str;
    int num;
    while(1){
        str.resize(0);
        getline(cin, inputstr);
        if (inputstr == "") break;
        for(int i=0;i<inputstr.length();i++) {
            if(inputstr[i] != ' ')
            str = str + inputstr[i];
        }
        

        for (int i = 1; i <= str.length(); i++) {
            num = search(str, i);
            if (num <= 1)
                break;
            else
                cout << num << endl;
        }
        cout << endl;
    }
    return 0;
}
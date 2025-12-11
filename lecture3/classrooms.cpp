#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#include<iostream>
#include<numeric>
#include<map>
#include<set>
#include<queue>

using namespace std;

typedef vector<int> vi;
typedef vector<long long int> vll;
typedef long long int ll;

//sort(v.begin(), v.end(), [](const vector<int>& alpha, const vector<int>& beta) {return alpha[0] < beta[0]; });
//二次元配列を0番目の要素でソート

int main() {
   // ios::sync_with_stdio(0), cin.tie(0);

    vector<vector<int>> time;
    //vector<int> room;
    multiset<int> room;
    vector<vector<int>> time2;
    int result;


    int N, K;
    cin >> N >> K;

    result = 0;

    time.assign(2, vector<int>(N,0));//start and end
    //room.assign(K,1000000000);//last starting time and last ending time;
    for (int i = 0; i < K; i++) {
        room.insert(1000000001);
    }//O(K)
    time2.assign(N, vector<int>(2, 0));
    


    for (int i = 0; i < N; i++) {
        cin >> time2[i][0] >> time2[i][1];
    }//O(N)

    sort(time2.begin(), time2.end(), [](const vector<int>& alpha, const vector<int>& beta) {return alpha[0] > beta[0]; });
    //O(logN)

    //転置
    for (int i = 0; i < N; i++) {
        time[0][i] = time2[i][0];
        time[1][i] = time2[i][1];
    }
    //O(N)
   /* for (int i = 0; i < N; i++) {
        cout << time[0][i] << "  " << time[1][i] << endl;
    }*/

    //solve
    for (int i = 0; i < N; i++) {

        //auto maxindex = upper_bound(room.begin(), room.end(), time[1][i]); //O(logK)?
        auto maxindex = room.upper_bound(time[1][i]);
        if (maxindex == room.end())
        {
            continue;
        }
        else
        {
            room.erase(maxindex);
            room.insert(time[0][i]);
            result++;
            //sort(room.begin(), room.end()); //O(KlogK) →　ソートせずに常に昇順の集合が必要 → multiset
        }        
    }//O(3NlogK)

    cout << result;

    return 0;
}
//O(2N+logN+K+3NlogK)=O(600000+log200000+600000log200000)=O(600000+16+9600000)=O(10200000)=0.1秒くらい？

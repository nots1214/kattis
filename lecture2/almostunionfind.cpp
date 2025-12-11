#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#include<iostream>
#include<numeric>
#include<map>
#include<queue>

using namespace std;

vector<int> num,mov;
vector<long long int> sum;
int find(int n);

int main() {

    int N, M, t, x, y;
    int k = 0;
    int loc_x, loc_y;
    int resultnum[1000000];
    long long int resultsum[1000000];
    while (cin >> N >> M) {
    //cin >> N >> M;


    //要素と集合をまとめる
    mov.assign(2 * N + 1, 0);
    sum.assign(N + 1, 0);
    num.assign(N + 1, 1);
    for (int i = 1; i <= N; i++) {
        mov[i] = i+N; 
        mov[i + N] = i+N;
        sum[i] = i;
    }

        for (int i = 0; i < M; i++) {
            cin >> t;
            if (t == 1) {
                cin >> x >> y;
                loc_x = find(x);
                loc_y = find(y);
                if (loc_x == loc_y) {
                    continue;}
                else
                {
                    //xの集合をyの集合へ
                    mov[loc_x] = loc_y;

                    sum[loc_y-N] += sum[loc_x-N];
                    num[loc_y-N] += num[loc_x-N]; 
                 
                }

            }
            else if (t == 2) {
                cin >> x >> y;
                loc_x = find(x);
                loc_y = find(y);

                //{1, 2}, { 3,4 }, { 5 }→{ 1,2,4 }, { 3 }, { 5 }
                if (loc_x == loc_y) {
                    continue;
                }
                else
                {
                    //xをyの集合へ
                    mov[x] = loc_y;
                    sum[loc_y-N] += x;
                    sum[loc_x-N] -= x;
                    num[loc_y-N]++;
                    num[loc_x-N]--;
                }
            }
            else if (t == 3) {
                cin >> x;
               // cout << num[find(x)-N] << " " << sum[find(x)-N] << endl;
                resultnum[k] = num[find(x) - N];
                resultsum[k] = sum[find(x) - N];

                k++;
            }
        }
   
}
        //結果出力
        for (int i = 0; i < k; i++) {
            cout << resultnum[i] << " " << resultsum[i] << endl;
        }
        return 0;
}


int find(int n) {//nの存在する集合の位置を探す(O(n))
    if (mov[n] == n)
        return n;
    else
        return find(mov[n]);
}


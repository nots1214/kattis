#include <stdio.h>
#include<vector>
#include<map>
#include<iostream>
#include<algorithm>
#include<set>
#include<stdlib.h>
#include<math.h>

using namespace std;
typedef vector<int> vi;



int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int k, n;
    int all;
    double result;
    double sum = 0.0;

    vector<vector<double>> part;
    while (cin >> k) {
        cin >> n;
        sum = 0;
        //vector<vector<int>> part(k + 1, vector<int>(n));
        part.assign(k + 1, (vector<double>(n, 0.0)));
        all = pow(k + 1, n);
        for (int i = 0; i <= k; i++) {
            part[i][0] = 1;
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= k; j++) {
                if (j == 0 && k == 0) {
                    part[j][i] = part[j][i - 1];
                }
                else if (j == 0)
                {
                    part[j][i] = part[j][i - 1] + part[j + 1][i - 1];
                    part[j][i] /= (k + 1);

                }
                else if (j == k) {
                    part[j][i] = part[j - 1][i - 1] + part[j][i - 1];
                    part[j][i] /= (k + 1);
                }
                else {
                    part[j][i] = part[j - 1][i - 1] + part[j][i - 1] + part[j + 1][i - 1];
                    part[j][i] /= (k + 1);
                }
            }
        }
        for (int i = 0; i <= k; i++) {
            sum += part[i][n - 1]/(k+1);
        }

        //result = (double)sum / all;
        //result *= 100;
        result = sum * 100.0;
        //cout << result;
        //printf("%d \n", sum);
        printf("%.9lf\n", result);
    }
    return 0;
}
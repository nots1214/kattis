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


int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int N, M;
    cin >> N >> M;
    vd nh;
    vd nt;
    vd ndt;
    vd mh;
    vd mt;
    vd mdt;
    double h = 0.0;
    int t1 = 0, t2 = 0;
    nh.assign(N, 0.0);
    nt.assign(N, 0.0);
    ndt.assign(N, 0.0);
    mh.assign(M, 0.0);
    mt.assign(M, 0.0);
    mdt.assign(M, 0.0);
    double ah, dh;
    double result = 0.0;

    ah = 0.0;
    for (int i = 0; i < N; i++) {
        cin >> nh[i] >> nt[i];
        h += nh[i];
        ndt[i] = nt[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> mh[i] >> mt[i];
        mdt[i] = mt[i];
    }

    dh = h;
    int x = 0; int y = 0;
    while (ah<dh) {
        if (ndt[x] < mdt[y])
        {

            ah += nh[x] * ndt[x] / nt[x];
            dh -= mh[y] * ndt[x] / mt[y];
            if (ah >= dh)
            {
              //  printf("ah=%lf,dh=%lf\n", ah, dh);
                ah -= nh[x] * ndt[x] / nt[x];
                dh += mh[y] * ndt[x] / mt[y];
                break;
            }
            t1 += ndt[x];
            mdt[y] -= ndt[x];
            result += ndt[x];
            
            x++;
        }
        else if (mdt[y] < ndt[x]) {
            t2 += mdt[y];
            dh -= mh[y] * mdt[y] / mt[y];
            ah += nh[x] * mdt[y] / nt[x];
            if (ah >= dh)
            {
                dh += mh[y] * mdt[y] / mt[y];
                ah -= nh[x] * mdt[y] / nt[x];
                break;
            }
            ndt[x] -= mdt[y];
            result += mdt[y];
           
            y++;
        }
        else if (mdt[y] == ndt[x])
        {
            ah += nh[x]*ndt[x]/nt[x];
            dh -= mh[y]*mdt[y]/mt[y];
            if (ah >= dh) {
                ah -= nh[x] * ndt[x] / nt[x];
                dh += mh[y] * mdt[y] / mt[y];
                break;
            }
            t1 += ndt[x];
            result += ndt[x];
            t2 += mdt[y];
       
            x++;
            y++;
        }
        //cout << ah <<"  "<< dh << endl;
       // printf("%lf : %lf\n", ah, dh);
       // //printf("%lf, %lf : %lf \n", result, ah + nh[x] * (nt[x] - ndt[x]) / nt[x], dh - mh[y] * (mt[y] - mdt[y]) / mt[y]);
    }
    // x--; y--; 
    //result -= nt[x];
  //  cout << result << endl;
   // x--;
    //ah -= nh[x];
    //dh += mh[y];

    //dh-mh/mt*t=ah + nh/nt+t
    //dh-ah=mh/mt+nh/nt *t
    //t=(dh-ah)/(mh/mt+nh/nt)

   // printf("dh %lf  ah %lf mh %lf mdt %lf nh %lf ndt %lf\n", dh, ah, mh[y], mdt[y], nh[x], ndt[x]);
 //   printf("%lf \n", result);
    
    
    //result -= 3;
    //x--;


   // mdt[y] += ndt[x];
    result += (dh - ah) / (mh[y] / mt[y] +nh[x] / nt[x]);
    printf("%lf", result);

    return 0;
}




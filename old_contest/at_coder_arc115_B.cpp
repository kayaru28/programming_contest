


#include  <iostream>
#include  <stdio.h>
#include <algorithm>
#include <map>
#include <math.h>

using namespace std;
#include <vector>
#define rep(i,n) for (ll i = 0; i < (n) ; i++)
#define INF 1e9
#define llINF 1e18
#define base10_4 10000      //1e4
#define base10_5 100000     //1e5
#define base10_6 1000000    //1e6
#define base10_7 10000000   //1e7
#define base10_8 100000000  //1e8
#define base10_9 1000000000 //1e9

#define MOD 1000000007
#define pb push_back
#define ll long long
#define ld long double
#define ull unsigned long long
#define vint vector<int>
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define vstr vector<string>
#define vvstr vector<vector<string>>


//#include <stack>
//#include <queue>

// #include <iomanip>
//  cout << fixed << setprecision(15) << y << endl;

string ans_Yes = "Yes"; 
string ans_No = "No"; 
string ans_yes = "yes"; 
string ans_no = "no"; 

ll N;
ll M;
ll K;

ll ltmp;
string stmp;
double dtmp;

vll C[500];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    rep(ni,N){
        C[ni].resize(N);
        rep(nii,N) cin >> C[ni][nii];
    }
    



    string ans = "Yes";
    for( ll ni = 1 ; ni <N ; ni++ ){
        ll base = C[ni][0]-C[ni-1][0];
        for( ll nj =1 ; nj <N ; nj++ ){
            if(base!= (C[ni][nj]-C[ni-1][nj])  ){
                ans = "No";
                ni = N;
                nj = N;
            }
        }
    }
    for( ll nj =1 ; nj <N ; nj++ ){
        ll base = C[0][nj]-C[0][nj-1];
        for( ll ni = 1 ; ni <N ; ni++ ){
            if(base!= (C[ni][nj]-C[ni][nj-1])  ){
                ans = "No";
                ni = N;
                nj = N;
            }
        }
    }

    vll B;
    vll A;
    if(ans=="Yes"){
        ll min_ni=0,min_nj=0;
        ll min_val = C[0][0];
        rep(ni,N){
            rep(nj,N){
                if(C[ni][nj]< min_val){
                    min_ni = ni;
                    min_nj = nj;
                    min_val = C[ni][nj];
                }
            }
        }





        ans = "No";
        for( ll a1 = 0 ; a1 <=C[min_ni][min_nj] ; a1++ ){

            ll flag = 1;
            A.clear();
            B.clear();

            rep(ji,N){
                ll tar = C[min_ni][ji] - a1;
                if(tar<0){
                    flag = 0;
                    break;
                }
                B.push_back(tar);
            }
            if(flag == 0) continue;
            rep(ni,N){
                ll tar = C[ni][0] - B[0];
                if(tar<0){
                    flag = 0;
                    break;
                }
                A.push_back(tar);
            }
            if(flag == 0) continue;

            ans = "Yes";
            break;
        }
    }

    cout << ans << endl;
    if(ans=="Yes"){
        rep(ai,A.size()) cout << A[ai] << " ";
        cout << endl;
        rep(bi,B.size()) cout << B[bi] << " ";

    }

}
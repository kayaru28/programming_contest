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
#define ull unsigned long long
#define vint vector<int>
#define vll vector<ll>

//#include <stack>
//#include <queue>

// #include <iomanip>
//  cout << fixed << setprecision(15) << y << endl;

string ans_Yes = "Yes"; 
string ans_No = "No"; 
string ans_yes = "yes"; 
string ans_no = "no"; 

vll A;
vll B;
ll C;
ll N;
ll M;
ll K;

ll ltmp;
string stmp;
double dtmp;
map<ll,ll> mapA,mapB;
vll vals;
map<ll,ll> mapV;
int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    A.resize(N);
    B.resize(N);
    
    rep(ni,N){
        cin >> A[ni] >> B[ni];
        mapA[A[ni]]++;
        mapB[B[ni]]++;
        mapV[A[ni]]++;
        mapV[B[ni]]++;
    }
    for(auto x : mapV) {
        ll key = x.first;
        vals.push_back(key);
    }
    
    double ans;
    if(N%2==1){
        ll ind_base = (N+1)/2;
        ll cnt_end=0;
        ll cnt_exi=0;
        ll cnt_ans = 0;
        rep(vi,vals.size()){
            ll ni = vals[vi];
            cnt_exi += mapA[ni];
            if(cnt_exi+cnt_end >= ind_base){
                cnt_ans++;
            }
            cnt_exi -= mapB[ni];
            cnt_end += mapB[ni];
            if(cnt_end >= ind_base) break;
        }
        ans = cnt_ans;
    }else{
        map<ll,ll> kouho1;
        map<ll,ll> kouho2;
        ll ind_base1 = N/2;
        ll ind_base2 = N/2+1;
        ll cnt_end=0;
        ll cnt_exi=0;
        ll cnt_ans = 0;
        rep(vi,vals.size()){
            ll ni = vals[vi];
            cnt_exi += mapA[ni];
            if(cnt_end < ind_base1 && cnt_exi+cnt_end >= ind_base1){
                kouho1[ni]+=cnt_exi;
            }
            if(cnt_end < ind_base2 && cnt_exi+cnt_end >= ind_base2){
                kouho2[ni]+=cnt_exi;
            }
            cnt_exi -= mapB[ni];
            cnt_end += mapB[ni];
            if(cnt_end >= ind_base2) break;
        }
        map<ll,ll> ansval;

        for(auto k1 : kouho1) {
            ll val1 = k1.first;
            ll cnt1 = k1.second;
            //cout << "calc" << endl;
            //cout << val1 << " " << cnt1 << endl;
            for(auto k2 : kouho2) {
                ll val2 = k2.first;
                ll cnt2 = k2.second;
                //cout << val2 << " " << cnt2 << endl;
    
                if(cnt1==1 && cnt2==1){
                    if(mapA[val2]==0){
                        continue;
                    }
                }
                ltmp = (val1+val2);
                //cout << dtmp << endl;
                ansval[ltmp]++;
            }
        }
        ans = ansval.size();
    }

    cout << ans << endl;

}
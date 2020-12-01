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

//#include <stack>
//#include <queue>

// #include <iomanip>
//  cout << fixed << setprecision(15) << y << endl;

string ans_Yes = "Yes"; 
string ans_No = "No"; 
string ans_yes = "yes"; 
string ans_no = "no"; 

vll A;
ll B;
ll C;
ll N;
ll M;
ll K;

ll ltmp;
string stmp;
double dtmp;

ll getCnt(ll ki){
    ll cnt=0;
    rep(ni,N){
        ll cut;
        if(A[ni]<=ki){
            cut = 0;
        }else if(A[ni]%ki>0){
            cut = A[ni]/ki;
        }else{
            cut = A[ni]/ki;
            cut--;
        }
        cnt += cut;
    }
    return cnt;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    cin >> K;
    ll sumA=0;

    rep(ni,N){
        cin >> ltmp;
        A.push_back(ltmp);
        sumA += ltmp;
    }
    sort(A.begin(),A.end());

    ll kl = 1;
    ll kr = A[N-1];
    if(getCnt(kl)<=K){
        cout << kl << endl;
    }else{
        while( kr-1 > kl ){
            //cout << kl << " : " << kr << endl;
            ll kmid = (kl + kr)/2;

            ll cnt = getCnt(kmid);
            if(cnt==K){
                kr = kmid;
            }else if(cnt>K){
                kl = kmid;
            }else{
                kr = kmid;
            }
        }
        cout << kr << endl;

    }
    



    

}
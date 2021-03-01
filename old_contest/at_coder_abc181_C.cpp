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

vector<double> X;
vector<double> Y;
ll C;
ll N;
ll M;
ll K;
vector<double> a;

ll ltmp;
string stmp;
double dtmp;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;


    rep(ni,N){
        cin >> dtmp;
        X.push_back(dtmp);
        cin >> dtmp;
        Y.push_back(dtmp);
    }

    map<double,ll> count_mapX;
    map<double,ll> count_mapY;
    rep(ni,N){
        count_mapX[X[ni]]++;
        count_mapY[Y[ni]]++;
    }

    string ans  ="No";
    for(auto x : count_mapX) {
        double key = x.first;
        ll value = x.second;
        if(value>=3) ans = "Yes";
    }
    for(auto x : count_mapY) {
        double key = x.first;
        ll value = x.second;
        if(value>=3) ans = "Yes";
    }

    if(ans == "No"){
        for( ll n1 = 0 ; n1 <N ; n1++ ){
            for( ll n2 = n1+1 ; n2 <N ; n2++ ){
                if(Y[n1]!=Y[n2]&&X[n1]!=X[n2]){
                    for( ll n3 = n2+1 ; n3 <N ; n3++ ){
                        if( (X[n1]-X[n3])*(Y[n1]-Y[n2]) == (X[n1]-X[n2])*(Y[n1]-Y[n3]) ){
                            ans = "Yes";
                        }
                        
                    }

                }
            }
        }


    }
    cout << ans << endl;
}
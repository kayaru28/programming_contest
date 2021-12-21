


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

ll A;
ll B;
ll C;
ll N;
ll M;
ll K;

ll ltmp;
string stmp;
double dtmp;

vll Ns;

ll getval(ll ni){
    string Sn;
    Sn = to_string(ni);

    vll Nup,Ndown;

    rep(si,Sn.size()){
        Nup.push_back(ni%10);
        ni = ni / 10;
    }

    Ndown = Nup;
    sort(Nup.rbegin(),Nup.rend());
    sort(Ndown.begin(),Ndown.end());

    ll tmpans = 0;
    rep(ni,Nup.size()){
        tmpans = tmpans*10 + (Nup[ni]-Ndown[ni]);
    }
    return tmpans;

}


int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    cin >> K;

    rep(ki,K){
        N = getval(N);
    }    
    cout << N << endl;

}
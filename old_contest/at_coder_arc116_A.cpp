


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
vll Ns;
ll M;
ll K;
ll T;
ll ltmp;
string stmp;
double dtmp;


vll yakusu;
void getYakusu(ll N){
    for( ll ni = 1 ; ni*ni <=N ; ni++ ){
        if(N%ni==0){
            yakusu.push_back(ni);
            if(N/ni!=ni) yakusu.push_back(N/ni);
        }
    }
    sort(yakusu.begin(),yakusu.end());
}

double double_hosei = 1000000; //求められる精度分補正をかけておく
int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    Ns.resize(T);
    rep(ti,T) cin >> Ns[ti];
    rep(ti,T){
        ll tar = Ns[ti];
        if(tar%2==1) cout << "Odd" << endl;
        else if(tar==2) cout << "Same" << endl;
        else if(tar%4==0) cout << "Even" << endl;
        else cout << "Same" << endl;
    }

}
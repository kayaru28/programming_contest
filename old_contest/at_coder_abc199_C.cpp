


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

vll A;
vll B;
ll C;
ll N;
ll M;
ll K;
vll T;
ll Q;
ll Y;
ll Z;
string S;

ll ltmp;
string stmp;
double dtmp;

ll llmin(ll a,ll b){
    if(a>=b) return b;
    return a;
}
ll llmax(ll a,ll b){
    if(a<=b) return b;
    return a;
}

double double_hosei = 1000000; //求められる精度分補正をかけておく
int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    cin >> S;
    cin >> Q;
    A.resize(Q);
    B.resize(Q);
    T.resize(Q);
    rep(qi,Q){
        cin >> T[qi];
        cin >> A[qi];
        cin >> B[qi];
    }


    string Sv[2];
    Sv[0] =  S.substr(0,N);
    Sv[1] =  S.substr(N,N);
    

    rep(qi,Q){
        ll judgeT = T[qi];
        if(judgeT==1){
            ll ind1 = A[qi]-1;
            ll ind2 = B[qi]-1;
    
            ll ind11 = ind1/N;
            ll ind12 = ind1 - ind11 * N;
            ll ind21 = ind2/N;
            ll ind22 = ind2 - ind21 * N;
            char ctmp = S[ind11][ind12];
            S[ind11][ind12] = S[ind21][ind22];
            S[ind21][ind22] = ctmp;
        }else{
            stmp = S.substr(N,N);
            stmp = stmp + S.substr(0,N);
            S = stmp;
        }
    }
    cout << S << endl;
    

}
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

long long koyaku_max(long long a,long long b){
    long long r;
    r = a % b;
    while(r!=0){
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

vll A;
ll B;
ll C;
ll N;
ll M;
ll K;

ll ltmp;
string stmp;
double dtmp;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    rep(ni,N){
        cin >> ltmp;
        A.push_back(ltmp);
    }

    sort(A.begin(),A.end());
    A.erase(std::unique(A.begin(), A.end()), A.end());

    ll topV = A[N-1];
    while(A.size()!=1){
        ll maxi = A.size()-1;
        A[0] = koyaku_max(A[0],A[maxi]);
        for( ll ni = 1 ; ni <A.size() ; ni++ ){
            A[ni] = A[ni] % A[0] + A[0];
        }

        sort(A.begin(),A.end());
        A.erase(std::unique(A.begin(), A.end()), A.end());

    }

    cout << A[0] << endl;

    

    

}
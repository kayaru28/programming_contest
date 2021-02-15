


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

ll ans = 0;

ll llmin(ll a,ll b){
    if(a>=b) return b;
    return a;
}
ll llmax(ll a,ll b){
    if(a<=b) return b;
    return a;
}
void getPlusRoot(ll tB, ll tC){
    if( tC/2 < tB  ){
        ll cnt2 = tC / 2;
        ll tmpans = cnt2;
        if(tC % 2 == 1) tmpans += cnt2;
        else tmpans+=(cnt2-1);
        ans += tmpans;
    }else{
        ll cnt2 = tB;
        ll tmpans = cnt2;
        tmpans += (cnt2-1); // except 0
        ans += tmpans;
    }
    

}
void getMinusRoot(ll tB, ll tC){
    ll cnt2 = tC / 2;

    ll tmpans = cnt2;
    if(tC % 2 == 1) tmpans += cnt2;
    else tmpans += (cnt2-1);
    ans += tmpans;
}


int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> B;
    cin >> C;

    ll Bp,Bm,Cp,Cm;
    
    if(B==0){
        ans++;
        getMinusRoot(B,C);
    }else{
        Bp = B;
        Cp = C;
        Bm = B * -1;
        Cm = C - 1;
        if(B<0){
            Bm = B;
            Cm = C;
            Bp = B * -1;
            Cp = C - 1;
        }
        if(Cp>=0) ans++; 
        if(Cm>=0) ans++; 
        
        if(Cp>1) getPlusRoot(Bp,Cp);
        if(Cm>1) getMinusRoot(Bm,Cm);

    }


    cout << ans << endl;    

}
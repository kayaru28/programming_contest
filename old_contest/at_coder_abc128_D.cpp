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

ll A;
ll B;
ll C;
ll N;
ll M;
ll K;
vll V;

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
int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    cin >> K;

    rep(ni,N){
        cin >> ltmp;
        V.push_back(ltmp);
    }

    ll li_max = llmin(K,N);
    ll ans = 0;
    for( ll li = 0 ; li <=K ; li ++ ){
        ll left_k = li_max - li;
        for( ll ri = 0 ; ri <= left_k ; ri++ ){
            
            vll Vp;
            vll Vm;

            rep(l,li){
                ll index = l;
                ll val = V[index];
                if(val>=0) Vp.push_back(val);
                else Vm.push_back(val);
            }
            rep(r,ri){
                ll index = (N-1) - r;
                ll val = V[index];
                if(val>=0) Vp.push_back(val);
                else Vm.push_back(val);
            }

            sort(Vm.begin(),Vm.end());
            ll tmpans=0;
            ll count_m = K - li - ri;
            rep(pi,Vp.size()) tmpans += Vp[pi];
            rep(mi,Vm.size()){
                if(count_m>0){
                    count_m--;
                }else{
                    tmpans+=Vm[mi];
                }
            }
            //cout << li << " : " << ri << " = " << tmpans << endl;
            ans = llmax(ans,tmpans);
        }
    }
    cout << ans << endl;



    

}
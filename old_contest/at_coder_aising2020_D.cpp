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

ll N;
ll X;
ll bit2[base10_6+10]={};

ll mod_p[base10_6+10]={};
ll mod_m[base10_6+10]={};
ll popcount[base10_6+10]={};

ll f1[base10_6+10]={};

ll getIntSubstr(string s,ll start_index,ll length){
    return atoi(s.substr(start_index,length).c_str());
}

ll ltmp;
string stmp;
double dtmp;

ll getPower(ll value,ll shisu,ll mod){
    ll ans = 1;
    ll cnt = shisu;
    while(cnt>0){
        if(cnt%2==1){
            ans = ans * value % mod;
        }
        value = value * value % mod;
        cnt = cnt/2;
    }
    return ans;
}

ll getMod(ll value,ll mod){
    if(value == 0) return 0;
    if(mod==0) return -1;
    value %= mod;
    if(value<0) value += mod;
    return value;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    string S;
    cin >> S;

    ll base_pop = 0;
    rep(ni,N){
        bit2[ni] = getIntSubstr(S,ni,1);
        //bit2[ni] = 1;
        base_pop+=bit2[ni];
    }

    ll basev= 1;

    basev=1;
    for( ll ni = 1 ; ni <=base10_6 ; ni=ni*2 ){
        popcount[ni]=1;
    }
    for( ll ni = 1 ; ni <=base10_6 ; ni++ ){
        if(popcount[ni]==1) basev = ni;
        else popcount[ni]= 1 + popcount[ ni % basev  ]; 
    }


    ll base_pop_p;
    ll base_pop_m;
    base_pop_p = base_pop+1;
    base_pop_m = base_pop-1;
    if(base_pop_m==0) base_pop_m=1;

    basev = 1;
    ltmp = 1;
    for( ll keta = 1 ; keta <=base10_6 ; keta++ ){
        mod_p[keta] = basev;
        basev = basev * 2;
        basev = getMod(basev,base_pop_p); 
    }
    basev = 1;
    for( ll keta = 1 ; keta <= base10_6 ; keta++ ){
        mod_m[keta] = basev;
        basev = basev * 2;
        basev = getMod(basev,base_pop_m); 
    }

    ll base_f1_p = 0;
    ll base_f1_m = 0;
    for( ll keta = 1 ; keta <=N ; keta++ ){
        ll ind = N -keta;
        base_f1_p += mod_p[keta] * bit2[ind];
        base_f1_m += mod_m[keta] * bit2[ind];
        base_f1_p = getMod(base_f1_p,base_pop_p );
        base_f1_m = getMod(base_f1_m,base_pop_m );
    }


    base_pop_p = base_pop+1;
    base_pop_m = base_pop-1;

    for( ll ind = 0 ; ind <N ; ind++ ){
        ll keta = N - ind;
        ll value;
        ll cnt = 1;
        if(bit2[ind]==1){
            if(base_pop_m==0){
                cout << 0 << endl;
                continue;
            }else{
                value = base_f1_m - mod_m[keta];
                value = getMod(value,base_pop_m);
            }
        }else{
            value = base_f1_p + mod_p[keta];
            value = getMod(value,base_pop_p);
        }

        while(value>0){
            cnt++;
            value = value % popcount[value];
        }
        cout << cnt << endl;
    }
   

}
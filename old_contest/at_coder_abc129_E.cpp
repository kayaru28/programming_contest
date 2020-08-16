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

ll ltmp;
string stmp;
double dtmp;

/*
max 448,000,000
map<string,ll> count_map;
count_map['0']=0;
for(auto x : count_map) {
    string key = x.first;
    ll value = x.second;
}
*/

ll getMod(ll value,ll mod){
    if(value == 0) return 0;
    if(mod==0) return -1;
    value %= mod;
    if(value<0) value += mod;
    return value;
}
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

vll total111;
vll total100;
vll hosei;

ll getAns(string maxL){
    if(maxL=="0"){
        return 1;
    }
    ll leng = maxL.size();
    ll totaltmp= 1;
    total111.push_back(totaltmp);
    total100.push_back(1);
    hosei.push_back(1);
    ll keta = 0;

    while(keta<leng){
        totaltmp = totaltmp * 2 + totaltmp;
        totaltmp = getMod(totaltmp,MOD);
        total111.push_back(totaltmp);
        total100.push_back( 2 + total111[keta] );

        //cout << keta << " : "<< total100[keta] << endl;
        keta++;
    }

    keta = leng;
    ll ans = 2 + total111[keta-1];
    ll base = 2;
    for( ll li = 1 ; li <leng ; li++ ){
        string key = maxL.substr(li,1);
        if(key=="1"){
            keta = leng - li;
            ll dans = total100[keta] - 1;
            dans = dans*base;
            dans = getMod(dans,MOD);
            //cout << "dans " << dans << endl;
            ans  += dans;
            ans = getMod(ans,MOD);

            base *= 2;
            base = getMod(base,MOD);

        }
    }    
    return ans;

}


int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string maxL;
    cin >> maxL;

    ll ans = getAns(maxL);

    cout << ans << endl;




}
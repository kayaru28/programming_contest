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
vll P;
vll C;
ll N;
ll K;
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

ll roopsum[5100]={};
ll roopcnt[5100]={};
ll roopcycle[5100]={}
ll roopS[5100]={}

map<ll,ll> belong_map;

/*
max 448,000,000
map<string,ll> count_map;
count_map['0']=0;
for(auto x : count_map) {
    string key = x.first;
    ll value = x.second;
}
*/

vll blist[5010];
ll fulbal[5010];
ll befP[5010];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    cin >> K;

    ll Csum=0;

    rep(ni,N){
        cin >> ltmp;
        ltmp--;
        P.push_back(ltmp);
    }
    rep(ni,N){
        cin >> ltmp;
        Csum+=ltmp;
        C.push_back(ltmp);
    }

    ll bi = 0;
    for( ll si = 0 ; si <=N-1 ; si++ ){
        ll index = P[si];
        befP[index] = si;
        if(belong_map.count(index)==0){
            while(belong_map.count(index)==0){
                blist.push_back(index);
                belong_map[index]=bi;
                befP[P[index]] = index;
                index = P[index];
            }
            bi++;
        }
    }

    for( ll li = 0 ; li <blist.size() ; li++ ){
        ll listmax = 0




    }





    ll ans=C[0];
    for( ll si = 0 ; si <=N-1 ; si++ ){
        ll index = P[si];
        ll bi = belong_map[index];
        ll roopnum = K / roopcnt[bi];
        roopnum = llmax(0,roopnum-1);
        if(roopsum[bi]<0) roopnum=0;

        ll tmp = roopnum * roopsum[bi];
        //cout << roopnum << " " << roopsum[bi] << endl;
        ll tmpK = K - roopcnt[bi] * roopnum;

        ll ki = 1;
        index = P[si];
        while( ki <=tmpK){
            tmp += C[index];
            ans = llmax(tmp,ans);
            index = P[index];
            ki++;
        }
    }
    cout << ans << endl;

}
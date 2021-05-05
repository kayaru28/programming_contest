


#include  <iostream>
#include  <stdio.h>
#include <algorithm>
#include <map>
#include <math.h>
#include <queue>
#include <vector>
#include <stack>
#include <set>
#include <bitset>

using namespace std;
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




// #include <iomanip>
//  cout << fixed << setprecision(15) << y << endl;

// for(char c : S)

//min({a1, a2, ..., an})
//max({a1, a2, ..., an})
//swap(a, b)
//S.substr(si)
// sort <--> reverse
//count(v.begin(), v.end(), x) 

//xを2進数にした時の1の数
//__builtin_popcount(x) 
//__builtin_popcountll(x) 

ll A;
ll B;
ll C;
ll D;
ll N;
ll M;
ll K;
ll T;
ll H;
ll W;
ll X;
ll Y;
ll Z;

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

ll getllSubstr(string s,ll start_index,ll length){
    return atoi(s.substr(start_index,length).c_str());
}
double double_hosei = 1000000; //求められる精度分補正をかけておく
int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    cin >> N;

    string S;
    cin >> S;

    vll pos[10];
    vll vals;
    rep(si,S.size()){
        ltmp = getllSubstr(S,si,1);
        vals.push_back(ltmp);
        pos[ltmp].push_back(si);
    }

    ll pos_first[10];
    ll pos_last[10];

    rep(ni,10){
        if(pos[ni].size()>0){
            pos_first[ni]=pos[ni][0];
            pos_last[ni]=pos[ni][pos[ni].size()-1];
        }else{
            pos_first[ni]=base10_7;
            pos_last[ni]=0;
        }
    }


    ll cnt=0;
    map<ll,ll> mapans;
    for( ll v1 = 0 ; v1 <=9 ; v1++ ){
        for( ll v2 = 0 ; v2 <=9 ; v2++ ){
            ll ind_str = pos_first[v1];
            ll ind_fin = pos_last[v2];

            ltmp = 0;
            for( ll ind = ind_str+1 ; ind <ind_fin ; ind++ ){
                //cout << ind << " " << ind_str << " " << ind_fin << endl;
                ll vtmp = vals[ind];
                ltmp = v1 * 100 + vtmp * 10 + v2;
                if(mapans[ltmp]==0) cnt++;
                mapans[ltmp]++;
            }
        }
    }
    //for(auto x : mapans){
    //    cout << x.first << endl;
    //}
    cout << cnt << endl;

    



    

}
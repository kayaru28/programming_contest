


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
vll Hs;
vll Ss;
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
//探索したいkeyより大きい
//upper_bound(x_vector.begin(), x_vector.end(), key) - x_vector.begin();
//探索したいkey以上
//lower_bound(x_vector.begin(), x_vector.end(),key) - x_vector.begin();
double double_hosei = 1000000; //求められる精度分補正をかけておく



ll binarySearchJudge(ll target_height){
    vll until_time;
    rep(ni,N){
        if(target_height < Hs[ni]) return 1;
        ltmp = (target_height - Hs[ni]) / Ss[ni];
        until_time.push_back(ltmp);
    }
    sort(until_time.begin(),until_time.end());
    ll result = 0;
    for( ll timei = N-1 ; timei >=0 ; timei-- ){
        ll ui = timei;
        if(timei > until_time[ui]){
            result=1;
            break;
        }
    }
    //for(ll  ui : until_time) cout << ui << " ";
    //cout << target_height << " " << result << endl;

    return result;
}

ll binarySearchExecute(){
    ll left     = 0;
    ll right    = llINF;
    ll mid;

    while(left+1<right){
        mid = (left+right)/2;
        
        ll result = binarySearchJudge(mid);
        if(result==1){
            left = mid;
        }else{
            right = mid;
        }

    }
    return right;
}


int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    Hs.resize(N);
    Ss.resize(N);
    rep(ni,N) cin >> Hs[ni] >> Ss[ni];

    cout << binarySearchExecute() << endl;



    

}
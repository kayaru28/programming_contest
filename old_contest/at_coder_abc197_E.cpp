
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
vll C;
ll N;
vll X;
ll K;
 
ll ltmp;
string stmp;
double dtmp;
 
#include <set>
multiset<ll> ms[200010];
/*
multiset<int> ms;
ms.insert(7);
ms.insert(5);
ms.insert(2);
ms.insert(7);
ms.count(5);
if (ms.find(5) == ms.end()){}else{}
ms.erase(5);
*/
ll getMsMax(multiset<ll> msi){
    auto itr = msi.end();
    --itr;
    return *itr; 
}
ll getMsMin(multiset<ll> msi){
    auto itr = msi.begin();
    return *itr; 
}
ll llmin(ll a,ll b){
    if(a>=b) return b;
    return a;
}
ll llmax(ll a,ll b){
    if(a<=b) return b;
    return a;
}
 
vll Cs;
ll ans = llINF;
 
void getAns(ll starti, ll cind, ll tmpans){
    if(tmpans < ans){

        if(cind==Cs.size()){
            tmpans = tmpans + abs(starti);
            ans = llmin(ans,tmpans);
        //}else if(ms[ci].size()>0){
        } else{
            ll ci = Cs[cind];
            ll vmin = getMsMin(ms[ci]);
            ll vmax = getMsMax(ms[ci]);
            if(vmin == vmax){
                ltmp = abs(starti - vmin)+ tmpans; 
                getAns(vmin, cind+1, ltmp);
            }else if(starti < vmin){
                ltmp = (vmax - starti) + tmpans; 
                getAns(vmax, cind+1, ltmp);
    
            }else if(starti > vmax){
                ltmp = (starti - vmin) + tmpans; 
                getAns(vmin, cind+1, ltmp);
            }else if(vmin <= starti && starti <= vmax){
                
                ltmp = (starti - vmin) + (vmax - vmin) + tmpans; 
                getAns(vmax, cind+1, ltmp);
    
                ltmp = (vmax - starti) + (vmax - vmin) + tmpans; 
                getAns(vmin, cind+1, ltmp);
    
            }
        }
        //else{
        //    getAns(starti,ci+1,tmpans);
        //}
    }
}

ll dp[200010][2];
int main(){
 
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    cin >> N;
    X.resize(N);
    C.resize(N);
    
    map<ll,ll> mapC;
 
    rep(ni,N){
        cin >> X[ni];
        cin >> C[ni];
        ms[C[ni]].insert(X[ni]);
        mapC[C[ni]]++;
    }
 
    for(auto x : mapC) {
        ll key = x.first;
        ll value = x.second;
        Cs.push_back(key);
    }
    sort(Cs.begin(),Cs.end());
 
    ll s0 = 0;
    ll s1 = 0;
    ll dp0 = 0;
    ll dp1 = 0;

    for( ll cind = 0 ; cind <Cs.size() ; cind++ ){
        ll ci = Cs[cind];
        ll vmin = getMsMin(ms[ci]);
        ll vmax = getMsMax(ms[ci]);

        dp[cind][0] = llmin(abs(vmax - s0) + (vmax-vmin) + dp0,abs(vmax - s1) + (vmax-vmin) + dp1);
        dp[cind][1] = llmin(abs(vmin - s0) + (vmax-vmin) + dp0,abs(vmin - s1) + (vmax-vmin) + dp1 );
        s0 = vmin;
        s1 = vmax;
        dp0 = dp[cind][0];
        dp1 = dp[cind][1];
    }
    ll cindMax = Cs.size()-1;
    ans = llmin(dp[cindMax][0]+abs(s0),dp[cindMax][1]+abs(s1));

    cout << ans << endl;
 
 
 
 
    
 
}



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
ll Q;
vll a,t,x;

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
ll getIndexUpperBoundLong(vll x_vector,ll key){
    decltype(x_vector)::iterator it = upper_bound(x_vector.begin(), x_vector.end(), key);
    ll index = distance(x_vector.begin(), it);
    return index;
}
//探索したいkeyより大きい
ll getIndexUpperBoundString(vector<string> x_vector,string key){
    decltype(x_vector)::iterator it = upper_bound(x_vector.begin(), x_vector.end(), key);
    ll index = distance(x_vector.begin(), it);
    return index;
}
//探索したいkey以上
ll getIndexLowerBoundLong(vll x_vector,ll key){
    decltype(x_vector)::iterator it = lower_bound(x_vector.begin(), x_vector.end(), key);
    ll index = distance(x_vector.begin(), it);
    return index;
}
//探索したいkey以上
ll getIndexLowerBoundString(vector<string> x_vector,string key){
    decltype(x_vector)::iterator it = lower_bound(x_vector.begin(), x_vector.end(), key);
    ll index = distance(x_vector.begin(), it);
    return index;
}
ll gevval(ll xi){
    rep(ni,N){
        ltmp = t[ni];
        if(ltmp == 1){
            xi += a[ni];
        }else if(ltmp == 2){
            ll amax = a[ni];
            xi = llmax(xi,amax);
        }else{
            ll amin = a[ni];
            xi = llmin(xi,amin);
        }
    }
    return xi;
}
int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    a.resize(N);
    t.resize(N);
    rep(ni,N){
        cin >> a[ni];
        cin >> t[ni];
    }
    cin >> Q;
    x.resize(Q);
    rep(qi,Q) cin >> x[qi];

    vll li_borders;
    vll ri_borders;
    ll li = -1 * llINF;
    ll ri = llINF;
    ll asums = 0;
    map<ll,ll> point_li,point_ri;
    rep(ni,N){
        ltmp = t[ni];
        if(ltmp == 1){
            asums += a[ni];
        }else if(ltmp == 2){
            ll amax = a[ni];
            ll li_border = amax - asums;
            if(li < li_border){
                li_borders.push_back(li_border);
                point_li[li_border] = ni;
                li = li_border;
            }
        }else{
            ll amin = a[ni];
            ll ri_border = amin - asums;
            if(ri > ri_border){
                ri_borders.push_back(ri_border);
                point_ri[ri_border] = ni;
                ri = ri_border;
            }

        }
    }

    map<ll,ll> li_val;    
    map<ll,ll> ri_val;    
    
    rep(li,li_borders.size()){
        ll val = li_borders[li];
        li_val[val] = gevval(val);
    }
    rep(ri,ri_borders.size()){
        ll val = ri_borders[ri];
        ri_val[val] = gevval(val);
    }
    sort(ri_borders.begin(),ri_borders.end());

    rep(qi,Q){
        ll xi = x[qi];
        ll ans = 0;
        ll point = llINF;

        ans = xi + asums;

        if(xi <= li){
            ll ind = getIndexLowerBoundLong(li_borders,xi);
            ll val = li_borders[ind];
            point = point_li[val];

            ans = li_val[val];
        }
        
        if(xi >= ri){
            
            ll ind = getIndexUpperBoundLong(ri_borders,xi);
            ind = ind - 1;
            ll val = ri_borders[ind];
            if (point_ri[val]<point){
                ans = ri_val[val];
            }
        }

        cout << ans << endl;
    }
}
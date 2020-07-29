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
vll L;

ll ltmp;
string stmp;
double dtmp;

ll getIndexUpperBoundLong(vll x_vector,ll key){
    decltype(x_vector)::iterator it = upper_bound(x_vector.begin(), x_vector.end(), key);
    ll index = distance(x_vector.begin(), it);
    return index;
}
ll getIndexUpperBoundString(vector<string> x_vector,string key){
    decltype(x_vector)::iterator it = upper_bound(x_vector.begin(), x_vector.end(), key);
    ll index = distance(x_vector.begin(), it);
    return index;
}
ll getIndexLowerBoundLong(vll x_vector,ll key){
    decltype(x_vector)::iterator it = lower_bound(x_vector.begin(), x_vector.end(), key);
    ll index = distance(x_vector.begin(), it);
    return index;
}
ll getIndexLowerBoundString(vector<string> x_vector,string key){
    decltype(x_vector)::iterator it = lower_bound(x_vector.begin(), x_vector.end(), key);
    ll index = distance(x_vector.begin(), it);
    return index;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    rep(ni,N){
        cin >> ltmp;
        L.push_back(ltmp);
    }
    L.push_back(100000);

    ll max_index = N-1;
    ll cnt = 0;
    sort(L.begin(),L.end());
    for( ll t1 = 0 ; t1 <=max_index-2 ; t1++ ){
        for( ll t2 = t1+1 ; t2 <=max_index-1 ; t2++ ){
            ll sum2 = L[t1]+L[t2];
            ll index = getIndexLowerBoundLong(L,sum2);
            //cout << index << endl;
            cnt+=((index-1) - t2 );

        }
    }
    cout << cnt << endl;


}
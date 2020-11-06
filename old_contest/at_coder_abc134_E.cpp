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

//#include <stack>
//#include <queue>

// #include <iomanip>
//  cout << fixed << setprecision(15) << y << endl;

string ans_Yes = "Yes"; 
string ans_No = "No"; 
string ans_yes = "yes"; 
string ans_no = "no"; 

vll A;
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
count_map['0']=0;
for(auto x : count_map) {
    string key = x.first;
    ll value = x.second;
}
*/

map<ll,vll> count_map;
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
int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    rep(ni,N){
        cin >> ltmp;
        A.push_back(ltmp);
        count_map[ltmp].push_back(ni+1);
    }

    vll values;
    values.push_back(A[N-1]);
    for( ll ni = N-2 ; ni >=0 ; ni-- ){
        ll vmax = values[values.size()-1];
        if(A[ni]<vmax){
            ll index = getIndexUpperBoundLong(values,A[ni]);
            values[index] = A[ni];
        }else{
            values.push_back(A[ni]);
        }
    }

    cout << values.size() << endl;

    

}
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
count_map['0']=0;
for(auto x : count_map) {
    string key = x.first;
    ll value = x.second;
}
*/
ll getllSubstr(string s,ll start_index,ll length){
    return atoi(s.substr(start_index,length).c_str());
}
ll llmin(ll a,ll b){
    if(a>=b) return b;
    return a;
}
ll llmax(ll a,ll b){
    if(a<=b) return b;
    return a;
}
ll getans(ll n1,ll n2,ll n3){
    ll hint = n1 * 100 + n2 * 10 + n3;
    if(hint%2==0){
        hint = hint /2;
        hint = hint % 100;
        if(hint%4==0){
            //cout << "------------" << endl;
            //cout << hint << endl;
            //cout << n1 << endl;
            //cout << n2 << endl;
            //cout << n3 << endl;
            return 1;
        }
    }
    return 0;
}
int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string S;
    
    cin >> S;
    if(S.size()<3){
        if(S.size()==1){
            if(getllSubstr(S,0,1)%8==0) cout << "Yes" << endl;
            else cout << "No" << endl;
        }else{
            ll v1 = getllSubstr(S,0,1);
            ll v2 = getllSubstr(S,1,1);
            if( (v1*10+v2) %8==0  ) cout << "Yes" << endl;
            else if( (v2*10+v1) %8==0  ) cout << "Yes" << endl;
            else cout << "No" << endl;
        }

    }else{
        map<ll,ll> count_map;
        rep(si,S.size()){
            ltmp = getllSubstr(S,si,1);
            count_map[ltmp]++;
        }

        vll numbers;
        for(auto x : count_map) {
            ll key = x.first;
            ll value = x.second;
            ll cmax = llmin(3,value);
            rep(ci,cmax){
                numbers.push_back(key);
            }
        }

        ll nmax  = numbers.size();
        ll ans = 0;
        for( ll n1 = 0 ; n1 <nmax ; n1++ ){
            for( ll n2 = n1+1 ; n2 <nmax ; n2++ ){
                for( ll n3 = n2+1 ; n3 <nmax ; n3++ ){
                    ll v1 = numbers[n1];
                    ll v2 = numbers[n2];
                    ll v3 = numbers[n3];

                    ans += getans(v1,v2,v3);
                    ans += getans(v1,v3,v2);
                    ans += getans(v2,v3,v1);
                    ans += getans(v2,v1,v3);
                    ans += getans(v3,v1,v2);
                    ans += getans(v3,v2,v1);

                }
            }
        }   
        if(ans>0) cout << "Yes" << endl; 
        else cout << "No" << endl;

    }
}
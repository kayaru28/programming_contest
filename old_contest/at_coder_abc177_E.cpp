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


vector<ll> prime_numbers;
void getPrimeNumbers(ll n_max){
    bool is_prime[n_max+1];
    for( ll ni = 0 ; ni <=n_max ; ni++ ){
        is_prime[ni]=true;
    }
   is_prime[0]=is_prime[1]=false;
    for( ll number = 2 ; number <=n_max ; number++ ){
        if(is_prime[number]){
            prime_numbers.push_back(number);
            for( ll ni = number*2 ; ni <=n_max ; ni+=number ){
                is_prime[ni]=false;
            }
        }
    }
}

ll llmin(ll a,ll b){
    if(a>=b) return b;
    return a;
}
ll llmax(ll a,ll b){
    if(a<=b) return b;
    return a;
}
/*
max 448,000,000
map<string,ll> count_map;
count_map['0']=0;
for(auto x : count_map) {
    string key = x.first;
    ll value = x.second;
}
*/
map<ll,ll> count_map;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    rep(ni,N){
        cin >> ltmp;
        A.push_back(ltmp);
        count_map[ltmp]++;
        
    }

    sort(A.begin(),A.end());
    getPrimeNumbers(A[N-1]+1);   
    


    ll cnt_max=0;
    //cout << prime_numbers.size() << endl;
    rep(pi,prime_numbers.size()){
        ll cnt = 0;
        ll p0 = prime_numbers[pi];
        for( ll pval = p0 ; pval <=A[N-1] ; pval+=p0 ){
            cnt += count_map[pval];
        }

        cnt_max = llmax(cnt_max,cnt);
        if(cnt_max==N) break;
        else if(cnt_max>1 && p0>A[0]) break;
    }

    if(cnt_max==N) cout << "not coprime" << endl;
    else if(cnt_max>1) cout << "setwise coprime" << endl;
    else cout << "pairwise coprime" << endl;


}
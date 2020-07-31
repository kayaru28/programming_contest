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

ll llmin(ll a,ll b){
    if(a>=b) return b;
    return a;
}
ll llmax(ll a,ll b){
    if(a<=b) return b;
    return a;
}

ll ltmp;
string stmp;
double dtmp;


long long koyaku_max(long long a,long long b){
    long long r;
    r = a % b;
    while(r!=0){
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

vll enum_divisors(long long N) {
    vll res;
    for (long long i = 1; i * i <= N; ++i) {
        if (N % i == 0) {
            res.push_back(i);
            // 重複しないならば i の相方である N/i も push
            if (N/i != i) res.push_back(N/i);
        }
    }
    // 小さい順に並び替える
    sort(res.begin(), res.end());
    return res;
}

/*
max 448,000,000
count_map['0']=0;
for(auto x : count_map) {
    string key = x.first;
    ll value = x.second;
}
*/

vector<ll> prime_numbers;
void getPrimeNumbers(ll n_max){
    bool is_prime[n_max+1];
    for( int ni = 0 ; ni <=n_max ; ni++ ){
        is_prime[ni]=true;
    }
   is_prime[0]=is_prime[1]=false;
    for( int number = 2 ; number <=n_max ; number++ ){
        if(is_prime[number]){
            prime_numbers.push_back(number);
            for( int ni = number*2 ; ni <=n_max ; ni+=number ){
                is_prime[ni]=false;
            }
        }
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> A;
    cin >> B;
    map<ll,ll> count_map;

    //A = 1000000000000;
    //B = 1000000000000;

    C = koyaku_max(A,B);

    vll yakusu = enum_divisors(C);

    rep(yi,yakusu.size()){
        //cout << yakusu[yi] << endl;
        count_map[yakusu[yi]]=1;
    }

    ll cnt = 1;
    for( ll yi = 1 ; yi <yakusu.size() ; yi++ ){
        ll val = yakusu[yi];
        if(count_map[val]==1){
            cnt++;
            for( ll yii = yi+1 ; yii <yakusu.size() ; yii++ ){
                ll val2 = yakusu[yii];
                if(val2 % val == 0) count_map[val2]=0;
            }
        }
    }

    cout << cnt << endl;

    

}
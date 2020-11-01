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
ll N;

ll ltmp;
string stmp;
double dtmp;
int flag[base10_6]={};
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
int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    getPrimeNumbers(base10_6);

    cin >> N;
    A.push_back(0);
    rep(ni,N){
        cin >> ltmp;
        A.push_back(ltmp);
    }

    for( ll ni = N ; ni >=1 ; ni-- ){
        ll cnt = A[ni];
        //ll index = 0;
        //while(ni*prime_numbers[index]<=N){
        ll index = 2;
        while(ni*index<=N){
        
            ll val = ni*index;
            cnt += flag[val];
            index++;
        }

        flag[ni] = (cnt%2);
    }

    ll csum=0;
    for( ll ni = 1 ; ni <=N ; ni++ ){
        csum += flag[ni];
    }
    cout << csum << endl;
    for( ll ni = 1 ; ni <=N ; ni++ ){
        if(flag[ni]==1) cout << ni << " ";
    }
}
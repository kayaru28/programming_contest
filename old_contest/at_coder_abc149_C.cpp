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

    cin >> A;
    getPrimeNumbers(base10_5+10000);
    ll index = getIndexLowerBoundLong(prime_numbers,A);
    //cout << index << endl;
    cout << prime_numbers[index] << endl;

}
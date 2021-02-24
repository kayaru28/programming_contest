


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
ll K;

ll ltmp;
string stmp;
double dtmp;


int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    string S;
    
    cin >> S;

    ll cnt=0;
    char tar='1';

    ll si = S.size()-1-1-1;
    map<char,ll> mapC;
    mapC[S[S.size()-1]]++;
    mapC[S[S.size()-1-1]]++;

    ll maxindex = S.size()-1;
    while(si>=0){
        tar = S[si];
        if(S[si]==S[si+1]){
            cnt+= maxindex - si - mapC[tar];

            mapC.clear();
            mapC[tar]= maxindex - si + 1;
        }else{
            mapC[tar]++;
        }
        si--;
    }


    cout << cnt << endl;


    

}
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

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll gu = 0;
    ll ch = 1;
    ll pa = 2;
    ll blank = 3;
    ll point[4];
    point[blank]=0;
    string S;

    cin >> N;
    cin >> K;
    cin >> point[gu];
    cin >> point[ch];
    cin >> point[pa];
    cin >> S;
    /*
    N = base10_5;
    K = N-1;
    point[gu]=1;
    point[ch]=2;
    point[pa]=3;
    S = "";
    rep(ni,N){
        if(ni%3==0) S+="r";
        else if(ni%3==1) S+="s";
        else S+="p";
    }*/

    vll ans;
    ll ans_index = 0;
    rep(ki,K){
        ans.push_back(blank);
        ans_index++;
    }
    

    rep(si,S.size()){
        stmp = S.substr(si,1);
        if(stmp=="r"){
            ltmp = pa;
        }else if(stmp=="s"){
            ltmp = gu;
        }else{
            ltmp = ch;
        }

        ll bef_index = ans_index - K;
        if(ans[bef_index]==ltmp){
            ans.push_back(blank);
        }else{
            ans.push_back(ltmp);
        }
        ans_index++;
    }

    ll sum = 0;
    rep(ai,ans.size()){
        ll index = ans[ai];
        sum+=point[index];
    }
    cout << sum << endl;

    

}
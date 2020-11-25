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

vll A;
vll B;
vll Ai;
vll Bi;
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

    cin >> N;
    cin >> M;
    cin >> K;
 
    ll sumA=0;
    A.push_back(0);

    ll sumtmp=0;
    rep(ni,N){
        cin >> ltmp;
        sumtmp+=ltmp;
        if(sumtmp<=K){
            sumA+=ltmp;
            A.push_back(sumA);
        }
    }
    
    ll sumB=0;
    B.push_back(0);
    rep(ni,M){
        cin >> ltmp;
        //if(sumB+ltmp<=K){
        sumB+=ltmp;
        B.push_back(sumB);
        //}
    }

    ll bi = B.size()-1;
    ll cnt = 0;
    rep(ai,A.size()){
        if(A[ai]>K) break;
        while(A[ai]+B[bi]>K){
            bi--;
        }
        if(cnt<ai+bi) cnt = ai + bi;

    }

    cout << cnt << endl;




}
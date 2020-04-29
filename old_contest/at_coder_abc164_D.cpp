#include  <iostream>
#include  <stdio.h>
#include <algorithm>
using namespace std;
#include <vector>
#define rep(i,n) for (int i = 0; i < (n) ; i++)
#define INF 1e9
#define llINF 1e18
#define MOD 1000000007
#define pb push_back
#define ll long long
#define ull unsigned long long
#define vint vector<int>
#define vll vector<ll>

//#include <stack>
//#include <queue>

/*
#include <math.h>
int standerd = int(pow(10.0,9.0)) + 7;
*/
string ans_Yes = "Yes"; 
string ans_No = "No"; 
string ans_yes = "yes"; 
string ans_no = "no"; 
 
ll N;
int getIntSubstr(string s,int start_index,int length){
    return atoi(s.substr(start_index,length).c_str());
}
ll A[3000]={};
ll cnt=0;
int main(){

    string S;
    
    cin >> S;
    N = S.size();
    A[0]++;
    ll ans;
    ll val;
    ll target=0;
    ll base = 1;
    for( int ni = N-1 ; ni>=0 ; ni-- ){
        val = getIntSubstr(S,ni,1);
        target = (target + val * base)%2019;
        cnt+=A[target];
        A[target]++;
        base = (base * 10 ) % 2019;
    }
    cout << cnt << endl;
    

    

}
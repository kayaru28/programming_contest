#include  <iostream>
#include  <stdio.h>
#include <algorithm>
#include <map>
#include <math.h>

using namespace std;
#include <vector>
#define rep(i,n) for (int i = 0; i < (n) ; i++)
#define INF 1e9
#define llINF 1e18
#define base10_4 10000      //1e4
#define base10_5 100000     //1e5
#define base10_6 1000000    //1e6
#define base10_7 10000000   //1e7
#define base10_8 100000000  //1e8
#define base10_9 1000000000 //1e9

#define MOD      1000000007
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
ll ans=0;

int main(){

    
    cin >> N;
    cin >> K;

    if(K==N+1){
        cout << 1 << endl;
    }else{
        ll left     = 0;
        ll right    = 0;

        for( int cnt = 1 ; cnt <=K-1 ; cnt++ ){
            ll d = cnt-1;
            left += d;
            right += (N-d);
        }    

        for( int cnt = K ; cnt <=N+1 ; cnt++ ){
            ll d = cnt-1;
            left += d;
            right += (N-d);
            ans += (right - left) + 1;
            ans = ans % MOD;
            //cout << left << " : " << right << " = " << ans << endl;

        }    

        cout << ans << endl;

    }

}
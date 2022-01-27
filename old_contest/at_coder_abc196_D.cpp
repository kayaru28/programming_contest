


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
ll H,W;
ll N;
ll M;
ll K;

ll ltmp;
string stmp;
double dtmp;

ll ans = 0;

ll jEnd(ll kouho[20]){
    ll tatami[20][20]={};

    for( ll hi = 0 ; hi <H ; hi++ ){
        tatami[hi][W] = 1;
    }
    for( ll wi = 0 ; wi <W ; wi++ ){
        tatami[H][wi] = 1;
    }



    for( ll ki =0 ; ki <20 ; ki++ ){
        if(kouho[ki]==1){
            ll hi = ki / W;
            ll wi = ki % W;

            if(tatami[hi][wi]==1) return 0;
            if(tatami[hi+1][wi]==1) return 0;
            tatami[hi][wi]=1;
            tatami[hi+1][wi]=1;
        }else if(kouho[ki]==2){
            ll hi = ki / W;
            ll wi = ki % W;

            if(tatami[hi][wi]==1) return 0;
            if(tatami[hi][wi+1]==1) return 0;
            tatami[hi][wi]=1;
            tatami[hi][wi+1]=1;
        }
    }

    return 1;


}

void getAns(ll ind,ll left,ll lmax,ll kouho[]){
    if(left==0){
        //for( ll ki = 0 ; ki <20 ; ki++ ){
        //    cout << kouho[ki] << " ";
        //}
        //cout  << endl;
        
        ans += jEnd(kouho);
    
    }
    else if(ind==lmax){
        ll nothing;
    }else{
        kouho[ind]=1;
        getAns(ind+1,left-1,lmax,kouho);

        kouho[ind]=2;
        getAns(ind+1,left-1,lmax,kouho);

        kouho[ind]=0;
        getAns(ind+1,left,lmax,kouho);

    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> H;
    cin >> W;
    cin >> A;
    cin >> B;

    ll lmax = H*W;
    ll kouho[20]={};
    ll ind = 0;
    ll left = A;


    getAns(ind,left,lmax,kouho);
    cout << ans << endl;
    

    
    

}
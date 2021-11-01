


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

vll A;
ll B;
ll C;
ll N;
ll M;
ll K;

ll ltmp;
string stmp;
double dtmp;

ll getOR(ll si,ll ei){
    ll val = A[si];
    for( ll ind = si+1 ; ind <=ei ; ind++ ){
        val = val | A[ind];
    }
    return val;
}
ll ans = 0;

ll llmin(ll a,ll b){
    if(a>=b) return b;
    return a;
}
ll llmax(ll a,ll b){
    if(a<=b) return b;
    return a;
}
void getans(ll tari,ll cnt, string part){
    if(tari==N-1){
        if(cnt>0){
            vll vals;
            ll si,ei=0;
            si = 0;

            part = part + "1";
            //cout << "-0000000000000000" << endl;
            for( ll ni = 0 ; ni <N ; ni++ ){
                if(part[ni]=='1'){
                    //cout << ni << " ";
                    ei = ni;
                    ll val = getOR(si,ei);
                    vals.push_back(val);
                    si = ni + 1;
                }
            }
            //cout << endl;

            ll val = vals[0];
            //cout << vals[0] << " ";
            for( ll vi = 1 ; vi <vals.size() ; vi++ ){
                //cout << vals[vi]  << " ";
                val = val^vals[vi];
            }
            //cout  << endl;
            //cout << val << endl;
            ans = llmin(ans,val);


        }

    }else{
        getans(tari+1,cnt,part+"0");

        getans(tari+1,cnt+1,part+"1");
    }



}
int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    A.resize(N);
    rep(ni,N) cin >> A[ni];

    ans = getOR(0,N-1);

    ll cnt = 0;

    

    getans(0,cnt,"");
    cout << ans << endl;


    


}
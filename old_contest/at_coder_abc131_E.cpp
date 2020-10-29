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

    cin >> N;
    cin >> K;

    ll maxK = (N-1)*(N-2)/2;
    vll ans_to;
    vll ans_from;
    ll cnt = 0;
    if(K > maxK) cout << -1 << endl;
    else{

        for( ll ni = 2 ; ni <=N ; ni++ ){
            ans_from.push_back(1);
            ans_to.push_back(ni);
            cnt++;                        
        }

        ll leftK = maxK - K;

        cnt+=leftK;
        ll vfrom,vto;
        vfrom = 2;
        vto = 3;
        rep(li,leftK){
            ans_to.push_back(vto);
            ans_from.push_back(vfrom);

            vto++;
            if(vto>N){
                vfrom++;
                vto = vfrom + 1;
            }
        }

        cout << cnt << endl;
        rep(ci,cnt){
            cout << ans_from[ci] << " " << ans_to[ci] << endl;
        }



    }

}
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

map<string, ll> count_map[5010];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    string S;
    cin >> S;
    ll cnt = 0;

    for( ll ni = 1 ; ni <=N ; ni++ ){
        string tar = S.substr(ni-1,1);
        string ag;
        ag = "A";
        count_map[ni][ag] = count_map[ni-1][ag];
        ag = "T";
        count_map[ni][ag] = count_map[ni-1][ag];
        ag = "G";
        count_map[ni][ag] = count_map[ni-1][ag];
        ag = "C";
        count_map[ni][ag] = count_map[ni-1][ag];

        ag = tar;
        count_map[ni][ag]++;

    }


    for( ll leng = 2 ; leng <=S.size() ; leng=leng+2 ){
        for( ll si = 1 ; si <=(N-(leng-1)) ; si++ ){
            ll li = si + leng - 1;
            string ag;
            ag = "A";
            ll cntA = count_map[li][ag] - count_map[si-1][ag];
            ag = "G";
            ll cntG = count_map[li][ag] - count_map[si-1][ag];
            ag = "T";
            ll cntT = count_map[li][ag] - count_map[si-1][ag];
            ag = "C";
            ll cntC = count_map[li][ag] - count_map[si-1][ag];
            if(cntA==cntT && cntC==cntG) cnt++;
        }
    }
    cout << cnt << endl;

    

}
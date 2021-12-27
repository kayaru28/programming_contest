


#include  <iostream>
#include  <stdio.h>
#include <algorithm>
#include <map>
#include <math.h>
#include <iomanip>

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
map<ll,ll> mapTaka;
map<ll,ll> mapAoki;

ll getllSubstr(string s,ll start_index,ll length){
    return atoi(s.substr(start_index,length).c_str());
}

ll judge(ll ctaka,ll caoki){

    mapTaka[ctaka]++;
    mapAoki[caoki]++;
    ll scoreTaka=0;
    ll scoreAoki=0;
    for( ll card = 1 ; card <=9 ; card++ ){
        scoreTaka += ( card * pow(10, mapTaka[card]));
        scoreAoki += ( card * pow(10, mapAoki[card]));
    }
    mapTaka[ctaka]--;
    mapAoki[caoki]--;

    if(scoreTaka>scoreAoki) return 1;
    else return 0;
}
int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> K;

    map<ll,ll> leftcard;
    for( ll score = 1 ; score <=9 ; score++ ){
        leftcard[score]=K;
    }


    string S,T;
    cin >> S;
    cin >> T;

    ll taka = 0;
    ll aoki = 0;
    
    rep(ni,4){
        taka = getllSubstr(S,ni,1);
        aoki = getllSubstr(T,ni,1);
        mapTaka[taka]++;
        mapAoki[aoki]++;

        leftcard[taka]--;
        leftcard[aoki]--;
    }

    double total = 9 * K - 8;
    double ans = 0;
    for( ll ctaka = 1 ; ctaka <=9 ; ctaka++ ){
        for( ll caoki = 1 ; caoki <=9 ; caoki++ ){
            double pcard = 0;

            if( leftcard[ctaka] > 0 ){
                pcard = leftcard[ctaka] / total;
                leftcard[ctaka]--;

                if( leftcard[caoki] > 0 ){
                    pcard = pcard * leftcard[caoki] / (total-1);
                    //cout << pcard << endl;
                    ans += ( judge(ctaka,caoki) * pcard  );

                }
                leftcard[ctaka]++;
            
            }
        }
    }

    cout << fixed << setprecision(15) << ans << endl;

    

}
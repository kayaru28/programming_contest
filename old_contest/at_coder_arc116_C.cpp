


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

#define MOD 998244353
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
ll ans;


vll yakusu;
void getYakusu(ll N){
    yakusu.clear();
    for( ll ni = 1 ; ni*ni <=N ; ni++ ){
        if(N%ni==0){
            yakusu.push_back(ni);
            if(N/ni!=ni) yakusu.push_back(N/ni);
        }
    }
    sort(yakusu.begin(),yakusu.end());
}

ll getMod(ll value,ll mod=MOD){
    if(value == 0) return 0;
    if(mod==0) return -1;
    value %= mod;
    if(value<0) value += mod;
    return value;
}

ll add[200010];
ll sumN1[200010];

double double_hosei = 1000000; //求められる精度分補正をかけておく
int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    cin >> M;

    ans = 0;

    ans = 1;
    
    sumN1[1]=N-1;
    add[1]=1;
    for( ll ni = 2 ; ni <=M ; ni++ ){
        add[ni] = 1;
        sumN1[ni] = 0;
        getYakusu(ni);
        rep(yi,yakusu.size()-1){
            ll yakubal = yakusu[yi];
            add[ni] += sumN1[yakubal];
            sumN1[ni] -=  
            add[ni] = getMod(add[ni]);
        }

        ans += add[ni];
        ans = getMod(ans);

    }
    cout << ans << endl;

    

}
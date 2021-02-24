


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
ll C;
ll N;
ll M;
ll K;

ll ltmp;
string stmp;
double dtmp;

ll getPower(ll value,ll shisu,ll mod){
    ll ans = 1;
    ll cnt = shisu;
    while(cnt>0){
        if(cnt%2==1){
            ans = ans * value % mod;
        }
        value = value * value % mod;
        cnt = cnt/2;
    }
    return ans;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> A;
    cin >> B;
    cin >> C;

    vll tmpA;
    map<ll,ll> mapA;
    A = A % 10;
    ll baseA = A;
    while(mapA[A]==0){
        mapA[A]++;
        tmpA.push_back(A);
        A = A * baseA;
        A = A % 10;
    }
    ll roopA = tmpA.size();
    
    if(roopA==1) cout << tmpA[0] << endl;
    else{
        /*
        vll tmpB;
        map<ll,ll> mapB;
        B = B % roopA;
        ll baseB = B;
        while(mapB[B]==0){
            mapB[B]++;
            tmpB.push_back(B);
            B = B * baseB;
            B = B % roopA;
        }*/

        //ll roopB = tmpB.size();
        //ll indexB = C % roopB;
        //if(indexB == 0) indexB = roopB;
        //indexB--;
        
        //ll indexA = tmpB[indexB];
        ll indexA = getPower(B,C,roopA);
        if(indexA == 0) indexA = roopA;
        indexA--;

        cout << tmpA[indexA] << endl;

    }

    

}
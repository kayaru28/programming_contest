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

    string S;
    
    cin >> S;

    N = S.size();

    if(S.substr(N-1,1)=="1"){
        cout << -1 << endl;
    }else if(S.substr(N-2,1)=="0"){
        cout << -1 << endl;
    }else if(S.substr(0,1)=="0"){
        cout << -1 << endl;
    }else{


        bool flag = false;
        rep(si,(N-1)/2){
            string S1 = S.substr(si,1);
            string S2 = S.substr( (N-1)-si-1 ,1 );
            if(S1 != S2){
                flag = true;
                break;
            }
        }

        if(flag){
            cout << -1 << endl;
        }else{
            ll base_node = 1;
            ll next_node = 2;
            rep(si,S.size()-1){
                
                cout << base_node << " " << next_node << endl;
                stmp = S.substr(si,1);
                if(stmp=="1"){
                    base_node = next_node;
                }
                next_node++;

            }
        }


    }

    

}
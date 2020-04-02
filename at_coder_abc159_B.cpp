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
 

int main(){

    string S;
    cin >> S;

    int N;
    N = S.length();

    string S_rev="";

    rep(si,N){
        S_rev = S_rev + S.substr((N-1)-si,1);
    }
    //cout << S_rev << endl;
    if(S == S_rev){
        string S2 = S.substr(0,(N-1)/2);
        int N2 = S2.length();
        S_rev="";
        rep(si,N2){
            S_rev = S_rev + S2.substr((N2-1)-si,1);
        }
        if(S2 == S_rev){
            S_rev="";
            string S2 = S.substr((N+3)/2-1,N);
            int N2 = S2.length();
            rep(si,N2){
                S_rev = S_rev + S2.substr((N2-1)-si,1);
            }
            if(S2 == S_rev){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
        }else{
            cout << "No" << endl;
        }
    }else{
        cout << "No" << endl;
    }


}
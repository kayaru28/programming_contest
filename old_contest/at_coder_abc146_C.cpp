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
ll X;

ll ltmp;
string stmp;
double dtmp;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> A;
    cin >> B;
    cin >> X;
    
    ll left = 0;
    ll right = base10_9;
    right * base10_9;
    
    while(left<right){
        ll midval = (left+right)/2;
        string S = to_string(midval);
        ll midmoney = A * midval + B * S.size();
        //cout << left << " " << right << "=" << midval << endl;
        if(midmoney==X){
            left = midval;
            break;
        }else if(midmoney<X){
            left = midval + 1;
        }else{
            right = midval-1;
        }
    }

    string S = to_string(left);
    ll money = A * left + B * S.size();
    if(money > X && left>0){
        left--;
    }

    cout << left << endl;

    

}
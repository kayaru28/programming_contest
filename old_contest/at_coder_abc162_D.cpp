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

ll N;
string S;
ll ans;

int main(){


    
    cin >> N;
    cin >> S;

    ll cntR=0;
    ll cntG=0;
    ll cntB=0;
    vint value;
    string target;
    rep(ni,N){
        target = S.substr(ni,1);
        //cout << target << endl;
        if(target=="R"){
            cntR++;
            value.push_back(1);
        }else if(target=="G"){
            cntG++;
            value.push_back(10);

        }else if(target=="B"){
            cntB++;
            value.push_back(100);
        }
    }
    //rep(ni,value.size()) cout << value[ni] << endl;

    ans = cntR * cntG * cntB;
    //cout << cntR * cntG<< endl;
    //cout << ans << endl;
    for( int bef = 1 ; bef < N ; bef++ ){
        for( int start = 0 ; start <N ; start++ ){
            int next = start + bef;
            int last = start + bef + bef;
            if(last<N){
                if(value[start]+value[next]+value[last]==111){
                    ans--;
                }
            }
        }
    }
    if(ans<0) ans = 0;
    cout << ans << endl;


}
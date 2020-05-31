#include  <iostream>
#include  <stdio.h>
#include <algorithm>
#include <map>
#include <math.h>

using namespace std;
#include <vector>
#define rep(i,n) for (int i = 0; i < (n) ; i++)
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
ll C;
ll N;
ll H;
ll W;

int main(){

    cin >> H;
    cin >> W;
    ll ph[H];
    ll pw[W];
    string s[H][W];

    rep(hi,H){
        string tmp;
        cin >> tmp;
        rep(wi,W){
            s[hi][wi]=tmp.substr(wi,1);
        }
    }

    
    ll d[H][W]={};
    int rev[H][W]={};
    for( int hi = 0 ; hi <=0 ; hi++ ){
        for( int wi = 0 ; wi <=0 ; wi++ ){
            if(s[hi][wi]=="#"){
                rev[hi][wi]=1;
                d[hi][wi]=1;
            }
        }
        for( int wi = 1 ; wi <W ; wi++ ){
            if(s[hi][wi]=="#"){
                rev[hi][wi]=1;
                if(rev[hi][wi-1]==1){
                    d[hi][wi]=d[hi][wi-1];
                }else{
                    d[hi][wi]=d[hi][wi-1]+1;
                }
            }else{
                rev[hi][wi]=0;
                d[hi][wi]=d[hi][wi-1];
            }
            
        }
    }

    for( int hi = 1 ; hi <H ; hi++ ){
        for( int wi = 0 ; wi <=0 ; wi++ ){
            if(s[hi][wi]=="#"){
                rev[hi][wi]=1;
                if(rev[hi-1][wi]==1){
                    d[hi][wi]=d[hi-1][wi];
                }else{
                    d[hi][wi]=d[hi-1][wi]+1;
                }
            }else{
                rev[hi][wi]=0;
                d[hi][wi]=d[hi-1][wi];
            }
        }
    }

    for( int hi = 1 ; hi <H ; hi++ ){
        for( int wi = 1 ; wi <W ; wi++ ){
            int d_from_top  = d[hi-1][wi];
            int d_from_left = d[hi][wi-1];
            if(s[hi][wi]=="#"){
                rev[hi][wi]=1;
                if(rev[hi-1][wi]==0){
                    d_from_top++;
                }
                if(rev[hi][wi-1]==0){
                    d_from_left++;
                }
            }else{
                rev[hi][wi]=0;
            }
            d[hi][wi]=min(d_from_left,d_from_top);
        }
    }
    cout << d[H-1][W-1] << endl;

}
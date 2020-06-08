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
ll M;
ll Q;

int main(){

    
    cin >> N;
    cin >> M;
    cin >> Q;

    ll RES[N+10][M+10]={};
    ll SCORE[M+10];

    rep(mi,M+10){
        SCORE[mi]=N;
        rep(ni,N+10) RES[ni][mi]=0;
    }

    ll flag;
    ll ni;
    ll mi;

    rep(qi,Q){
        cin >> flag;
        cin >> ni;
        if(flag==1){
            ll sco=0;
            for( mi = 1 ; mi <=M ; mi++ ){
                sco+=SCORE[mi]*RES[ni][mi];
            }
            cout << sco << endl;
        }else{
            cin >> mi;
            RES[ni][mi]=1;
            SCORE[mi]--;
        }

    }


    

}
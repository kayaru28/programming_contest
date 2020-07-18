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
ll C;
ll N;
ll M;
ll K;

ll ltmp;
string stmp;
double dtmp;
ll talk[20][20]={};
ll maxans=0;

void execalc(vll status){
    bool flag=true;
    for( ll speaker = 1 ; speaker <=N ; speaker++ ){
        if(status[speaker]==1){
            for( ll taker = 1 ; taker <=N ; taker++ ){
                ll talked_status = talk[speaker][taker];
                if(talked_status>=0){
                    if(talked_status!=status[taker]){
                        flag = false;
                        break;
                    }
                }
            }
        }
        if(flag==false) break;
    }

    //for(ll ni = 1;ni<=N;ni++) cout << status[ni];
    //cout << endl;
    //cout << flag << endl;

    if(flag){
        ll cnt1=0;
        for( ll ni = 1 ; ni <=N ; ni++ ){
            cnt1+=status[ni];
        }
        if(maxans<cnt1) maxans=cnt1;
    }
    
} 

void calcMaxAns(ll index,vll status){
    if(index==N){
        execalc(status);
    }else{
        index++;
        status.push_back(0);
        calcMaxAns(index,status);
        status[index]=1;
        calcMaxAns(index,status);
    }

}


int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    rep(ni,20){
        rep(mi,20){
            talk[ni][mi]=-1;
        }
    }

    for( ll ni = 1 ; ni <=N ; ni++ ){
        cin >> A;
        rep(ai,A){
            ll num,status;
            cin >> num >> status;
            talk[ni][num]=status;
        }
    }

    vll status;
    status.push_back(0);
    calcMaxAns(0,status);


    cout << maxans << endl;    

}
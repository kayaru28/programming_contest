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
ll L;
ll f_H[base10_5]={};
ll x_time[base10_5+10];

ll minV(ll a,ll b){
    ll ans = a;
    if(a>b) ans = b;
    return ans;
}


int main(){

    

    cin >> N;
    cin >> L;

    rep(ni,N){
        ll tmp;
        cin >> tmp;

        f_H[tmp]=1;
    }

    ll T1,T2,T3;
    cin >> T1;
    cin >> T2;
    cin >> T3;

    x_time[0]=0;
    x_time[1]=T1 + f_H[1] * T3;
    for(int index = 2 ; index <=3 ; index++ ){
        x_time[index]=x_time[index-2] + T1 + T2; // a2
        x_time[index]=minV(x_time[index], x_time[index-1] + T1); // a1
        x_time[index]+=f_H[index]*T3;
    }
    ll ans;
    if(L==2){
        ans = T1*0.5 + T2 * 1.5; // from 0
        ans = minV(ans,x_time[1]+T1); // from 1
        ans = minV(ans,x_time[1]+0.5*T1 + 0.5*T2); // from 1
    }else if(L==3){
        ans = T1*0.5 + T2 * 2.5; // from 0
        ans = minV(ans,x_time[1]+T1+T2); // from 1
        ans = minV(ans,x_time[1]+0.5*T1 + 1.5*T2); // from 1
        ans = minV(ans,x_time[2]+T1); // from 2
        ans = minV(ans,x_time[2]+0.5*T1 + 0.5*T2); // from 2
    }else{
        for(int index = 4 ; index <L ; index++ ){
            x_time[index]=x_time[index-4] + T1 + 3*T2; // a3
            x_time[index]=minV(x_time[index], x_time[index-2] + T1 + T2); // a2
            x_time[index]=minV(x_time[index], x_time[index-1] + T1); // a1
            x_time[index]+=f_H[index]*T3;

        }

        ans =         x_time[L-4]+T1 + T2*3; // from -4
        //cout << ans << endl;
        ans = minV(ans,x_time[L-3]+T1*0.5 + T2*2.5); // from -3
        //cout << ans << endl;
        ans = minV(ans,x_time[L-2]+T1 + T2); // from -2
        //cout << ans << endl;
        ans = minV(ans,x_time[L-2]+T1*0.5 + T2*1.5); // from -2
        //cout << ans << endl;
        ans = minV(ans,x_time[L-1]+T1); // from -1
        //cout << ans << endl;
        ans = minV(ans,x_time[L-1]+T1*0.5 + T2*0.5); // from -1


 
    }
        
    cout << ans << endl;


}
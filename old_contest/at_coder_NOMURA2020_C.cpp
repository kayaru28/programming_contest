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

ll A[base10_6];
ll maxN[base10_6];
ll minN[base10_6];
//long double ldvMin;
//long double ldvMax;
long double ldvMax;
long double ldvMin;
ll B;
ll C;
ll N;
ll M;
ll K;
ll cntans = 0;
ll realMax = 2;

ll cnt;
ll getPower(ll value,ll shisu){
    ll ans = 1;
    cnt = shisu;
    while(cnt>0){
        if(cnt%2==1){
            ans = ans * value;
        }
        value = value * value;
        cnt = cnt/2;
    }
    return ans;
}

int main(){

    
    cin >> N;
    for( int ni = 0 ; ni <=N ; ni++ ){
        cin >> A[ni];
    }

    bool flag=true;
    maxN[N] = A[N];
    minN[N] = A[N];
    ldvMin  = minN[N];
    //cout << ldvMin << endl;
    if(log2(ldvMin) > N){
        flag = false;
    }


    if(flag){

        //cout << cntans << endl;
        for( int ni = N-1 ; ni >=0 ; ni-- ){
            maxN[ni] = A[ni] + maxN[ni+1];
            minN[ni] = A[ni] + minN[ni+1]/2 + minN[ni+1]%2;
            ldvMin  = minN[ni];
            //cout << ldvMin << endl;
            if(log2(ldvMin) > ni){
                flag = false;
                break;
            }
            ldvMax  = maxN[ni];
            //cout << ldvMax << endl;
            if(log2(ldvMax) > ni){
                //cout << "getpower " << ni << " : " << getPower(2,ni)<< endl;
                maxN[ni] = getPower(2,ni);
            }
        }
    }
    if(flag){
        cntans = 1;
        realMax = 2;
        for( int ni = 1 ; ni <=N ; ni++ ){
            if(realMax > maxN[ni]){
                realMax = maxN[ni];
            }
            else if(minN[ni]>realMax){
                flag = false;
                break;
            }
            cntans+=realMax;
            realMax = realMax - A[ni];
            realMax = realMax * 2;
        }
        cout << cntans << endl;
    }else{
        cout << -1 << endl;
    }
    

}
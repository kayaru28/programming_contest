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

// #include <iomanip>
//  cout << fixed << setprecision(15) << y << endl;

string ans_Yes = "Yes"; 
string ans_No = "No"; 
string ans_yes = "yes"; 
string ans_no = "no"; 

vll A;
vll B;
ll C;
ll X;
ll Y;
ll K;
ll ans = 0;
ll leng;
ll lengX;
ll lengY;


ll ltmp;
string stmp;
double dtmp;

ll llmin(ll a,ll b){
    if(a>=b) return b;
    return a;
}
ll llmax(ll a,ll b){
    if(a<=b) return b;
    return a;
}


void storageXY(ll Xi, ll Yi){
    ans++;
    A.push_back(Xi);
    B.push_back(Yi);
}
void updataLeng(ll Xi, ll Yi){
    lengX = abs(X-Xi);
    lengY = abs(Y-Yi);
    leng  = lengX + lengY;
    //cout << X <<" < "<< Xi << " = " << lengX <<endl;
}

ll directionX;
ll directionY;

int getAns(){
    directionX = X/abs(X);
    directionY = Y/abs(Y);
    leng = abs(X)+abs(Y);

    if(leng==K){
        storageXY(X,Y);
        return 0;
    }

    if(leng%2==1){
        if(K%2==0){
            cout << -1 << endl;
            return 0;
        }else if(K%2==1){
            ans++;
            ll dx = K * ( lengX / leng );
            ll dy = K * ( lengY / leng );
            dx += (K - dx - dy);

            Xi+=dx;
            Yi+=dy;
            storageXY(Xi,Yi);
            updataLeng(Xi,Yi);
        }
    }

    while(leng!=0){
        ll huriwake = K;
        ll diff = abs(lengX-lengY);
        huriwake-=diff;
        if(lengX>lengY) dx = diff;
        else            dy = diff;



    }





}


int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> K;
    cin >> X;
    cin >> Y;

    getAns();


    

}
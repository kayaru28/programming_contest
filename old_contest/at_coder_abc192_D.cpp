


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
#define vvll vector<vector<ll>>
#define vstr vector<string>
#define vvstr vector<vector<string>>


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
ll getllSubstr(string s,ll start_index,ll length){
    return atoi(s.substr(start_index,length).c_str());
}
vll X;

ll maxX;

ll getval(ll shinho){

    ll ansval = 0;
    rep(xi,X.size()){
        ansval = ansval * shinho + X[xi];
        if(ansval <= 0) return llINF*1.1;
    }
    return ansval;
}
ll getans(){

    ll li = maxX+1;
    ll ri = llINF+1;
    ll vli = getval(li);
    ll vri = getval(ri);

    while(li!=ri-1){
        //cout << li << " " << ri << endl;
        ll mid = (li + ri)/2;
        ll vmid = getval(mid);
        //cout << "  " << mid << " " << vmid << endl;

        if(vmid == M) return mid;
        else if(vmid < M) li = mid;
        else ri = mid;
    }
    return li;

}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string S;
    cin >> S;
    cin >> M;

 
    rep(si,S.size()){
        X.push_back( getllSubstr(S,si,1)  );
    }

    vll tmpX=X;
    sort(tmpX.rbegin(),tmpX.rend());
    maxX = tmpX[0];

    if(getval(maxX+1)>M) cout << 0 << endl;
    else if(X.size()==1){
        cout << 1 << endl;
    }
    else{
        cout << getans()-maxX << endl;

    }

    

}
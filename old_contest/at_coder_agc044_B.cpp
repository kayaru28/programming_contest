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

vint hop;
vll left;
vector<vector<ll>> neigher;

ll getR(ll P){
    ll ri = (P-1)/N + 1;
    return ri;
}
ll getC(ll P,ll ri){
    ll ci = P - N*(ri-1);    
    return ci;
}
ll getP(ll ri,ll ci){
    ll P = ci + N*(ri-1);
    return P;
}
void addNeigher(ll ri,ll ci){
    ll baseP = getP(ri,ci);
    ll tmpP;

    tmpP = getP(ri-1,ci);
    neigher[baseP].push_back(tmpP);
    tmpP = getP(ri+1,ci);
    neigher[baseP].push_back(tmpP);
    tmpP = getP(ri,ci-1);
    neigher[baseP].push_back(tmpP);
    tmpP = getP(ri,ci+1);
    neigher[baseP].push_back(tmpP);
}
ll getAroundMin(ll P){
    int ans = 1000;
    rep(ni,neigher[P].size()){
        ll tmpP = neigher[P][ni];
        ans = min(ans,hop[tmpP]);
        if(ans == -1){
            return ans;
        }
    }
    return ans;
}


int main(){

    
    cin >> N;

    hop.resize(N*N+1);
    left.resize(N*N+1);
    neigher.resize(N*N+1);
    hop[0]=-1;

    ll left = 1;
    ll right = N;
    for( int ni = left ; ni <=right ; ni++ ){
        hop[getP(ni,left)]=0;
        hop[getP(ni,right)]=0;
        hop[getP(left,ni)]=0;
        hop[getP(right,ni)]=0;
    }



    left++;
    right--;
    ll base = 1;
    while(left<right){
        for( int ni = left ; ni <=right ; ni++ ){
            ll ri,ci;
            ri = ni;
            ci = left;
            hop[getP(ri,ci)]=base;
            addNeigher(ri,ci);

            ri = ni;
            ci = right;
            hop[getP(ri,ci)]=base;
            addNeigher(ri,ci);

            ri = left;
            ci = ni;
            hop[getP(ri,ci)]=base;
            addNeigher(ri,ci);

            ri = right;
            ci = ni;
            hop[getP(ri,ci)]=base;
            addNeigher(ri,ci);

        }
        base++;
        left++;
        right--;
    }
    if(left==right){
        ri = right;
        ci = left;
        hop[getP(ri,ci)]=base;
        addNeigher(ri,ci);
    } 
    
    ll cnt=0;
    rep(ni,N*N){
        ll P;
        cin >> P;
        ll ri = getR(P);
        ll ci = getC(P,ri);
        ll valu = getAroundMin(P);

        seki[ri][ci] = valu;
        cnt = cnt + (valu+1);

        left[ri][ci]=1;
        updateSeki(ri,ci);


        cout << "-----------" << endl;
        cout << P << endl;
        cout << valu << endl;
        cout << cnt << endl;


    }
    cout << cnt << endl;


}
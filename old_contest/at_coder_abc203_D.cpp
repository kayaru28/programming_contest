

#include  <iostream>
#include  <stdio.h>
#include <algorithm>
#include <map>
#include <math.h>
#include <queue>
#include <vector>
#include <stack>
#include <set>
#include <bitset>

using namespace std;
#define rep(i,n) for (ll i = 0; i < (n) ; i++)
#define rep2(i,n,i2,n2) for (ll i = 0; i < (n) ; i++) for (ll i2 = 0; i2 < (n2) ; i2++)
#define incRepFT(i,s,n) for (ll i = (s); i <= (n) ; i++)
#define decRepFT(i,s,n) for (ll i = (s); i >= (n) ; i--)

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
typedef pair<ll,ll> P;  




// #include <iomanip>
//  cout << fixed << setprecision(15) << y << endl;

// for(char c : S)

//min({a1, a2, ..., an})
//max({a1, a2, ..., an})
//swap(a, b)
//S.substr(si)
// sort <--> reverse
//count(v.begin(), v.end(), x) 
// char t - 'a'
// char t - '0'

//xを2進数にした時の1の数
//__builtin_popcount(x) 
//__builtin_popcountll(x) 

ll A;
ll B;
ll C;
ll D;
ll N;
ll M;
ll K;
ll T;
ll H;
ll W;
ll X;
ll Y;
ll Z;

string S;

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
P d_move[4] = {
    P(0 , 1),P(0 , -1),P(1 , 0),P(-1 , 0)//,P(1 , 1),P(1 , -1),P(-1 , 1),P(-1 , -1)
};
//for(P drc : d_move)
vvll mapA;
/*
ms.insert(7);
ms.insert(5);
ms.insert(2);
ms.insert(7);
ms.count(5);
if (ms.find(5) == ms.end()){}else{}
ms.erase(5);
ll getMsMax(multiset<ll> msi){
    auto itr = msi.end();
    --itr;
    return *itr; 
}
ll getMsMin(multiset<ll> msi){
    auto itr = msi.begin();
    return *itr; 
}
*/
ll maxA=0;
ll baseind;
double double_hosei = 1000000; //求められる精度分補正をかけておく

class ruisekiwa2D {
private:
    vvll data2D;
    ll numR,numC;
public:
    ruisekiwa2D(ll R, ll C){ //最初は全てが根であるとして初期化
        numR = R;
        numC = C;
        data2D.resize(R);
        rep(ri,R){
            rep(ci,C) data2D[ri].push_back(0);
        }
    }
    void set(ll ri,ll ci,ll val){
        data2D[ri][ci] = val;
    }
    void add(ll ri,ll ci,ll val){
        data2D[ri][ci] += val;
    }
    void calc(){
        rep(ri,numR){ 
            for( ll ci = 1 ; ci <numC; ci++ ){
                data2D[ri][ci]+=data2D[ri][ci-1];
            }
        }
        for( ll ri = 1 ; ri <numR ; ri++ ){
            for( ll ci = 0 ; ci <numC ; ci++ ){
                data2D[ri][ci]+=data2D[ri-1][ci];
            }
        }
    }
    ll get(ll ri,ll ci){
        return data2D[ri][ci];
    }
};
ruiseki
bool judge(ll tarM){

    ruisekiwa2D ruisekiwa2d(N,N);
    rep(ni1,N){
        rep(ni2,N){
            if( mapA[ni1][ni2] > tarM ) ruisekiwa2d.set(ni1,ni2,1);
            else ruisekiwa2d.set(ni1,ni2,0);
        }
    }
    ruisekiwa2d.calc();
    /*
    cout << tarM << endl;
    rep(ri,N){
        rep(ci,N){
            cout <<  ruisekiwa2D[ri][ci] << " ";
        }
        cout << endl;
    }*/


    rep(ri,N){
        ll rs = ri;
        ll re = rs+K-1;
        if(re>=N) break;
        ll cs = 0;
        ll ce = cs+K-1;
        rep(ci,N){
            //cout << "cnttop " << tarM << " " << cnttop << endl;
            ll cnt = ruisekiwa2d.get(re,ce);
            if(rs>0) cnt -= ruisekiwa2d.get(rs-1,ce);
            if(cs>0) cnt -= ruisekiwa2d.get(re,cs-1);
            if(rs*cs>0) cnt += ruisekiwa2d.get(rs-1,cs-1);
            //cout << rs << " " << cs << " " << tarM << " is " << cnt << endl;
            
            if(cnt<baseind) return true;
            cs++;
            ce++;
            if(ce>=N) break;
        }
    }
    return false;
}
ll getans(){
    ll li = 0;
    ll ri = maxA;
    ll mid;
    while(li+1<ri){
        //cout << li << " " << ri << endl;
        mid = (li + ri)/2;
        if(judge(mid)){
            ri = mid;
        }else{
            li = mid;
        }
    }
    return ri;
}


int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    cin >> K;
    mapA.resize(N);
    dtmp = K;

    baseind = int(dtmp*dtmp/2)+1;
    rep(ni1,N){
        mapA[ni1].resize(N);
        rep(ni2,N){
            cin >> mapA[ni1][ni2];
            maxA = llmax(maxA, mapA[ni1][ni2]);
        }
    }
    cout << getans() << endl;


}
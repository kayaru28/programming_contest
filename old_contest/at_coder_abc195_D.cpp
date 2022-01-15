
#include <set>

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
ll Q;
vll W,V,X;
vll L,R;

ll ltmp;
string stmp;
double dtmp;

/*
multiset<int> ms;
ms.insert(7);
ms.insert(5);
ms.insert(2);
ms.insert(7);
ms.count(5);
if (ms.find(5) == ms.end()){}else{}
ms.erase(5);
*/

#include <queue>
//https://cpprefjp.github.io/reference/queue/priority_queue/pop.html
//std::priority_queue<ll> que;
//que.push(val);
//ll getv = que.top();
//que.pop();
typedef pair<ll,ll> P;  
//priority_queue<P,vector<P>, greater<P> > que;
//que.push(P(0,base_index));
int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    cin >> M;
    cin >> Q;

    W.resize(N);
    V.resize(N);
    rep(ni,N){
        cin >> W[ni];
        cin >> V[ni];
    }

    X.resize(M);
    rep(mi,M) cin >> X[mi];

    L.resize(Q);
    R.resize(Q);
    rep(qi,Q){
        cin >> L[qi];
        cin >> R[qi];
        L[qi]--;
        R[qi]--;
    }

    priority_queue<P,vector<P>, greater<P> >  que,tmpque;

    rep(ni,N){
        que.push(P(W[ni],V[ni]));
    }


    rep(qi,Q){
        //cout << qi << "------------------------------" << endl;
        vll boxsize;
        for( ll ind = 0 ; ind <L[qi] ; ind++ ){
            boxsize.push_back(X[ind]);
        }
        for( ll ind = R[qi]+1 ; ind <M ; ind++ ){
            boxsize.push_back(X[ind]);
        }

        sort(boxsize.begin(),boxsize.end());

        multiset<ll> ms;
        tmpque = que;
        P getv = tmpque.top();
        tmpque.pop();


        ll ans = 0;
        rep(bi,boxsize.size()){
           // cout << "next" << endl;
            ll tarsize = boxsize[bi];
            while(getv.first<= tarsize){
                //cout << getv.second << " " << tarsize << endl;
                ms.insert(getv.second);
                if(tmpque.size()>0){
                    getv = tmpque.top();
                    tmpque.pop();
                }else{
                    getv.first = llINF;
                }
            }
            if(ms.size()>0){
                decltype(ms)::iterator it = ms.end();
                it--;

                ll val = *it;
                //cout << "mark " << val << endl;
                ans += val;
                ms.erase(ms.find(val));
            }
        }

        cout << ans << endl;



    }



    

}
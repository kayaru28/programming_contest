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


ll N;
ll Q;
vll S;
vll T,X,D;

ll ltmp;
string stmp;
double dtmp;

map<string,ll> getT;
vll listS;



#include <queue>
typedef pair<ll,ll> P;  
priority_queue<P,vector<P>, greater<P>> que;
priority_queue<P,vector<P>, greater<P>> que_tmp;

ll llmin(ll a,ll b){
    if(a>=b) return b;
    return a;
}
ll llmax(ll a,ll b){
    if(a<=b) return b;
    return a;
}
string getKey(ll S,ll X){
    return to_string(S) + to_string(X);
}
int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    cin >> Q;

    rep(ni,N){
        ll Si,Ti,Xi;
        cin >> Si >> Ti >> Xi;
        X.push_back(Xi);
        S.push_back(Si);
        T.push_back(Ti);
    }

    rep(qi,Q){
        cin >> ltmp;
        D.push_back(ltmp);    
    }

    rep(ni,N){
        ll Si,Ti,Xi;
        Xi = X[ni];
        Si = llmax(0,S[ni]-Xi);
        Ti = llmax(0,T[ni]-Xi-1);
        que.push(P(Si,Xi));
        getT[getKey(Si,Xi)] = Ti;
    }

    ll si=0;
    vll ans;
    for( ll di = 0 ; di <Q ; di++ ){
        ll Di = D[di];
        //cout << "Di " << Di << endl;
        while(1){
            if(que.size()==0){
                break;
            }else{
                P Psx = que.top();
                ll Xi = Psx.second;
                ll Si = Psx.first;
                if(Di<Si) break;
                else{
                    que_tmp.push(P(Xi,Si));
                    //cout << "gets " << Xi << endl;
                    que.pop();
                }
            }
        }

        while(1){
            if(que_tmp.size()==0){
                ans.push_back(-1);
                break;
            }else{
                P Pxs = que_tmp.top();
                ll Xi = Pxs.first;
                ll Si = Pxs.second;
                ll Ti = getT[getKey(Si,Xi)];
                //cout << "top " << Xi << endl;
                if(Di<Si){
                    ans.push_back(-1);
                    break;
                }
                else if(Ti<Di){
                    que_tmp.pop();
                    //cout << "Ti " << Ti << endl;
                    //cout << "pop " << Xi << endl;
                }
                else{
                    ans.push_back(Xi);
                    break;
                }
            }
        }
    }

    rep(ai,ans.size()){
        cout << ans[ai] << endl;
    }


}
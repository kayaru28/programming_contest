


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

vll A;
vll B;
ll C;
ll N;
ll M;
ll Q;
vll T;
vll X;
vll Y;
ll Z;

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


double double_hosei = 1000000; //求められる精度分補正をかけておく
int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    cin >> M;
    cin >> Q;

    rep(ni,N+1) A.push_back(0);
    rep(mi,M+1) B.push_back(0);

    T.resize(Q) ;   
    X.resize(Q) ;   
    Y.resize(Q) ;

    rep(qi,Q){
        cin >> T[qi];
        cin >> X[qi];
        cin >> Y[qi];
    }

    ll ans = 0;
    ll cntA = 0;
    ll cntB = 0;

    map<ll,ll> valA;
    map<ll,ll> valB;

    rep(qi,Q){
        ll cind = X[qi];
        ll cval = Y[qi];
        if(T[qi]==1){
            ll fromval = A[cind];
            A[cind] = cval;
            valA[cval]++;

            if(fromval==0){
                cntA++;
            }
            else{
                valA[fromval]--;
                if(valA[fromval]==0){
                    valA.erase(fromval);
                }
            }

            ll dv =  cval - fromval;
            
            ans = ans + (M-cntB) * dv;

            for(auto x : valB) {
                ll xval = x.first;
                ll xcnt = x.second;
                if(xval > fromval){
                    if(cval > xval){
                        ans += (cval - xval) * xcnt;
                    }else{
                        break;
                    }
                }else{
                    if(cval > xval){
                        ans += (cval - fromval) * xcnt;
                    }else{
                        ans += (xval - fromval) * xcnt;
                    }
                }
            }
        }else{
            ll fromval = B[cind];
            B[cind] = cval;
            valB[cval]++;

            if(fromval==0) cntB++;
            else{
                valB[fromval]--;
                if(valB[fromval]==0) valB.erase(fromval);
            }

            ll dv =  cval - fromval;
            
            ans = ans + (N-cntA) * dv;
            for(auto x : valA) {
                ll xval = x.first;
                ll xcnt = x.second;
                if(xval > fromval){
                    if(cval > xval){
                        ans += (cval - xval) * xcnt;
                    }else{
                        break;
                    }
                }else{
                    if(cval > xval){
                        ans += (cval - fromval) * xcnt;
                        
                    }else{
                        ans += (xval - fromval) * xcnt;
                    }
                }
            }

        }
        cout << ans << endl;

    }



}
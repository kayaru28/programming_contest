


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
vll X,Y;
vll op[2];


ll ltmp;
string stmp;
double dtmp;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    X.resize(N);
    Y.resize(N);
    rep(ni,N){
        cin >> X[ni];
        cin >> Y[ni];
    }
    cin >> M;
    op[0].resize(M);
    op[1].resize(M);
    rep(mi,M){
        cin >> op[0][mi];
        if(op[0][mi]>=3){
            cin >> op[1][mi];
        }
    }
    cin >> Q;
    A.resize(Q);
    B.resize(Q);
    rep(qi,Q){
        cin >> A[qi];
        cin >> B[qi];
    }

    vll addx;
    vll addy;
    vll multix;
    vll multiy;
    vll rev;

    addx.push_back(0);
    addy.push_back(0);
    multix.push_back(1);
    multiy.push_back(1);
    rev.push_back(0);
    rep(mi,M){
        ll index = mi+1;
        ll opid = op[0][mi];
        addx.push_back(addx[index-1]);
        addy.push_back(addy[index-1]);
        multix.push_back(multix[index-1]);
        multiy.push_back(multiy[index-1]);
        rev.push_back(rev[index-1]);
        if(opid==1){
            if(rev[index-1]==0){
                multix[index] *= -1;
                addx[index]  *= -1;
                multiy[index] *= 1;
            }else{
                multix[index] *= 1;
                multiy[index] *= -1;
                addy[index]  *= -1;
            }
            rev[index] = (rev[index]+1)%2;
        }else if(opid==2){
            if(rev[index-1]==0){
                multix[index] *= 1;
                multiy[index] *= -1;
                addy[index]  *= -1;
            }else{
                multix[index] *= -1;
                addx[index]  *= -1;
                multiy[index] *= 1;
            }
            rev[index] = (rev[index]+1)%2;
        }else if(opid==3){
            ll opval = op[1][mi];
            
            if(rev[index-1]==0){
                multix[index] *= -1;
                addx[index]  *= -1;
                addx[index] += (2 * opval);
            }else{
                multiy[index] *= -1;
                addy[index]  *= -1;
                addy[index] += (2 * opval);
            }
        }else if(opid==4){
            ll opval = op[1][mi];
            
            if(rev[index-1]==0){
                multiy[index] *= -1;
                addy[index]  *= -1;
                addy[index] += (2 * opval);
            }else{
                multix[index] *= -1;
                addx[index]  *= -1;
                addx[index] += (2 * opval);
            }
        }
        
    }
    rep(qi,Q){
        ll mi;
        mi = A[qi];
        ll ni;
        ni = B[qi];
        ni--;
        ll xi,yi;
        xi = X[ni];
        yi = Y[ni];
        xi = xi * multix[mi] + addx[mi];
        yi = yi * multiy[mi] + addy[mi];
        if(rev[mi]==0){
            cout << xi << " " << yi << endl;
        }else{
            cout << yi << " " << xi << endl;

        }
    }




    

}
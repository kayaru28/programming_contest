


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
ll K;
ll T;
ll X;
ll Y;
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
ll ans = 0;





vector<vector<ll> > G; 
vector<vector<ll> > G2; 

ll tmpans3=0;
void get3unit(ll index,ll keisu,vll color){
    //cout << index << " " << N + 1 << " aaa" << endl;
    if(index==N+1){
        //cout << "sss" << endl;
        //rep(ni,N) cout << color[ni+1] << " ";
        //cout << endl;

        ll flag = 1;
        rep(mi,M){
            ll ind1 = A[mi];
            ll ind2 = B[mi];
            if(color[ind1]==color[ind2]){
                flag = 0;
                break;
            }
        }
        //cout << keisu << endl;
        tmpans3 += (flag * keisu);
    }
    else{

        if(G2[index].size()==0){
            keisu *= 3;
            //cout << index << " " << keisu << endl;
            get3unit(index+1,keisu,color);
        }else{
            ll val[100]={};
            rep(gi,G[index].size()){
                ll tar = G[index][gi];
                ll tarcol = color[tar];
                val[tarcol]++;
            }


            ll nowcol;
            nowcol = 0;
            if(val[nowcol] == 0){
                color[index] = nowcol;
                get3unit(index+1,keisu,color);
            }
            nowcol = 1;
            if(val[nowcol] == 0){
                color[index] = nowcol;
                get3unit(index+1,keisu,color);
            }
            nowcol = 2;
            if(val[nowcol] == 0){
                color[index] = nowcol;
                get3unit(index+1,keisu,color);
            }
        }

    }
}

ll get3(){
    //ll color[100];
    vll color;
    //rep(ni,100) color[ni]=100;
    rep(ni,N+10) color.push_back(100);

    color[1] = 0;
    get3unit(2,1,color);
    return tmpans3 * 3;
    
    //get3unit(1,1,color);
    //return tmpans3;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    cin >> M;
    A.resize(M);
    B.resize(M);
    G.resize(N+1);
    G2.resize(N+1);
    rep(mi,M) cin >> A[mi] >> B[mi];

    rep(mi,M){
        if(A[mi] > B[mi]) G[A[mi]].push_back(B[mi]);
        else G[B[mi]].push_back(A[mi]);
        G2[A[mi]].push_back(B[mi]);
        G2[B[mi]].push_back(A[mi]);
    }

    ans += get3();

    cout << ans << endl;





}
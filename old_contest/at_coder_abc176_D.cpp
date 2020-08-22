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

ll H;
ll W;
ll Ch,Cw;
ll Dh,Dw;
ll M;
ll K;

#include <queue>
//https://cpprefjp.github.io/reference/queue/priority_queue/pop.html
//std::priority_queue<ll> que;
//que.push(val);
//ll getv = que.top();
//que.pop();
//typedef pair<ll,ll> P;  
//priority_queue<P,vector<P>, greater<P> > que;
//que.push(P(0,base_index));

typedef pair<ll,ll> P; 
ll ltmp;
string stmp;
double dtmp;
int S[1010][1010];
ll score[1010][1010]={};

void gettable(){
        cout << "++++++++++++" << endl;
        rep(hi,H){
            rep(wi,W){
                if(score[hi][wi]<10000) cout << score[hi][wi];
                else cout << "#";
            }
            cout << "" << endl;
        }

}
int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> H;
    cin >> W;
    cin >> Ch >> Cw;
    cin >> Dh >> Dw;
    Ch--;
    Cw--;
    Dh--;
    Dw--;
    
    string tS;
    rep(hi,H){
        cin >> tS;
        rep(wi,W){
            if(tS.substr(wi,1)==".")    S[hi][wi] = 1;
            else S[hi][wi] = 0;
            score[hi][wi]=10000;
        }
    }

    priority_queue<P,vector<P>, greater<P> > que ;
    que.push(P(0,Ch*1000+Cw));
    score[Ch][Cw]=0;
    while(que.size()>0){
        P getv = que.top();
        que.pop();

        ll si = getv.first;
        ll hi = getv.second/1000;
        ll wi = getv.second%1000;
        if(score[hi][wi]<si) continue;
        //cout << hi << endl;
        for( int dw = -2 ; dw <=2 ; dw++ ){
            for( int dh = -2 ; dh <=2 ; dh++ ){
                ll wii = wi + dw;
                ll hii = hi + dh;
                if(wii <0) continue;    
                if(wii >=W) continue;    
                if(hii <0) continue;    
                if(hii >=H) continue;    
                if(S[hii][wii]==0) continue;
                if(dw==0 && dh==0) continue;

                ll sii = si + 1;
                if(abs(dw) + abs(dh) == 1) sii = si;
                if(score[hii][wii]<=sii) continue;
                score[hii][wii] = sii;
                que.push(P(sii,hii*1000+wii));
            }
        }
        //gettable();
    }

    //gettable();
    if(score[Dh][Dw]==10000) cout << -1 << endl;
    else cout << score[Dh][Dw] << endl;
}


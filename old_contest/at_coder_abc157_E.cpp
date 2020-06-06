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

#define baseMax 500010
ll N;
ll K;
char s[baseMax];
ll matrix[27][baseMax]={};

ll chAToN(char s){
    return s-'a';
}

void gain(char alpha, ll pos){
    int alphai = chAToN(alpha);
    for( int pi = pos ; pi <N ; pi++ ){
        matrix[alphai][pi]++;
    }
}
void loss(char alpha, ll pos){
    int alphai = chAToN(alpha);
    for( int pi = pos ; pi <N ; pi++ ){
        matrix[alphai][pi]--;
    }
}

void showMatrix(){
    cout << "--------------------------------------" << endl;
    rep(a,26){
        rep(b,N){
            cout << matrix[a][b];
        }
        cout << endl;
    }
    cout << "--------------------------------------" << endl;
}

int main(){
 

 
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    cin >> N;
    cin >> s;

    cin >> K;

    /*
    rep(alphai,26){
        rep(pos,N){
            matrix[alphai][pos]=0;
        }
    }
    */

    rep(pos,N){
        int alphai = chAToN(s[pos]);
        matrix[alphai][pos]=1;
    }

    for( int alphai = 0 ; alphai <26 ; alphai++ ){
        for( ll pos = 1 ; pos <N ; pos++ ){
            matrix[alphai][pos] = matrix[alphai][pos] + matrix[alphai][pos-1];
        }
    }

    int type;
    int li,ri,ii;
    char aft;
    rep(ki,K){
        cin >> type;
        if(type==1){
            cin >> ii >> aft;
            ii--;
            char bef = s[ii];
            gain(aft,ii);
            loss(bef,ii);
            s[ii]=aft;
        }else{
            cin >> li >> ri;
            li--;
            ri--;
            ll cnt=0;
            //showMatrix();
            rep(alphai,26){
                if(matrix[alphai][ri]-matrix[alphai][li-1]>0){
                    cnt++;
                }
            }
            cout << cnt << endl;
        }
        

    }

}
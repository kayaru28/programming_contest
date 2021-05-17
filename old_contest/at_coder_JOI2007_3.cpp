

#include  <iostream>
#include  <stdio.h>
#include <algorithm>
#include <map>
#include <math.h>
#include <vector>


using namespace std;
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





// #include <iomanip>
//  cout << fixed << setprecision(15) << y << endl;

// for(char c : S)

//min({a1, a2, ..., an})
//max({a1, a2, ..., an})
//swap(a, b)
//S.substr(si)
// sort <--> reverse
//count(v.begin(), v.end(), x) 

//xを2進数にした時の1の数
//__builtin_popcount(x) 
//__builtin_popcountll(x) 

ll N;
ll X;
ll Y;


int llmax(int a,int b){
    if(a<=b) return b;
    return a;
}

typedef pair<int,int> point;


int getKey(point px ){
    return px.first * 10000 + px.second;
}
double double_hosei = 10000; //求められる精度分補正をかけておく
int main(){


    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    //X.resize(N);
    //Y.resize(N);

    point pos_XY[N];
    map<int,int> map_XY;
    rep(ni,N){
        cin >> X;//[ni];
        cin >> Y;//[ni];
        pos_XY[ni] = point(X,Y);
        //pos_XY[ni] = point(X[ni],Y[ni]);
        map_XY[ getKey(pos_XY[ni]) ]++;
        //map_XY[X[ni]][Y[ni]]++;
    }

    int ans = 0;
    int tmpans;
    for( int ind1 = 0 ; ind1 <N ; ind1++ ){
        for( int ind2 = ind1+1 ; ind2 <N ; ind2++ ){
            point p1 = pos_XY[ind1];
            point p2 = pos_XY[ind2];
            int vx = p2.first-p1.first;
            int vy = p2.second-p1.second;
            tmpans = vx*vx + vy*vy;

            if(tmpans>ans){

                point p3;
                p3.first = p1.first + vy;
                if(p3.first < 0 ) continue;
                if(p3.first > 5000 ) continue;

                p3.second = p1.second - vx;
                if(p3.second < 0 ) continue;
                if(p3.second > 5000 ) continue;

                point p4;
                p4.first = p3.first + vx;
                if(p4.first < 0 ) continue;
                if(p4.first > 5000 ) continue;

                p4.second = p3.second + vy;
                if(p4.second < 0 ) continue;
                if(p4.second > 5000 ) continue;

                if(map_XY[ getKey(p3) ]==0) continue;
                
                if(map_XY[ getKey(p4) ]==0) continue;

                ans = llmax(tmpans,ans);
                        

            }
        }
    }

    cout << ans << endl;



    

}
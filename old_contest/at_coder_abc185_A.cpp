
    #include <string>
    #include <iostream>
    #include <algorithm>
    #include <vector>
    #include <iomanip>
    #include <math.h>
    #include <complex>
    #include <queue>
    #include <deque>
    #include <stack>
    #include <map>
    #include <set>
    #include <bitset>
    #include <functional>
    #include <assert.h>
    #include <numeric>

    using namespace std;
    #define rep(i,n) for (ll i = 0; i < (n) ; i++)
    #define vsort(v) sort(v.begin(),v.end())
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

    //#include <stack>
    //#include <queue>

    // #include <iomanip>
    //  cout << fixed << setprecision(15) << y << endl;

    /*
    sort(ord.begin(),ord.end(),[&](int x, int y){
        return p[x]>p[y];
    });
    */



    string ans_Yes = "Yes"; 
    string ans_No = "No"; 
    string ans_yes = "yes"; 
    string ans_no = "no"; 

    vll A;
    ll B;
    ll C;
    ll N;
    ll M;
    ll K;

    ll ltmp;
    string stmp;
    double dtmp;

    int main(){

        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);

        A.resize(4);
        rep(ni,4) cin >> A[ni]; 
        vsort(A);
        cout << A[0] << endl;

    }
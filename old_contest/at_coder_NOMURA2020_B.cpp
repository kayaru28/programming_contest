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
string ReplaceString
(
      std::string String1   // 置き換え対象
    , std::string String2   // 検索対象
    , std::string String3   // 置き換える内容
)
{
    std::string::size_type  Pos( String1.find( String2 ) );
 
    while( Pos != std::string::npos )
    {
        String1.replace( Pos, String2.length(), String3 );
        Pos = String1.find( String2, Pos + String3.length() );
    }
 
    return String1;
}
ll A;
ll B;
ll C;
ll N;
ll M;
ll K;

int main(){

    
    string T;
    string S="";
    cin >> T;

    cout << ReplaceString(T,"?","D") << endl;

}
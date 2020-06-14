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

ll N;
ll M;
ll K;

vector<int> values;
class BinarySearch
{
    public:
        ll search(int target){
            int left  = 0;
            int right = values.size();
            int mid;

            while(left<right){
                mid = (left+right)/2;
                if(target>values[mid]){
                    right = mid;
                }else{
                    left = mid+1;
                }
            }
            return right;
        }
};

vll ans;
int main(){

    
    cin >> N;
    cin >> M;
    values.resize(N);
    rep(ni,N) values[ni]=0;
    BinarySearch binary_search; // int main の中で使う
    rep(mi,M){
        ll a;
        cin >> a;
        ll res = binary_search.search(a);
        //cout << "res " << res << endl;
        if(values[res]>a){
            ans.push_back(-1);
        }else if(res >= values.size()){
            ans.push_back(-1);
        }else{
            ans.push_back(res+1);
            values[res]=a;
        }
    }
    
    rep(mi,M) cout << ans[mi] << endl;    
    

}
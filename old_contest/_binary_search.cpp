#include  <iostream>
#include  <stdio.h>
#include <algorithm>
using namespace std;
#include <vector>
#define rep(i,n) for (int i = 0; i < (n) ; i++)
#define INF 1e9
#define llINF 1e18
#define MOD 1000000007
#define pb push_back
#define ll long long
#define ull unsigned long long
#define vint vector<int>
#define vll vector<ll>

//#include <stack>
//#include <queue>



vector<int> values;
class BinarySearch
{
    private:
        // 検索対象を判定する条件を設定
        int CODE_MARCH = 0;
        int judge(int target_value,int comparison_index){
            if(target_value==values[comparison_index]) return CODE_MARCH;
            else if(target_value > values[comparison_index]) return 1;
            else return 2;
        }
    public:
        int search(int target){
            int left  = 0;
            int right = values.size();
            int mid;

            while(left<right){
                mid = (left+right)/2;
                if(judge(target,mid)==CODE_MARCH){
                        return mid;
                // 検索結果が条件に合致しない場合の処理
                }else if(judge(target,mid)==1){
                    left = mid;
                }else{
                    right = mid;
                }
            }
        }
};

int main(){

    int N;
    cin >> N;

    rep(ni,N){
        values.push_back(ni);
    }
    
    int target;
    cin >> target;
    
    BinarySearch binary_search; // int main の中で使う
    cout << "answer is " << endl;
    cout << binary_search.search(target) << endl;

}










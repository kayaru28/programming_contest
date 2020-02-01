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

/*
#include <math.h>
int standerd = int(pow(10.0,9.0)) + 7;
*/
string ans_Yes = "Yes"; 
string ans_No = "No"; 
string ans_yes = "yes"; 
string ans_no = "no"; 
 
int N;



vector<int> values;
int judgeForBinarySearch(int target,int index){
    if(target==values[index]) return 0;
    else if(target > values[index]) return 1;
    else return 2;
}
int binarySearch(int target){
    int left=0;
    int right;
    right = values.size();
    int mid;
    while(left<right){ //二分探索
        mid = (left+right)/2;
        if(judgeForBinarySearch(target,mid)==0){
            return mid;
        }else if(judgeForBinarySearch(target,mid)==1){
            right = mid;
        }else{
            left = mid;
        }
    }
}



int main(){
    cin >> N;
    int tmp;
    rep(ni,N){
        cin >> tmp;
        values.push_back(tmp);
    }

    int target;
    cin >> target;
    cout << binarySearch(target) << endl;
}
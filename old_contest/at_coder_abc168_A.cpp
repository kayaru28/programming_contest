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

ll A;
ll B;
ll C;
ll N;
ll M;
ll K;

int getIntSubstr(string s,int start_index,int length){
    return atoi(s.substr(start_index,length).c_str());
}
int main(){

    
    string S;
    cin >> S;
    int tar;
    tar = getIntSubstr(S,S.size()-1,1);
    if(tar==3){
        cout << "bon" << endl;
    }else if(tar==0||tar==1||tar==6||tar==8){
        cout << "pon" << endl;
    }else{
        cout << "hon" << endl;
    }
    

}
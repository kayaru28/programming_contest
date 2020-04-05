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

ll N;
ll K;
ll C;
vint point;
vint after;
vint before;

int main(){


    
    cin >> N;
    cin >> K;
    cin >> C;

    string S;
    cin >> S;


    //o か x
    int point_x;
    int bef_index=0;
    int point_i;
    point_i=0;
    rep(ni,N){
        if(S.substr(ni,1)=="o"){
            point_x = ni + 1;
            point.push_back(point_x);
            after.push_back(0);
            before.push_back(0);
            while(point_x > point[bef_index] + C){
                after[bef_index]=point_i;
                bef_index++;
            }
            point_i++;
        }
    }

    int last_index = point.size()-1;
    int aft_index= last_index;
    for( int index = last_index ; index >=0 ; index-- ){
        point_x = point[index];
        while(point_x + C < point[aft_index]){
            before[aft_index]=index;
            aft_index--;
        }
    }

    //rep(ni,point.size()){
        //cout << ni << " : " << point[ni]  << "/" << after[ni]<< "/"<< before[ni] << endl;
    //}

    ll load_front[K];
    ll load_back[K];

    point_i=0;
    point_x = point[point_i];
    load_front[0]=(point_x);
    for( int index = 1 ; index <=K-1 ; index++ ){
        point_i = after[point_i];
        point_x = point[point_i];
        load_front[index]=point_x;
    }

    //cout << "back" << endl;
    point_i = last_index;
    point_x = point[point_i];
    load_back[K-1]=(point_x);
    for( int index = K-2 ; index >=0 ; index-- ){
        point_i = before[point_i];
        point_x = point[point_i];
        load_back[index]=point_x;
    }
    //cout << "vs" << endl;
    rep(index,K){
        //cout << load_front[index] << " vs " << load_back[index] << endl;
        if(load_front[index]==load_back[index]) cout << load_front[index] << endl;
    }


}
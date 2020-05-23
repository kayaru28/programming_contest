#include  <iostream>
#include  <stdio.h>
#include <algorithm>
using namespace std;
#include <vector>
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

long long getKoyaku(long long a , long long b){
  long long r, tmp;
 
  /* 自然数 a > b を確認・入替 */
  if(a<b){
    tmp = a;
    a = b;
    b = tmp;
  }
 
  /* ユークリッドの互除法 */
  r = a % b;
  while(r!=0){
    a = b;
    b = r;
    r = a % b;
  }
 
  /* 最大公約数を出力 */
  //printf("最大公約数 = %d\n", b);
  return b;
}

int main(){

    int N;
    cin >> N;
    vector<int> val;

    int tmp;

    
    int count=0;
    for( int ni = 0 ; ni < N ; ni++ ){
        cin >> tmp;
        count+=tmp-1;
        val.push_back(tmp);

    }
    //cout << count;
    
    sort(val.begin(),val.end());

    long long kobai = 1;
    for( int ni = 0 ; ni < N ; ni++ ){
        kobai = kobai * val[ni] / getKoyaku(kobai,val[ni]);
    }

    long long ans = 0;
    for( int ni = 0 ; ni < N ; ni++ ){
        ans += (kobai - 1) % val[ni];
    }

    cout << ans << endl;
    
}
#include  <iostream>
#include  <stdio.h>
#include <algorithm>
using namespace std;
#include <vector>
//#include <stack>
//#include <queue>
#include <iomanip>

/*
#include <math.h>
int standerd = int(pow(10.0,9.0)) + 7;
*/
string ans_Yes = "Yes"; 
string ans_No = "No"; 
string ans_yes = "yes"; 
string ans_no = "no"; 
 
int main(){

    int N;
    long long K;
    cin >> N;
    cin >> K;

    int tmp;
    vector<int> va;
    for( int ni = 0 ; ni < N ; ni++ ){
        cin >> tmp;
        va.push_back(tmp);
    }

    int min_index=-1;
    long long cnt = 0;
    long long sum = 0;
    for( int ni = 0 ; ni < N ; ni++ ){
        int nni = min_index;
        while(sum < K ){
            nni++;
            if(nni >= N ) break;
            sum+= va[nni];
            min_index = nni;
        }

        if(nni >= N ) break;
        //cout << min_index << endl;
        sum -= va[ni];
        cnt += max(0,N-min_index);        
    }
    cout << cnt;

}
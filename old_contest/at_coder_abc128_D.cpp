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


int N_hoseki;
int K_sousa;

int main(){

    cin >> N_hoseki;
    cin >> K_sousa;

    int value[N_hoseki];
    vector<int> minus_value;


    for( int ni = 0 ; ni < N_hoseki ; ni++ ){
        cin >> value[ni];
    }

    int max_rindex;
    int max_lindex;
    int ans = 0;
    int getv;
    max_rindex = min(N_hoseki,K_sousa);
    for( int rget = 0 ; rget <= max_rindex ; rget++ ){
        max_lindex = min(K_sousa - rget, N_hoseki - rget);
        for( int lget = 0 ; lget <= max_lindex  ; lget++ ){
            getv = 0;
            minus_value.clear();

            for( int nr = 0 ; nr < rget ; nr++ ){
                getv += value[nr];
                if(value[nr]<0) minus_value.push_back(value[nr]);
            }
            int index;
            for( int nl = 0 ; nl < lget ; nl++ ){
                index = N_hoseki - 1 - nl;
                getv += value[index];
                if(value[index]<0) minus_value.push_back(value[index]);
            }

            sort(minus_value.begin(),minus_value.end());
            for( int nt = 0 ; nt < K_sousa - rget - lget ; nt++ ){
                if(minus_value.size()>0){
                    getv += -1 * minus_value[0];
                    minus_value.erase(minus_value.begin());
                }
            }
            //cout << getv << ":" << rget << "-" << lget << endl;
            if(ans < getv) ans = getv;
        }
    }

    cout << ans;



}
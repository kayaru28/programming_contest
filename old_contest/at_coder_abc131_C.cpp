#include  <iostream>
#include  <stdio.h>
#include <algorithm>
using namespace std;
#include <vector>
//#include <stack>
//#include <queue>

/*
#include <math.h>
long long standerd = long long(pow(10.0,9.0)) + 7;
*/
string ans_Yes = "Yes"; 
string ans_No = "No"; 
string ans_yes = "yes"; 
string ans_no = "no"; 

long long koyaku_max(long long a,long long b){
    long long r;
    r = a % b;
    while(r!=0){
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

long long kobai_min(long long a,long long b){
    long long tmp;
    tmp =  a / koyaku_max(a,b);
    return tmp * b;
}


int main(){

    long long A;
    long long B;
    long long C;
    long long D;
    cin >> A;
    cin >> B;
    cin >> C;
    cin >> D;
    long long CD;

    CD = kobai_min(C,D);

    long long maxvalue;
    long long minvalue;

    maxvalue = B - (B / C + B / D - B / CD );
    minvalue = (A-1) - ((A-1) / C + (A-1) / D - (A-1) / CD );

    //cout << CD << endl;
    //cout << maxvalue << endl;
    //cout << minvalue << endl;
    cout << maxvalue-minvalue << endl;

}
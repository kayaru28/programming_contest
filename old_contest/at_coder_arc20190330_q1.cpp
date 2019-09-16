#include  <iostream>
#include  <stdio.h>
using namespace std;


int main(){

    int A;
    int B;
    int C;

    cin >> A;
    cin >> B;
    cin >> C;
    string ans;

    ans = "No";

    if(A == B){
        if(A == C){
            ans = "Yes";
        }
    }
    cout << ans;
    return 0;
}
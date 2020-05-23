#include  <iostream>
#include  <stdio.h>
using namespace std;


int main(){

    int A,B,C;
    cin >> A;
    cin >> B;
    cin >> C;

    if(A < C && C < B){
        cout << "Yes";
    }else if(A > C && C > B){
        cout << "Yes";
    }else{
        cout << "No";
    }
}
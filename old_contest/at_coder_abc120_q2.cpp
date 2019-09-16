#include  <iostream>
#include  <stdio.h>
using namespace std;


int main(){

    int A;
    int B;
    int K;

    cin >> A;
    cin >> B;
    cin >> K;

    int count;
    count = 0;
    for(int i=101;i>0;i--){
        if(A % i==0){
            if(B % i==0){
                count = count + 1;
            }
        }
        if(count==K){
            cout << i;
            break;
        }
    }

    

}
#include  <iostream>
#include  <stdio.h>
using namespace std;


int main(){

    long K;
    long A;
    long B;
    long count2;
    long count;
    long base;

    base = 1000000000;
    count2 = 0;
    cin >> K;
    cin >> A;
    cin >> B;

    if( A > K ){
        cout << 1 + K;
    }else{
        if(B - A > 2){

            K = K - ( A - 1);
            count = A;
            if(K % 2 == 0){
                for(long ki =0; ki < int(K/2) ; ki++){
                    count = count + (B-A);
                    if(count > base){
                        count = count % base;
                        count2 = count2 + 1;
                    }
                }
            }else{
                for(long ki =0; ki < int((K-1)/2) ; ki++){
                    count = count + (B-A);
                    if(count > base){
                        count = count % base;
                        count2 = count2 + 1;
                    }
                }
                count = count + 1;
            }
            if(count2 > 0){
                cout << count2 << count;
            }else{
                cout << count;
            }
        }else{
            cout << 1 + K;
        }
    }

}
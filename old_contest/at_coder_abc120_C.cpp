#include  <iostream>
#include  <stdio.h>
using namespace std;


int main(){

    int lenS;
    string S;
    cin >> S;
    lenS = (int)(S.length()); 
    int count_0;
    int count_1;
    count_0 = 0;
    count_1 = 0;


    for(int i = 100; i < lenS; i++){
        if(S.substr(i,1)=="0"){
            count_0 = count_0 + 1;
        }else{
            count_1 = count_1 + 1;
        }
    }
    if(count_1 > count_0){
        cout << count_0 * 2;
    }else{
        cout << count_1 * 2;
    }

}
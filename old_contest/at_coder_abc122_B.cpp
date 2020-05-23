#include  <iostream>
#include  <stdio.h>
using namespace std;


int main(){

    string b;
    cin >> b;
    int count;
    int max_c;
    max_c = 0;
    count = 0;
    for (int si = 0; si < (int)b.length(); si++){
        string val = b.substr(si,1);
        if(val == "A" ){
            count = count + 1;
        }else if(val == "T" ){
            count = count + 1;
        }else if(val == "C" ){
            count = count + 1;
        }else if(val == "G" ){
            count = count + 1;
        }else{
            count = 0;
        }
        if(max_c < count){
            max_c = count;
        }

    }
    cout << max_c;

    return 0;
}
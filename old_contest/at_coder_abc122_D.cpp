#include  <iostream>
#include  <stdio.h>
using namespace std;
#include <math.h>

int standerd;

int calc(string s1,string s2,int stage,int N){
    if(stage == N){
        string s12;
        s12 = s1 + s2;
        if(s12=="AG"){
            return 3;
        }else if(s12=="AC"){
            return 3;
        }else if(s12=="GA"){
            return 3;
        }else{
            return 4;
        }
    }else{
        int ans;
        stage = stage + 1;
        if(s1 == "A"){
            if(s2 == "G"){
                ans=calc(s2,"A",stage,N)+calc(s2,"G",stage,N)+calc(s2,"T",stage,N);
                ans = ans % standerd;
                return ans;
            }else if(s2 == "C"){
                ans=calc(s2,"A",stage,N)+calc(s2,"C",stage,N)+calc(s2,"T",stage,N);
                ans = ans % standerd;
                return ans;
            }else{
                ans=calc(s2,"A",stage,N)+calc(s2,"G",stage,N)+calc(s2,"C",stage,N)+calc(s2,"T",stage,N);
                ans = ans % standerd;
                return ans;
            }
        }else if(s1 == "G"){
            if(s2 == "A"){
                ans=calc(s2,"A",stage,N)+calc(s2,"G",stage,N)+calc(s2,"T",stage,N);
                ans = ans % standerd;
                return ans;
            }else{
                ans=calc(s2,"A",stage,N)+calc(s2,"G",stage,N)+calc(s2,"C",stage,N)+calc(s2,"T",stage,N);
                ans = ans % standerd;
                return ans;
            }
        }else{
            ans=calc(s2,"A",stage,N)+calc(s2,"G",stage,N)+calc(s2,"C",stage,N)+calc(s2,"T",stage,N);
            ans = ans % standerd;
            return ans;
        }
    }
}


int main(){
    int N;
    cin >> N;
    standerd = int(pow(10.0,9.0)) + 7;


    string str1;
    int ans;
    ans = 0;

    str1 = "A";
    ans = ans + calc(str1,"A",3,N);
    ans = ans % standerd;
    ans = ans + calc(str1,"G",3,N);
    ans = ans % standerd;
    ans = ans + calc(str1,"C",3,N);
    ans = ans % standerd;
    ans = ans + calc(str1,"T",3,N);
    ans = ans % standerd;

    str1 = "G";
    ans = ans + calc(str1,"A",3,N);
    ans = ans % standerd;
    ans = ans + calc(str1,"G",3,N);
    ans = ans % standerd;
    ans = ans + calc(str1,"C",3,N);
    ans = ans % standerd;
    ans = ans + calc(str1,"T",3,N);
    ans = ans % standerd;

    str1 = "C";
    ans = ans + calc(str1,"A",3,N);
    ans = ans % standerd;
    ans = ans + calc(str1,"G",3,N);
    ans = ans % standerd;
    ans = ans + calc(str1,"C",3,N);
    ans = ans % standerd;
    ans = ans + calc(str1,"T",3,N);
    ans = ans % standerd;

    str1 = "T";
    ans = ans + calc(str1,"A",3,N);
    ans = ans % standerd;
    ans = ans + calc(str1,"G",3,N);
    ans = ans % standerd;
    ans = ans + calc(str1,"C",3,N);
    ans = ans % standerd;
    ans = ans + calc(str1,"T",3,N);
    ans = ans % standerd;

    cout << ans;
    return 0;
}
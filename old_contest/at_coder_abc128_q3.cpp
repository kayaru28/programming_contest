#include  <iostream>
#include  <stdio.h>
#include <algorithm>
using namespace std;
//#include <vector>
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
 

int countSwitch(int sw[],int status[][10],int N, int ni,int P[],int M){
    if(ni >= N){
//        cout << "count:" << ni << endl;
        for( int mi = 0 ; mi < M ; mi++ ){
            int sumv = 0;
            for( int nni = 0 ; nni < N ; nni++ ){
                sumv+= status[mi][nni] * sw[nni];
//                cout << sw[nni];
            }
//            cout << endl;
//            cout << sumv << endl;
            if(sumv%2!=P[mi]){
                return 0;
            }
        }
        return 1;
    }else{
        int count;
        sw[ni]=0;
        count = countSwitch(sw,status,N,ni+1,P,M);
        sw[ni]=1;
        count += countSwitch(sw,status,N,ni+1,P,M);
        return count;
    }
}

int main(){

    int N;

    cin >> N;

    int M;
    cin >> M;
    int k[M];
    int status[10][10]={};

    for( int mi = 0 ; mi < M ; mi++ ){
        cin >> k[mi];
        int val;
        for( int si = 0 ; si < k[mi] ; si++ ){
            cin >> val;
            status[mi][val-1]=1;
        }
    }

    int P[M];
    for( int pi = 0 ; pi < M ; pi++ ){
        cin >> P[pi];
    }

    int count=0;
    int sw[N];

    cout << countSwitch(sw,status,N,0,P,M);
    



    


}
#include  <iostream>
#include  <stdio.h>
using namespace std;


int main(){

    int a[6];
    int index;

    index = 0;
    cin >> a[index];
    index = index + 1;
    cin >> a[index];
    index = index + 1;
    cin >> a[index];
    index = index + 1;
    cin >> a[index];
    index = index + 1;
    cin >> a[index];
    index = index + 1;
    cin >> a[index];

    int cnt[4];
    index = 0;
    cnt[index]=0;
    index = index + 1;
    cnt[index]=0;
    index = index + 1;
    cnt[index]=0;
    index = index + 1;
    cnt[index]=0;
    
    index = 0;
    for(int i1 = 0;i1<6;i1++){
        if(a[i1]==1){
            cnt[index] = cnt[index] + 1;
        }
    }

    index = 1;
    for(int i1=0;i1<6;i1++){
        if(a[i1]==2){
            cnt[index] = cnt[index] + 1;
        }
    }

    index = 2;
    for(int i1=0;i1<6;i1++){
        if(a[i1]==3){
            cnt[index] = cnt[index] + 1;
        }
    }

    index = 3;
    for(int i1=0;i1<6;i1++){
        if(a[i1]==4){
            cnt[index] = cnt[index] + 1;
        }
    }

    int max_cnt,min_cnt;
    max_cnt = 0;
    min_cnt = 6;
    for(int i1=0;i1<4;i1++){
        if(cnt[i1] > max_cnt){
            max_cnt = cnt[i1];
        }
        if(cnt[i1] < min_cnt){
            min_cnt = cnt[i1];
        }

    }

    if(max_cnt < 3 && min_cnt >0){
        cout << "YES";
    }else{
        cout << "NO";
    }



}
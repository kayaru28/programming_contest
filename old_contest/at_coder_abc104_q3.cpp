#include  <iostream>
#include  <stdio.h>
#include <algorithm>
using namespace std;
#include <vector>
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

int Num_P;
int target;

int getMin(int flag[],int pi,int Num_Q[],int Comp_P[]){
    int tmp_min;
    if(pi==Num_P){
        int get_p=0;
        int count=0;
        for( int pi = 0 ; pi < Num_P ; pi++ ){
            count+= flag[pi] * Num_Q[pi];
            get_p+= flag[pi] * (Num_Q[pi] * (pi+1) * 100 + Comp_P[pi]);
        }
        if(get_p >= target) return count;
        else{
            int tmp_p=0;
            int tmp_num;
            for( int pi = 0 ; pi < Num_P ; pi++ ){
                if(tmp_p < (1-flag[pi])*(pi+1)*100){
                    tmp_p = (1-flag[pi])*(pi+1)*100;
                    tmp_num = Num_Q[pi] - 1;
                }
            }
            //cout << get_p <<" " << tmp_p << ":" << tmp_num << ":"    << endl;
            if(tmp_p==0) return 1000000;
            else if( (target - get_p) > (tmp_p * tmp_num) ) return 100000;
            else{
                //cout << count << endl;
                if((target - get_p) % tmp_p==0)
                    return (target - get_p) / tmp_p + count;
                else
                    return (target - get_p) / tmp_p + 1 + count;
            }
        }
    }else{
        flag[pi] = 1;
        tmp_min = getMin(flag,pi+1,Num_Q,Comp_P);
        flag[pi] = 0;
        return min(tmp_min,getMin(flag,pi+1,Num_Q,Comp_P));
    }

}


int main(){

    cin >> Num_P;
    cin >> target;
    int Num_Q[Num_P];
    int Comp_P[Num_P];

    int tmp;
    for( int qi = 0 ; qi < Num_P ; qi++ ){
        cin >> tmp;
        Num_Q[qi]=tmp;
        cin >> tmp;
        Comp_P[qi]=tmp;
    }
    int pi = 0;
    int flag[20]={};
    cout << getMin(flag,pi,Num_Q,Comp_P);
}
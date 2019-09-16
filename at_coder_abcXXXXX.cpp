#include  <iostream>
#include  <stdio.h>
using namespace std;

/*
#include <math.h>
int standerd = int(pow(10.0,9.0)) + 7;
*/
string ans_Yes = "Yes"; 
string ans_No = "No"; 
string ans_yes = "yes"; 
string ans_no = "no"; 
 

class BinaryTreeJudge {
public:
    virtual bool  evaluate(int target_value,int evaluated_value) = 0;
    virtual bool  nextDecition(int target_value,int evaluated_value) = 0;
};
class BinaryTreeJudgeEqual: public BinaryTreeJudge{
public:
    bool evaluate(int target_value,int evaluated_value){
        if(target_value==evaluated_value){
            return true;
        }else{
            return false;
        }
    }
    int  getNextIndex(int index_min,int index_max,int target_value,int evaluated_value){
        int index;
        index = ((index_max - index_min) + 1) / 2 ;
        if(target_value > evaluated_value){
            index = ( index  
        }else{

        }
        return index;            
    }

};
int BinaryTreeIndexSearch(int target_array[],int index,int target_value,BinaryTreeJudge judge){

    if(judge.evaluate( target_value, target_array[index])){
        return index;
    }else{

    }
}

int main(){

    int A_int;
    int B_int;
    
    cin >> A_int;
    cin >> B_int;

    BinaryTreeJudgeEqual btj_e;
    if( btj_e.evaluate(A_int,B_int)){
        cout << "true";
    }else{
        cout << "false";
    }

}
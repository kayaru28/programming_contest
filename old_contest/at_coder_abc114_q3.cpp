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
 
vector<int> val_list;

void createVal(int keta,int count,int val,string flag1,string flag2,string flag3){
    if(count==keta){
        if(flag1 + flag2 + flag3 == "111")    val_list.push_back(val);
    }else{
        count++;
        createVal(keta,count,val*10+7,"1",flag2,flag3);
        createVal(keta,count,val*10+5,flag1,"1",flag3);
        createVal(keta,count,val*10+3,flag1,flag2,"1");
    }
}

int main(){

    int N;
    cin >> N;

    int keta = to_string(N).length();
    if(N < 357){
        cout << 0;
    }else{
        for( int ni = keta ; ni >= 3  ; ni-- ){
            int val = 0;    
            int count = 0;
            createVal(ni,count,val,"","","");
        }

        while(val_list[0] > N) val_list.erase(val_list.begin());

        cout << val_list.size() << endl;
        
        //for( int ni = 0 ; ni < val_list.size() ; ni++ )  cout << val_list[ni] << endl;

        








    }

}
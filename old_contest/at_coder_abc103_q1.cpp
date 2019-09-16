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
 

int main(){

    vector<int> cost;
    int tmp;

    cin >> tmp;
    cost.push_back(tmp);
    cin >> tmp;
    cost.push_back(tmp);
    cin >> tmp;
    cost.push_back(tmp);

    sort(cost.begin(),cost.end());
    cout << cost[2]-cost[0];

    

}
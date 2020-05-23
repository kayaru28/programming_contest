#include  <iostream>
#include  <stdio.h>
using namespace std;


int main(){
    int N;
    int Q;
    string S;

    cin >> N;
    cin >> Q;
    cin >> S;


    int li;
    int ri;
    int count[Q];
    int pre_count[N];
    int flag;

    int si;
    pre_count[0]=0;
    string target;
    for(si=1;si< N;si++){
        target = S.substr(si - 1,2);
        pre_count[si] = pre_count[si - 1];
        if(target=="AC"){
            pre_count[si] = pre_count[si] + 1;
        }
     }
    for(int qi=0;qi<Q;qi++){
        cin >> li;
        cin >> ri;
        li = li - 1;
        ri = ri - 1;
        count[qi] = pre_count[ri] - pre_count[li];
    }

    for(int qi=0;qi<Q;qi++){
        cout << count[qi] << endl;
    }
    return 0;
}
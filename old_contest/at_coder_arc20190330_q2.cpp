#include  <iostream>
#include  <stdio.h>
using namespace std;
#include <map>

int main(){

    int N;
    int Q;
    cin >> N;
    cin >> Q;

    string s;
    cin >> s;

    char t[Q];
    char d[Q];
    
    for(int qi = 0; qi < Q ; qi++){
        cin >> t[qi];
        cin >> d[qi];
    }

    map<string, int> start_alpha;

    start_alpha["a"] = 0;


    return 0;
}
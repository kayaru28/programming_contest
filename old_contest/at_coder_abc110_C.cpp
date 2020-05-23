#include <iostream>
#include <stdio.h>
#include <unordered_map>

using namespace std;

int main(){

    string S;
    string T;
    string tmp;
    string tmp2;
    string ans;

    unordered_map<string, int> mp_S;
    unordered_map<string, int> mp_T;

    cin >> S;
    cin >> T;
 
    int num_C;
    int si = 0;

    ans = "Yes";
    num_C = 1;

    tmp = S[si];
    mp_S[tmp] = num_C;
    tmp = T[si];
    mp_T[tmp] = num_C;
    num_C++;
    for( si = 1 ; si < S.length() ; si++ ){
        tmp  = S[si];
        tmp2 = T[si];
        auto itr  = mp_S.find(tmp);        // "xyz" が設定されているか？
        auto itr2 = mp_T.find(tmp2);        // "xyz" が設定されているか？
        if( itr != mp_S.end() || itr2 != mp_T.end() ) {
            //設定されている場合の処理
            if( mp_S[tmp] != mp_T[tmp2]  ){
                ans = "No";
                   break;
            }

        } else {
            //設定されていない場合の処理
            mp_S[tmp] = num_C;
            mp_T[tmp2] = num_C;
            num_C++;
        }
    }

    cout << ans;

    return 0;
}
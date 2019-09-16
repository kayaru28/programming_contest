#include<iostream>
using namespace std;



int main(){
    int N;
    int size;
    string W[100];
    string ans;
    string tar_word;
    string bef_word;


    cin >> N;
    cin >> W[0];

    ans = "Yes";

    for(int n = 1 ; n < N ; n++ ){

        cin >> W[n];

        tar_word = W[n];
        bef_word  = W[n - 1];
        size      = bef_word.size() - 1;

        if (bef_word[size] != tar_word[0] ){
            ans = "No";
            cout << ans;
            return 0;
        }
        for(int nn = 0 ; nn < n ; nn++){
            bef_word = W[nn];
            if (bef_word == tar_word ){
                ans = "No";
                cout << ans;
                return 0;
            }
        }
    }



    cout << ans;
    return 0;
}
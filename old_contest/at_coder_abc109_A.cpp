#include<iostream>
using namespace std;

int main(){
    int A;
    int B;
    string ans;

    cin >> A;
    cin >> B;

    ans = "Yes";

    if ( A == 2 ) ans = "No";
    else if ( B == 2 ) ans = "No";

    cout << ans;



    return 0;
}
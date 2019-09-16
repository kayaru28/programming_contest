#include  <iostream>
#include  <stdio.h>
using namespace std;


int main(){

    int H;
    int W;
    int h;
    int w;
    
    cin >> H;
    cin >> W;
    cin >> h;
    cin >> w;

    cout << H * W - ( H * w + W * h - h * w);
    

}
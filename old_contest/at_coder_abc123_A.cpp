#include  <iostream>
#include  <stdio.h>
using namespace std;


int main(){

    int dist[5];
    int number;
    number = 0;
    cin >> dist[number];
    number = number + 1;
    cin >> dist[number];
    number = number + 1;
    cin >> dist[number];
    number = number + 1;
    cin >> dist[number];
    number = number + 1;
    cin >> dist[number];

    int k;
    cin >> k;

    if(dist[4]-dist[0]>k){
        cout << ":(";
    }else{
        cout << "Yay!";
    }
}
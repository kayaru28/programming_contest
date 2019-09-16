#include  <iostream>
#include  <stdio.h>
#include  <math.h>
using namespace std;

int A;
int B;
int C;
int N;

int fuctrical(int x){

    if(x <= 1){
        return 1;
    }else{
        return x * fuctrical(x-1);
    }
}
int nCr(int n,int r){
    int ans;
    ans = fuctrical(n);
    ans = ans / fuctrical(r);
    ans = ans / fuctrical(n-r);
    return ans;
}

int get_cost(int l[],int assign[]){
    int length[3];
    int cost = 0;
    for( int li = 0 ; li < 3 ; li++ ){
        length[li] = 0;
    }

    int number;
    for( int ni = 0 ; ni < N ; ni++ ){
        number = assign[ni];
        if(number < 3){
            if(length[number]>0){
                cost = cost + 10;
            }
            length[number] = length[number] + l[ni];
        }
    }
    
    for( int li = 0 ; li < 3 ; li++ )
        if(length[li] == 0) length[li] = 1000000;


    number = 0;
    cost = cost + abs(A - length[number]);
    number = 1;
    cost = cost + abs(B - length[number]);
    number = 2;
    cost = cost + abs(C - length[number]);

    /*
    for( int ni = 0 ; ni < N ; ni++ )
        cout << assign[ni] << " : ";
    cout << " = "<< cost << endl;
    */
    return cost;

}

int calc_cost(int l[],int assign[],int ni){
    int cost;
    int tmp_cost;
    cost = 100000;
    if(ni == N){
        return get_cost(l,assign);
    }else{
        for( int ai = 0 ; ai < 4 ; ai++ ){
            assign[ni] = ai;
            tmp_cost = calc_cost(l,assign,ni+1);
            if( tmp_cost < cost ){
                cost = tmp_cost;
            }
        }
        return cost;
    }
}

int main(){

    cin >> N;
    int cost=10000;

    cin >> A;
    cin >> B;
    cin >> C;

    int l[N];
    int assign[N];
    
    for( int ni = 0 ; ni < N ; ni++ ){
        cin >> l[ni];
        assign[ni] = 0;
    }
    
    cost = calc_cost(l,assign,0);

    cout << cost;

}
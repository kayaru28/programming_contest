#include<iostream>
#include  <stdio.h>
using namespace std;

int H;
int W;
int K;


int goAhead(int left_H,int x_H,int x_W,int point[][],int max_W){

    int toosa;
    int tmp_W;
    int tmp_H;
    int d_W;

    toosa = abs( K - x_W );


    if( toosa - left_H == 0 ){
        d_W = ( K - x_W ) / toosa; //近づく
        tmp_W = x_W;
        tmp_H = x_H;
        while (1) {

            tmp_H = tmp_H + 1;

            point[tmp_W - 1][tmp_H] = 0;
            point[tmp_W + 1][tmp_H] = 0;

            tmp_W = tmp_W + d_W;
            point[tmp_W + d_W][tmp_H] = 0;

            if(tmp_H == H){
                count_up(point);
            }
        }
    }else if( toosa -left_H > 1 ){
        if(K!=x_W){

            d_W = ( K - x_W ) / toosa; //近づく
            tmp_W = x_W;
            tmp_H = x_H;

            tmp_H = tmp_H + 1;
            point[tmp_W][tmp_H] = 0;

            tmp_W = tmp_W + d_W;
            point[tmp_W + d_W][tmp_H] = 0;

            if(d_W < 0){
                point[tmp_W + d_W -1 ][tmp_H] = 0;
            }else{
                point[tmp_W - 1 ][tmp_H] = 0;
            }
            goAhead(left_H,x_H,x_W,point,max_W)        
        }

        d_W = 0;
        tmp_W = x_W;
        tmp_H = x_H;

        tmp_H = tmp_H + 1;

        point[tmp_W - 1][tmp_H] = 0;

        tmp_W = tmp_W + d_W;
        point[tmp_W + d_W][tmp_H] = 0;

        goAhead(left_H,x_H,x_W,point,max_W)        


        if( toosa -left_H > 2 ){
            x_W = x_W + ( x_W - K ) / toosa;
        }
    }



}



int main(){


    cin >> H;
    cin >> W;
    cin >> K;

    int point[W + 2][H + 1];

    for( int w = 1 ; w <= W ; w++ ){
        for( int h = 1 ; h <= H ; h++ ){
            point[w][h] = 1;
        }
    }

    for( int max_W = 1 + 1; max_W <= W; max_W++ ){
        if(max_W > H) break;



    }

    return 0;
}   
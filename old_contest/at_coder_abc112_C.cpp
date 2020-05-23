#include<iostream>
#include  <stdio.h>
using namespace std;

int main(){

    int N;

    cin >> N;

    int xi[N];
    int yi[N];
    int hi[N];
    int hii;
    int Cx;
    int Cy;
    int H;
    int Cxi;
    int Cyi;
    int n;

    for( n = 0 ; n < N ; n++ ){

        cin >> xi[n];
        cin >> yi[n];
        cin >> hi[n];
    }

    if( N == 1 ){
        Cx = xi[0];
        Cy = yi[0];
        H  = hi[0];
    }else{
        int i_start;
        int i_end;
        int i;


        i_start = 0;
        i_end   = N - 1;

        int hiii;
        int flag;
        H = 0;
        for(Cxi = 0 ; Cxi <= 100 ; Cxi++){
            for(Cyi = 0; Cyi <= 100 ; Cyi++){


                    n    = 0;
                    hii  = hi[n] + abs(xi[n] - Cxi) + abs(yi[n] - Cyi);
                    hiii = hii;
                    flag = 1;
                    for(n = 1 ; n < N ; n++){
                        if(hi[n] != 0){

                            hii  = hi[n] + abs(xi[n] - Cxi) + abs(yi[n] - Cyi);
                            if(hiii != hii){
                                flag = 0;
                                break;
                            }
                        }

                    }

                    if( H < hiii * flag ){
                        H  = hiii;
                        Cx = Cxi;
                        Cy = Cyi;
                    }


            }
        }



    }




    cout << Cx;
    cout << " ";
    cout << Cy;
    cout << " ";
    cout << H;


}
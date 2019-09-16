#include  <iostream>
#include  <stdio.h>
using namespace std;




int main(){

    int N;
    string S;
    cin >> N;
    cin >> S;

    string tmp;
    int ni;

    ni = N - 1;
    tmp = S.substr(ni,1);
    int length;
    
    if(tmp == "#"){
        while(tmp == "#"){
            ni = ni - 1;
            if(ni >= 0){
                tmp = S.substr(ni,1);
            }else{
                tmp = "";
            }
        }
    }

    if(ni < 0){
        // all black
        cout << 0;
    }else{
        int ne;
        ne = 0;
        tmp = S.substr(ne,1);
        while(tmp == "."){
            ne = ne + 1;
            if(ne <= ni){
                tmp = S.substr(ne,1);
            }else{
                tmp = "";
            }
        }

        if(ne >= ni){
            //all white or white black
            cout << 0;
        }else{

            length = ni + 1 - ( ne + 1 ) + 1 ;
            int count_bk[N];
            int count_wh[N];
            tmp = S.substr(ne,1);
            if(tmp=="#"){
                count_bk[ne]=1;
                count_wh[ne]=0;
            }else{
                count_bk[ne]=0;
                count_wh[ne]=1;
            } 
            for( int nni = ne + 1 ; nni <= ni ; nni++ ){
                tmp = S.substr(nni,1);
                if(tmp=="#"){
                    count_bk[nni]=count_bk[nni-1] + 1;
                    count_wh[nni]=count_wh[nni-1];
                }else{
                    count_bk[nni]=count_bk[nni-1];
                    count_wh[nni]=count_wh[nni-1] + 1;
                } 
            }
            int min;
            int count;
            //cout << ne << ":" << ni << endl;
            min = count_wh[ni];
            for( int nni = ne; nni <= ni ; nni++ ){
                count = count_bk[nni] + ( count_wh[ni] - count_wh[nni]);
                //cout << count << endl;
                if(min > count){
                    min = count;
                }
            }
            cout << min;
            
        }
    }
}
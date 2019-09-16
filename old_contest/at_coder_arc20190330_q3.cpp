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

    map<string, int> start_alpha;
    map<string, int> end_alpha;

    int number;
    number = -1;
    start_alpha["A"] = number;
    start_alpha["B"] = number;
    start_alpha["C"] = number;
    start_alpha["D"] = number;
    start_alpha["E"] = number;
    start_alpha["F"] = number;
    start_alpha["G"] = number;
    start_alpha["H"] = number;
    start_alpha["I"] = number;
    start_alpha["J"] = number;
    start_alpha["K"] = number;
    start_alpha["L"] = number;
    start_alpha["M"] = number;
    start_alpha["N"] = number;
    start_alpha["O"] = number;
    start_alpha["P"] = number;
    start_alpha["Q"] = number;
    start_alpha["R"] = number;
    start_alpha["S"] = number;
    start_alpha["T"] = number;
    start_alpha["U"] = number;
    start_alpha["V"] = number;
    start_alpha["W"] = number;
    start_alpha["X"] = number;
    start_alpha["Y"] = number;
    start_alpha["Z"] = number;

    end_alpha["A"] = number;
    end_alpha["B"] = number;
    end_alpha["C"] = number;
    end_alpha["D"] = number;
    end_alpha["E"] = number;
    end_alpha["F"] = number;
    end_alpha["G"] = number;
    end_alpha["H"] = number;
    end_alpha["I"] = number;
    end_alpha["J"] = number;
    end_alpha["K"] = number;
    end_alpha["L"] = number;
    end_alpha["M"] = number;
    end_alpha["N"] = number;
    end_alpha["O"] = number;
    end_alpha["P"] = number;
    end_alpha["Q"] = number;
    end_alpha["R"] = number;
    end_alpha["S"] = number;
    end_alpha["T"] = number;
    end_alpha["U"] = number;
    end_alpha["V"] = number;
    end_alpha["W"] = number;
    end_alpha["X"] = number;
    end_alpha["Y"] = number;
    end_alpha["Z"] = number;



    string target;
    int masu[N];
    int masu_f[N];
    int next_masu[N];
    int bef_masu[N];
    for(int si = 0; si < N; si ++){


        int sii;
        sii = N - si - 1;
        
        masu[sii] = 1;
        masu_f[sii] = 1;
        bef_masu[sii] = -1;

        target = s.substr(sii,1);
        if(start_alpha[target] == -1){
            next_masu[sii] = -1;
        }else{
            next_masu[sii] = start_alpha[target];
            bef_masu[next_masu[sii]]  = sii;
        }

        if(end_alpha[target]== -1){
            end_alpha[target] = sii;
        }
        start_alpha[target] = sii;
    }


    string t[Q];
    string d[Q];
    
    int move;
    int mi;
    int left;
    left = N;
    for(int qi = 0; qi < Q ; qi++){
        cin >> t[qi];
        cin >> d[qi];
    }
    for(int qi = 0; qi < Q ; qi++){
        if(d[qi] == "L"){
            if(start_alpha[t[qi]]>-1){
                move = -1;
                mi = start_alpha[t[qi]];
                if(mi==0){
                    //cout << masu[mi]<<endl;
                    left = left - masu[mi];
                    //masu_f[mi]=0;
                    masu[mi]=0;
                    mi = next_masu[mi];
                }
                while(mi > -1){
                    //masu_f[mi+move] = masu_f[mi+move]+masu[mi];
                    //masu_f[mi] = 0;
                    masu[mi+move] = masu[mi+move]+masu[mi];
                    masu[mi] = 0;
                    mi = next_masu[mi];
                }
            }
        }else{
            if(end_alpha[t[qi]]>-1){
                move = 1;
                mi = end_alpha[t[qi]];
                if(mi==N-1){
                    left = left - masu[mi];
                    masu[mi]=0;
                    mi = bef_masu[mi];
                }
                while(mi > -1){
                    masu[mi+move] = masu[mi+move]+masu[mi];
                    masu[mi] = 0;
                    mi = bef_masu[mi];
                }
            }
            /*
            for(int si=0; si <N;si++){
                masu[si] = masu_f[si];
            }
            */
        }
        /*
        for(int si=0; si <N;si++){
            cout << masu[si];
        }
        cout <<endl;
        */
    }
    cout << left;

    return 0;
}
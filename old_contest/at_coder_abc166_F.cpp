#include  <iostream>
#include  <stdio.h>
#include <algorithm>
using namespace std;
#include <vector>
#define rep(i,n) for (int i = 0; i < (n) ; i++)
#define INF 1e9
#define llINF 1e18
#define MOD 1000000007
#define pb push_back
#define ll long long
#define ull unsigned long long
#define vint vector<int>
#define vll vector<ll>

//#include <stack>
//#include <queue>

/*
#include <math.h>
int standerd = int(pow(10.0,9.0)) + 7;
*/
string ans_Yes = "Yes"; 
string ans_No = "No"; 
string ans_yes = "yes"; 
string ans_no = "no"; 

ll ABC[4];
ll N;
ll A;
ll B;
ll C;

int main(){

    
    cin >> N;
    cin >> A;
    cin >> B;
    cin >> C;
    ABC[0]=A;
    ABC[1]=B;
    ABC[2]=C;
    string VAL[4];
    VAL[0]="A";
    VAL[1]="B";
    VAL[2]="C";

    string flag="Yes";
    vector<string> ans;
    vector<string> ss;
    string sentaku;
    int index1;
    int index2;
    if(A==0&&B==0&&C==0){
        cout << "No" << endl;
    }else{
        rep(ni,N){
            cin >> sentaku;
            ss.push_back(sentaku);
        }
        rep(ni,N){
            sentaku=ss[ni];
            if(sentaku=="AB"){
                index1=0;
                index2=1;
            } else if(sentaku=="BC"){
                index1=1;
                index2=2;
            } else{
                index1=0;
                index2=2;
            }

            if(ABC[index1]==0&&ABC[index2]==0){
                flag="No";
                break;
            }else if(ABC[index1]==1&&ABC[index2]==1&&ni+1<N){
                if(ss[ni+1].substr(0,1)==VAL[index1]){
                    if(ss[ni+1].substr(1,1)==VAL[index2]){
                        ABC[index1]--;
                        ABC[index2]++;
                        ans.push_back(VAL[index2]);
                    }else{
                        ABC[index2]--;
                        ABC[index1]++;
                        ans.push_back(VAL[index1]);

                    }
                }else if(ss[ni+1].substr(1,1)==VAL[index1]){
                    ABC[index2]--;
                    ABC[index1]++;
                    ans.push_back(VAL[index1]);
                }else{
                    ABC[index1]--;
                    ABC[index2]++;
                    ans.push_back(VAL[index2]);
                }
            }else{
                if(ABC[index1]>=ABC[index2]){
                    ABC[index1]--;
                    ABC[index2]++;
                    ans.push_back(VAL[index2]);
                }else{
                    ABC[index2]--;
                    ABC[index1]++;
                    ans.push_back(VAL[index1]);
                }
            }

        }
        cout << flag << endl;
        if(flag=="Yes"){
            rep(ni,ans.size()){
                cout << ans[ni] << endl;
            }
        }
    }
}
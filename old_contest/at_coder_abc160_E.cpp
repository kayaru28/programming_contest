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

void quickSortIndex(int value[ ],int index[], int left_i, int right_i);
void quickSwap(int x[ ], int i, int j);
void quickSortIndex(int value[ ],int index[], int left_i, int right_i)
{
    int li, ri;
    int pivot;
    li = left_i;
    ri = right_i;
    pivot = value[index[(left_i + right_i) / 2]]; /* 基準値を配列の中央付近にとる */
    while (1) {
        while (value[index[li]] < pivot)       /* pivot より大きい値が */
            li++;                   /* 出るまで i を増加させる */
        while (pivot < value[index[ri]])       /* pivot より小さい値が */
            ri--;                   /*  出るまで j を減少させる */
        if (li >= ri)                /* i >= j なら */
            break;                 /* 無限ループから抜ける */
        quickSwap(index, li, ri);
        li++;                       /* 次のデータ */
        ri--;
    }
    if (left_i < li - 1)              /* 基準値の左に 2 以上要素があれば */
        quickSortIndex(value, index, left_i, li - 1);    /* 左の配列を Q ソートする */
    if (ri + 1 <  right_i)            /* 基準値の右に 2 以上要素があれば */
        quickSortIndex(value, index,ri + 1, right_i);    /* 右の配列を Q ソートする */
}
/* 配列の要素を交換する */
void quickSwap(int x[ ], int i, int j)
{
    int temp;
    temp = x[i];
    x[i] = x[j];
    x[j] = temp;
}

int R=0;
int G=1;
int K=2;
int X,Y,A,B,C;
int color[1000000];
int index[1000000];
int taste[1000000];

int main(){
    cin >> X >> Y >> A >> B >> C;
    int N = A + B + C;
    int value;
    int cnt=0;
    rep(ni,A){
        index[cnt]=cnt;
        color[cnt]=R;
        cin >> value;
        taste[cnt]=value;
        cnt++;
    }
    rep(ni,B){
        index[cnt]=cnt;
        color[cnt]=G;
        cin >> value;
        taste[cnt]=value;
        cnt++;
    }
    rep(ni,C){
        index[cnt]=cnt;
        color[cnt]=K;
        cin >> value;
        taste[cnt]=value;
        cnt++;
    }
    
    ll ans = 0;
    int cntR = 0;
    int cntG = 0;
    int cntK = 0;
    int cntAll = 0;
    quickSortIndex(taste,index,0,N-1);
    int ni = 0;
    while(cntAll<X+Y){
        int ii =  index[(N-1) -ni];
        if(color[ii]==R){
            if(cntR<X){
                cntR = cntR + 1;
                cntAll = cntAll + 1;
                ans = ans + taste[ii];
            }
        }else if(color[ii]==G){
            if(cntG<Y){
                cntG = cntG + 1;
                cntAll = cntAll + 1;
                ans = ans + taste[ii];
            }
        }else if(color[ii]==K){
            cntAll = cntAll + 1;
            ans = ans + taste[ii];
        }
        ni++;
        //cout << ans << endl;
    }

    cout << ans << endl;

}
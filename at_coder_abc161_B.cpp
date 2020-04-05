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

double M;
ll N;

void quickSort(int x[ ], int left_i, int right_i);
void quickSwap(int x[ ], int i, int j);
void quickSort(int x[ ], int left_i, int right_i)
{
    int li, ri;
    int pivot;
    li = left_i;
    ri = right_i;
    pivot = x[(left_i + right_i) / 2]; /* 基準値を配列の中央付近にとる */
    while (1) {                    /* 無限ループ */
        while (x[li] < pivot)       /* pivot より大きい値が */
            li++;                   /* 出るまで i を増加させる */
        while (pivot < x[ri])       /* pivot より小さい値が */
            ri--;                   /*  出るまで j を減少させる */
        if (li >= ri)                /* i >= j なら */
            break;                 /* 無限ループから抜ける */
        quickSwap(x, li, ri);             /* x[i] と x[j]を交換 */
        li++;                       /* 次のデータ */
        ri--;
    }
    if (left_i < li - 1)              /* 基準値の左に 2 以上要素があれば */
        quickSort(x, left_i, li - 1);    /* 左の配列を Q ソートする */
    if (ri + 1 <  right_i)            /* 基準値の右に 2 以上要素があれば */
        quickSort(x, ri + 1, right_i);    /* 右の配列を Q ソートする */
}
/* 配列の要素を交換する */
void quickSwap(int x[ ], int i, int j)
{
    int temp;
    temp = x[i];
    x[i] = x[j];
    x[j] = temp;
}

int main(){


    cin >> N;
    cin >> M;
    double sum=0;

    int A[N];

    rep(ni,N){
        cin >> A[ni];
        sum+=A[ni]/ 4.0 / M  ;
    }
    quickSort(A,0,N-1);

    //cout << A[N-1-(M-1)] << endl;
    if(A[N-1-(int(M)-1)]< sum){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;

    }
    

}
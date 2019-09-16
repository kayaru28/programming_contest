#include  <iostream>
#include  <stdio.h>
#include <algorithm>
using namespace std;
#include <vector>
//#include <stack>
//#include <queue>

/*
#include <math.h>
long long standerd = long long(pow(10.0,9.0)) + 7;
*/
string ans_Yes = "Yes"; 
string ans_No = "No"; 
string ans_yes = "yes"; 
string ans_no = "no"; 

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


int main(){

    int N;
    cin >> N;
    int A[N];
    int B[N];
    int index[N];
    for( int ni = 0 ; ni < N ; ni++ ){
        cin >> A[ni];
        cin >> B[ni];
        index[ni] = ni;
    }
    
    quickSortIndex(B,index,0,N-1);

    int nowtime = 0;
    bool flag = true;
    int bi;
    for( int ni = 0 ; ni < N ; ni++ ){
        bi = index[ni];
        nowtime+=A[bi];
        if(nowtime>B[bi]) flag = false;
    }
    if(flag) cout << ans_Yes << endl;
    else cout << ans_No << endl;
}
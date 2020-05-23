#include  <iostream>
#include  <stdio.h>
using namespace std;
#include  <iomanip>
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

int main(){

    int N;
    int M;
    
    cin >> N;
    cin >> M;

    int A[N];
    int B[N];
    int index[N];
    for( int ni = 0 ; ni < N ; ni++ ){
        cin >> A[ni];
        cin >> B[ni];
        index[ni] = ni;
    }
    quickSortIndex(A,index,0,N-1);

    int count = 0;
    int cost = 0;
    int cost_2 = 0;
    int ii = -1;
    int abi;
    int standerd = 100000000;
    int bi;
    int plus;
    while(count < M)
    {
        ii  = ii + 1;
        abi = index[ii];
        bi  = 0;
        while(count < M && bi < B[abi]){
            count = count + 1;
            cost  = cost + A[abi];
            //cout << cost << endl;
            //cout << cost_2 << endl;
            if(cost >= standerd)
            {
                plus   = cost / standerd;
                cost_2 = cost_2 + plus;
                cost   = cost - standerd * plus;
            }
            bi = bi + 1;
        }
    }
    if(cost_2 > 0){
        cout << cost_2;
        cout.fill('0');
        cout << setw(8);
    }
    cout << cost;
}


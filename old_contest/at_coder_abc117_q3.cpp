#include<iostream>
#include  <stdio.h>
#include <cstdlib>
using namespace std;

void QSort(int x[ ], int left, int right);
void Swap(int x[ ], int i, int j);

void QSort(int x[ ], int left, int right)
{
    int i, j;
    int pivot;

    i = left;                      /* ソートする配列の一番小さい要素の添字 */
    j = right;                     /* ソートする配列の一番大きい要素の添字 */

    pivot = x[(left + right) / 2]; /* 基準値を配列の中央付近にとる */

    while (1) {                    /* 無限ループ */

        while (x[i] < pivot)       /* pivot より大きい値が */
            i++;                   /* 出るまで i を増加させる */

        while (pivot < x[j])       /* pivot より小さい値が */
            j--;                   /*  出るまで j を減少させる */
        if (i >= j)                /* i >= j なら */
            break;                 /* 無限ループから抜ける */

        Swap(x, i, j);             /* x[i] と x[j]を交換 */
        i++;                       /* 次のデータ */
        j--;
    }
    //ShowData(x, 10);               /* 途中経過を表示 */

    if (left < i - 1)              /* 基準値の左に 2 以上要素があれば */
        QSort(x, left, i - 1);     /* 左の配列を Q ソートする */
    if (j + 1 <  right)            /* 基準値の右に 2 以上要素があれば */
        QSort(x, j + 1, right);    /* 右の配列を Q ソートする */
}

  /* 配列の要素を交換する */
void Swap(int x[ ], int i, int j)
{
    int temp;

    temp = x[i];
    x[i] = x[j];
    x[j] = temp;
}

  /* n 個のデータを表示する */
void ShowData(int x[ ], int n)
{
    int i;

    for (i = 0; i < n ; i++)
        printf("%d  ", x[i]);
    printf("\n");
}


int main(){

    int N;
    int M;

    cin >> N;
    cin >> M;

    int X[M];
    int L[M-1];
    int i_start;
    int i_end;

    for(int n = 0 ; n < M ; n++ ) cin >> X[n];
    i_start = 0;
    i_end   = M - 1;
    QSort(X, i_start, i_end);

    for(int n = 0 ; n < M - 1; n++ ){
        L[n] = X[n+1] - X[n];
    }
    i_start = 0;
    i_end   = M - 2;
    QSort(L, i_start, i_end);

    int ans;
    ans = 0;
    for(int n = 0 ; n < M - 1 - ( N - 1 ) ; n++ ) ans = ans + L[n];

    cout << ans;
    return 0;
}
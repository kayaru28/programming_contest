#include<iostream>
#include  <stdio.h>
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
    int num_city;
    int x_start;
    int i_start;
    int i_end;
    int d;
    int d_start;
    int bet;
    int y;
    int y_start;
    int i;
    int ans;

    cin >> num_city;
    cin >> x_start;

    int x[num_city];
    for(int n = 0 ; n < num_city ; n++ ) cin >> x[n];
    i_start = 0;
    i_end   = num_city - 1;
    QSort(x, i_start, i_end);

    d_start = 1000000000;
    if( x[i_start] < x_start ){
        d_start = x_start - x[i_start] ;
    }

    if( x[i_end]   > x_start ){
        bet = x[i_end] - x_start;
        if( d_start > bet ) d_start = bet ;
    }

     ans = 0;

    if(num_city == 1){
        if(x[i_start] > x_start) d = x[i_start] - x_start;
        else if(x[i_start] < x_start) d = x_start - x[i_start] ;
        ans = d;
        cout << ans;
        return 0;
    }

 
    y_start = x[i_start];

    for( d = d_start ; d > 0 ; d-- ){
        i = i_start;
        y = y_start;
        while(1){
            if ( x[i] < y ){
                //next d length
                break;
            }
            else if ( x[i] == y ){
                //next city
                //cout << "next_city" << endl;
                i = i + 1;
                if( i == num_city ){
                    ans = d;
                    cout << ans;
                    return 0;
                }
            }
            //next point
            y = y + d;
        }
    }

    cout << ans;
    return 0;
}
#include  <iostream>
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

int min(int a,int b)
{
    int ans;
    ans = a;
    if(b < a){
        ans = b;
    }
    return b;

}

int main(){

    int N;
    int M;

    cin >> N;
    cin >> M;
    int A[M]; 
    int AA[M]; 
    int AAA[M]; 
    int tmpA;
    
    for(int i = 0 ;i < M;i++){
        cin >> AA[i];
        switch (AA[i]) {
            case 1:
                A[i] = 2;
                break;
            case 2:
                A[i] = 5;
                break;
            case 3:
                A[i] = 5;
                break;
            case 4:
                A[i] = 4;
                break;
            case 5:
                A[i] = 5;
                break;
            case 6:
                A[i] = 6;
                break;
            case 7:
                A[i] = 3;
                break;
            case 8:
                A[i] = 7;
                break;
            case 9:
                A[i] = 6;
                break;
        } 
        AAA[i] = A[i];       
    }

    QSort(A, 0, M-1);

    int Acount;
    Acount = 0;
    tmpA = 0;
    for(int i = 0 ;i < M;i++){
        if(tmpA!=A[i]){
            tmpA = A[i];
            Acount = Acount + 1;
        }
    }
    int MAX[8];
    for(int i = 0 ; i < 8; i++){
        MAX[i] = 0;
    }

    int NUM[10];
    for(int i = 0 ; i < 10; i++){
        NUM[i] = 0;
    }

    for(int i = 0 ;i < M;i++){
        if(MAX[AAA[i]] < AA[i]){
            MAX[AAA[i]] = AA[i];
        }
    }


    int number[Acount];
    int numcount;
    numcount = 0;
    tmpA = 0;
    for(int i = 0 ;i < M;i++){
        if(tmpA!=A[i]){
            tmpA = A[i];
            number[numcount] = tmpA;
            numcount = numcount + 1;
        }
    }


    int keta;
    int ketanum[Acount];
    keta = 0;
    int left;
    left = N;
    for(int i = 0 ; i < Acount; i++){
        ketanum[i] = 0;
    }
    do{
        for(int i = 0 ; i < Acount; i++){
            if(left - number[i] > number[i])
            {
                ketanum[i] = ketanum[i] + 1;
                left = left - number[i];
                break;
            }
            if(left - number[i] == 0)
            {
                ketanum[i] = ketanum[i] + 1;
                left = left - number[i];
                break;
            }
        }
    }while(left != 0);

    for(int i = 0 ; i < Acount; i++){
        NUM[MAX[number[i]]] = ketanum[i];
    }
    for(int i = 0 ; i < 9; i++){
        int index;
        index = 9 - i;
        for (int j=0 ; j <NUM[index];j++ ){
            cout << index;
        }
    }
    /*
    int i_MAX;
    int target;
    i_MAX = Acount;
    for(int i = 0 ; i < i_MAX; i++){
        target = ketanum[i];
        cout << target << endl;
    }
    */

}
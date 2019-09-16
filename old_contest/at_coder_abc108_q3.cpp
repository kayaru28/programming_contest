    #include  <iostream>
    #include  <stdio.h>
    #include <algorithm>
    #include <vector>
    //#include <stack>
    //#include <queue>

    #include <math.h>
    /*
    int standerd = int(pow(10.0,9.0)) + 7;
    */
    using namespace std;
    string ans_Yes = "Yes"; 
    string ans_No = "No"; 
    string ans_yes = "yes"; 
    string ans_no = "no"; 
    

    int main(){
        int N,K;
        cin >> N;
        cin >> K;

        double count=0.0;
        long long abc_count=0;
        long long abc_count2=0;



        //abc_count = N / K ;
        for(int i=K; i<=N; i+=K) abc_count++;
        count += pow(abc_count,3);
        //count += abc_count * max(0,(abc_count - 1)) * 3;
        //count += abc_count * max(0,(abc_count - 1))  * max(0,(abc_count - 2));

        if(K % 2 == 0){

            for(int i=K/2; i<=N; i+=K) abc_count2++;
            //abc_count = N/(K/2) - abc_count;
            //count += abc_count;
            //count += abc_count * max(0,(abc_count - 1)) * 3;
            //count += abc_count * max(0,(abc_count - 1))  * max(0,(abc_count - 2));
            count += pow(abc_count2,3);

        }
        cout << abc_count2 * abc_count2 * abc_count2 + abc_count * abc_count * abc_count;    

    }
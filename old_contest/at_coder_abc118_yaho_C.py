#coding: UTF-8


import numpy as np
import glob
import os

if __name__ == "__main__":

    inputt = input()
    K,A,B  = inputt.split(" ")
    K = int(K)
    A = int(A)
    B = int(B)


    base0 = 1000
    if( A > K ):
        print(1 + K)
    else:
        if(B - A > 2):
            K = K - ( A - 1);
            count = A;
            if(K % 2 == 0):
                ki = 0
                while ki < int(K/2):
                    if int(K/2) - ki > base0:
                        count = count + (B-A) * base0
                        ki = ki + base0
                    elif int(K/2) - ki > 100:
                        count = count + (B-A) * 100
                        ki = ki + 100
                    else:
                        count = count + (B - A)
                        ki = ki + 1
            else:
                while ki < int((K-1)/2):
                    if int(K/2) - ki > base0:
                        count = count + (B-A) * base0
                        ki = ki + base0
                    elif int(K/2) - ki > 100:
                        count = count + (B-A) * 100
                        ki = ki + 100
                    else:
                        count = count + (B - A)
                        ki = ki + 1
                count = count + 1
       
            print(count)
        else:
            print(1 + K)

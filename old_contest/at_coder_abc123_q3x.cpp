#include  <iostream>
#include  <stdio.h>
#include  <math.h>
#include <string>
using namespace std;

class BigInt{
    private:
        const static int max_length=100;
        int length;
        bool checkNumeric(string string_value){
            if(string_value == "0") return true;
            else if(string_value == "1") return true;
            else if(string_value == "2") return true;
            else if(string_value == "3") return true;
            else if(string_value == "4") return true;
            else if(string_value == "5") return true;
            else if(string_value == "6") return true;
            else if(string_value == "7") return true;
            else if(string_value == "8") return true;
            else if(string_value == "9") return true;
            else return false;
        }
        int getIntSubstr(string s,int index,int length){
            return atoi(s.substr(index,length).c_str());
        }
        void remeasureLength(){
            length = 0;
            for( int ni = max_length - 1 ; ni >= 0 ; ni-- ){
                if(value[ni]>0){
                    length = ni + 1;
                    break;     
                }
            }
            if(length == 0){
                length = 1;
                sign   = "";
            }
        }
    public:
        int value[max_length];
        string sign = "";
        BigInt( string string_value ){
            setStringValue(string_value);
        }
        void setStringValue(string string_value){
            
            for( int li = 0 ; li < max_length ; li++ ) value[li] = 0;
            
            if(string_value.substr(0,1) == "-"){
                sign  = "-";
                string_value = string_value.substr(1,string_value.length()-1);
            }
            for( int si = 0 ; si < string_value.length() ; si++ ){
                if(checkNumeric(string_value.substr(si,1))){
                    value[(string_value.length()-1) - si] = getIntSubstr(string_value,si,1);
                }else{
                    cout << "you have not big int : " << string_value << endl;
                }
            }
            remeasureLength();
        }
        string getValueFormattedString(){
            remeasureLength();
            string ans="";
            for( int ni = 0 ; ni < length ; ni++ ){
                ans = to_string(value[ni]) + ans;
            }
            return sign + ans;
        }
        int getLength(){
            remeasureLength();
            return length;
        }
};

class CalcBigInt{
    private:
        BigInt additionOfAbsoluteValues(string sign,BigInt bigint_left,BigInt bigint_right){
            int tmp_ans;
            BigInt ans("0");
            ans.sign = sign;
            for( int li = 0 ; li < bigint_right.getLength() ; li++ ){
                tmp_ans = bigint_left.value[li] + bigint_right.value[li];
                ans.value[li]     = ans.value[li]     + tmp_ans % 10;
                ans.value[li + 1] = ans.value[li + 1] + tmp_ans / 10;
            }
            return ans;
        }
        BigInt subtractionOfAbsoluteValues(string sign,BigInt bigint_left,BigInt bigint_right){
            int tmp_ans;
            BigInt ans("0");
            ans.sign = sign;
            for( int li = 0 ; li < bigint_left.getLength() ; li++ ){
                bigint_left.value[li+1] = bigint_left.value[li+1] - 1;
                tmp_ans = 10 + bigint_left.value[li] - bigint_right.value[li];
                bigint_left.value[li+1] = bigint_left.value[li+1] + tmp_ans / 10;
                ans.value[li] = ans.value[li] + tmp_ans % 10;
            }
            return ans;
        }
        BigInt multiplicationOfAbsoluteValues(string sign,BigInt bigint_left,BigInt bigint_right){
            int tmp_ans;
            int keta = 0;
            int index;
            BigInt ans("0");
            ans.sign = sign;
            for( int ri = 0 ; ri < bigint_right.getLength() ; ri++ ){
                for( int li = 0 ; li < bigint_left.getLength() ; li++ ){
                    index = li + keta;
                    tmp_ans = bigint_left.value[li] * bigint_right.value[ri];
                    ans.value[index]   = ans.value[index]   + tmp_ans;
                    ans.value[index+1] = ans.value[index+1] + ans.value[index] / 10;
                    ans.value[index]   = ans.value[index] % 10;
                }
                keta = keta + 1;
            }
            return ans;
        }
        BigInt divisionOfAbsoluteValues(string sign,BigInt bigint_left,BigInt bigint_right){
            double diff_length;
            int index;
            BigInt ans("0");
            ans.sign = sign;
            BigInt const_ten("10");
            BigInt var_int("0");
            diff_length = bigint_left.getLength() - bigint_right.getLength();
            while(diff_length >= 0){
                var_int = bigint_right;
                for( int di = 0 ; di < diff_length ; di++ ){
                    var_int = multiplicationOfAbsoluteValues("",var_int,const_ten);
                }
                index = diff_length;
                while(isBiggerOfAbsoluteValues(bigint_left,var_int)){
                    bigint_left = subtractionOfAbsoluteValues("",bigint_left,var_int);
                    ans.value[index] = ans.value[index] + 1;
                }
                diff_length = diff_length - 1;
            }
            return ans;
        }
    public:
        bool isBiggerOfAbsoluteValues(BigInt bigint_left,BigInt bigint_right){
            int left_length  = bigint_left.getLength();
            int right_length = bigint_right.getLength();
            
            if(left_length > right_length)      return true;
            else if(left_length < right_length) return false;
            else{
                for( int ni = left_length - 1 ; ni >= 0 ; ni-- ){
                    if(bigint_left.value[ni] > bigint_right.value[ni])       return true;
                    else if(bigint_left.value[ni] < bigint_right.value[ni])  return false;
                }
                return true;
            }
        }
        BigInt addition(BigInt bigint_left,BigInt bigint_right){
            if(bigint_left.sign == bigint_right.sign){
                return additionOfAbsoluteValues(bigint_left.sign,bigint_left,bigint_right);
            }else{
                if(isBiggerOfAbsoluteValues(bigint_left,bigint_right)){
                    return subtractionOfAbsoluteValues(bigint_left.sign,bigint_left,bigint_right);
                }else{
                    return subtractionOfAbsoluteValues(bigint_right.sign,bigint_right,bigint_left);
                }
            }
        }
        BigInt subtraction(BigInt bigint_left,BigInt bigint_right){
            if(bigint_right.sign == "")          bigint_right.sign = "-";      
            else if(bigint_right.sign == "-")    bigint_right.sign = "";
            return addition(bigint_left,bigint_right);
        }
        BigInt multiplication(BigInt bigint_left,BigInt bigint_right){
            string sign;
            if(bigint_left.sign == bigint_right.sign)   sign = "";
            else                                        sign = "-";
            return multiplicationOfAbsoluteValues(sign,bigint_left,bigint_right);
        }
        BigInt division(BigInt bigint_left,BigInt bigint_right){
            string sign;
            if(isBiggerOfAbsoluteValues(bigint_left,bigint_right)==false){
                BigInt ans("0");
                return ans;
            }else if(bigint_right.getValueFormattedString() == "0"){
                BigInt ans("0");
                return ans;
            }else{
                if(bigint_left.sign == bigint_right.sign)   sign = "";
                else                                        sign = "-";
                return divisionOfAbsoluteValues(sign,bigint_left,bigint_right);
            }
        }
};



int main(){

    int A;
    int B;
    int result[1000];
    int num_test=0;

    BigInt int1("-100");
    result[num_test] = (int1.getLength() == 3); num_test++;
    result[num_test] = (int1.sign   == "-"); num_test++;
    BigInt int2("100");
    result[num_test] = (int2.getLength() == 3); num_test++;
    result[num_test] = (int2.sign   == ""); num_test++;
    BigInt int3("1000");
    BigInt int4("-1000");
    CalcBigInt calc;
    result[num_test] = (calc.addition(int2,int3).getValueFormattedString() == "1100"); num_test++;
    result[num_test] = (calc.addition(int1,int1).getValueFormattedString() == "-200"); num_test++;
    result[num_test] = (calc.addition(int3,int1).getValueFormattedString() == "900"); num_test++;
    result[num_test] = (calc.addition(int2,int4).getValueFormattedString() == "-900"); num_test++;
    result[num_test] = (calc.addition(int3,int4).getValueFormattedString() == "0"); num_test++;
    result[num_test] = (calc.subtraction(int1,int1).getValueFormattedString() == "0"); num_test++;
    result[num_test] = (calc.subtraction(int3,int4).getValueFormattedString() == "2000"); num_test++;
    result[num_test] = (calc.subtraction(int1,int3).getValueFormattedString() == "-1100"); num_test++;
    result[num_test] = (calc.subtraction(int3,int2).getValueFormattedString() == "900"); num_test++;

    BigInt int5("123");
    BigInt int6("-234");
    result[num_test] = (calc.multiplication(int5,int6).getValueFormattedString() == "-28782"); num_test++;
    result[num_test] = (calc.multiplication(int5,int5).getValueFormattedString() == "15129"); num_test++;
    result[num_test] = (calc.multiplication(int6,int6).getValueFormattedString() == "54756"); num_test++;
    result[num_test] = (calc.multiplication(int2,int6).getValueFormattedString() == "-23400"); num_test++;

    result[num_test] = (calc.division(int5,int6).getValueFormattedString() == "0"); num_test++;
    result[num_test] = (calc.division(int6,int5).getValueFormattedString() == "-1"); num_test++;
    result[num_test] = (calc.division(int4,int1).getValueFormattedString() == "10"); num_test++;
    result[num_test] = (calc.division(int4,int5).getValueFormattedString() == "-8"); num_test++;
    
    BigInt int7("100000000023");
    BigInt int8("1");
    BigInt int9("2");
    BigInt int10("1000000000023");
    result[num_test] = (calc.division(int7,int8).getValueFormattedString() == "100000000023"); num_test++;
    result[num_test] = (calc.division(int7,int9).getValueFormattedString() == "50000000011"); num_test++;
    result[num_test] = (calc.division(int7,int10).getValueFormattedString() == "0"); num_test++;
    
    //cout << calc.division(int7,int11).getValueFormattedString() << endl;
    for( int ni = 0 ; ni < num_test ; ni++ ){
        cout << result[ni];
    }
    
}


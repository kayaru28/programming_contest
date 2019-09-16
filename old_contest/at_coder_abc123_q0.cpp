
#include  <iostream>
#include  <stdio.h>
#include  <math.h>
#include <string>
using namespace std;
class CalcBigInt{
    private:
        int ans;
        int v1,v2;
        int index;
    public:
        int getIntSubstr(string s,int start_index,int length){
            return atoi(s.substr(start_index,length).c_str());
        }
        int isBigger(string x1, string x2){
            if(x1 == x2)                       return 2;
            else if(x1.length() < x2.length()) return 1;
            else if(x1.length() > x2.length()) return 0;
            else{
                ans   = -1;
                index = 0;
                while(ans < 0){
                    v1 = getIntSubstr(x1,index,1);
                    v2 = getIntSubstr(x2,index,1);
                    if(v1 > v2)       ans = 0;
                    else if(v1 < v2)  ans = 1;
                    index = index + 1;
                }
                return ans;
            }
            if(x1.length() == x2.length() && getIntSubstr(x1,0,1) < getIntSubstr(x2,0,1)){
                return 1;
            }else return 0;
        }
        string subtraction(string x1,string x2){
            string answer = "";
            string sign   = "";
            int flag = isBigger(x1,x2);
            if(flag == 2) return "0";
            else{
                if(flag == 1) sign = "-";
                if(flag == 1) swap(x1,x2);
                int ketaochi = 0;
                for( int ni = 0 ; ni < x1.length(); ni++ ){
                    v1 = getIntSubstr(x1,( x1.length() - 1 ) - ni,1) - ketaochi; 
                    v2 = 0;
                    if(x2.length() > ni) v2 = getIntSubstr(x2, ( x2.length() - 1 ) - ni,1); 
                    
                    if( v1 >= v2) ketaochi = 0;
                    else          ketaochi = 1;
                    ans = v1 - v2  + 10 * ketaochi;
                    answer = to_string(ans) + answer;
                }
                while(answer.substr(0,1)=="0") answer = answer.substr(1,answer.length()-1);
                return sign + answer;
            }
        }
        string addition(string x1,string x2){
            string answer = "";
            int flag = isBigger(x1,x2);
            if(flag == 1) swap(x1,x2);
            int ketaage = 0;
            for( int ni = 0 ; ni < x1.length(); ni++ ){
                v1 = getIntSubstr(x1, ( x1.length() - 1 ) - ni, 1) + ketaage; 
                if(x2.length() > ni) v2 = getIntSubstr(x2, ( x2.length() - 1 ) - ni,1); 
                else                 v2 = 0;
                ans = v1 + v2;
                ketaage = ans / 10;
                if(ans >= 10) ans = ans - 10;
                answer = to_string(ans) + answer;
            }
            if(ketaage > 0) answer = to_string(ketaage) + answer;
            return answer;
        }
        string unitMultiplication(string x1,string x2){
            string answer = "0";
            int keta = 1;
            for( int ni = 0 ; ni < x1.length(); ni++ ){
                index  = (  x1.length() -  1 ) - ni;
                v1     = getIntSubstr(x1,index,1);
                v2     = getIntSubstr(x2,0,1);
                ans    = v1 * v2 * keta;
                answer = addition(answer,to_string(ans));
                keta   = keta * 10;
            }
            return answer;
        }
        string multiplication(string x1,string x2){
            string answer = "0";
            string answer_tmp;
            string x2_tmp;
            int flag = isBigger(x1,x2);
            if(flag == 1) swap(x1,x2);
            string keta = "";
            for( int ni = 0 ; ni < x2.length(); ni++ ){
                index  = (  x2.length() -  1 ) - ni;
                x2_tmp = x2.substr(index,1);
                answer_tmp = unitMultiplication(x1,x2_tmp);
                answer_tmp = answer_tmp + keta;
                answer = addition(answer,answer_tmp);
                keta   = keta + "0";
            }
            return answer;
        }
        string unitDivision(string x1,string x2){
            int count = 0;
            while(isBigger(x1,x2)!=1){
                x1    = subtraction(x1,x2);
                count = count + 1;
            }
            return to_string(count);
        }
        string division(string x1,string x2){
            int flag = isBigger(x1,x2);
            string answer = "";
            if(isBigger(x2,"0") > 0) return "error";
            else if(flag == 1)      return "0";
            else if(flag == 2)      return "1";
            else{
                string tmp_x1 = "";
                string tmp_answer;
                for( int ni = 0 ; ni < x1.length(); ni++ ){
                    tmp_x1 = tmp_x1 + x1.substr(ni,1);
                    if(isBigger(tmp_x1,x2)==1) answer = answer + "0";
                    else{
                        tmp_answer = unitDivision(tmp_x1,x2);
                        answer     = answer + tmp_answer;
                        tmp_x1     = subtraction(tmp_x1,multiplication(x2,tmp_answer));
                    }
                }
            }
            while(answer.substr(0,1)=="0") answer = answer.substr(1,answer.length()-1);
            return answer;
        }
};

int main(){

    string N;
    cin >> N;

    string N2;
    cin >> N2;

    CalcBigInt calc;

    cout << "a:" << calc.addition(N,N2) << endl;
    cout << "s:" << calc.subtraction(N,N2) << endl;
    cout << "m:" << calc.multiplication(N,N2) << endl;
    cout << "d:" << calc.division(N,N2) << endl;


/* 
    int num_city = 5;
    string bet_time;
    for( int ni = 0 ; ni < num_city ; ni++ ){
        cin >> bet_time;
    }
 */
    


}











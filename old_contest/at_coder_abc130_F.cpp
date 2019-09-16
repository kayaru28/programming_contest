#include  <iostream>
#include  <stdio.h>
#include <algorithm>
using namespace std;
#include <vector>
#define rep(i,n) for (int i = 0; i < (n) ; i++)
typedef long long ll;
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

vector<double> target_times;

const int i_inc = 0;
const int i_dec = 1;
const int i_stay = 2;

const ll smax = -1e10;
const ll smin = 1e10;

class point{
public:
    double p[3];
    int start;

    point(ll startv){
        start = startv;
        rep(ni,3) p[ni] = start;
    }
   
    double getUpdateMax(double ti){
        double ans;
        int pi;
        pi = i_inc;
        ans = p[pi] + ti;
        pi = i_dec;
        if(ans < p[pi] -ti) ans = p[pi] - ti;
        pi = i_stay;
        if(ans < p[pi]    ) ans = p[pi];
        return ans;
    }
    double getUpdateMin(double ti){
        double ans;
        int pi;
        pi = i_inc;
        ans = p[pi] + ti;
        pi = i_dec;
        if(ans > p[pi] - ti) ans = p[pi] - ti;
        pi = i_stay;
        if(ans > p[pi]     ) ans = p[pi];
        return ans;
    }
    void calcMaxChangeTime(){
        calcChangeTime(i_dec,i_inc);
    }
    void calcMinChangeTime(){
        calcChangeTime(i_inc,i_dec);
    }

    void calcChangeTime(int i_near,int i_far){
        if(p[i_near] > p[i_stay] and p[i_near] > p[i_far]){
            double time1 = 0.0;
            double time2 = 0.0;

            if(p[i_far] != start){
                time1 = ( p[i_near] - p[i_far] ) / 2;
                target_times.push_back(time1);
            }
            if(p[i_stay] != start){
                time2 = ( p[i_near] - p[i_stay] );
                if(time2 < time1 or time1 == 0.0) target_times.push_back(time2);
            }
        }else if(p[i_stay] > p[i_far]){
            if(p[i_far] != start) target_times.push_back(p[i_stay] - p[i_far]);
        }
    }


} ;

point x_max(smax);
point x_min(smin);
point y_max(smax);
point y_min(smin);

double calcAns(double ti){
    double diff_x;
    double diff_y;
    diff_x = x_max.getUpdateMax(ti) - x_min.getUpdateMin(ti);
    diff_y = y_max.getUpdateMax(ti) - y_min.getUpdateMin(ti);
    return diff_x * diff_y;
}

int main(){

    int N;
    cin >> N;
    
    int x,y;
    string d;
    
    int xi,yi;
    for( int ni = 0 ; ni < N ; ni++ ){
        cin >> x;    
        cin >> y;    
        cin >> d;

        yi = i_stay;
        xi = i_stay;
        if(d=="R")      xi = i_inc;
        else if(d=="L") xi = i_dec;
        else if(d=="U") yi = i_inc;
        else if(d=="D") yi = i_dec;
        
        if(x_max.p[xi] <= x) x_max.p[xi] = x;
        if(x_min.p[xi] >= x) x_min.p[xi] = x;
        if(y_max.p[yi] <= y) y_max.p[yi] = y;
        if(y_min.p[yi] >= y) y_min.p[yi] = y;        
    }

    x_max.calcMaxChangeTime();
    x_min.calcMinChangeTime();
    y_max.calcMaxChangeTime();
    y_min.calcMinChangeTime();
    
    double ans = calcAns(0.0);

    /*
    cout << "\nx y" << endl;
    rep(ni,3) cout << x_max.p[ni] << endl;
    rep(ni,3) cout << x_min.p[ni] << endl;
    rep(ni,3) cout << y_max.p[ni] << endl;
    rep(ni,3) cout << y_min.p[ni] << endl;
    cout << "\nans" << endl;
    cout << ans << endl;
    cout << "\nti ans" << endl;
     */
    for(double ti : target_times){
        //cout << ti << endl;
        if(ans > calcAns(ti)) ans = calcAns(ti);
        //cout << ans << endl;
    }


    printf("%f",ans);
}
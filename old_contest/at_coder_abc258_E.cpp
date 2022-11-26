#include <bits/stdc++.h>
using namespace std;

using ll = long long;
roop

class RoopArray {
public:
    ll loop_cnt = -1;
    ll non_loop_cnt = -1;
    ll array_size;
    vector<ll> order_array;
    vector<int> order, path;
    RoopArray(ll N){ //最初は全てが根であるとして初期化
        array_size = N;
        for( ll ni = 0 ; ni <N ; ni++ ){
            order.push_back(-1);
        }
    }
    ll getNextIndex(){
        //-----------------------------------------
        // 　毎回カスタマイズ
        //-----------------------------------------
        return -1;
    }
    void detectRoop(){
        ll index = 0;
        ll order_cnt = 0;
        while( order[index] == -1) {
            order_array.push_back(index);
            order[index] = order_cnt;
            order_cnt++;
            index = getNextIndex();
        }
        loop_cnt = order_cnt - order[index];
        non_loop_cnt = (int)order_array.size() - loop_cnt;
    }

    ll getValue(ll target_index){
        if (target_index < non_loop_cnt) {
            target_index = target_index;
        } else {
            target_index = (target_index - non_loop_cnt) % loop_cnt;
            target_index = non_loop_cnt+target_index;
        }
        return order_array[target_index];
    }
};
class RoopArray2 {
public:
    ll loop_cnt = -1;
    ll non_loop_cnt = -1;
    ll array_size;
    vector<ll> order_array;
    vector<int> order, path;
    RoopArray2(ll N){ //最初は全てが根であるとして初期化
        array_size = N;
        for( ll ni = 0 ; ni <N ; ni++ ){
            order.push_back(-1);
        }
    }
    ll getNextIndex(ll index, ll count_val){
        //-----------------------------------------
        // 　毎回カスタマイズ
        //-----------------------------------------
        return (index + count_val) % array_size;
    }
    void detectRoop(vector<int> count){
        ll index = 0;
        ll order_cnt = 0;
        while( order[index] == -1) {
            order_array.push_back(index);
            order[index] = order_cnt;
            order_cnt++;
            index = getNextIndex(index, count[index]);
        }
        loop_cnt = order_cnt - order[index];
        non_loop_cnt = (int)order_array.size() - loop_cnt;
    }

    ll getValue(ll target_index){
        if (target_index < non_loop_cnt) {
            //target_index = target_index;
        } else {
            target_index = (target_index - non_loop_cnt) % loop_cnt;
            target_index = non_loop_cnt + target_index;
        }
        return order_array[target_index];
    }
};
int main() {
    int n, q, x;
    cin >> n >> q >> x;
    vector<int> w(2 * n);
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
        w[i + n] = w[i];
    }
    const ll all = accumulate(begin(w), begin(w) + n, 0ll);
    vector<int> count(n, (x / all) * n);
    x %= all;
    for (int i = 0, j = 0, s = 0; i < n; ++i) {
        if (j < i) {
            j = i;
            s = 0;
        }
        while (s < x) {
            s += w[j];
            j += 1;
        }
        count[i] += j - i;
        s -= w[i];
    }

    RoopArray2 ra2(n);
    ra2.detectRoop(count);

    while (q--) {
        ll k;
        cin >> k;
        k -= 1;
        ll count_index = ra2.getValue(k) ;
        cout << count[ count_index]<< endl;
    }
    return 0;
}
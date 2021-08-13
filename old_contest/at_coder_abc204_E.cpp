#include <bits/stdc++.h>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    vector<vector<tuple<int, int, int>>> E(N);
    for (int i = 0; i < M; i++){
        int A, B, C, D;
        cin >> A >> B >> C >> D;
        A--;
        B--;
        E[A].push_back(make_tuple(C, D, B));
        E[B].push_back(make_tuple(C, D, A));
    }
    vector<long long> d(N, -1);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push(make_pair(0, 0));
    while (!pq.empty()){
        long long dd = pq.top().first;
        int v = pq.top().second;
        pq.pop();
        if (d[v] == -1){
            d[v] = dd;
            for (auto e : E[v]){
                int C = get<0>(e);
                int D = get<1>(e);
                int w = get<2>(e);
                if (d[w] == -1){
                    int mn;
                    if (D <= 1){
                        mn = 0;
                    } else {
                        int a = D * 2;
                        for (int i = sqrt(D) - 10; i <= sqrt(D) + 10; i++){
                            if (i >= 0){
                            long long t2 = i + D / (i + 1);
                            if (t2 < a){
                                a = t2;
                                mn = i;
                            }
                            }
                        }
                    }
                    long long d2 = dd;
                    d2 = max(d2, (long long) mn);
                    long long d3 = d2 + C + D / (d2 + 1);
                    pq.push(make_pair(d3, w));
                }
            }
        }
    }
    cout << d[N - 1] << endl;
}
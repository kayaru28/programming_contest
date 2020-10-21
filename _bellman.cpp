#include <iostream>
#include <vector>
using namespace std;


//http://ronly.hatenablog.com/entry/2017/06/17/153147
struct Edge { int to, cost; };
typedef vector<vector<Edge> > AdjList;  // 隣接リストの型
AdjList graph;

const int bellINF = 1000000;
vector<int> belldist;
bool bellman_ford(int node_n, int start_i){
    belldist = vector<int>(node_n,bellINF);
    belldist[start_i] = 0;
    for(int rep_c=0;rep_c<node_n;rep_c++){
        for(int from_i = 0 ; from_i < node_n ; from_i++){
            for(int to_i=0 ; to_i<graph[from_i].size() ; to_i++){
                Edge e = graph[from_i][to_i];
                if(belldist[from_i] != bellINF && belldist[e.to] > belldist[from_i] + e.cost){
                    belldist[e.to] = belldist[from_i] + e.cost;
                    if(rep_c == node_n-1) return true;
                }
            }
        }
    }
    return false;
}

int main(void){
    int n, m;
    cin >> n >> m;

    graph = AdjList(n);

    for(int i=0;i<m;i++){
        int from, to, cost;
        cin >> from >> to >> cost;
        graph[from].push_back((Edge){to,cost});
    }

    bellman_ford(n,0);

    for (int i = 1; i < n; i++){
       if(belldist[i] != bellINF){
           cout << "0から" << i << "へのコスト:" << belldist[i] << endl;
       }
    }
    return 0;
}


using Graph = vector<vector<int>>; //第一引数のノードは、その中のベクターにあるノードとつながりがある
vector<bool> visited;
void dfs(const Graph &G, int v) {
    visited[v] = true; // v を訪問済にする

    // v から行ける各頂点 next_v について
    for (auto next_v : G[v]) { 
        if (visited[next_v]) continue; // next_v が探索済だったらスルー
        dfs(G, next_v); // 再帰的に探索
    }
}
//以下を、main関数の中で使用
Graph G(N);


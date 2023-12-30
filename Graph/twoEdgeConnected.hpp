# include "lowlink.hpp"
# include "connected.hpp"

// 二辺連結成分分解
struct TwoEdgeConnectedComponents{
    int v;
    vector<vector<int>> groups;
    Graph &G;
    Lowlink lowlink;
    TwoEdgeConnectedComponents(Graph G) : G(G), lowlink(G){
        v = (int)G.size();
        
        set<pair<int, int>> bridge;
        for(auto& e : lowlink.bridge) bridge.insert(e);
        // bridgeを削除したグラフを作る
        Graph g(v);
        for(int i = 0; i < v; i++){
            for(auto& e : G[i]){
                // 橋でない辺を追加
                if(bridge.count({min(i, e), max(i, e)}) == 0){
                    g[i].push_back(e);
                }
            }
        }

        // 連結成分分解
        ConnectedComponents cc(g);
        groups = cc.groups;
    }
};
# include "templete.hpp"

// 木の直径を求める

using CostT = long long;


struct Edge{
    int to;
    CostT cost;
};

using Graph = vector<vector<Edge>>;

void dfs(Graph &G,int v,int p,long d,vector<CostT>&dist){
    // v:現在の頂点
    // p:親の頂点
    // d:現在の距離
    dist[v] = d;
    for(auto& e:G[v]){
        if(e.to!=p){
            dfs(G,e.to,v,d+e.cost,dist);
        }
    }
}

pair<int,CostT> treeDiameter(Graph &G){
    // 木の直径を求める
    // return: (直径の端点のうちの一つ,直径の重さ)
    int n = G.size();
    vector<CostT> dist(n);
    dfs(G,0,-1,0,dist);
    int u = max_element(dist.begin(),dist.end())-dist.begin();
    dfs(G,u,-1,0,dist);
    int v = max_element(dist.begin(),dist.end())-dist.begin();
    return {v,dist[v]};
}

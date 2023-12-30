# include "templete.hpp"

using Graph = vector<vector<int>>;

// 連結成分を求める
struct ConnectedComponents{
    int v;
    vector<vector<int>> groups;
    vector<int> id;
    Graph &G;
    ConnectedComponents(Graph &G) : G(G) {
        v = (int)G.size();
        id.resize(v, -1);
        int k = 0;
        for(int i = 0; i < v; i++){
            if(id[i] == -1){
                vector<int> group;
                dfs(i, k, group);
                k++;
                groups.push_back(group);
            }
        }
    }

    void dfs(int n, int k, vector<int> &group){
        id[n] = k;
        group.push_back(n);
        for(auto& e : G[n]){
            if(id[e] == -1) dfs(e, k, group);
        }
    }
};
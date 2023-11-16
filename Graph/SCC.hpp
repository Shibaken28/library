# include "templete.hpp"

using Graph = vector<vector<int>>;
struct StronglyConnectedComponents{
    Graph &G;
    Graph invG;
    vector<int> ord, inv;
    vector<vector<int>> groups;
    StronglyConnectedComponents(Graph &_G): G(_G){
        int v = (int)G.size();
        invG.resize(v);
        for(int i=0;i<v;i++){
            for(auto&g:G[i]){
                invG[g].push_back(i);
            }
        }
        // DFSをする
        ord.resize(v, -1);
        inv.resize(v, -1);
        int k = 0;
        for(int i=0;i<v;i++){
            if(ord[i]==-1)k = dfs(i, k);
        }

        for(int i=0;i<v;i++){
            inv[ord[i]] = i;
            ord[i] = -1;
        }
        // 辺を逆向きにしてDFS
        k = 0;
        for(int i=0;i<v;i++){
            if(ord[i]==-1){
                vector<int> group(0);
                k = dfs2(i, k, group);
                groups.push_back(group);  
            }
        }
    }
    int dfs(int n, int k){
        ord[n] = k++;
        for(auto&e:G[n]){
            if(ord[e]==-1){
                k = dfs(e, k);
            }
        }
        return k;
    }
    int dfs2(int n,int k, vector<int>&group){
        group.push_back(n);
        ord[n] = k++;
        for(auto&e:invG[n]){
            if(ord[e]==-1){
                k = dfs(e, k);
            }
        }
        return k;
    }
};

# include "SCC.hpp"

struct TwoSAT{
    int n;
    vector<bool> ans;
    Graph g;
    TwoSAT(int n):n(n),ans(n),g(2*n){}
    void add_clause(int x, bool a, int y, bool b){
        g[x+n*(a?0:1)].push_back(y+n*(b?1:0));
        g[y+n*(b?0:1)].push_back(x+n*(a?1:0));
    }
    bool satisfiable(){
        StronglyConnectedComponents scc(g);
        vector<int> id(n*2, -1); //その頂点含まれている連結成分の番号
        for(int i=0;i<(int)scc.groups.size();i++){
            for(int v:scc.groups[i]){
                if(id[v] != -1) return false;
                id[v] = i;
            }
        }
        for(int i=0;i<n;i++){
            if(id[i] == id[i+n]) return false;
            ans[i] = id[i] < id[i+n];
        }
        return true;
    }
};

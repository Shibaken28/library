# include "templete.hpp"

struct Edge{
    int from;
    int to;
    long cost;
};

using Graph = vector<vector<Edge>>;
using Pll = pair<long,long>;

/*プリム法*/
struct Prim{
    Graph G;
    int V;
    Prim(int V):V(V){
        G.resize(V);
    }
    //無向グラフ！
    void addEdge(int from,int to,long cost){
        G[from].push_back({from,to,cost});
        G[to].push_back({to,from,cost});
    }
    long long build(){
        long long res = 0;
        vector<bool> used(V,false);
        priority_queue<Pll,vector<Pll>,greater<Pll>> que;
        que.push({0,0});
        while(!que.empty()){
            auto [cost, v] = que.top(); que.pop();
            if(used[v])continue;
            used[v] = true;
            res += cost;
            for(auto& e:G[v]){
                if(!used[e.to]){
                    que.push({e.cost,e.to});
                }
            }
        }
        return res;
    }
};

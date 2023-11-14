# include "templete.hpp"

struct Edge{
    int to;
    long cost;
};

struct WeightedVertex{
    int v;
    long cost;
};

using Graph = vector<vector<Edge>>;

void dijkstra(int s,Graph &G,vector<long>&D){
    auto comp = [](WeightedVertex &l,WeightedVertex &r){return l.cost > r.cost;};
    priority_queue < 
        WeightedVertex,
        vector<WeightedVertex>,
        function<bool(WeightedVertex&,WeightedVertex&)>
        > qu (comp);
    D.resize(G.size());
    fill(D.begin(),D.end(),-1);
    D[s] = 0;
    qu.push({s,0});
    while(!qu.empty()){
        auto a = qu.top(); qu.pop();
        int from = a.v;
        for(auto&e:G[from]){
            if(D[e.to] == -1 || D[e.to] > D[from] + e.cost){
                D[e.to] = D[from] + e.cost;
                qu.push({e.to,D[e.to]});
            }
        }
    }
}

# include "templete.hpp"
# include "UnionFind.hpp"

/*クラスカル法*/
struct Edge{
    int from;
    int to;
    long cost;
};

using Graph = vector<vector<Edge>>;

struct Kruskal{
    vector<Edge> edges;
    Graph G;
    int V;
    Kruskal(int V):V(V){
        G.resize(V);
    }
    //無向グラフ！
    void addEdge(int from,int to,long cost){
        edges.push_back({from,to,cost});
    }
    long long build(){
        sort(edges.begin(),edges.end(),[](const Edge& e1,const Edge& e2){
            return e1.cost<e2.cost;
        });
        UnionFind uf(V);
        long long res = 0;
        for(auto& e:edges){
            if(!uf.same(e.from,e.to)){
                uf.unite(e.from,e.to);
                res += e.cost;
                G[e.from].push_back({e.from,e.to,e.cost});
                G[e.to].push_back({e.to,e.from,e.cost});
            }
        }
        return res;
    }
};

# include <vector>
# include <queue>
# include <functional>
using namespace std;

struct Edge{
    int from;
    int to;
    long cost;
};

struct WeightedVertex{
    int v;
    long cost;
};

using Graph = vector<vector<Edge>>; //隣接グラフ

const long INF = 1e17; 

/*
重みはlong型
始点s，グラフGの点をDに
戻り値は **sからgの経路** を作るときに重みが負の無限になるか
*/
bool bellmanFord(int s,Graph &G,vector<long>&D){
    const int N = G.size();
    vector<Edge>edges;
    for(auto A:G){
        for(Edge& a:A){
            edges.push_back(a);
        }
    }
    D.resize(N);
    fill(D.begin(),D.end(),INF);
    D[s] = 0;
    for(int i=0;i<=N;i++){
        for(auto&e:edges){
            long d = D[e.from] + e.cost;
            if(D[e.from] < INF && D[e.to] > d){
                D[e.to] = d;
                if(i==N){
                    return true;
                }
            }
        }
    }
    return false;
}

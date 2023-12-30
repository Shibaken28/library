# define PROBLEM "https://judge.yosupo.jp/problem/two_edge_connected_components"
# include <iostream>
# include "twoEdgeConnected.hpp"
using namespace std;

int main(){
    int v,e; cin>>v>>e;
    Graph G(v);
    for(int i=0;i<e;i++){
        int s,t; cin>>s>>t;
        G[s].push_back(t);
        G[t].push_back(s);
    }
    TwoEdgeConnectedComponents tecc(G);
    cout << tecc.groups.size() << endl;
    for(auto& x : tecc.groups){
        cout << x.size();
        for(int y : x) cout << " " << y;
        cout << endl;
    }
}


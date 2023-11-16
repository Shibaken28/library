# define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_3_B"
# include <iostream>
# include "lowlink.hpp"
using namespace std;

int main(){
    int v,e; cin>>v>>e;
    Graph G(v);
    for(int i=0;i<e;i++){
        int s,t; cin>>s>>t;
        G[s].push_back(t);
        G[t].push_back(s);
    }
    Lowlink lowlink(G);
    sort(lowlink.bridge.begin(), lowlink.bridge.end());
    for(auto& x : lowlink.bridge) cout << x.first << " " << x.second << endl;
}


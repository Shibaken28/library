# define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_A"
# include <iostream>
# include "Dijkstra.hpp"
using namespace std;

int main(){
    Graph g;
    int n,m,r;
    cin >> n >> m >> r;
    g.resize(n);
    for(int i=0;i<m;i++){
        int s,t,d;
        cin >> s >> t >> d;
        g[s].push_back({t,d});
    }
    vector<long> d;
    dijkstra(r,g,d);
    for(int i=0;i<n;i++){
        if(d[i] == -1)cout << "INF" << endl;
        else cout << d[i] << endl;
    }
}


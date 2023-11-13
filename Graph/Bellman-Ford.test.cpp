# define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_B"
# include <iostream>
# include "Bellman-Ford.hpp"
using namespace std;

int main(){
    Graph g;
    int n,m,r;
    cin >> n >> m >> r;
    g.resize(n);
    for(int i=0;i<m;i++){
        int s,t,d;
        cin >> s >> t >> d;
        g[s].push_back({s,t,d});
    }
    vector<long> d;
    if(bellmanFord(r,g,d)){
        cout << "NEGATIVE CYCLE" << endl;
        return 0;
    }else{
        for(int i=0;i<n;i++){
            if(d[i] == INF)cout << "INF" << endl;
            else cout << d[i] << endl;
        }
    }
}


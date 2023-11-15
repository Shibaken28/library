# define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_A"
# include "treeDiameter.hpp"

int main(){
    int n;cin>>n;
    Graph G(n);
    for(int i=0;i<n-1;i++){
        int s,t,w;cin>>s>>t>>w;
        G[s].push_back({t,w});
        G[t].push_back({s,w});
    }
    auto res = treeDiameter(G);
    cout<<res.second<<endl;
}

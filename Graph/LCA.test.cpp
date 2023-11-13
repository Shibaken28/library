# define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_5_C"
# include <iostream>
# include "LCA.hpp"
using namespace std;


int main(){
    int n;cin>>n;
    LCA lca(n);
    for(int i=0;i<n;i++){
        int k;cin>>k;
        for(int j=0;j<k;j++){
            int c;cin>>c;
            lca.G[c].push_back({i});
            lca.G[i].push_back({c});
        }
    }
    lca.build();
    int q;cin>>q;
    for(int i=0;i<q;i++){
        int u,v;cin>>u>>v;
        cout<<lca.lca(u,v)<<endl;
    }
}

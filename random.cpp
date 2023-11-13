#line 1 "Graph/LCA.test.cpp"
# define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_5_C"
# include <iostream>
#line 1 "Graph/LCA.hpp"
# include <vector>
using namespace std;


struct Edge{
    int to;
};

using Graph = vector<vector<Edge>>;

struct LCA{
    Graph G;
    vector<vector<int>> ancestor;
    //ancestor[i][j]:=頂点iの2^j個親
    vector<int> depth;//深さ
    int N;
    int root = 0;
    const int maxDepth = 25;
    LCA(int _N){
        this-> N = _N;
        init();
    }
    void init(){
        G.resize(N);
        depth.resize(N);
        ancestor.resize(N);
        for(int i=0;i<N;i++){
            ancestor[i].resize(maxDepth);
        }
    }
    void build(){
        ancestor[root][0] = root;
        bfs(root,root,0);
        for(int i=1;i<maxDepth;i++){
            for(int j=0;j<N;j++){
                ancestor[j][i] = ancestor[ancestor[j][i-1]][i-1];
            }
        }
    }
    void bfs(int n,int pre,int d){
        depth[n] = d;
        ancestor[n][0] = pre;
        for(auto&E:G[n]){
            if(E.to==pre)continue;
            bfs(E.to,n,d+1);
        }
    }
    //頂点nのs個先の祖先
    int anc(int n,int s){
        for(int i=0;i<maxDepth;i++){
            if(s&(1<<i)){
                n = ancestor[n][i];
            }
        }
        return n;
    }
    //頂点nの深さs(root=0)の祖先
    int levelAnc(int n,int s){
        return anc(n,depth[n]-s);
    }
    //頂点a,bの共通最近祖先
    int lca(int a,int b){
        if(depth[a]<depth[b])swap(a,b);
        a = levelAnc(a,depth[b]);//同じ深さにする
        if(a==b)return a;
        for(int k=maxDepth-1;k>=0;k--){
            if(ancestor[a][k]!=ancestor[b][k]){
                a = ancestor[a][k];
                b = ancestor[b][k];
            }
        }
        return ancestor[a][0];
    }
};
#line 4 "Graph/LCA.test.cpp"
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

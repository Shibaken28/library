# define IGNORE
# define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_4_B"
# include "topological.hpp"

int main(){
    int n,m;
    cin >> n >> m;
    Graph g(n);
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
    }
    auto ans=topologicalSort(g);
    for(auto&h:ans){
        cout << h << endl;
    }
}

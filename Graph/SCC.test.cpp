# define PROBLEM "https://judge.yosupo.jp/problem/scc"
# include "SCC.hpp"

int main(){
    int n,m;
    cin >> n >> m;
    Graph g(n);
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
    }
    StronglyConnectedComponents scc(g);
    cout << scc.groups.size() << endl;
    for(int i=0;i<(int)scc.groups.size();i++){
        cout << scc.groups[i].size();
        for(int v:scc.groups[i]){
            cout << " " << v;
        }
        cout << endl;
    }
}

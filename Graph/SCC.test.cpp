# define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_3_C"
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
    vector<int> num(n,-1); //どの強連結成分に含まれているか
    for(int i=0;i<(int)scc.groups.size();i++){
        for(auto&v:scc.groups[i]){
            num[v] = i;
        }
    }
    int q;cin>>q;
    for(int i=0;i<q;i++){
        int s,t;cin>>s>>t;
        cout << (num[s] == num[t]) << endl;
    }
}

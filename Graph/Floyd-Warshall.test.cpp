# define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_C"
# include <iostream>
# include "Floyd-Warshall.hpp"
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<long>> g(n,vector<long>(n,INF));
    for(int i=0;i<n;i++)g[i][i] = 0;
    for(int i=0;i<m;i++){
        int s,t,d;
        cin >> s >> t >> d;
        g[s][t] = d;
    }
    auto h = floydWarshall(g);
    for(int i=0;i<n;i++){
        if(h[i][i] < 0){
            cout << "NEGATIVE CYCLE" << endl;
            return 0;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(h[i][j] == INF)cout << "INF";
            else cout << h[i][j];
            if(j!=n-1)cout << " ";
        }
        cout << endl;
    }
}


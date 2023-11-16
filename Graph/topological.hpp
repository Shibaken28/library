# include "templete.hpp"

using Graph = vector<vector<int>>;
// グラフがDAGである
// トポロジカルソート
vector<int> topologicalSort(Graph &G){
    // 入次数を数える
    vector<int> in(G.size(),0);
    for(auto&g:G){
        for(auto&h:g){
            in[h]++;
        }
    }
    // 入次数が0のものをキューに入れる
    queue<int> q;
    for(int i=0;i<(int)G.size();i++){
        if(in[i]==0){
            q.push(i);
        }
    }
    // 入次数が0のものを取り出して、その頂点から出ている辺を削除する
    vector<int> ans;
    while(!q.empty()){
        int n=q.front(); q.pop();
        ans.push_back(n);
        for(auto&g:G[n]){
            in[g]--;
            if(in[g]==0){
                q.push(g);
            }
        }
    }
    return ans;
}

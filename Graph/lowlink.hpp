# include "templete.hpp"

using Graph = vector<vector<int>>;

// 橋と関節点を求める
struct Lowlink{
    int v;
    vector<int> ord, low;
    // ord[i] := 頂点iにdfsで訪れた順番
    // low[i] := DFS木を下っていき(葉方向に進んでいき)、最後に後退辺を使って頂点iより前に訪れた頂点のordの最小値
    // * すなわち、後退辺=ループが見つかると、そのループ内のlowに同じ数字を割り当てていくことになる(ループが複数重なっている場合もなんかいいかんじの挙動になる)
    vector<int> articulation;
    vector<pair<int, int>> bridge;
    Graph &G;
    Lowlink(Graph &G) : G(G) {
        v = (int)G.size();
        ord.resize(v, -1);
        low.resize(v, -1);
        for(int i = 0; i < v; i++){
            if(ord[i] == -1) dfs(i, -1, 0);
        }
    }
    int dfs(int n, int par, int c){
        ord[n] = c++;
        low[n] = ord[n];
        bool is_articulation = false;
        int cnt = 0; // 子の数
        for(auto& e : G[n]){
            if(ord[e] == -1){
                cnt++;
                c = dfs(e, n, c);
                low[n] = min(low[n], low[e]); //lowを伝搬
                if(par != -1 && ord[n] <= low[e]) is_articulation = true; //関節点
                if(ord[n] < low[e]) bridge.push_back({min(n, e), max(n, e)}); //橋
            }else if(e != par){ //後退辺
                low[n] = min(low[n], ord[e]); //ループ検出
            }
        }
        if(par == -1 && cnt > 1) is_articulation = true; //根
        if(is_articulation) articulation.push_back(n);
        return c;
    }
};


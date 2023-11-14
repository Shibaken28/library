# include "templete.hpp"

struct UnionFind{
    public:
    vector<int> par;//親
    vector<long> weight;//重み
    vector<long> weightAlone;//単体の重み
    UnionFind(int n):par(n),weight(n),weightAlone(n){
        for(int i=0;i<n;i++){
            par[i]=i; //親は自分自身にしておく
            weight[i] = weightAlone[i] = 1;
        }
    }
    //途中で実行すると壊れます
    void setWeight(int i,long w){
        weight[i] = weightAlone[i] = w;
    }
    //途中で実行しても大丈夫
    void changeWeight(int i,long w){
        long pre = weightAlone[i];
        weightAlone[i] = w;
        weight[root(i)] += w-pre;
    }
    int root(int x){
        if(par[x]==x){
            return x;
        }else{
            int r = root(par[x]);
            par[x]=r;
            return r;
        }
    }
    void unite(int x,int y){
        int rx=root(x);
        int ry=root(y);
        if(rx==ry){
            return;
        }
        par[rx]=ry;
        weight[ry] += weight[rx];
    }
    bool same(int x,int y){
        int rx=root(x);
        int ry=root(y);
        return rx==ry;
    }
    long getWeight(int x){
        return weight[root(x)];
    }
    vector<vector<int>> getGroups(){
        vector<vector<int>> res;
        map<int,vector<int>> mp;
        for(int i=0;i<(int)par.size();i++){
            mp[root(i)].push_back(i);
        }
        for(auto&[k,v]:mp){
            (void)k; //使いません
            res.push_back(v);
        }
        return res;
    }
};



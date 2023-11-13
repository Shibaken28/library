---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Graph/UnionFind.test.cpp
    title: Graph/UnionFind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Graph/UnionFind.hpp\"\n# include <vector>\n# include <map>\n\
    using namespace std;\n\nstruct UnionFind{\n    public:\n    vector<int> par;//\u89AA\
    \n    vector<long> weight;//\u91CD\u307F\n    vector<long> weightAlone;//\u5358\
    \u4F53\u306E\u91CD\u307F\n    UnionFind(int n):par(n),weight(n),weightAlone(n){\n\
    \        for(int i=0;i<n;i++){\n            par[i]=i; //\u89AA\u306F\u81EA\u5206\
    \u81EA\u8EAB\u306B\u3057\u3066\u304A\u304F\n            weight[i] = weightAlone[i]\
    \ = 1;\n        }\n    }\n    //\u9014\u4E2D\u3067\u5B9F\u884C\u3059\u308B\u3068\
    \u58CA\u308C\u307E\u3059\n    void setWeight(int i,long w){\n        weight[i]\
    \ = weightAlone[i] = w;\n    }\n    //\u9014\u4E2D\u3067\u5B9F\u884C\u3057\u3066\
    \u3082\u5927\u4E08\u592B\n    void changeWeight(int i,long w){\n        long pre\
    \ = weightAlone[i];\n        weightAlone[i] = w;\n        weight[root(i)] += w-pre;\n\
    \    }\n    int root(int x){\n        if(par[x]==x){\n            return x;\n\
    \        }else{\n            int r = root(par[x]);\n            par[x]=r;\n  \
    \          return r;\n        }\n    }\n    void unite(int x,int y){\n       \
    \ int rx=root(x);\n        int ry=root(y);\n        if(rx==ry){\n            return;\n\
    \        }\n        par[rx]=ry;\n        weight[ry] += weight[rx];\n    }\n  \
    \  bool same(int x,int y){\n        int rx=root(x);\n        int ry=root(y);\n\
    \        return rx==ry;\n    }\n    long getWeight(int x){\n        return weight[root(x)];\n\
    \    }\n    vector<vector<int>> getGroups(){\n        vector<vector<int>> res;\n\
    \        map<int,vector<int>> mp;\n        for(int i=0;i<(int)par.size();i++){\n\
    \            mp[root(i)].push_back(i);\n        }\n        for(auto&[k,v]:mp){\n\
    \            (void)k; //\u4F7F\u3044\u307E\u305B\u3093\n            res.push_back(v);\n\
    \        }\n        return res;\n    }\n};\n\n\n"
  code: "# include <vector>\n# include <map>\nusing namespace std;\n\nstruct UnionFind{\n\
    \    public:\n    vector<int> par;//\u89AA\n    vector<long> weight;//\u91CD\u307F\
    \n    vector<long> weightAlone;//\u5358\u4F53\u306E\u91CD\u307F\n    UnionFind(int\
    \ n):par(n),weight(n),weightAlone(n){\n        for(int i=0;i<n;i++){\n       \
    \     par[i]=i; //\u89AA\u306F\u81EA\u5206\u81EA\u8EAB\u306B\u3057\u3066\u304A\
    \u304F\n            weight[i] = weightAlone[i] = 1;\n        }\n    }\n    //\u9014\
    \u4E2D\u3067\u5B9F\u884C\u3059\u308B\u3068\u58CA\u308C\u307E\u3059\n    void setWeight(int\
    \ i,long w){\n        weight[i] = weightAlone[i] = w;\n    }\n    //\u9014\u4E2D\
    \u3067\u5B9F\u884C\u3057\u3066\u3082\u5927\u4E08\u592B\n    void changeWeight(int\
    \ i,long w){\n        long pre = weightAlone[i];\n        weightAlone[i] = w;\n\
    \        weight[root(i)] += w-pre;\n    }\n    int root(int x){\n        if(par[x]==x){\n\
    \            return x;\n        }else{\n            int r = root(par[x]);\n  \
    \          par[x]=r;\n            return r;\n        }\n    }\n    void unite(int\
    \ x,int y){\n        int rx=root(x);\n        int ry=root(y);\n        if(rx==ry){\n\
    \            return;\n        }\n        par[rx]=ry;\n        weight[ry] += weight[rx];\n\
    \    }\n    bool same(int x,int y){\n        int rx=root(x);\n        int ry=root(y);\n\
    \        return rx==ry;\n    }\n    long getWeight(int x){\n        return weight[root(x)];\n\
    \    }\n    vector<vector<int>> getGroups(){\n        vector<vector<int>> res;\n\
    \        map<int,vector<int>> mp;\n        for(int i=0;i<(int)par.size();i++){\n\
    \            mp[root(i)].push_back(i);\n        }\n        for(auto&[k,v]:mp){\n\
    \            (void)k; //\u4F7F\u3044\u307E\u305B\u3093\n            res.push_back(v);\n\
    \        }\n        return res;\n    }\n};\n\n\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/UnionFind.hpp
  requiredBy: []
  timestamp: '2023-11-13 15:54:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Graph/UnionFind.test.cpp
documentation_of: Graph/UnionFind.hpp
layout: document
title: UnionFind
---

## 概要
頂点のマージ、連結判定を高速に行うデータ構造です

## 使い方
- `unite(u,v)` : 頂点`u`と頂点`v`を同じ集合にする
- `same(u,v)` : 頂点`u`と頂点`v`が同じ集合に属するか判定する
- `getGroups()` : 集合ごとに分けた頂点のリストを返す
- `getWeight(u)` : 頂点`u`が属する集合の重みを返す
- `changeWeight(u)` : 頂点`u`の重みを変更する

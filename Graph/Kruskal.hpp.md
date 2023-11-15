---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/UnionFind.hpp
    title: UnionFind
  - icon: ':heavy_check_mark:'
    path: templete.hpp
    title: "templete / \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Graph/Kruskal.test.cpp
    title: Graph/Kruskal.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"templete.hpp\"\n\n#include <iostream> // cout, endl, cin\n\
    #include <string> // string, to_string, stoi\n#include <vector> // vector\n#include\
    \ <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound\n#include\
    \ <utility> // pair, make_pair\n#include <tuple> // tuple, make_tuple\n#include\
    \ <cstdint> // int64_t, int*_t\n#include <cstdio> // printf\n#include <map> //\
    \ map\n#include <queue> // queue, priority_queue\n#include <set> // set\n#include\
    \ <stack> // stack\n#include <deque> // deque\n#include <unordered_map> // unordered_map\n\
    #include <unordered_set> // unordered_set\n#include <bitset> // bitset\n#include\
    \ <cctype> // isupper, islower, isdigit, toupper, tolower\n#include <iomanip>\n\
    #include <climits>\n#include <cmath>\n#include <functional>\n#include <numeric>\n\
    #include <regex>\n#include <array>\n#include <fstream>\n#include <sstream>\n\n\
    \nusing namespace std;\n\n\n\ntemplate<class T> inline bool chmin(T& a, T b) {\n\
    \    if (a > b) {\n        a = b;\n        return true;\n    }\n    return false;\n\
    }\ntemplate<class T> inline bool chmax(T& a, T b) {\n    if (a < b) {\n      \
    \  a = b;\n        return true;\n    }\n    return false;\n}\n\ntemplate<class\
    \ T> void printArray(vector<T>&A){\n    for(T&a:A){\n        cout<<a<<\" \";\n\
    \    }\n    cout<<endl;\n}\ntemplate<class T> void printArrayln(vector<T>&A){\n\
    \    for(T&a:A){\n        cout<<a<<endl;\n    }\n}\n\n\ntemplate<class T1,class\
    \ T2> std::ostream &operator<<(std::ostream &out, const pair<T1,T2> &A){\n   \
    \ cout<<\"{\"<<A.first<<\",\"<<A.second<<\"}\";\n    return out;\n}\n\ntemplate<class\
    \ T1,class T2> std::ostream &operator<<(std::ostream &out, const map<T1,T2> &M){\n\
    \    for(const auto&A:M){\n        cout<<\"{\"<<A.first<<\",\"<<A.second<<\"}\"\
    ;\n    }\n    return out;\n}\n\ntemplate<class T1> std::ostream &operator<<(std::ostream\
    \ &out, const set<T1> &M){\n    cout<<\"{\";\n    for(const auto&A:M){\n     \
    \   cout<<A<<\", \";\n    }\n    cout<<\"}\"<<endl;\n    return out;\n}\n\n\n\
    template<class T1> std::ostream &operator<<(std::ostream &out, const multiset<T1>\
    \ &M){\n    cout<<\"{\";\n    for(const auto&A:M){\n        cout<<A<<\", \";\n\
    \    }\n    cout<<\"}\"<<endl;\n    return out;\n}\n\ntemplate<class T> std::ostream\
    \ &operator<<(std::ostream &out, const vector<T> &A){\n    for(const T &a:A){\n\
    \        cout<<a<<\" \";\n    }\n    return out;\n}\n\nvoid print() { cout <<\
    \ endl; }\n \ntemplate <typename Head, typename... Tail>\nvoid print(Head H, Tail...\
    \ T) {\n  cout << H << \" \";\n  print(T...);\n}\n\n\ntemplate<class T> std::istream\
    \ &operator>>(std::istream &in,vector<T>&A){\n    for(T&a:A){\n        std::cin>>a;\n\
    \    }\n    return in;\n}\n\n#line 2 \"Graph/UnionFind.hpp\"\n\nstruct UnionFind{\n\
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
    \        }\n        return res;\n    }\n};\n\n\n#line 3 \"Graph/Kruskal.hpp\"\n\
    \n/*\u30AF\u30E9\u30B9\u30AB\u30EB\u6CD5*/\nstruct Edge{\n    int from;\n    int\
    \ to;\n    long cost;\n};\n\nusing Graph = vector<vector<Edge>>;\n\nstruct Kruskal{\n\
    \    vector<Edge> edges;\n    Graph G;\n    int V;\n    Kruskal(int V):V(V){\n\
    \        G.resize(V);\n    }\n    //\u7121\u5411\u30B0\u30E9\u30D5\uFF01\n   \
    \ void addEdge(int from,int to,long cost){\n        edges.push_back({from,to,cost});\n\
    \    }\n    long long build(){\n        sort(edges.begin(),edges.end(),[](const\
    \ Edge& e1,const Edge& e2){\n            return e1.cost<e2.cost;\n        });\n\
    \        UnionFind uf(V);\n        long long res = 0;\n        for(auto& e:edges){\n\
    \            if(!uf.same(e.from,e.to)){\n                uf.unite(e.from,e.to);\n\
    \                res += e.cost;\n                G[e.from].push_back({e.from,e.to,e.cost});\n\
    \                G[e.to].push_back({e.to,e.from,e.cost});\n            }\n   \
    \     }\n        return res;\n    }\n};\n"
  code: "# include \"templete.hpp\"\n# include \"UnionFind.hpp\"\n\n/*\u30AF\u30E9\
    \u30B9\u30AB\u30EB\u6CD5*/\nstruct Edge{\n    int from;\n    int to;\n    long\
    \ cost;\n};\n\nusing Graph = vector<vector<Edge>>;\n\nstruct Kruskal{\n    vector<Edge>\
    \ edges;\n    Graph G;\n    int V;\n    Kruskal(int V):V(V){\n        G.resize(V);\n\
    \    }\n    //\u7121\u5411\u30B0\u30E9\u30D5\uFF01\n    void addEdge(int from,int\
    \ to,long cost){\n        edges.push_back({from,to,cost});\n    }\n    long long\
    \ build(){\n        sort(edges.begin(),edges.end(),[](const Edge& e1,const Edge&\
    \ e2){\n            return e1.cost<e2.cost;\n        });\n        UnionFind uf(V);\n\
    \        long long res = 0;\n        for(auto& e:edges){\n            if(!uf.same(e.from,e.to)){\n\
    \                uf.unite(e.from,e.to);\n                res += e.cost;\n    \
    \            G[e.from].push_back({e.from,e.to,e.cost});\n                G[e.to].push_back({e.to,e.from,e.cost});\n\
    \            }\n        }\n        return res;\n    }\n};\n"
  dependsOn:
  - templete.hpp
  - Graph/UnionFind.hpp
  isVerificationFile: false
  path: Graph/Kruskal.hpp
  requiredBy: []
  timestamp: '2023-11-16 00:45:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Graph/Kruskal.test.cpp
documentation_of: Graph/Kruskal.hpp
layout: document
title: "Kruskal's algorithm / \u30AF\u30E9\u30B9\u30AB\u30EB\u6CD5\u306B\u3088\u308B\
  \u6700\u5C0F\u5168\u57DF\u6728"
---

## 概要
最小全域木を求めます。

## 使い方
- `Kruskal(n)` : 頂点数`n`に設定します
- `addEdge(u,v,c)` : 頂点`u`と頂点`v`を結ぶ重み`c`の辺を追加します(無向辺)
- `build()` : 最小全域木を構築します

## 計算量
頂点数$N$、辺数$M$として、
- 構築(`build()`) : $O(N + M\log M)$

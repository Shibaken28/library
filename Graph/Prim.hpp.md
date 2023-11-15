---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: templete.hpp
    title: "templete / \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Graph/Prim.test.cpp
    title: Graph/Prim.test.cpp
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
    \    }\n    return in;\n}\n\n#line 2 \"Graph/Prim.hpp\"\n\nstruct Edge{\n    int\
    \ from;\n    int to;\n    long cost;\n};\n\nusing Graph = vector<vector<Edge>>;\n\
    using Pll = pair<long,long>;\n\n/*\u30D7\u30EA\u30E0\u6CD5*/\nstruct Prim{\n \
    \   Graph G;\n    int V;\n    Prim(int V):V(V){\n        G.resize(V);\n    }\n\
    \    //\u7121\u5411\u30B0\u30E9\u30D5\uFF01\n    void addEdge(int from,int to,long\
    \ cost){\n        G[from].push_back({from,to,cost});\n        G[to].push_back({to,from,cost});\n\
    \    }\n    long long build(){\n        long long res = 0;\n        vector<bool>\
    \ used(V,false);\n        priority_queue<Pll,vector<Pll>,greater<Pll>> que;\n\
    \        que.push({0,0});\n        while(!que.empty()){\n            auto [cost,\
    \ v] = que.top(); que.pop();\n            if(used[v])continue;\n            used[v]\
    \ = true;\n            res += cost;\n            for(auto& e:G[v]){\n        \
    \        if(!used[e.to]){\n                    que.push({e.cost,e.to});\n    \
    \            }\n            }\n        }\n        return res;\n    }\n};\n"
  code: "# include \"templete.hpp\"\n\nstruct Edge{\n    int from;\n    int to;\n\
    \    long cost;\n};\n\nusing Graph = vector<vector<Edge>>;\nusing Pll = pair<long,long>;\n\
    \n/*\u30D7\u30EA\u30E0\u6CD5*/\nstruct Prim{\n    Graph G;\n    int V;\n    Prim(int\
    \ V):V(V){\n        G.resize(V);\n    }\n    //\u7121\u5411\u30B0\u30E9\u30D5\uFF01\
    \n    void addEdge(int from,int to,long cost){\n        G[from].push_back({from,to,cost});\n\
    \        G[to].push_back({to,from,cost});\n    }\n    long long build(){\n   \
    \     long long res = 0;\n        vector<bool> used(V,false);\n        priority_queue<Pll,vector<Pll>,greater<Pll>>\
    \ que;\n        que.push({0,0});\n        while(!que.empty()){\n            auto\
    \ [cost, v] = que.top(); que.pop();\n            if(used[v])continue;\n      \
    \      used[v] = true;\n            res += cost;\n            for(auto& e:G[v]){\n\
    \                if(!used[e.to]){\n                    que.push({e.cost,e.to});\n\
    \                }\n            }\n        }\n        return res;\n    }\n};\n"
  dependsOn:
  - templete.hpp
  isVerificationFile: false
  path: Graph/Prim.hpp
  requiredBy: []
  timestamp: '2023-11-16 00:45:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Graph/Prim.test.cpp
documentation_of: Graph/Prim.hpp
layout: document
title: "Prim's algorithm / \u30D7\u30EA\u30E0\u6CD5\u306B\u3088\u308B\u6700\u5C0F\u5168\
  \u57DF\u6728"
---

## 概要
最小全域木を求めます。

## 使い方
- `Prim(n)` : 頂点数`n`に設定します
- `addEdge(u,v,c)` : 頂点`u`と頂点`v`を結ぶ重み`c`の辺を追加します(無向辺)
- `build()` : 最小全域木を構築します

## 計算量
頂点数$N$、辺数$M$として、
- 構築(`build()`) : $O(M\log N)$

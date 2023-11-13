---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Graph/Dijkstra.test.cpp
    title: Graph/Dijkstra.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Graph/Dijkstra.hpp\"\n# include <vector>\n# include <queue>\n\
    # include <functional>\nusing namespace std;\n\nstruct Edge{\n    int to;\n  \
    \  long cost;\n};\n\nstruct WeightedVertex{\n    int v;\n    long cost;\n};\n\n\
    using Graph = vector<vector<Edge>>;\n\nvoid dijkstra(int s,Graph &G,vector<long>&D){\n\
    \    auto comp = [](WeightedVertex &l,WeightedVertex &r){return l.cost > r.cost;};\n\
    \    priority_queue < \n        WeightedVertex,\n        vector<WeightedVertex>,\n\
    \        function<bool(WeightedVertex&,WeightedVertex&)>\n        > qu (comp);\n\
    \    D.resize(G.size());\n    fill(D.begin(),D.end(),-1);\n    D[s] = 0;\n   \
    \ qu.push({s,0});\n    while(!qu.empty()){\n        auto a = qu.top(); qu.pop();\n\
    \        int from = a.v;\n        for(auto&e:G[from]){\n            if(D[e.to]\
    \ == -1 || D[e.to] > D[from] + e.cost){\n                D[e.to] = D[from] + e.cost;\n\
    \                qu.push({e.to,D[e.to]});\n            }\n        }\n    }\n}\n"
  code: "# include <vector>\n# include <queue>\n# include <functional>\nusing namespace\
    \ std;\n\nstruct Edge{\n    int to;\n    long cost;\n};\n\nstruct WeightedVertex{\n\
    \    int v;\n    long cost;\n};\n\nusing Graph = vector<vector<Edge>>;\n\nvoid\
    \ dijkstra(int s,Graph &G,vector<long>&D){\n    auto comp = [](WeightedVertex\
    \ &l,WeightedVertex &r){return l.cost > r.cost;};\n    priority_queue < \n   \
    \     WeightedVertex,\n        vector<WeightedVertex>,\n        function<bool(WeightedVertex&,WeightedVertex&)>\n\
    \        > qu (comp);\n    D.resize(G.size());\n    fill(D.begin(),D.end(),-1);\n\
    \    D[s] = 0;\n    qu.push({s,0});\n    while(!qu.empty()){\n        auto a =\
    \ qu.top(); qu.pop();\n        int from = a.v;\n        for(auto&e:G[from]){\n\
    \            if(D[e.to] == -1 || D[e.to] > D[from] + e.cost){\n              \
    \  D[e.to] = D[from] + e.cost;\n                qu.push({e.to,D[e.to]});\n   \
    \         }\n        }\n    }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/Dijkstra.hpp
  requiredBy: []
  timestamp: '2023-11-14 00:58:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Graph/Dijkstra.test.cpp
documentation_of: Graph/Dijkstra.hpp
layout: document
title: "Dijkstra's algorithm / \u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5\u306B\u3088\
  \u308B\u6700\u77ED\u7D4C\u8DEF"
---

## 概要
重みが非負のグラフにおいて、ある頂点から各頂点への最短経路を求めます。

## 計算量
頂点数$N$、辺数$M$として、$O((N+M)\log N)$

---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Graph/Floyd-Warshall.test.cpp
    title: Graph/Floyd-Warshall.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Graph/Floyd-Warshall.hpp\"\n# include <vector>\nusing namespace\
    \ std;\n\n/*\nG\u306F\u96A3\u63A5\u884C\u5217\u3067\u3042\u308B\u5FC5\u8981\u304C\
    \u3042\u308A\uFF0C\u8FBA\u304C\u306A\u3044\u5834\u5408\u306FINF\uFF0C\u81EA\u5DF1\
    \u30EB\u30FC\u30D7\u8FBA\u306F0\n*/\nconst long INF = 1e17;\n\nvector<vector<long>>\
    \ floydWarshall(vector<vector<long>> &G){\n    const int N = G.size();\n    auto\
    \ H = G;\n    for(int a=0;a<N;a++){\n        for(int b=0;b<N;b++){\n         \
    \   for(int c=0;c<N;c++){\n                long d = H[b][a] + H[a][c];\n     \
    \           if(H[b][a]==INF||H[a][c]==INF)d = INF;\n                if(H[b][c]\
    \ > d){\n                    H[b][c] = d;\n                }\n            }\n\
    \        }\n    }\n    return H;\n}\n"
  code: "# include <vector>\nusing namespace std;\n\n/*\nG\u306F\u96A3\u63A5\u884C\
    \u5217\u3067\u3042\u308B\u5FC5\u8981\u304C\u3042\u308A\uFF0C\u8FBA\u304C\u306A\
    \u3044\u5834\u5408\u306FINF\uFF0C\u81EA\u5DF1\u30EB\u30FC\u30D7\u8FBA\u306F0\n\
    */\nconst long INF = 1e17;\n\nvector<vector<long>> floydWarshall(vector<vector<long>>\
    \ &G){\n    const int N = G.size();\n    auto H = G;\n    for(int a=0;a<N;a++){\n\
    \        for(int b=0;b<N;b++){\n            for(int c=0;c<N;c++){\n          \
    \      long d = H[b][a] + H[a][c];\n                if(H[b][a]==INF||H[a][c]==INF)d\
    \ = INF;\n                if(H[b][c] > d){\n                    H[b][c] = d;\n\
    \                }\n            }\n        }\n    }\n    return H;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/Floyd-Warshall.hpp
  requiredBy: []
  timestamp: '2023-11-14 00:58:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Graph/Floyd-Warshall.test.cpp
documentation_of: Graph/Floyd-Warshall.hpp
layout: document
title: "Floyd-Warshall algorithm / \u30D5\u30ED\u30A4\u30C9\u30EF\u30FC\u30B7\u30E3\
  \u30EB\u6CD5\u306B\u3088\u308B\u5168\u70B9\u5BFE\u6700\u77ED\u7D4C\u8DEF"
---

## 概要
グラフで、全ての頂点間の最短経路を求めます。重みが負の辺があっても動作します。負閉路がある場合は、その旨を報告します。

## 計算量
頂点数$N$として、$O(N^3)$

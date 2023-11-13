---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/Dijkstra.hpp
    title: "Dijkstra's algorithm / \u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5\u306B\
      \u3088\u308B\u6700\u77ED\u7D4C\u8DEF"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_A
  bundledCode: "#line 1 \"Graph/Dijkstra.test.cpp\"\n# define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_A\"\
    \n# include <iostream>\n#line 1 \"Graph/Dijkstra.hpp\"\n# include <vector>\n#\
    \ include <queue>\n# include <functional>\nusing namespace std;\n\nstruct Edge{\n\
    \    int to;\n    long cost;\n};\n\nstruct WeightedVertex{\n    int v;\n    long\
    \ cost;\n};\n\nusing Graph = vector<vector<Edge>>;\n\nvoid dijkstra(int s,Graph\
    \ &G,vector<long>&D){\n    auto comp = [](WeightedVertex &l,WeightedVertex &r){return\
    \ l.cost > r.cost;};\n    priority_queue < \n        WeightedVertex,\n       \
    \ vector<WeightedVertex>,\n        function<bool(WeightedVertex&,WeightedVertex&)>\n\
    \        > qu (comp);\n    D.resize(G.size());\n    fill(D.begin(),D.end(),-1);\n\
    \    D[s] = 0;\n    qu.push({s,0});\n    while(!qu.empty()){\n        auto a =\
    \ qu.top(); qu.pop();\n        int from = a.v;\n        for(auto&e:G[from]){\n\
    \            if(D[e.to] == -1 || D[e.to] > D[from] + e.cost){\n              \
    \  D[e.to] = D[from] + e.cost;\n                qu.push({e.to,D[e.to]});\n   \
    \         }\n        }\n    }\n}\n#line 4 \"Graph/Dijkstra.test.cpp\"\nusing namespace\
    \ std;\n\nint main(){\n    Graph g;\n    int n,m,r;\n    cin >> n >> m >> r;\n\
    \    g.resize(n);\n    for(int i=0;i<m;i++){\n        int s,t,d;\n        cin\
    \ >> s >> t >> d;\n        g[s].push_back({t,d});\n    }\n    vector<long> d;\n\
    \    dijkstra(r,g,d);\n    for(int i=0;i<n;i++){\n        if(d[i] == -1)cout <<\
    \ \"INF\" << endl;\n        else cout << d[i] << endl;\n    }\n}\n\n"
  code: "# define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_A\"\
    \n# include <iostream>\n# include \"Dijkstra.hpp\"\nusing namespace std;\n\nint\
    \ main(){\n    Graph g;\n    int n,m,r;\n    cin >> n >> m >> r;\n    g.resize(n);\n\
    \    for(int i=0;i<m;i++){\n        int s,t,d;\n        cin >> s >> t >> d;\n\
    \        g[s].push_back({t,d});\n    }\n    vector<long> d;\n    dijkstra(r,g,d);\n\
    \    for(int i=0;i<n;i++){\n        if(d[i] == -1)cout << \"INF\" << endl;\n \
    \       else cout << d[i] << endl;\n    }\n}\n\n"
  dependsOn:
  - Graph/Dijkstra.hpp
  isVerificationFile: true
  path: Graph/Dijkstra.test.cpp
  requiredBy: []
  timestamp: '2023-11-14 00:58:48+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Graph/Dijkstra.test.cpp
layout: document
redirect_from:
- /verify/Graph/Dijkstra.test.cpp
- /verify/Graph/Dijkstra.test.cpp.html
title: Graph/Dijkstra.test.cpp
---

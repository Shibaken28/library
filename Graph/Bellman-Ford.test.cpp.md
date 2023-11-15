---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/Bellman-Ford.hpp
    title: "Bellman-Ford algorithm / \u30D9\u30EB\u30DE\u30F3\u30D5\u30A9\u30FC\u30C9\
      \u6CD5\u306B\u3088\u308B\u6700\u77ED\u7D4C"
  - icon: ':heavy_check_mark:'
    path: templete.hpp
    title: "templete / \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_B
  bundledCode: "#line 1 \"Graph/Bellman-Ford.test.cpp\"\n# define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_B\"\
    \n# include <iostream>\n#line 2 \"templete.hpp\"\n\n#line 4 \"templete.hpp\"\n\
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
    \    }\n    return in;\n}\n\n#line 2 \"Graph/Bellman-Ford.hpp\"\n\nstruct Edge{\n\
    \    int from;\n    int to;\n    long cost;\n};\n\nstruct WeightedVertex{\n  \
    \  int v;\n    long cost;\n};\n\nusing Graph = vector<vector<Edge>>; //\u96A3\u63A5\
    \u30B0\u30E9\u30D5\n\nconst long INF = 1e17; \n\n/*\n\u91CD\u307F\u306Flong\u578B\
    \n\u59CB\u70B9s\uFF0C\u30B0\u30E9\u30D5G\u306E\u70B9\u3092D\u306B\n\u623B\u308A\
    \u5024\u306F **s\u304B\u3089g\u306E\u7D4C\u8DEF** \u3092\u4F5C\u308B\u3068\u304D\
    \u306B\u91CD\u307F\u304C\u8CA0\u306E\u7121\u9650\u306B\u306A\u308B\u304B\n*/\n\
    bool bellmanFord(int s,Graph &G,vector<long>&D){\n    const int N = G.size();\n\
    \    vector<Edge>edges;\n    for(auto A:G){\n        for(Edge& a:A){\n       \
    \     edges.push_back(a);\n        }\n    }\n    D.resize(N);\n    fill(D.begin(),D.end(),INF);\n\
    \    D[s] = 0;\n    for(int i=0;i<=N;i++){\n        for(auto&e:edges){\n     \
    \       long d = D[e.from] + e.cost;\n            if(D[e.from] < INF && D[e.to]\
    \ > d){\n                D[e.to] = d;\n                if(i==N){\n           \
    \         return true;\n                }\n            }\n        }\n    }\n \
    \   return false;\n}\n#line 4 \"Graph/Bellman-Ford.test.cpp\"\nusing namespace\
    \ std;\n\nint main(){\n    Graph g;\n    int n,m,r;\n    cin >> n >> m >> r;\n\
    \    g.resize(n);\n    for(int i=0;i<m;i++){\n        int s,t,d;\n        cin\
    \ >> s >> t >> d;\n        g[s].push_back({s,t,d});\n    }\n    vector<long> d;\n\
    \    if(bellmanFord(r,g,d)){\n        cout << \"NEGATIVE CYCLE\" << endl;\n  \
    \      return 0;\n    }else{\n        for(int i=0;i<n;i++){\n            if(d[i]\
    \ == INF)cout << \"INF\" << endl;\n            else cout << d[i] << endl;\n  \
    \      }\n    }\n}\n\n"
  code: "# define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_B\"\
    \n# include <iostream>\n# include \"Bellman-Ford.hpp\"\nusing namespace std;\n\
    \nint main(){\n    Graph g;\n    int n,m,r;\n    cin >> n >> m >> r;\n    g.resize(n);\n\
    \    for(int i=0;i<m;i++){\n        int s,t,d;\n        cin >> s >> t >> d;\n\
    \        g[s].push_back({s,t,d});\n    }\n    vector<long> d;\n    if(bellmanFord(r,g,d)){\n\
    \        cout << \"NEGATIVE CYCLE\" << endl;\n        return 0;\n    }else{\n\
    \        for(int i=0;i<n;i++){\n            if(d[i] == INF)cout << \"INF\" <<\
    \ endl;\n            else cout << d[i] << endl;\n        }\n    }\n}\n\n"
  dependsOn:
  - Graph/Bellman-Ford.hpp
  - templete.hpp
  isVerificationFile: true
  path: Graph/Bellman-Ford.test.cpp
  requiredBy: []
  timestamp: '2023-11-14 13:45:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Graph/Bellman-Ford.test.cpp
layout: document
redirect_from:
- /verify/Graph/Bellman-Ford.test.cpp
- /verify/Graph/Bellman-Ford.test.cpp.html
title: Graph/Bellman-Ford.test.cpp
---
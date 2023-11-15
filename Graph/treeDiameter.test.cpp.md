---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/treeDiameter.hpp
    title: "Tree Diameter / \u6728\u306E\u76F4\u5F84"
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_A
  bundledCode: "#line 1 \"Graph/treeDiameter.test.cpp\"\n# define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_A\"\
    \n#line 2 \"templete.hpp\"\n\n#include <iostream> // cout, endl, cin\n#include\
    \ <string> // string, to_string, stoi\n#include <vector> // vector\n#include <algorithm>\
    \ // min, max, swap, sort, reverse, lower_bound, upper_bound\n#include <utility>\
    \ // pair, make_pair\n#include <tuple> // tuple, make_tuple\n#include <cstdint>\
    \ // int64_t, int*_t\n#include <cstdio> // printf\n#include <map> // map\n#include\
    \ <queue> // queue, priority_queue\n#include <set> // set\n#include <stack> //\
    \ stack\n#include <deque> // deque\n#include <unordered_map> // unordered_map\n\
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
    \    }\n    return in;\n}\n\n#line 2 \"Graph/treeDiameter.hpp\"\n\n// \u6728\u306E\
    \u76F4\u5F84\u3092\u6C42\u3081\u308B\n\nusing CostT = long long;\n\n\nstruct Edge{\n\
    \    int to;\n    CostT cost;\n};\n\nusing Graph = vector<vector<Edge>>;\n\nvoid\
    \ dfs(Graph &G,int v,int p,long d,vector<CostT>&dist){\n    // v:\u73FE\u5728\u306E\
    \u9802\u70B9\n    // p:\u89AA\u306E\u9802\u70B9\n    // d:\u73FE\u5728\u306E\u8DDD\
    \u96E2\n    dist[v] = d;\n    for(auto& e:G[v]){\n        if(e.to!=p){\n     \
    \       dfs(G,e.to,v,d+e.cost,dist);\n        }\n    }\n}\n\npair<int,CostT> treeDiameter(Graph\
    \ &G){\n    // \u6728\u306E\u76F4\u5F84\u3092\u6C42\u3081\u308B\n    // return:\
    \ (\u76F4\u5F84\u306E\u7AEF\u70B9\u306E\u3046\u3061\u306E\u4E00\u3064,\u76F4\u5F84\
    \u306E\u91CD\u3055)\n    int n = G.size();\n    vector<CostT> dist(n);\n    dfs(G,0,-1,0,dist);\n\
    \    int u = max_element(dist.begin(),dist.end())-dist.begin();\n    dfs(G,u,-1,0,dist);\n\
    \    int v = max_element(dist.begin(),dist.end())-dist.begin();\n    return {v,dist[v]};\n\
    }\n#line 3 \"Graph/treeDiameter.test.cpp\"\n\nint main(){\n    int n;cin>>n;\n\
    \    Graph G(n);\n    for(int i=0;i<n-1;i++){\n        int s,t,w;cin>>s>>t>>w;\n\
    \        G[s].push_back({t,w});\n        G[t].push_back({s,w});\n    }\n    auto\
    \ res = treeDiameter(G);\n    cout<<res.second<<endl;\n}\n"
  code: "# define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_A\"\n\
    # include \"treeDiameter.hpp\"\n\nint main(){\n    int n;cin>>n;\n    Graph G(n);\n\
    \    for(int i=0;i<n-1;i++){\n        int s,t,w;cin>>s>>t>>w;\n        G[s].push_back({t,w});\n\
    \        G[t].push_back({s,w});\n    }\n    auto res = treeDiameter(G);\n    cout<<res.second<<endl;\n\
    }\n"
  dependsOn:
  - Graph/treeDiameter.hpp
  - templete.hpp
  isVerificationFile: true
  path: Graph/treeDiameter.test.cpp
  requiredBy: []
  timestamp: '2023-11-16 00:45:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Graph/treeDiameter.test.cpp
layout: document
redirect_from:
- /verify/Graph/treeDiameter.test.cpp
- /verify/Graph/treeDiameter.test.cpp.html
title: Graph/treeDiameter.test.cpp
---

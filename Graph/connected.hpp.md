---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: templete.hpp
    title: "templete / \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy:
  - icon: ':x:'
    path: Graph/twoEdgeConnected.hpp
    title: "Two Edge Connected Components / \u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\
      \u5206\u89E3"
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Graph/twoEdgeConnected.test.cpp
    title: Graph/twoEdgeConnected.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
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
    \    }\n    return in;\n}\n\n#line 2 \"Graph/connected.hpp\"\n\nusing Graph =\
    \ vector<vector<int>>;\n\n// \u9023\u7D50\u6210\u5206\u3092\u6C42\u3081\u308B\n\
    struct ConnectedComponents{\n    int v;\n    vector<vector<int>> groups;\n   \
    \ vector<int> id;\n    Graph &G;\n    ConnectedComponents(Graph &G) : G(G) {\n\
    \        v = (int)G.size();\n        id.resize(v, -1);\n        int k = 0;\n \
    \       for(int i = 0; i < v; i++){\n            if(id[i] == -1){\n          \
    \      vector<int> group;\n                dfs(i, k, group);\n               \
    \ k++;\n                groups.push_back(group);\n            }\n        }\n \
    \   }\n\n    void dfs(int n, int k, vector<int> &group){\n        id[n] = k;\n\
    \        group.push_back(n);\n        for(auto& e : G[n]){\n            if(id[e]\
    \ == -1) dfs(e, k, group);\n        }\n    }\n};\n"
  code: "# include \"templete.hpp\"\n\nusing Graph = vector<vector<int>>;\n\n// \u9023\
    \u7D50\u6210\u5206\u3092\u6C42\u3081\u308B\nstruct ConnectedComponents{\n    int\
    \ v;\n    vector<vector<int>> groups;\n    vector<int> id;\n    Graph &G;\n  \
    \  ConnectedComponents(Graph &G) : G(G) {\n        v = (int)G.size();\n      \
    \  id.resize(v, -1);\n        int k = 0;\n        for(int i = 0; i < v; i++){\n\
    \            if(id[i] == -1){\n                vector<int> group;\n          \
    \      dfs(i, k, group);\n                k++;\n                groups.push_back(group);\n\
    \            }\n        }\n    }\n\n    void dfs(int n, int k, vector<int> &group){\n\
    \        id[n] = k;\n        group.push_back(n);\n        for(auto& e : G[n]){\n\
    \            if(id[e] == -1) dfs(e, k, group);\n        }\n    }\n};"
  dependsOn:
  - templete.hpp
  isVerificationFile: false
  path: Graph/connected.hpp
  requiredBy:
  - Graph/twoEdgeConnected.hpp
  timestamp: '2023-12-30 18:30:06+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Graph/twoEdgeConnected.test.cpp
documentation_of: Graph/connected.hpp
layout: document
title: "Connected Components / \u9023\u7D50\u6210\u5206\u5206\u89E3"
---

## 概要
グラフを連結成分に分解します。

## 計算量
頂点数$N$、辺数$M$として、$O(N+M)$



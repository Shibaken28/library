---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: templete.hpp
    title: "templete / \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Graph/2SAT.hpp
    title: "2-SAT / \u5145\u8DB3\u53EF\u80FD\u6027\u554F\u984C"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Graph/2SAT.test.cpp
    title: Graph/2SAT.test.cpp
  - icon: ':heavy_check_mark:'
    path: Graph/SCC.test.cpp
    title: Graph/SCC.test.cpp
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
    \    }\n    return in;\n}\n\n#line 2 \"Graph/SCC.hpp\"\n\nusing Graph = vector<vector<int>>;\n\
    struct StronglyConnectedComponents{\n    Graph &G;\n    Graph invG;\n    vector<int>\
    \ ord, visit, inv;\n    vector<vector<int>> groups;\n    StronglyConnectedComponents(Graph\
    \ &_G): G(_G){\n        int v = (int)G.size();\n        invG.resize(v);\n    \
    \    for(int i=0;i<v;i++){\n            for(auto&g:G[i]){\n                invG[g].push_back(i);\n\
    \            }\n        }\n        // DFS\u3092\u3059\u308B\n        ord.resize(v,\
    \ -1);\n        inv.resize(v, -1);\n        visit.resize(v, 0);\n        int k\
    \ = 0;\n        for(int i=0;i<v;i++){\n            if(ord[i]==-1)k = dfs(i, k);\n\
    \        }\n        for(int i=0;i<v;i++){\n            inv[ord[i]] = i;\n    \
    \        ord[i] = -1;\n        }\n        // \u8FBA\u3092\u9006\u5411\u304D\u306B\
    \u3057\u3066DFS\n        k = 0;\n        for(int i=v-1;i>=0;i--){\n          \
    \  if(ord[inv[i]]==-1){\n                vector<int> group(0);\n             \
    \   k = dfs2(inv[i], k, group);\n                groups.push_back(group);  \n\
    \            }\n        }\n    }\n    int dfs(int n, int k){\n        if(visit[n])return\
    \ k;\n        visit[n] = 1;\n        for(auto&e:G[n]){\n            k = dfs(e,\
    \ k);\n        }\n        ord[n] = k++;\n        return k;\n    }\n    int dfs2(int\
    \ n,int k, vector<int>&group){\n        group.push_back(n);\n        ord[n] =\
    \ k++;\n        for(auto&e:invG[n]){\n            if(ord[e]==-1){\n          \
    \      k = dfs2(e, k, group);\n            }\n        }\n        return k;\n \
    \   }\n};\n"
  code: "# include \"templete.hpp\"\n\nusing Graph = vector<vector<int>>;\nstruct\
    \ StronglyConnectedComponents{\n    Graph &G;\n    Graph invG;\n    vector<int>\
    \ ord, visit, inv;\n    vector<vector<int>> groups;\n    StronglyConnectedComponents(Graph\
    \ &_G): G(_G){\n        int v = (int)G.size();\n        invG.resize(v);\n    \
    \    for(int i=0;i<v;i++){\n            for(auto&g:G[i]){\n                invG[g].push_back(i);\n\
    \            }\n        }\n        // DFS\u3092\u3059\u308B\n        ord.resize(v,\
    \ -1);\n        inv.resize(v, -1);\n        visit.resize(v, 0);\n        int k\
    \ = 0;\n        for(int i=0;i<v;i++){\n            if(ord[i]==-1)k = dfs(i, k);\n\
    \        }\n        for(int i=0;i<v;i++){\n            inv[ord[i]] = i;\n    \
    \        ord[i] = -1;\n        }\n        // \u8FBA\u3092\u9006\u5411\u304D\u306B\
    \u3057\u3066DFS\n        k = 0;\n        for(int i=v-1;i>=0;i--){\n          \
    \  if(ord[inv[i]]==-1){\n                vector<int> group(0);\n             \
    \   k = dfs2(inv[i], k, group);\n                groups.push_back(group);  \n\
    \            }\n        }\n    }\n    int dfs(int n, int k){\n        if(visit[n])return\
    \ k;\n        visit[n] = 1;\n        for(auto&e:G[n]){\n            k = dfs(e,\
    \ k);\n        }\n        ord[n] = k++;\n        return k;\n    }\n    int dfs2(int\
    \ n,int k, vector<int>&group){\n        group.push_back(n);\n        ord[n] =\
    \ k++;\n        for(auto&e:invG[n]){\n            if(ord[e]==-1){\n          \
    \      k = dfs2(e, k, group);\n            }\n        }\n        return k;\n \
    \   }\n};\n"
  dependsOn:
  - templete.hpp
  isVerificationFile: false
  path: Graph/SCC.hpp
  requiredBy:
  - Graph/2SAT.hpp
  timestamp: '2023-11-17 03:21:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Graph/2SAT.test.cpp
  - Graph/SCC.test.cpp
documentation_of: Graph/SCC.hpp
layout: document
title: "Strongly Connected Components / \u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3"
---

## 概要
与えられた有向グラフを強連結成分に分解します。
分解された各強連結成分は、トポロジカル順序でソートされます。

## 計算量
頂点数$N$、辺数$M$として、$O(N+M)$
---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: templete.hpp
    title: "templete / \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Graph/topological.test.cpp
    title: Graph/topological.test.cpp
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
    \    }\n    return in;\n}\n\n#line 2 \"Graph/topological.hpp\"\n\nusing Graph\
    \ = vector<vector<int>>;\n// \u30B0\u30E9\u30D5\u304CDAG\u3067\u3042\u308B\n//\
    \ \u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\nvector<int> topologicalSort(Graph\
    \ &G){\n    // \u5165\u6B21\u6570\u3092\u6570\u3048\u308B\n    vector<int> in(G.size(),0);\n\
    \    for(auto&g:G){\n        for(auto&h:g){\n            in[h]++;\n        }\n\
    \    }\n    // \u5165\u6B21\u6570\u304C0\u306E\u3082\u306E\u3092\u30AD\u30E5\u30FC\
    \u306B\u5165\u308C\u308B\n    queue<int> q;\n    for(int i=0;i<(int)G.size();i++){\n\
    \        if(in[i]==0){\n            q.push(i);\n        }\n    }\n    // \u5165\
    \u6B21\u6570\u304C0\u306E\u3082\u306E\u3092\u53D6\u308A\u51FA\u3057\u3066\u3001\
    \u305D\u306E\u9802\u70B9\u304B\u3089\u51FA\u3066\u3044\u308B\u8FBA\u3092\u524A\
    \u9664\u3059\u308B\n    vector<int> ans;\n    while(!q.empty()){\n        int\
    \ n=q.front(); q.pop();\n        ans.push_back(n);\n        for(auto&g:G[n]){\n\
    \            in[g]--;\n            if(in[g]==0){\n                q.push(g);\n\
    \            }\n        }\n    }\n    return ans;\n}\n"
  code: "# include \"templete.hpp\"\n\nusing Graph = vector<vector<int>>;\n// \u30B0\
    \u30E9\u30D5\u304CDAG\u3067\u3042\u308B\n// \u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\
    \u30BD\u30FC\u30C8\nvector<int> topologicalSort(Graph &G){\n    // \u5165\u6B21\
    \u6570\u3092\u6570\u3048\u308B\n    vector<int> in(G.size(),0);\n    for(auto&g:G){\n\
    \        for(auto&h:g){\n            in[h]++;\n        }\n    }\n    // \u5165\
    \u6B21\u6570\u304C0\u306E\u3082\u306E\u3092\u30AD\u30E5\u30FC\u306B\u5165\u308C\
    \u308B\n    queue<int> q;\n    for(int i=0;i<(int)G.size();i++){\n        if(in[i]==0){\n\
    \            q.push(i);\n        }\n    }\n    // \u5165\u6B21\u6570\u304C0\u306E\
    \u3082\u306E\u3092\u53D6\u308A\u51FA\u3057\u3066\u3001\u305D\u306E\u9802\u70B9\
    \u304B\u3089\u51FA\u3066\u3044\u308B\u8FBA\u3092\u524A\u9664\u3059\u308B\n   \
    \ vector<int> ans;\n    while(!q.empty()){\n        int n=q.front(); q.pop();\n\
    \        ans.push_back(n);\n        for(auto&g:G[n]){\n            in[g]--;\n\
    \            if(in[g]==0){\n                q.push(g);\n            }\n      \
    \  }\n    }\n    return ans;\n}\n"
  dependsOn:
  - templete.hpp
  isVerificationFile: false
  path: Graph/topological.hpp
  requiredBy: []
  timestamp: '2023-11-16 21:58:22+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Graph/topological.test.cpp
documentation_of: Graph/topological.hpp
layout: document
redirect_from:
- /library/Graph/topological.hpp
- /library/Graph/topological.hpp.html
title: Graph/topological.hpp
---

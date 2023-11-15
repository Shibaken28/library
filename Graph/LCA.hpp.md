---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: templete.hpp
    title: "templete / \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Graph/LCA.test.cpp
    title: Graph/LCA.test.cpp
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
    \    }\n    return in;\n}\n\n#line 2 \"Graph/LCA.hpp\"\n\nstruct Edge{\n    int\
    \ to;\n};\n\nusing Graph = vector<vector<Edge>>;\n\nstruct LCA{\n    Graph G;\n\
    \    vector<vector<int>> ancestor;\n    //ancestor[i][j]:=\u9802\u70B9i\u306E\
    2^j\u500B\u89AA\n    vector<int> depth;//\u6DF1\u3055\n    int N;\n    int root\
    \ = 0;\n    const int maxDepth = 25;\n    LCA(int _N){\n        this-> N = _N;\n\
    \        init();\n    }\n    void init(){\n        G.resize(N);\n        depth.resize(N);\n\
    \        ancestor.resize(N);\n        for(int i=0;i<N;i++){\n            ancestor[i].resize(maxDepth);\n\
    \        }\n    }\n    void build(){\n        ancestor[root][0] = root;\n    \
    \    bfs(root,root,0);\n        for(int i=1;i<maxDepth;i++){\n            for(int\
    \ j=0;j<N;j++){\n                ancestor[j][i] = ancestor[ancestor[j][i-1]][i-1];\n\
    \            }\n        }\n    }\n    void bfs(int n,int pre,int d){\n       \
    \ depth[n] = d;\n        ancestor[n][0] = pre;\n        for(auto&E:G[n]){\n  \
    \          if(E.to==pre)continue;\n            bfs(E.to,n,d+1);\n        }\n \
    \   }\n    //\u9802\u70B9n\u306Es\u500B\u5148\u306E\u7956\u5148\n    int anc(int\
    \ n,int s){\n        for(int i=0;i<maxDepth;i++){\n            if(s&(1<<i)){\n\
    \                n = ancestor[n][i];\n            }\n        }\n        return\
    \ n;\n    }\n    //\u9802\u70B9n\u306E\u6DF1\u3055s(root=0)\u306E\u7956\u5148\n\
    \    int levelAnc(int n,int s){\n        return anc(n,depth[n]-s);\n    }\n  \
    \  //\u9802\u70B9a,b\u306E\u5171\u901A\u6700\u8FD1\u7956\u5148\n    int lca(int\
    \ a,int b){\n        if(depth[a]<depth[b])swap(a,b);\n        a = levelAnc(a,depth[b]);//\u540C\
    \u3058\u6DF1\u3055\u306B\u3059\u308B\n        if(a==b)return a;\n        for(int\
    \ k=maxDepth-1;k>=0;k--){\n            if(ancestor[a][k]!=ancestor[b][k]){\n \
    \               a = ancestor[a][k];\n                b = ancestor[b][k];\n   \
    \         }\n        }\n        return ancestor[a][0];\n    }\n};\n"
  code: "# include \"templete.hpp\"\n\nstruct Edge{\n    int to;\n};\n\nusing Graph\
    \ = vector<vector<Edge>>;\n\nstruct LCA{\n    Graph G;\n    vector<vector<int>>\
    \ ancestor;\n    //ancestor[i][j]:=\u9802\u70B9i\u306E2^j\u500B\u89AA\n    vector<int>\
    \ depth;//\u6DF1\u3055\n    int N;\n    int root = 0;\n    const int maxDepth\
    \ = 25;\n    LCA(int _N){\n        this-> N = _N;\n        init();\n    }\n  \
    \  void init(){\n        G.resize(N);\n        depth.resize(N);\n        ancestor.resize(N);\n\
    \        for(int i=0;i<N;i++){\n            ancestor[i].resize(maxDepth);\n  \
    \      }\n    }\n    void build(){\n        ancestor[root][0] = root;\n      \
    \  bfs(root,root,0);\n        for(int i=1;i<maxDepth;i++){\n            for(int\
    \ j=0;j<N;j++){\n                ancestor[j][i] = ancestor[ancestor[j][i-1]][i-1];\n\
    \            }\n        }\n    }\n    void bfs(int n,int pre,int d){\n       \
    \ depth[n] = d;\n        ancestor[n][0] = pre;\n        for(auto&E:G[n]){\n  \
    \          if(E.to==pre)continue;\n            bfs(E.to,n,d+1);\n        }\n \
    \   }\n    //\u9802\u70B9n\u306Es\u500B\u5148\u306E\u7956\u5148\n    int anc(int\
    \ n,int s){\n        for(int i=0;i<maxDepth;i++){\n            if(s&(1<<i)){\n\
    \                n = ancestor[n][i];\n            }\n        }\n        return\
    \ n;\n    }\n    //\u9802\u70B9n\u306E\u6DF1\u3055s(root=0)\u306E\u7956\u5148\n\
    \    int levelAnc(int n,int s){\n        return anc(n,depth[n]-s);\n    }\n  \
    \  //\u9802\u70B9a,b\u306E\u5171\u901A\u6700\u8FD1\u7956\u5148\n    int lca(int\
    \ a,int b){\n        if(depth[a]<depth[b])swap(a,b);\n        a = levelAnc(a,depth[b]);//\u540C\
    \u3058\u6DF1\u3055\u306B\u3059\u308B\n        if(a==b)return a;\n        for(int\
    \ k=maxDepth-1;k>=0;k--){\n            if(ancestor[a][k]!=ancestor[b][k]){\n \
    \               a = ancestor[a][k];\n                b = ancestor[b][k];\n   \
    \         }\n        }\n        return ancestor[a][0];\n    }\n};\n"
  dependsOn:
  - templete.hpp
  isVerificationFile: false
  path: Graph/LCA.hpp
  requiredBy: []
  timestamp: '2023-11-14 13:45:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Graph/LCA.test.cpp
documentation_of: Graph/LCA.hpp
layout: document
title: "Lowest Common Ancestor / \u6700\u5C0F\u5171\u901A\u7956\u5148"
---

## 概要
木構造に対して、2頂点の最小共通祖先を求めるデータ構造です

## 使い方
- `LCA(n)` : 頂点数`n`に設定します
- `G` : 隣接リストとして`G`に構築してください
- `build()` : `G`からLCAを構築します
- `anc(n,k)` : 頂点`n`の`k`個上の祖先を返します
- `lca(n,m)` : 頂点`n`と頂点`m`の最小共通祖先を返します
- `levelAnc(n,k)` : 頂点`n`の祖先で、深さが`k`のものを返します

## 計算量
- 頂点数 : $N$
- 構築(`build()`) : $O(N\log N)$
- その他のクエリ : $O(\log N)$

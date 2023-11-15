---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: templete.hpp
    title: "templete / \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Data-Structure/cumulative2D.test.cpp
    title: Data-Structure/cumulative2D.test.cpp
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
    \    }\n    return in;\n}\n\n#line 2 \"Data-Structure/cumulative2D.hpp\"\n\n\n\
    template<class T> struct CumulativeSum2D{\n    size_t H,W;\n    vector<vector<T>>data,A;\n\
    \    bool isBuild=false;\n    CumulativeSum2D(size_t H,size_t W){\n        this->H=H;\n\
    \        this->W=W;\n        data.resize(H+1,vector<T>(W+1,0));\n        A.resize(H+1,vector<T>(W+1,0));\n\
    \    }\n    void add(int y1,int x1,int y2,int x2,T x){\n        A[y1][x1]+=x;\n\
    \        A[y2][x1]-=x;\n        A[y1][x2]-=x;\n        A[y2][x2]+=x;\n    }\n\
    \    void add(int y1,int x1,T x){\n        add(y1,x1,y1+1,x1+1,x);\n    }\n  \
    \  void build(){\n        data=vector<vector<T>>(A.size()+1,vector<T>(A.front().size()+1,0));\n\
    \        \n        for(int _=0; _<2; _++){\n            for(size_t i=0; i<=H;\
    \ i++){\n                for(size_t j=0; j<W; j++){\n                    A[i][j+1]+=A[i][j];\n\
    \                }\n            }\n            for(size_t i=0; i<H; i++){\n  \
    \              for(size_t j=0; j<=W; j++){\n                    A[i+1][j]+=A[i][j];\n\
    \                }\n            }\n        }\n        for(size_t i=0; i<=H; i++){\n\
    \            for(size_t j=0; j<=W; j++){\n                data[i+1][j+1]=A[i][j];\n\
    \            }\n        }\n\n        isBuild=true;\n    }\n    T sum(int h1,int\
    \ w1,int h2,int w2){\n        if(!isBuild)build();\n        return data[h2][w2]-data[h1][w2]-data[h2][w1]+data[h1][w1];\n\
    \    }\n    T sum(int h1,int w1){\n        return sum(h1,w1,h1+1,w1+1);\n    }\n\
    };\n"
  code: "# include \"templete.hpp\"\n\n\ntemplate<class T> struct CumulativeSum2D{\n\
    \    size_t H,W;\n    vector<vector<T>>data,A;\n    bool isBuild=false;\n    CumulativeSum2D(size_t\
    \ H,size_t W){\n        this->H=H;\n        this->W=W;\n        data.resize(H+1,vector<T>(W+1,0));\n\
    \        A.resize(H+1,vector<T>(W+1,0));\n    }\n    void add(int y1,int x1,int\
    \ y2,int x2,T x){\n        A[y1][x1]+=x;\n        A[y2][x1]-=x;\n        A[y1][x2]-=x;\n\
    \        A[y2][x2]+=x;\n    }\n    void add(int y1,int x1,T x){\n        add(y1,x1,y1+1,x1+1,x);\n\
    \    }\n    void build(){\n        data=vector<vector<T>>(A.size()+1,vector<T>(A.front().size()+1,0));\n\
    \        \n        for(int _=0; _<2; _++){\n            for(size_t i=0; i<=H;\
    \ i++){\n                for(size_t j=0; j<W; j++){\n                    A[i][j+1]+=A[i][j];\n\
    \                }\n            }\n            for(size_t i=0; i<H; i++){\n  \
    \              for(size_t j=0; j<=W; j++){\n                    A[i+1][j]+=A[i][j];\n\
    \                }\n            }\n        }\n        for(size_t i=0; i<=H; i++){\n\
    \            for(size_t j=0; j<=W; j++){\n                data[i+1][j+1]=A[i][j];\n\
    \            }\n        }\n\n        isBuild=true;\n    }\n    T sum(int h1,int\
    \ w1,int h2,int w2){\n        if(!isBuild)build();\n        return data[h2][w2]-data[h1][w2]-data[h2][w1]+data[h1][w1];\n\
    \    }\n    T sum(int h1,int w1){\n        return sum(h1,w1,h1+1,w1+1);\n    }\n\
    };\n"
  dependsOn:
  - templete.hpp
  isVerificationFile: false
  path: Data-Structure/cumulative2D.hpp
  requiredBy: []
  timestamp: '2023-11-16 00:56:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Data-Structure/cumulative2D.test.cpp
documentation_of: Data-Structure/cumulative2D.hpp
layout: document
title: "2D cumulative sum / 2\u6B21\u5143\u7D2F\u7A4D\u548C"
---

## 概要
次の問題を解きます。
- $H \times W$のグリッドが与えられる。各マスの初期値は$0$である。
- $Q$個のクエリ$(x1_i, y1_i, x2_i, y2_i, x_i)$が与えられる。各クエリは、長方形の領域$[x1_i, x2_i) \times [y1_i, y2_i)$に$x_i$を加算することを意味する。
- $Q'$個のクエリ$(x1_i, y1_i, x2_i, y2_i)$が与えられる。各クエリは、長方形の領域$[x1_i, x2_i) \times [y1_i, y2_i)$の和を求めることを意味する。

## 注意
- 区間和のクエリは、すべての区間加算クエリを処理した後に行う必要がある。

## 計算量
- 各クエリの処理時間は$O(1)$である。
- 区間和のクエリの前準備として$O(HW)$の時間がかかる。

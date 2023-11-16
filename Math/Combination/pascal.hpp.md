---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: templete.hpp
    title: "templete / \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
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
    \    }\n    return in;\n}\n\n#line 2 \"Math/Combination/pascal.hpp\"\n\nstruct\
    \ Pascal{\n    //tri[a][b] = aCb\n    vector<vector<long>> tri;\n    int N;\n\
    \    Pascal(int N){\n        this->N = N;\n        init();\n    }\n    void init(){\n\
    \        tri.clear();\n        tri.push_back({1});\n        for(int i=1;i<N;i++){\n\
    \            vector<long> add(0);\n            add.push_back(1);\n           \
    \ for(int k=0;k<i-1;k++){\n                add.push_back(tri.back()[k]+tri.back()[k+1]);\n\
    \            }\n            add.push_back(1);\n            tri.push_back(add);\n\
    \        }\n    }\n    long com(int a,int b){\n        if(a<b)return 0;\n    \
    \    return tri[a][b];\n    }\n};\n"
  code: "# include \"templete.hpp\"\n\nstruct Pascal{\n    //tri[a][b] = aCb\n   \
    \ vector<vector<long>> tri;\n    int N;\n    Pascal(int N){\n        this->N =\
    \ N;\n        init();\n    }\n    void init(){\n        tri.clear();\n       \
    \ tri.push_back({1});\n        for(int i=1;i<N;i++){\n            vector<long>\
    \ add(0);\n            add.push_back(1);\n            for(int k=0;k<i-1;k++){\n\
    \                add.push_back(tri.back()[k]+tri.back()[k+1]);\n            }\n\
    \            add.push_back(1);\n            tri.push_back(add);\n        }\n \
    \   }\n    long com(int a,int b){\n        if(a<b)return 0;\n        return tri[a][b];\n\
    \    }\n};\n"
  dependsOn:
  - templete.hpp
  isVerificationFile: false
  path: Math/Combination/pascal.hpp
  requiredBy: []
  timestamp: '2023-11-14 13:45:06+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/Combination/pascal.hpp
layout: document
title: "Pascal's triangle / \u30D1\u30B9\u30AB\u30EB\u306E\u4E09\u89D2\u5F62\u306B\
  \u3088\u308B\u4E8C\u9805\u4FC2\u6570\u306E\u8A08\u7B97"
---

## 概要
パスカルの三角形を利用して$n$個のものから$r$個を選ぶ組み合わせの数を計算します

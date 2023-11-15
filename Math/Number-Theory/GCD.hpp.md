---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: templete.hpp
    title: "templete / \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Math/Number-Theory/CRT.test.cpp
    title: Math/Number-Theory/CRT.test.cpp
  - icon: ':heavy_check_mark:'
    path: Math/Number-Theory/GCD.test.cpp
    title: Math/Number-Theory/GCD.test.cpp
  - icon: ':heavy_check_mark:'
    path: Math/Number-Theory/LCM.test.cpp
    title: Math/Number-Theory/LCM.test.cpp
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
    \    }\n    return in;\n}\n\n#line 2 \"Math/Number-Theory/GCD.hpp\"\n\nlong GCD(long\
    \ a,long b){\n    if(a<b)return GCD(b,a);\n    if(b==0)return a;\n    return GCD(b,a%b);\n\
    }\n\nlong GCD(vector<long>&A){\n    long gcd = A.front();\n    for(auto&a:A)gcd\
    \ = GCD(gcd,a);\n    return gcd;\n}\n\nlong LCM(long a,long b){\n    return (a/GCD(a,b))*b;\n\
    }\n\n\nlong LCM(vector<long>&A){\n    long lcm = 1;\n    for(auto&a:A)lcm = LCM(lcm,a);\n\
    \    return lcm;\n}\n\n"
  code: "# include \"templete.hpp\"\n\nlong GCD(long a,long b){\n    if(a<b)return\
    \ GCD(b,a);\n    if(b==0)return a;\n    return GCD(b,a%b);\n}\n\nlong GCD(vector<long>&A){\n\
    \    long gcd = A.front();\n    for(auto&a:A)gcd = GCD(gcd,a);\n    return gcd;\n\
    }\n\nlong LCM(long a,long b){\n    return (a/GCD(a,b))*b;\n}\n\n\nlong LCM(vector<long>&A){\n\
    \    long lcm = 1;\n    for(auto&a:A)lcm = LCM(lcm,a);\n    return lcm;\n}\n\n"
  dependsOn:
  - templete.hpp
  isVerificationFile: false
  path: Math/Number-Theory/GCD.hpp
  requiredBy: []
  timestamp: '2023-11-14 13:45:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Math/Number-Theory/GCD.test.cpp
  - Math/Number-Theory/CRT.test.cpp
  - Math/Number-Theory/LCM.test.cpp
documentation_of: Math/Number-Theory/GCD.hpp
layout: document
title: "GCD, LCM / \u6700\u5927\u516C\u7D04\u6570\u3068\u6700\u5C0F\u516C\u500D\u6570"
---

## 概要
最大公約数(Greatest Common Divisor)と最小公倍数(Least Common Multiple)を求めます。

`vector`の入力にも対応しています

## 計算量
$O(\log \min(a,b))$



---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/Number-Theory/ext-euclid.hpp
    title: "Extended Euclidean algorithm / \u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\
      \u30C9\u306E\u4E92\u9664\u6CD5"
  - icon: ':question:'
    path: templete.hpp
    title: "templete / \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Math/Number-Theory/CRT.test.cpp
    title: Math/Number-Theory/CRT.test.cpp
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
    \    }\n    return in;\n}\n\n#line 1 \"Math/Number-Theory/ext-euclid.hpp\"\n//\
    \ \u62E1\u5F35Euclid\u306E\u4E92\u9664\u6CD5\n// ax + by = gcd(a, b) \u3068\u306A\
    \u308B\u3088\u3046\u306A (x, y) \u3092\u6C42\u3081\u308B \nlong extGCD(long a,\
    \ long b, long &x, long &y) {\n    if (b == 0) {\n        x = 1;\n        y =\
    \ 0;\n        return a;\n    }\n    long d = extGCD(b, a%b, y, x);\n    y -= a/b\
    \ * x;\n    return d;\n}\n#line 3 \"Math/Number-Theory/CRT.hpp\"\n\nlong mod(long\
    \ a,long m){\n    if(a>=0)return a%m; \n    return (m-(-a)%m)%m;\n}\n\n/*\n\u4E2D\
    \u56FD\u5270\u4F59\u5B9A\u7406\n*/\nbool CRT(long b1, long m1, long b2, long m2,long\
    \ &r,long &m) {\n    long p, q;\n    long d = extGCD(m1, m2, p, q);\n    if ((b2\
    \ - b1) % d != 0) return false;\n    m = m1 * (m2/d); \n    long tmp = (b2 - b1)\
    \ / d * p % (m2/d);\n    r = mod(b1 + m1 * tmp, m);\n    return true;\n}\n\nbool\
    \ CRT(const vector<pair<long,long>> &X,long &r,long &m) {\n    int s = X.size();\n\
    \    r = X.front().first;\n    m = X.front().second;\n    bool ok = true;\n  \
    \  for(int i=1;i<s;i++){\n        ok = CRT(r,m,X[i].first,X[i].second,r,m);\n\
    \        if(!ok){\n            break;\n        }\n    }\n    return ok;\n}\n\n"
  code: "# include \"templete.hpp\"\n# include \"ext-euclid.hpp\"\n\nlong mod(long\
    \ a,long m){\n    if(a>=0)return a%m; \n    return (m-(-a)%m)%m;\n}\n\n/*\n\u4E2D\
    \u56FD\u5270\u4F59\u5B9A\u7406\n*/\nbool CRT(long b1, long m1, long b2, long m2,long\
    \ &r,long &m) {\n    long p, q;\n    long d = extGCD(m1, m2, p, q);\n    if ((b2\
    \ - b1) % d != 0) return false;\n    m = m1 * (m2/d); \n    long tmp = (b2 - b1)\
    \ / d * p % (m2/d);\n    r = mod(b1 + m1 * tmp, m);\n    return true;\n}\n\nbool\
    \ CRT(const vector<pair<long,long>> &X,long &r,long &m) {\n    int s = X.size();\n\
    \    r = X.front().first;\n    m = X.front().second;\n    bool ok = true;\n  \
    \  for(int i=1;i<s;i++){\n        ok = CRT(r,m,X[i].first,X[i].second,r,m);\n\
    \        if(!ok){\n            break;\n        }\n    }\n    return ok;\n}\n\n"
  dependsOn:
  - templete.hpp
  - Math/Number-Theory/ext-euclid.hpp
  isVerificationFile: false
  path: Math/Number-Theory/CRT.hpp
  requiredBy: []
  timestamp: '2023-11-14 13:45:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Math/Number-Theory/CRT.test.cpp
documentation_of: Math/Number-Theory/CRT.hpp
layout: document
title: "Chinese Remainder Theorem / \u4E2D\u56FD\u5270\u4F59\u5B9A\u7406"
---

## 概要
次の問題を解きます。
- $N$個の整数の組$(A_i,B_i)$があります。
- すべての$i$について、$x$を$B_i$で割ったあまりが$A_i$となるような最小の非負整数$x$を求めてください。
- そのような$x$が存在しない場合はその旨を報告してください。

## 注意
- verifyに使用している問題『中華風(Easy)』は非負整数ではなく「正の整数」を求めています。

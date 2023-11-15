---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/Number-Theory/prime-factorize.hpp
    title: "prime factorize/ \u7D20\u56E0\u6570\u5206\u89E3"
  - icon: ':heavy_check_mark:'
    path: templete.hpp
    title: "templete / \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Math/Number-Theory/euler.test.cpp
    title: Math/Number-Theory/euler.test.cpp
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
    \    }\n    return in;\n}\n\n#line 2 \"Math/Number-Theory/prime-factorize.hpp\"\
    \n\n//\u7D20\u56E0\u6570\u5206\u89E3\nvector<long> factor(long x){\n    vector<long>\
    \ f(0);\n    for(long i=2;i*i<=x;i++){\n        if(x%i==0){\n            f.push_back(i);\n\
    \            x/=i;\n            i--;\n        }\n    }\n    if(x>1)f.push_back(x);\n\
    \    return f;\n}\n\n//\u7D20\u56E0\u6570\u5206\u89E32\n// (\u7D20\u6570,\u6307\
    \u6570) \u306Epair\nvector<pair<long,long>> factor2(long x){\n    auto f = factor(x);\n\
    \    vector<pair<long,long>> f2(0);\n    for(auto a:f){\n        if(f2.empty()){\n\
    \            f2.push_back({a,1});\n        }else if(f2.back().first==a){\n   \
    \         f2.back().second ++;\n        }else{\n            f2.push_back({a,1});\n\
    \        }\n    }\n    return f2;\n}\n#line 3 \"Math/Number-Theory/euler.hpp\"\
    \n\nlong power(long a, long b){\n    long ret = 1;\n    while(b){\n        if(b&1)ret\
    \ *= a;\n        a *= a;\n        b >>= 1;\n    }\n    return ret;\n}\n\n\nlong\
    \ euler(long n){\n    if(n<=1)return 0;\n    // \u30AA\u30A4\u30E9\u30FC\u95A2\
    \u6570\n    // p1^e1 * p2^e2 * ... * pk^ek \u306B\u5BFE\u3057\u3066\n    // (p1-1)*p1^(e1-1)\
    \ * (p2-1)*p2^(e2-1) * ... * (pk-1)*pk^(ek-1)\n    // \u3092\u8FD4\u3059\n   \
    \ auto f = factor2(n);\n    long ret = 1;\n    for(auto[p,e]:f){\n        ret\
    \ *= (p-1)*power(p,e-1);\n    }\n    return ret;\n}\n"
  code: "# include \"templete.hpp\"\n# include \"prime-factorize.hpp\"\n\nlong power(long\
    \ a, long b){\n    long ret = 1;\n    while(b){\n        if(b&1)ret *= a;\n  \
    \      a *= a;\n        b >>= 1;\n    }\n    return ret;\n}\n\n\nlong euler(long\
    \ n){\n    if(n<=1)return 0;\n    // \u30AA\u30A4\u30E9\u30FC\u95A2\u6570\n  \
    \  // p1^e1 * p2^e2 * ... * pk^ek \u306B\u5BFE\u3057\u3066\n    // (p1-1)*p1^(e1-1)\
    \ * (p2-1)*p2^(e2-1) * ... * (pk-1)*pk^(ek-1)\n    // \u3092\u8FD4\u3059\n   \
    \ auto f = factor2(n);\n    long ret = 1;\n    for(auto[p,e]:f){\n        ret\
    \ *= (p-1)*power(p,e-1);\n    }\n    return ret;\n}"
  dependsOn:
  - templete.hpp
  - Math/Number-Theory/prime-factorize.hpp
  isVerificationFile: false
  path: Math/Number-Theory/euler.hpp
  requiredBy: []
  timestamp: '2023-11-14 13:45:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Math/Number-Theory/euler.test.cpp
documentation_of: Math/Number-Theory/euler.hpp
layout: document
title: "Euler's Phi Function / \u30AA\u30A4\u30E9\u30FC\u306E\u30D5\u30A1\u30A4\u95A2\
  \u6570"
---

## 概要
$n$以下の正の整数のうち、$n$と互いに素なものの個数を求めます。

## 計算量
$O(\sqrt{n})$


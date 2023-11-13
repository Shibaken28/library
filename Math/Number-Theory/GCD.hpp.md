---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
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
  bundledCode: "#line 1 \"Math/Number-Theory/GCD.hpp\"\n# include <vector>\nusing\
    \ namespace std;\n\nlong GCD(long a,long b){\n    if(a<b)return GCD(b,a);\n  \
    \  if(b==0)return a;\n    return GCD(b,a%b);\n}\n\nlong GCD(vector<long>&A){\n\
    \    long gcd = A.front();\n    for(auto&a:A)gcd = GCD(gcd,a);\n    return gcd;\n\
    }\n\nlong LCM(long a,long b){\n    return (a/GCD(a,b))*b;\n}\n\n\nlong LCM(vector<long>&A){\n\
    \    long lcm = 1;\n    for(auto&a:A)lcm = LCM(lcm,a);\n    return lcm;\n}\n\n"
  code: "# include <vector>\nusing namespace std;\n\nlong GCD(long a,long b){\n  \
    \  if(a<b)return GCD(b,a);\n    if(b==0)return a;\n    return GCD(b,a%b);\n}\n\
    \nlong GCD(vector<long>&A){\n    long gcd = A.front();\n    for(auto&a:A)gcd =\
    \ GCD(gcd,a);\n    return gcd;\n}\n\nlong LCM(long a,long b){\n    return (a/GCD(a,b))*b;\n\
    }\n\n\nlong LCM(vector<long>&A){\n    long lcm = 1;\n    for(auto&a:A)lcm = LCM(lcm,a);\n\
    \    return lcm;\n}\n\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/Number-Theory/GCD.hpp
  requiredBy: []
  timestamp: '2023-11-13 15:54:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Math/Number-Theory/GCD.test.cpp
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



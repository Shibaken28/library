---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Math/Number-Theory/enum-prme.test.cpp
    title: Math/Number-Theory/enum-prme.test.cpp
  - icon: ':heavy_check_mark:'
    path: Math/Number-Theory/isprime.test.cpp
    title: Math/Number-Theory/isprime.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Math/Number-Theory/isprime.hpp\"\nbool isPrime(long N){\n\
    \    if(N<=1)return false;\n    for(long i=2;i*i<=N;i++){\n        if(N%i==0){\n\
    \            return false;\n        }\n    }\n    return true;\n}\n"
  code: "bool isPrime(long N){\n    if(N<=1)return false;\n    for(long i=2;i*i<=N;i++){\n\
    \        if(N%i==0){\n            return false;\n        }\n    }\n    return\
    \ true;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/Number-Theory/isprime.hpp
  requiredBy: []
  timestamp: '2023-11-13 15:54:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Math/Number-Theory/isprime.test.cpp
  - Math/Number-Theory/enum-prme.test.cpp
documentation_of: Math/Number-Theory/isprime.hpp
layout: document
title: "is prime / \u7D20\u6570\u5224\u5B9A"
---

## 概要
素数判定を行います。

## 計算量
$O(\sqrt{n})$



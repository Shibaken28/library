---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Math/Mod/modpow.test.cpp
    title: Math/Mod/modpow.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Math/Mod/modpow.hpp\"\n\nlong modpow(long a, long b, long\
    \ m){\n    // a^b mod m\n    long ret = 1;\n    while(b>0){\n        if(b&1) ret\
    \ = (ret * a)%m;\n        a = (a * a)%m;\n        b >>= 1;\n    }\n    return\
    \ ret;\n}\n\n"
  code: "\nlong modpow(long a, long b, long m){\n    // a^b mod m\n    long ret =\
    \ 1;\n    while(b>0){\n        if(b&1) ret = (ret * a)%m;\n        a = (a * a)%m;\n\
    \        b >>= 1;\n    }\n    return ret;\n}\n\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/Mod/modpow.hpp
  requiredBy: []
  timestamp: '2023-11-13 15:54:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Math/Mod/modpow.test.cpp
documentation_of: Math/Mod/modpow.hpp
layout: document
title: "power(mod) / \u3079\u304D\u4E57(mod)"
---

## 概要
$ a^b \mod m $を計算します

## 計算量
$ O(\log b) $

---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: Math/Number-Theory/CRT.hpp
    title: "Chinese Remainder Theorem / \u4E2D\u56FD\u5270\u4F59\u5B9A\u7406"
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Math/Number-Theory/CRT.test.cpp
    title: Math/Number-Theory/CRT.test.cpp
  - icon: ':heavy_check_mark:'
    path: Math/Number-Theory/ext-euclid.test.cpp
    title: Math/Number-Theory/ext-euclid.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Math/Number-Theory/ext-euclid.hpp\"\n// \u62E1\u5F35Euclid\u306E\
    \u4E92\u9664\u6CD5\n// ax + by = gcd(a, b) \u3068\u306A\u308B\u3088\u3046\u306A\
    \ (x, y) \u3092\u6C42\u3081\u308B \nlong extGCD(long a, long b, long &x, long\
    \ &y) {\n    if (b == 0) {\n        x = 1;\n        y = 0;\n        return a;\n\
    \    }\n    long d = extGCD(b, a%b, y, x);\n    y -= a/b * x;\n    return d;\n\
    }\n\n"
  code: "// \u62E1\u5F35Euclid\u306E\u4E92\u9664\u6CD5\n// ax + by = gcd(a, b) \u3068\
    \u306A\u308B\u3088\u3046\u306A (x, y) \u3092\u6C42\u3081\u308B \nlong extGCD(long\
    \ a, long b, long &x, long &y) {\n    if (b == 0) {\n        x = 1;\n        y\
    \ = 0;\n        return a;\n    }\n    long d = extGCD(b, a%b, y, x);\n    y -=\
    \ a/b * x;\n    return d;\n}\n\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/Number-Theory/ext-euclid.hpp
  requiredBy:
  - Math/Number-Theory/CRT.hpp
  timestamp: '2023-11-13 15:54:10+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - Math/Number-Theory/CRT.test.cpp
  - Math/Number-Theory/ext-euclid.test.cpp
documentation_of: Math/Number-Theory/ext-euclid.hpp
layout: document
title: "Extended Euclidean algorithm / \u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\
  \u306E\u4E92\u9664\u6CD5"
---

## 概要
$ax + by = \mathrm{gcd} (a, b)$ を満たす $x, y$ を求めます。$|x| + |y|$ が最小で、$x\leq y$ となるように $x, y$ を求めます。

## 計算量
$O(\log \min(a, b))$


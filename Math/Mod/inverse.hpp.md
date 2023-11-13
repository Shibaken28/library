---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/Number-Theory/ext-euclid.hpp
    title: "Extended Euclidean algorithm / \u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\
      \u30C9\u306E\u4E92\u9664\u6CD5"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Math/Number-Theory/ext-euclid.hpp\"\n// \u62E1\u5F35Euclid\u306E\
    \u4E92\u9664\u6CD5\n// ax + by = gcd(a, b) \u3068\u306A\u308B\u3088\u3046\u306A\
    \ (x, y) \u3092\u6C42\u3081\u308B \nlong extGCD(long a, long b, long &x, long\
    \ &y) {\n    if (b == 0) {\n        x = 1;\n        y = 0;\n        return a;\n\
    \    }\n    long d = extGCD(b, a%b, y, x);\n    y -= a/b * x;\n    return d;\n\
    }\n#line 2 \"Math/Mod/inverse.hpp\"\n\n// \u9006\u5143 a^{-1} mod m\nlong modinv(long\
    \ a,long m){\n    long x,y;\n    extGCD(a,m,x,y);\n    return (m+x%m)%m;\n}\n"
  code: "# include \"../Number-Theory/ext-euclid.hpp\"\n\n// \u9006\u5143 a^{-1} mod\
    \ m\nlong modinv(long a,long m){\n    long x,y;\n    extGCD(a,m,x,y);\n    return\
    \ (m+x%m)%m;\n}"
  dependsOn:
  - Math/Number-Theory/ext-euclid.hpp
  isVerificationFile: false
  path: Math/Mod/inverse.hpp
  requiredBy: []
  timestamp: '2023-11-14 01:12:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/Mod/inverse.hpp
layout: document
title: "inverse / \u9006\u5143"
---

## 概要
$\pmod m$の世界での逆元を求めます

## 制約
- 逆元が存在しない場合に使用するとバグります


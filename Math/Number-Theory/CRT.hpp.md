---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Math/Number-Theory/ext-euclid.hpp
    title: "Extended Euclidean algorithm / \u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\
      \u30C9\u306E\u4E92\u9664\u6CD5"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Math/Number-Theory/CRT.test.cpp
    title: Math/Number-Theory/CRT.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Math/Number-Theory/CRT.hpp\"\n# include <vector>\n# include\
    \ <utility>\n#line 1 \"Math/Number-Theory/ext-euclid.hpp\"\n// \u62E1\u5F35Euclid\u306E\
    \u4E92\u9664\u6CD5\n// ax + by = gcd(a, b) \u3068\u306A\u308B\u3088\u3046\u306A\
    \ (x, y) \u3092\u6C42\u3081\u308B \nlong extGCD(long a, long b, long &x, long\
    \ &y) {\n    if (b == 0) {\n        x = 1;\n        y = 0;\n        return a;\n\
    \    }\n    long d = extGCD(b, a%b, y, x);\n    y -= a/b * x;\n    return d;\n\
    }\n\n#line 4 \"Math/Number-Theory/CRT.hpp\"\nusing namespace std;\n\nlong mod(long\
    \ a,long m){\n    if(a>=0)return a%m; \n    return (m-(-a)%m)%m;\n}\n\n/*\n\u4E2D\
    \u56FD\u5270\u4F59\u5B9A\u7406\n*/\nbool CRT(long b1, long m1, long b2, long m2,long\
    \ &r,long &m) {\n    long p, q;\n    long d = extGCD(m1, m2, p, q);\n    if ((b2\
    \ - b1) % d != 0) return false;\n    m = m1 * (m2/d); \n    long tmp = (b2 - b1)\
    \ / d * p % (m2/d);\n    r = mod(b1 + m1 * tmp, m);\n    return true;\n}\n\nbool\
    \ CRT(const vector<pair<long,long>> &X,long &r,long &m) {\n    int s = X.size();\n\
    \    r = X.front().first;\n    m = X.front().second;\n    bool ok = true;\n  \
    \  for(int i=1;i<s;i++){\n        ok = CRT(r,m,X[i].first,X[i].second,r,m);\n\
    \        if(!ok){\n            break;\n        }\n    }\n    return ok;\n}\n\n"
  code: "# include <vector>\n# include <utility>\n# include \"ext-euclid.hpp\"\nusing\
    \ namespace std;\n\nlong mod(long a,long m){\n    if(a>=0)return a%m; \n    return\
    \ (m-(-a)%m)%m;\n}\n\n/*\n\u4E2D\u56FD\u5270\u4F59\u5B9A\u7406\n*/\nbool CRT(long\
    \ b1, long m1, long b2, long m2,long &r,long &m) {\n    long p, q;\n    long d\
    \ = extGCD(m1, m2, p, q);\n    if ((b2 - b1) % d != 0) return false;\n    m =\
    \ m1 * (m2/d); \n    long tmp = (b2 - b1) / d * p % (m2/d);\n    r = mod(b1 +\
    \ m1 * tmp, m);\n    return true;\n}\n\nbool CRT(const vector<pair<long,long>>\
    \ &X,long &r,long &m) {\n    int s = X.size();\n    r = X.front().first;\n   \
    \ m = X.front().second;\n    bool ok = true;\n    for(int i=1;i<s;i++){\n    \
    \    ok = CRT(r,m,X[i].first,X[i].second,r,m);\n        if(!ok){\n           \
    \ break;\n        }\n    }\n    return ok;\n}\n\n"
  dependsOn:
  - Math/Number-Theory/ext-euclid.hpp
  isVerificationFile: false
  path: Math/Number-Theory/CRT.hpp
  requiredBy: []
  timestamp: '2023-11-13 16:15:52+09:00'
  verificationStatus: LIBRARY_ALL_WA
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



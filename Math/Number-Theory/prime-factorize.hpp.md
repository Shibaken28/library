---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Math/Number-Theory/euler.hpp
    title: "Euler's Phi Function / \u30AA\u30A4\u30E9\u30FC\u306E\u30D5\u30A1\u30A4\
      \u95A2\u6570"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Math/Number-Theory/euler.test.cpp
    title: Math/Number-Theory/euler.test.cpp
  - icon: ':heavy_check_mark:'
    path: Math/Number-Theory/prime-factorize.test.cpp
    title: Math/Number-Theory/prime-factorize.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Math/Number-Theory/prime-factorize.hpp\"\n# include <vector>\n\
    using namespace std;\n\n//\u7D20\u56E0\u6570\u5206\u89E3\nvector<long> factor(long\
    \ x){\n    vector<long> f(0);\n    for(long i=2;i*i<=x;i++){\n        if(x%i==0){\n\
    \            f.push_back(i);\n            x/=i;\n            i--;\n        }\n\
    \    }\n    if(x>1)f.push_back(x);\n    return f;\n}\n\n//\u7D20\u56E0\u6570\u5206\
    \u89E32\n// (\u7D20\u6570,\u6307\u6570) \u306Epair\nvector<pair<long,long>> factor2(long\
    \ x){\n    auto f = factor(x);\n    vector<pair<long,long>> f2(0);\n    for(auto\
    \ a:f){\n        if(f2.empty()){\n            f2.push_back({a,1});\n        }else\
    \ if(f2.back().first==a){\n            f2.back().second ++;\n        }else{\n\
    \            f2.push_back({a,1});\n        }\n    }\n    return f2;\n}\n"
  code: "# include <vector>\nusing namespace std;\n\n//\u7D20\u56E0\u6570\u5206\u89E3\
    \nvector<long> factor(long x){\n    vector<long> f(0);\n    for(long i=2;i*i<=x;i++){\n\
    \        if(x%i==0){\n            f.push_back(i);\n            x/=i;\n       \
    \     i--;\n        }\n    }\n    if(x>1)f.push_back(x);\n    return f;\n}\n\n\
    //\u7D20\u56E0\u6570\u5206\u89E32\n// (\u7D20\u6570,\u6307\u6570) \u306Epair\n\
    vector<pair<long,long>> factor2(long x){\n    auto f = factor(x);\n    vector<pair<long,long>>\
    \ f2(0);\n    for(auto a:f){\n        if(f2.empty()){\n            f2.push_back({a,1});\n\
    \        }else if(f2.back().first==a){\n            f2.back().second ++;\n   \
    \     }else{\n            f2.push_back({a,1});\n        }\n    }\n    return f2;\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/Number-Theory/prime-factorize.hpp
  requiredBy:
  - Math/Number-Theory/euler.hpp
  timestamp: '2023-11-13 15:54:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Math/Number-Theory/prime-factorize.test.cpp
  - Math/Number-Theory/euler.test.cpp
documentation_of: Math/Number-Theory/prime-factorize.hpp
layout: document
title: "prime factorize/ \u7D20\u56E0\u6570\u5206\u89E3"
---

## 概要
素因数分解を行います。
昇順の素数のリストを返します。

## 計算量
$O(\sqrt{n})$


---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Math/Number-Theory/divisor.test.cpp
    title: Math/Number-Theory/divisor.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Math/Number-Theory/divisor.hpp\"\n# include <vector>\n#\
    \ include <algorithm>\nusing namespace std;\n\n//\u7D04\u6570\u5217\u6319\nvector<long>\
    \ divisor(long x){\n    vector<long> f(0);\n    for(long i=1;i*i<=x;i++){\n  \
    \      if(x%i==0){\n            f.push_back(i);\n            if(i!=x/i)f.push_back(x/i);\n\
    \        }\n    }\n    sort(f.begin(),f.end());\n    return f;\n}\n"
  code: "# include <vector>\n# include <algorithm>\nusing namespace std;\n\n//\u7D04\
    \u6570\u5217\u6319\nvector<long> divisor(long x){\n    vector<long> f(0);\n  \
    \  for(long i=1;i*i<=x;i++){\n        if(x%i==0){\n            f.push_back(i);\n\
    \            if(i!=x/i)f.push_back(x/i);\n        }\n    }\n    sort(f.begin(),f.end());\n\
    \    return f;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/Number-Theory/divisor.hpp
  requiredBy: []
  timestamp: '2023-11-13 15:54:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Math/Number-Theory/divisor.test.cpp
documentation_of: Math/Number-Theory/divisor.hpp
layout: document
title: "divisors / \u7D04\u6570\u5217\u6319"
---

## 概要
約数を昇順に列挙します。

## 計算量
$O(\sqrt{n})$



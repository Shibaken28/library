---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Math/Natural/GCD.test.cpp
    title: Math/Natural/GCD.test.cpp
  - icon: ':heavy_check_mark:'
    path: Math/Natural/LCM.test.cpp
    title: Math/Natural/LCM.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Math/Natural/GCD.hpp\"\n# include <vector>\nusing namespace\
    \ std;\n\nlong GCD(long a,long b){\n    if(a<b)return GCD(b,a);\n    if(b==0)return\
    \ a;\n    return GCD(b,a%b);\n}\n\nlong GCD(vector<long>&A){\n    long gcd = A.front();\n\
    \    for(auto&a:A)gcd = GCD(gcd,a);\n    return gcd;\n}\n\nlong LCM(long a,long\
    \ b){\n    return (a/GCD(a,b))*b;\n}\n\n\nlong LCM(vector<long>&A){\n    long\
    \ lcm = 1;\n    for(auto&a:A)lcm = LCM(lcm,a);\n    return lcm;\n}\n\n"
  code: "# include <vector>\nusing namespace std;\n\nlong GCD(long a,long b){\n  \
    \  if(a<b)return GCD(b,a);\n    if(b==0)return a;\n    return GCD(b,a%b);\n}\n\
    \nlong GCD(vector<long>&A){\n    long gcd = A.front();\n    for(auto&a:A)gcd =\
    \ GCD(gcd,a);\n    return gcd;\n}\n\nlong LCM(long a,long b){\n    return (a/GCD(a,b))*b;\n\
    }\n\n\nlong LCM(vector<long>&A){\n    long lcm = 1;\n    for(auto&a:A)lcm = LCM(lcm,a);\n\
    \    return lcm;\n}\n\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/Natural/GCD.hpp
  requiredBy: []
  timestamp: '2023-11-13 12:17:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Math/Natural/GCD.test.cpp
  - Math/Natural/LCM.test.cpp
documentation_of: Math/Natural/GCD.hpp
layout: document
redirect_from:
- /library/Math/Natural/GCD.hpp
- /library/Math/Natural/GCD.hpp.html
title: Math/Natural/GCD.hpp
---

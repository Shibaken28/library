---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Math/Combination/combination.test.cpp
    title: Math/Combination/combination.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Math/Combination/combination.hpp\"\n# include <vector>\n\
    using namespace std;\n\ntemplate<class T> struct Combination{\n    int N;\n  \
    \  vector<T> fac;//\u968E\u4E57\n    vector<T> finv;//\u968E\u4E57\u306E\u9006\
    \u5143\n    Combination(int N){\n        this->N = N;\n        init();\n    }\n\
    \    void init(){\n        fac.resize(N);\n        finv.resize(N);\n        fac[0]\
    \ = fac[1] = 1;\n        finv[0] = finv[1] = 1;\n        for(int i=2;i<N;i++){\n\
    \            fac[i] = fac[i-1] * i;\n            finv[i] = finv[i-1] / i;\n  \
    \      }\n    }\n    /*aCb\u306E\u8A08\u7B97*/\n    T com(int a,int b){\n    \
    \    if(a < b)return 0;\n        return fac[a] * finv[b] * finv[a-b];\n    }\n\
    };\n\n"
  code: "# include <vector>\nusing namespace std;\n\ntemplate<class T> struct Combination{\n\
    \    int N;\n    vector<T> fac;//\u968E\u4E57\n    vector<T> finv;//\u968E\u4E57\
    \u306E\u9006\u5143\n    Combination(int N){\n        this->N = N;\n        init();\n\
    \    }\n    void init(){\n        fac.resize(N);\n        finv.resize(N);\n  \
    \      fac[0] = fac[1] = 1;\n        finv[0] = finv[1] = 1;\n        for(int i=2;i<N;i++){\n\
    \            fac[i] = fac[i-1] * i;\n            finv[i] = finv[i-1] / i;\n  \
    \      }\n    }\n    /*aCb\u306E\u8A08\u7B97*/\n    T com(int a,int b){\n    \
    \    if(a < b)return 0;\n        return fac[a] * finv[b] * finv[a-b];\n    }\n\
    };\n\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/Combination/combination.hpp
  requiredBy: []
  timestamp: '2023-11-13 23:35:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Math/Combination/combination.test.cpp
documentation_of: Math/Combination/combination.hpp
layout: document
redirect_from:
- /library/Math/Combination/combination.hpp
- /library/Math/Combination/combination.hpp.html
title: Math/Combination/combination.hpp
---

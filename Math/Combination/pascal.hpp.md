---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Math/Combination/pascal.hpp\"\n# include <vector>\nusing\
    \ namespace std;\n\nstruct Pascal{\n    //tri[a][b] = aCb\n    vector<vector<long>>\
    \ tri;\n    int N;\n    Pascal(int N){\n        this->N = N;\n        init();\n\
    \    }\n    void init(){\n        tri.clear();\n        tri.push_back({1});\n\
    \        for(int i=1;i<N;i++){\n            vector<long> add(0);\n           \
    \ add.push_back(1);\n            for(int k=0;k<i-1;k++){\n                add.push_back(tri.back()[k]+tri.back()[k+1]);\n\
    \            }\n            add.push_back(1);\n            tri.push_back(add);\n\
    \        }\n    }\n    long com(int a,int b){\n        if(a<b)return 0;\n    \
    \    return tri[a][b];\n    }\n};\n"
  code: "# include <vector>\nusing namespace std;\n\nstruct Pascal{\n    //tri[a][b]\
    \ = aCb\n    vector<vector<long>> tri;\n    int N;\n    Pascal(int N){\n     \
    \   this->N = N;\n        init();\n    }\n    void init(){\n        tri.clear();\n\
    \        tri.push_back({1});\n        for(int i=1;i<N;i++){\n            vector<long>\
    \ add(0);\n            add.push_back(1);\n            for(int k=0;k<i-1;k++){\n\
    \                add.push_back(tri.back()[k]+tri.back()[k+1]);\n            }\n\
    \            add.push_back(1);\n            tri.push_back(add);\n        }\n \
    \   }\n    long com(int a,int b){\n        if(a<b)return 0;\n        return tri[a][b];\n\
    \    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/Combination/pascal.hpp
  requiredBy: []
  timestamp: '2023-11-13 23:35:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/Combination/pascal.hpp
layout: document
title: "Pascal's triangle / \u30D1\u30B9\u30AB\u30EB\u306E\u4E09\u89D2\u5F62\u306B\
  \u3088\u308B\u4E8C\u9805\u4FC2\u6570\u306E\u8A08\u7B97"
---

## 概要
パスカルの三角形を利用して$n$個のものから$r$個を選ぶ組み合わせの数を計算します

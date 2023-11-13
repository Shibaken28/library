---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Enumerate/permutations.test.cpp
    title: Enumerate/permutations.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Enumerate/permutations.hpp\"\n# include <vector>\n# include\
    \ <algorithm>\nusing namespace std;\n\n// \u9806\u5217\u5217\u6319\nvector<vector<int>>\
    \ permutations(int N){\n    vector<int> array(N);\n    vector<vector<int>> A(0);\n\
    \    for(int i=0;i<N;i++)array[i]=i;\n    do{\n        A.push_back(array);\n \
    \   }while(next_permutation(array.begin(),array.end()));\n    return A;\n}\n\n"
  code: "# include <vector>\n# include <algorithm>\nusing namespace std;\n\n// \u9806\
    \u5217\u5217\u6319\nvector<vector<int>> permutations(int N){\n    vector<int>\
    \ array(N);\n    vector<vector<int>> A(0);\n    for(int i=0;i<N;i++)array[i]=i;\n\
    \    do{\n        A.push_back(array);\n    }while(next_permutation(array.begin(),array.end()));\n\
    \    return A;\n}\n\n"
  dependsOn: []
  isVerificationFile: false
  path: Enumerate/permutations.hpp
  requiredBy: []
  timestamp: '2023-11-13 23:35:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Enumerate/permutations.test.cpp
documentation_of: Enumerate/permutations.hpp
layout: document
title: "enumerate permutations / \u9806\u5217\u5217\u6319"
---

## 概要
長さが`n`の順列を辞書順に列挙します

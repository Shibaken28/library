---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Enumerate/permutations.hpp
    title: "enumerate permutations / \u9806\u5217\u5217\u6319"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/8/ITP2/5/ITP2_5_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/8/ITP2/5/ITP2_5_D
  bundledCode: "#line 1 \"Enumerate/permutations.test.cpp\"\n# define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/8/ITP2/5/ITP2_5_D\"\
    \n# include <iostream>\n#line 1 \"Enumerate/permutations.hpp\"\n# include <vector>\n\
    # include <algorithm>\nusing namespace std;\n\n// \u9806\u5217\u5217\u6319\nvector<vector<int>>\
    \ permutations(int N){\n    vector<int> array(N);\n    vector<vector<int>> A(0);\n\
    \    for(int i=0;i<N;i++)array[i]=i;\n    do{\n        A.push_back(array);\n \
    \   }while(next_permutation(array.begin(),array.end()));\n    return A;\n}\n\n\
    #line 4 \"Enumerate/permutations.test.cpp\"\nusing namespace std;\n\nint main(){\n\
    \    int n; cin>>n;\n    auto A=permutations(n);\n    for(auto a:A){\n       \
    \ for(int i=0;i<n;i++){\n            if(i)cout<<\" \";\n            cout<<a[i]+1;\n\
    \        }\n        cout<<endl;\n    }\n}\n"
  code: "# define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/8/ITP2/5/ITP2_5_D\"\
    \n# include <iostream>\n# include \"permutations.hpp\"\nusing namespace std;\n\
    \nint main(){\n    int n; cin>>n;\n    auto A=permutations(n);\n    for(auto a:A){\n\
    \        for(int i=0;i<n;i++){\n            if(i)cout<<\" \";\n            cout<<a[i]+1;\n\
    \        }\n        cout<<endl;\n    }\n}\n"
  dependsOn:
  - Enumerate/permutations.hpp
  isVerificationFile: true
  path: Enumerate/permutations.test.cpp
  requiredBy: []
  timestamp: '2023-11-13 23:35:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Enumerate/permutations.test.cpp
layout: document
redirect_from:
- /verify/Enumerate/permutations.test.cpp
- /verify/Enumerate/permutations.test.cpp.html
title: Enumerate/permutations.test.cpp
---

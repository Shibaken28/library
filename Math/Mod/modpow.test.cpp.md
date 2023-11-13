---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/Mod/modpow.hpp
    title: "power(mod) / \u3079\u304D\u4E57(mod)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_B
  bundledCode: "#line 1 \"Math/Mod/modpow.test.cpp\"\n# define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_B\"\
    \n# include <iostream>\n#line 1 \"Math/Mod/modpow.hpp\"\n\nlong modpow(long a,\
    \ long b, long m){\n    // a^b mod m\n    long ret = 1;\n    while(b>0){\n   \
    \     if(b&1) ret = (ret * a)%m;\n        a = (a * a)%m;\n        b >>= 1;\n \
    \   }\n    return ret;\n}\n\n#line 4 \"Math/Mod/modpow.test.cpp\"\n\nusing namespace\
    \ std;\n\nint main(){\n    int a,b; cin>>a>>b;\n    cout << modpow(a,b,1000000007)\
    \ << endl;\n}\n"
  code: "# define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_B\"\
    \n# include <iostream>\n# include \"modpow.hpp\"\n\nusing namespace std;\n\nint\
    \ main(){\n    int a,b; cin>>a>>b;\n    cout << modpow(a,b,1000000007) << endl;\n\
    }\n"
  dependsOn:
  - Math/Mod/modpow.hpp
  isVerificationFile: true
  path: Math/Mod/modpow.test.cpp
  requiredBy: []
  timestamp: '2023-11-13 15:54:10+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Math/Mod/modpow.test.cpp
layout: document
redirect_from:
- /verify/Math/Mod/modpow.test.cpp
- /verify/Math/Mod/modpow.test.cpp.html
title: Math/Mod/modpow.test.cpp
---

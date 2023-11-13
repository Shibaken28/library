---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/Number-Theory/GCD.hpp
    title: "GCD, LCM / \u6700\u5927\u516C\u7D04\u6570\u3068\u6700\u5C0F\u516C\u500D\
      \u6570"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_C
  bundledCode: "#line 1 \"Math/Number-Theory/LCM.test.cpp\"\n# define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_C\"\
    \n\n# include <iostream>\n# include <vector>\n#line 2 \"Math/Number-Theory/GCD.hpp\"\
    \nusing namespace std;\n\nlong GCD(long a,long b){\n    if(a<b)return GCD(b,a);\n\
    \    if(b==0)return a;\n    return GCD(b,a%b);\n}\n\nlong GCD(vector<long>&A){\n\
    \    long gcd = A.front();\n    for(auto&a:A)gcd = GCD(gcd,a);\n    return gcd;\n\
    }\n\nlong LCM(long a,long b){\n    return (a/GCD(a,b))*b;\n}\n\n\nlong LCM(vector<long>&A){\n\
    \    long lcm = 1;\n    for(auto&a:A)lcm = LCM(lcm,a);\n    return lcm;\n}\n\n\
    #line 6 \"Math/Number-Theory/LCM.test.cpp\"\nusing namespace std;\n\nint main(){\n\
    \    int n;cin>>n;\n    vector<long>A(n);\n    for(auto&a:A)cin>>a;\n    cout<<LCM(A)<<endl;\n\
    }\n\n"
  code: "# define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_C\"\n\n\
    # include <iostream>\n# include <vector>\n# include \"GCD.hpp\"\nusing namespace\
    \ std;\n\nint main(){\n    int n;cin>>n;\n    vector<long>A(n);\n    for(auto&a:A)cin>>a;\n\
    \    cout<<LCM(A)<<endl;\n}\n\n"
  dependsOn:
  - Math/Number-Theory/GCD.hpp
  isVerificationFile: true
  path: Math/Number-Theory/LCM.test.cpp
  requiredBy: []
  timestamp: '2023-11-13 15:54:10+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Math/Number-Theory/LCM.test.cpp
layout: document
redirect_from:
- /verify/Math/Number-Theory/LCM.test.cpp
- /verify/Math/Number-Theory/LCM.test.cpp.html
title: Math/Number-Theory/LCM.test.cpp
---
